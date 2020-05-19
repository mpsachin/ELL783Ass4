#ifndef MAINWINDOW2_H
#define MAINWINDOW2_H

#include <unistd.h>
#include "mysem.h"
#include <QMainWindow>

namespace Ui {
class MainWindow2;
}

class MainWindow2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow2(QWidget *parent = nullptr);
    ~MainWindow2();

private:
    Ui::MainWindow2 *ui;

   // my declaration
private:
    pthread_t pthid1,pthid2;
public:

    friend void * threadfun2(void *);
    void createthreads();
    Ui::MainWindow2 * uihandle()
    {
        return ui;
    }
};

#endif // MAINWINDOW2_H
