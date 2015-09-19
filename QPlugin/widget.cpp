#include "widget.h"
#include "ui_widget.h"


#include<QTimer>
#include<QDateTime>
#include<QDebug>


widget::widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::widget)
{
    ui->setupUi(this);

    QTimer *timer = new QTimer(this);
    //新建定时器
    connect(timer,SIGNAL(timeout()),this,SLOT(timerUpdate()));

    //关联定时器计满信号和相应的槽函数
    timer->setInterval(1000);
    timer->start();
}

widget::~widget()
{
    delete ui;
}

void widget::timerUpdate()
{
    QDateTime time = QDateTime::currentDateTime();//获取系统现在的时间
    QString str = time.toString("yyyy-MM-dd hh:mm:ss ddd"); //设置显示格式

    QString strx= strx.fromLocal8Bit("当前时间:") + str;//调用中文显示

    qDebug() << "strx = " <<strx;
    ui->lblTips->setText(strx);

    ui->lblTips->update();
}
