#include "mythread.h"
#include "ui_mainwindow.h"

#include <QDebug>

MyThread::MyThread(QObject *parent) :
    QThread(parent)
{
}

void MyThread::time_stop()
{
    suspend=0;
}
void MyThread::time_start()
{
    suspend=1;
}

void MyThread::run()
{
    suspend=1;

    imageDir.setPath("/udisk");
    QStringList filter ;
    filter << "*.jpg" << "*.bmp" << "*.jpeg" << "*.png" << "*.xpm"<<"*.gif" ;
    imageList = imageDir.entryList(filter, QDir::Files |QDir::NoSymLinks,QDir::Name) ;
    if(imageList.size()==0) {
        emit dataChanged("no");
        suspend=0;
    }

    //QString st = imageDir.absolutePath() + QDir::separator()+ imageList.at(0);



    t.start();
    index = 0;
        while(1)
        {

            if((t.elapsed() % 5000 == 0)&&suspend==1)
            {
               // qDebug("\nready to show picture!index=%d\n",index);


                if(index < imageList.size()-1 )
                {
                    index ++ ;
                    QString st = imageDir.absolutePath() + QDir::separator()+ imageList.at(index);
                    emit dataChanged(st);
                }
                else
                {
                    index = 0;
                    QString st = imageDir.absolutePath() + QDir::separator()+ imageList.at(index);
                    emit dataChanged(st);
                }

            }
        }

}
