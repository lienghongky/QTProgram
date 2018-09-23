#ifndef MAINWINDOWM_H
#define MAINWINDOWM_H

#include <QMainWindow>
#include "camviewer.h"
#include <opencv2/highgui/highgui.hpp>

namespace Ui {
class MainWindowM;
}

class MainWindowM : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindowM(QWidget *parent = nullptr);
    ~MainWindowM();

private:
    Ui::MainWindowM *ui;
    QTimer *timer_1s;
    QGraphicsScene scene;
    cv::VideoCapture videoCap;
    cv::Mat frame;
    int CAM_ID = 0;

private slots:
    void UpdateTime();
    void updateFrame(void);
    void initCamera();
    void on_btnStart_clicked();
    void on_btnBrowns_clicked();
};


#endif // MAINWINDOWM_H
