#include "mainwindow.h"
#include "ui_mainwindow.h"


#include <QtGui>
#include <QPluginLoader>
#include <QMessageBox>

#include "qbaseplugin.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    loadplugin();
    this->setCentralWidget(testwidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//加载插件函数
QWidget *loadPlugins(QString pluginFileName, QWidget *parent)
{
    QPluginLoader loader( pluginFileName, parent );

    bool lbok = loader.load();
    if(lbok)
    {
        qDebug("loder ok!\r\n");
    }
    else
    {
        qDebug("loder error!\r\n");
    }

    QObject *plugin = loader.instance();

    if (plugin)
    {
        QBasePlugin *qbPlugin = qobject_cast<QBasePlugin *>(plugin);
        if(qbPlugin){
            QWidget *widget = qbPlugin->createWidget(parent);
            return widget;
        }
    }
    else
    {
        qDebug("loader.instance() error\r\n");
    }

    return NULL;
}


//初始化插件
void MainWindow::loadplugin()
{
    QString DirPath=QApplication::applicationDirPath();

    //DirPath=DirPath.left(DirPath.lastIndexOf("/"));

    QString pluginfilename = DirPath+"/baseplugind.dll";

    qDebug() << "pluginfilename = " << pluginfilename;

    testwidget = loadPlugins( pluginfilename, this );
}
