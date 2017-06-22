#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QtGui>
#include "mythread.h"
#include "mylabel.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private:
    Ui::MainWindow *ui;

    QImage* img;

    MyThread *t;

    MyLabel *label;


    int index;
    QStringList imageList;
    QDir imageDir;
    int flag;



public slots:
    void audochange(QString);
    void on_lable_clickLabel();
     void timerUpDate();



};

#endif // MAINWINDOW_H
