#include "mainwindowm.h"
#include "ui_mainwindowm.h"
#include <QDate>
#include <iostream>
#include <qtextstream.h>
#include <QTimer>
#include <QFileDialog>
MainWindowM::MainWindowM(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindowM)

{
    ui->setupUi(this);
    ui->statusbar->addPermanentWidget(ui->lblStatusBar,0);
    timer_1s = new QTimer(this);
    QObject::connect(timer_1s, SIGNAL(timeout()), this, SLOT(UpdateTime()));
    timer_1s->start(1000);

    QTimer* timer = new QTimer(this);
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(updateFrame()));
    timer->start(30);
    ui->camviewer->setScene(&scene);

}

MainWindowM::~MainWindowM()
{
    delete ui;
}
void MainWindowM::UpdateTime()
{
    QDate cd = QDate::currentDate();
    QTime ct = QTime::currentTime();
    ui->lblDayOfWeek->setText(cd.toString("dddd"));
    ui->lblDay->setText(cd.toString("d"));
    ui->lblMonth->setText(cd.toString("MMMM"));
    ui->lblTime->setText(ct.toString("h:mm:ss A"));
}
void MainWindowM::initCamera(){
    if (videoCap.isOpened()){
        videoCap.release();
        ui->btnStart->setText("Start");
    }else{
        videoCap.open(CAM_ID);
        ui->btnStart->setText("Stop");
    }
}

void MainWindowM::updateFrame(){
    if (!videoCap.isOpened()) return;
    cv::Mat frame;
    while (1) {
       videoCap >> frame;
       if (!frame.empty()) break;
    }
    if (frame.empty()) return;
    ui->camviewer->setImage(QImage((const unsigned char*)(frame.data),frame.cols,frame.rows,QImage::Format_RGB888).rgbSwapped());
}

void MainWindowM::on_btnStart_clicked()
{

   initCamera();
}

void MainWindowM::on_btnBrowns_clicked()
{
    videoCap >> this->frame;
    QString filename =  QFileDialog::getSaveFileName(
              this,
              "Save to",
              QDir::currentPath(),
              "JPG files (*.jpg);; PNG files (*.png)");

        if( !filename.isNull() )
        {
         cv::imwrite(filename.toUtf8().constData(),frame);
        }
}
