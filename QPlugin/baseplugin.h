#ifndef BasePlugin_H
#define BasePlugin_H

#include <QObject>
#include <QtPlugin>

#include "qbaseplugin.h"

class BasePlugin : public QObject, public QBasePlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID QBasePlugin_IID FILE "qbaseplugin.json")
    Q_INTERFACES(QBasePlugin)

public:
    BasePlugin(QObject *parent = 0);

    ~BasePlugin();

    QWidget *createWidget(QWidget *parent) Q_DECL_OVERRIDE;

protected:
    QVariant ExecCmd(const QString instanceName, int cmdID, QVariant param) Q_DECL_OVERRIDE;

};

#endif // BasePlugin_H
