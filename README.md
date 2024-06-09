# Radio Xiph

**Radio Xiph** is a cross-platform radio player that allows users to search, play, and manage their favorite radio stations from the Xiph.org directory. The application supports both Windows and Linux platforms and provides a modern, intuitive user interface.

## Features

- **Search and Play Radio Stations**: Easily search for radio stations and play them directly from the application.
- **Favorites Management**: Add your favorite radio stations to a favorites list for quick access.
- **Dark Mode Support**: The application adapts to the system's dark mode settings.
- **Cross-Platform**: Runs on both Windows and Linux using the Qt framework.

## Screenshots

![Radio Xiph Screenshot](https://github.com/leonuck/radio-xiph-qt/radio-xiph-qt.png.png)

## Getting Started

### Prerequisites

- **Qt Framework**: Ensure you have the Qt framework installed. You can download it from [Qt's official website](https://www.qt.io/download).
- **NAudio**: For Windows builds, install the NAudio library for media playback.

### Installing

1. **Clone the Repository**:

    ```bash
    git clone https://github.com/leonuck/radio-xiph-qt.git
    cd radio-xiph
    ```

2. **Build the Project**:

    For Windows:

    ```bash
    qmake
    make
    ```

    For Linux:

    ```bash
    qmake
    make
    ```

### Running the Application

After building the project, you can run the application using the following command:

```bash
./radio-xiph

Dependencies
Qt Framework: Required for building and running the application. Ensure you have the necessary Qt modules installed (Widgets, Network, etc.).
NAudio: For audio playback on Windows.
Contributing
We welcome contributions! Please fork the repository and submit pull requests.

License
This project is licensed under the MIT License - see the LICENSE file for details.

Authors
Your Leonardo UCK - Initial work - leonuck

