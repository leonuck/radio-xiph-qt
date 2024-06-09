#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QXmlStreamReader>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , mediaPlayer(new QMediaPlayer(this))
{
    ui->setupUi(this);
    loadRadios();
    loadFavorites();

    // Conectar sinais aos slots
    connect(ui->buttonPlay, &QPushButton::clicked, this, &MainWindow::on_buttonPlay_clicked);
    connect(ui->buttonStop, &QPushButton::clicked, this, &MainWindow::on_buttonStop_clicked);
    connect(ui->buttonAddToFavorites, &QPushButton::clicked, this, &MainWindow::on_buttonAddToFavorites_clicked);
    connect(ui->buttonRemoveFromFavorites, &QPushButton::clicked, this, &MainWindow::on_buttonRemoveFromFavorites_clicked);
    connect(ui->buttonSearch, &QPushButton::clicked, this, &MainWindow::on_buttonSearch_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_buttonPlay_clicked()
{
    QListWidgetItem *selectedItem = ui->listWidgetRadios->currentItem();
    if (!selectedItem) {
        selectedItem = ui->listWidgetFavorites->currentItem();
    }
    if (selectedItem) {
        QString url = selectedItem->data(Qt::UserRole).toString();
        mediaPlayer->setMedia(QUrl(url));
        mediaPlayer->play();
    }
}

void MainWindow::on_buttonStop_clicked()
{
    mediaPlayer->stop();
}

void MainWindow::on_buttonAddToFavorites_clicked()
{
    QListWidgetItem *selectedItem = ui->listWidgetRadios->currentItem();
    if (selectedItem) {
        // Verificar se a estação já está na lista de favoritos
        bool alreadyInFavorites = false;
        for (int i = 0; i < ui->listWidgetFavorites->count(); ++i) {
            QListWidgetItem *item = ui->listWidgetFavorites->item(i);
            if (item->text() == selectedItem->text()) {
                alreadyInFavorites = true;
                break;
            }
        }

        if (!alreadyInFavorites) {
            ui->listWidgetFavorites->addItem(selectedItem->clone());
            saveFavorites();
        }
    }
}

void MainWindow::on_buttonRemoveFromFavorites_clicked()
{
    QListWidgetItem *selectedItem = ui->listWidgetFavorites->currentItem();
    if (selectedItem) {
        int row = ui->listWidgetFavorites->row(selectedItem);
        delete ui->listWidgetFavorites->takeItem(row);
        saveFavorites();
    }
}


void MainWindow::on_buttonSearch_clicked()
{
    QString searchText = ui->lineEditSearch->text().toLower();
    for (int i = 0; i < ui->listWidgetRadios->count(); ++i) {
        QListWidgetItem *item = ui->listWidgetRadios->item(i);
        item->setHidden(!item->text().toLower().contains(searchText));
    }
}

void MainWindow::loadRadios()
{
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    QNetworkRequest request(QUrl("http://dir.xiph.org/yp.xml"));
    QNetworkReply *reply = manager->get(request);
    connect(reply, &QNetworkReply::finished, this, [this, reply]() {
        if (reply->error() == QNetworkReply::NoError) {
            QByteArray response = reply->readAll();
            QXmlStreamReader xml(response);
            while (!xml.atEnd()) {
                xml.readNext();
                if (xml.isStartElement() && xml.name() == "entry") {
                    QString listenUrl;
                    QString stationName;
                    while (!(xml.isEndElement() && xml.name() == "entry")) {
                        xml.readNext();
                        if (xml.isStartElement()) {
                            if (xml.name() == "listen_url") {
                                listenUrl = xml.readElementText();
                            } else if (xml.name() == "server_name") {
                                stationName = xml.readElementText();
                            }
                        }
                    }
                    if (!listenUrl.isEmpty() && !stationName.isEmpty()) {
                        QListWidgetItem *item = new QListWidgetItem(stationName);
                        item->setData(Qt::UserRole, listenUrl);
                        ui->listWidgetRadios->addItem(item);
                    }
                }
            }
        }
        reply->deleteLater();
    });
}

void MainWindow::saveFavorites()
{
    QJsonArray favorites;
    for (int i = 0; i < ui->listWidgetFavorites->count(); ++i) {
        QListWidgetItem *item = ui->listWidgetFavorites->item(i);
        QJsonObject favorite;
        favorite["name"] = item->text();
        favorite["url"] = item->data(Qt::UserRole).toString();
        favorites.append(favorite);
    }
    QFile file("favorites.json");
    if (file.open(QIODevice::WriteOnly)) {
        file.write(QJsonDocument(favorites).toJson());
    }
}

void MainWindow::loadFavorites()
{
    QFile file("favorites.json");
    if (file.open(QIODevice::ReadOnly)) {
        QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
        QJsonArray favorites = doc.array();
        for (const QJsonValue &value : favorites) {
            QJsonObject obj = value.toObject();
            QListWidgetItem *item = new QListWidgetItem(obj["name"].toString());
            item->setData(Qt::UserRole, obj["url"].toString());
            ui->listWidgetFavorites->addItem(item);
        }
    }
}
