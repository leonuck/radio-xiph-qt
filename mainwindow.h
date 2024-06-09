#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_buttonPlay_clicked();
    void on_buttonStop_clicked();
    void on_buttonAddToFavorites_clicked();
    void on_buttonRemoveFromFavorites_clicked();
    void on_buttonSearch_clicked();

private:
    Ui::MainWindow *ui;
    QMediaPlayer *mediaPlayer;
    void loadRadios();
    void saveFavorites();
    void loadFavorites();
};

#endif // MAINWINDOW_H
