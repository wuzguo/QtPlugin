#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class widget;
}

class widget : public QWidget
{
    Q_OBJECT

public:
    explicit widget(QWidget *parent = 0);
    ~widget();

private slots:
       void  timerUpdate();

private:
    Ui::widget *ui;
};

#endif // WIDGET_H
