#include "mainwindowm.h"
#include "ui_mainwindowm.h"

MainWindowM::MainWindowM(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindowM)
{
    ui->setupUi(this);
    ui->statusbar->addPermanentWidget(ui->lblStatusBar,0);

}

MainWindowM::~MainWindowM()
{
    delete ui;
}
