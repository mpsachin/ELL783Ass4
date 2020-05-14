#include "mainwindow2.h"
#include "ui_mainwindow2.h"

MainWindow2::MainWindow2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow2)
{
    ui->setupUi(this);
}

MainWindow2::~MainWindow2()
{
    delete ui;
}


void *threadfunRecReq2(void * i)
{
    while(1){
        //printf("Inside Thread Service Provider Personnel\n");
        ((Ui::MainWindow2 *)i)->label_2->setText("RecReq::Thread start");
        sleep(2);

        // Sem2 Wait

        // Add request in msg queue

        // sem2 release

        ((Ui::MainWindow2 *)i)->label_2->setText("RecReq::Thread End");
        sleep(2);
    }
    return NULL;
}
void *threadfunAddReq2(void * i)
{
    while(1){
        //printf("Inside Thread Service Provider Personnel\n");
        ((Ui::MainWindow2 *)i)->label_3->setText("AddReq::Thread start");
        sleep(2);

        // Sem1 Wait

        // Add request in msg queue

        // sem1 release

        ((Ui::MainWindow2 *)i)->label_3->setText("AddReq::Thread End");
        sleep(2);
    }
    return NULL;
}

void MainWindow2::createthreads(){
    pthid1=0;
    if(0!=pthread_create(&pthid1,NULL,threadfunRecReq2 ,(void *)uihandle())){
        // error msg;
        return;
    }
    pthid2=0;
    if(0!=pthread_create(&pthid2,NULL,threadfunAddReq2,(void *)uihandle())){
        // error msg;
        return;
    }

}
