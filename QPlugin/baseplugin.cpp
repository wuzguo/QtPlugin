#include "baseplugin.h"

#include "widget.h"
#include <QMessageBox>
#include <QDebug>

BasePlugin::BasePlugin(QObject *parent)
    :QObject(parent)
{

}

BasePlugin::~BasePlugin()
{

}

QWidget *BasePlugin::createWidget(QWidget *parent)
{

    return new widget(parent);
}

QVariant BasePlugin::ExecCmd(const QString instanceName, int cmdID, QVariant param)
{
    qDebug() << " stName == " << instanceName;
    return cmdID;
}
