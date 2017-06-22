#ifndef MYLABEL_H
#define MYLABEL_H

#include <QWidget>
#include <QLabel>

class MyLabel : public QLabel
{
    Q_OBJECT
public:
    MyLabel(QWidget *parent=0): QLabel(parent){}
    ~MyLabel() {}
signals:
    void clicked(MyLabel* click); // 点击信号
protected:
    void mouseReleaseEvent(QMouseEvent*); // 重载了鼠标释放事件

};


#endif // MYLABEL_H
