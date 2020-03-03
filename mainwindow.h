#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QMessageBox>

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
    void on_pushButton_clicked();
    void er(QAbstractSocket::SocketError);
    void sockReady();
    void sockDisc();
    void connected();

private:
    Ui::MainWindow *ui;
    QTcpSocket *socket;
    QByteArray data;
};
#endif // MAINWINDOW_H
