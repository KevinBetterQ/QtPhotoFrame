#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mythread.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->hide();
    setWindowState(Qt::WindowMinimized);

    img=new QImage;
    label = new MyLabel(this);
    connect(label,SIGNAL(clicked(MyLabel*)), this, SLOT(on_lable_clickLabel()));
    //label->setScaledContents(true);//让图片适应label大小
    label->setWindowFlags(Qt::Dialog);
    label->showFullScreen();


/*

    imageDir.setPath("/udisk");
    QStringList filter ;
    filter << "*.jpg" << "*.bmp" << "*.jpeg" << "*.png" << "*.xpm" <<"*.gif";
    imageList = imageDir.entryList(filter, QDir::Files |QDir::NoSymLinks,QDir::Name) ;
    if(imageList.size()==0) {
        QMessageBox::information(this,tr("no pictures!"),tr("no pictures!"));

    }
*/

    index = 0;
    //ui->label->setPixmap(QPixmap::fromImage(*img));
    //label->setPixmap(QPixmap::fromImage(*img));
    flag = 1;
/*
    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timerUpDate()));
    timer->start(5000);
*/


    t = new MyThread();
    connect(t, SIGNAL(dataChanged(QString)), this, SLOT(audochange(QString)));
    t->start();


}

void MainWindow::audochange(QString str){
    if(QString::compare(str,"no")==0){
        QMessageBox::information(this,tr("no pictures!"),tr("no pictures!"));
        t->time_start();

    }else{
        QFileInfo fileInfo(str);
        QString lastname = fileInfo.completeSuffix();

        if(QString::compare(lastname,"gif")==0){
            QMovie *movie = new QMovie(str);
            //QPixmap pix = QPixmap::fromImage(*img).scaled(label->width(),label->height(),Qt::KeepAspectRatio);
            label->setMovie(movie);
            label->setAlignment(Qt::AlignCenter);
            movie->start();
        }else{
            img->load(str);
            QPixmap pix = QPixmap::fromImage(*img).scaled(label->width(),label->height(),Qt::KeepAspectRatio);
            label->setPixmap(pix);
            label->setAlignment(Qt::AlignCenter);
        }
    }







}

void MainWindow::on_lable_clickLabel(){
    t->time_stop();
    flag=0;
    int reply = QMessageBox::question(this, "Suspend", "Want to continue?", QMessageBox::Yes | QMessageBox::No);
    if(reply==QMessageBox::Yes) {
        t->time_start();
        flag=1;
    }
    else this->close();
}

void MainWindow::timerUpDate()
{

    if(index < imageList.size()-1 )
    {
        index ++ ;
        QString str = imageDir.absolutePath() + QDir::separator()+ imageList.at(index);
        QFileInfo fileInfo(str);
        QString lastname = fileInfo.completeSuffix();


        if(flag==1){
            if(QString::compare(lastname,"gif")==0){
                QMovie *movie = new QMovie(str);
                //QPixmap pix = QPixmap::fromImage(*img).scaled(label->width(),label->height(),Qt::KeepAspectRatio);
                label->setMovie(movie);
                label->setAlignment(Qt::AlignCenter);
                movie->start();
            }else{
                img->load(str);
                QPixmap pix = QPixmap::fromImage(*img).scaled(label->width(),label->height(),Qt::KeepAspectRatio);
                label->setPixmap(pix);
                label->setAlignment(Qt::AlignCenter);
            }


        }
    }
    else
    {
        index = 0;
        QString str = imageDir.absolutePath() + QDir::separator()+ imageList.at(index);
         QFileInfo fileInfo(str);
        QString lastname = fileInfo.completeSuffix();
        if(flag==1){
            if(QString::compare(lastname,"gif")==0){
                QMovie *movie = new QMovie(str);
                //QPixmap pix = QPixmap::fromImage(*img).scaled(label->width(),label->height(),Qt::KeepAspectRatio);
                label->setMovie(movie);
                label->setAlignment(Qt::AlignCenter);
                movie->start();
            }else{
                img->load(str);
                QPixmap pix = QPixmap::fromImage(*img).scaled(label->width(),label->height(),Qt::KeepAspectRatio);
                label->setPixmap(pix);
                label->setAlignment(Qt::AlignCenter);
            }
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
