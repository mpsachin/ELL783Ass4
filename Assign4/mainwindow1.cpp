#include "mainwindow1.h"
#include "ui_mainwindow1.h"

MainWindow1::MainWindow1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow1)
{
    ui->setupUi(this);
}

MainWindow1::~MainWindow1()
{
    delete ui;
}

void *threadfunAddReq1(void * i)
{
    while(1){
        //printf("Inside Thread Service Provider Personnel\n");
        ((Ui::MainWindow1 *)i)->label_2->setText("AddReq::Thread start");
        sleep(2);

        // Sem1 Wait

        // Add request in msg queue

        // sem1 release

        ((Ui::MainWindow1 *)i)->label_2->setText("AddReq::Thread End");
        sleep(2);
    }
    return NULL;
}
void *threadfunRecReq1(void * i)
{
    while(1){
        //printf("Inside Thread Service Provider Personnel\n");
        ((Ui::MainWindow1 *)i)->label_3->setText("RecReq::Thread start");
        sleep(2);

        // Sem2 Wait

        // Add request in msg queue

        // sem2 release

        ((Ui::MainWindow1 *)i)->label_3->setText("RecReq::Thread End");
        sleep(2);
    }
    return NULL;
}
void MainWindow1::createthreads(){
    pthid1=0;
    if(0!=pthread_create(&pthid1,NULL,threadfunAddReq1,(void *)uihandle())){
        // error msg;
        return;
    }
    pthid2=0;
    if(0!=pthread_create(&pthid2,NULL,threadfunRecReq1,(void *)uihandle())){
        // error msg;
        return;
    }

}
