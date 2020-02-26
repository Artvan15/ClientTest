#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    socket = new QTcpSocket(this);

    connect(socket, &QTcpSocket::readyRead, this, &MainWindow::sockReady);
    connect(socket, &QTcpSocket::disconnected, this, &MainWindow::sockDisc);
    connect(socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(er(QAbstractSocket::SocketError)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::sockReady(){
    /*if(socket->waitForConnected(500)){
        socket->waitForReadyRead(500);
        data = socket->readAll();
        qDebug() << data << "ddd";
    }*/
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
