#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    socket = new QTcpSocket(this);

    connect(socket, &QTcpSocket::readyRead, this, &MainWindow::sockReady);
    connect(socket, &QTcpSocket::connected, this, &MainWindow::connectYes);
    connect(socket, &QTcpSocket::disconnected, socket, &QTcpSocket::deleteLater);
    connect(socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(er(QAbstractSocket::SocketError)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::connectYes(){
    qDebug() << "Client is connected!";
}

void MainWindow::sockReady(){
    if(socket->waitForConnected(1000)){
        socket->waitForReadyRead(1000);
        data = socket->readAll();
        ui->label->setText(data);
    }
}

void MainWindow::sockDisc(){
    socket->deleteLater();
}

void MainWindow::on_pushButton_clicked()
{
    socket->connectToHost("127.0.0.1", 5555);
    qDebug() << socket->state();
}
void MainWindow::er(QAbstractSocket::SocketError error){
    qDebug() << error;
}
