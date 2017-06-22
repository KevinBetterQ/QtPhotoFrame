#ifndef MYTHREAD_H
#define MYTHREAD_H
#include <QThread>
#include <QTextEdit>
#include<QtGui>
class MyThread : public QThread
{
    Q_OBJECT
public:
    explicit MyThread(QObject *parent = 0);
    virtual void run();
    int index;
    QStringList imageList;
    QDir imageDir;
    QTime t;
    int suspend;

public:
    void time_start();
    void time_stop();

signals:
    void dataChanged(QString);

public slots:

};



#endif // MYTHREAD_H
