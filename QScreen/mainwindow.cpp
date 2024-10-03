#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Timer = new QTimer();
    connect(Timer, SIGNAL(timeout()), this, SLOT(Capture_Screen_Image()));
    Timer->setInterval(300);

    for (int i = 0; i < QGuiApplication::screens().size() ; i++) {
        qDebug() << QGuiApplication::screens().at(i)->name();
    }

    QScreen *screen = QGuiApplication::primaryScreen();
    QPixmap ScreenImage = screen->grabWindow(0);
    ScreenImage.save(QCoreApplication::applicationDirPath() + "/ScreenImage.bmp");
    ui->label->setPixmap(ScreenImage);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_CaptureBtn_clicked()
{
    Timer->stop();

//    int x = 100;
//    int y = 100;
//    int width = 500;
//    int height = 500;

//    QScreen *screen = QGuiApplication::primaryScreen();
//    QPixmap ScreenImage = screen->grabWindow(0, x, y, width, height);
//    QPixmap ScreenImage = screen->grabWindow(0);
//    ScreenImage.save(QCoreApplication::applicationDirPath() + "/ScreenImage.bmp");
//    ui->label->setPixmap(ScreenImage);
}

void MainWindow::Capture_Screen_Image()
{
    ImageCounter += 1;
    QScreen *screen = QGuiApplication::primaryScreen();
    QPixmap image = screen->grabWindow(0);
    image.save(QCoreApplication::applicationDirPath() + "/Screen Image/image_"+QString::number(ImageCounter)+".jpg");
    ui->label->setPixmap(image);
//    qDebug() << QCoreApplication::applicationDirPath();
}


void MainWindow::on_CaptureStartBtn_clicked()
{
    Timer->start();
}

