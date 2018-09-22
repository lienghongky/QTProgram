#ifndef MAINWINDOWM_H
#define MAINWINDOWM_H

#include <QMainWindow>

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
};

#endif // MAINWINDOWM_H
