#ifndef MAINWINDOW1_H
#define MAINWINDOW1_H

#include <unistd.h>
#include "mysem.h"
#include "msgq.h"
#include <QMainWindow>

namespace Ui {
class MainWindow1;
}

class MainWindow1 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow1(QWidget *parent = nullptr);
    ~MainWindow1();

private:
    Ui::MainWindow1 *ui;

   // my declaration
private:
    pthread_t pthid1,pthid2;
public:

    friend void * threadfunAddReq1(void *);
    friend void * threadfunRecReq1(void *);
    void createthreads();
    Ui::MainWindow1 * uihandle()
    {
        return ui;
    }
};

#endif // MAINWINDOW1_H
