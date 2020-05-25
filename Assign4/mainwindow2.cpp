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
    //printf("Inside Thread Service Provider Personnel\n");
    ((Ui::MainWindow2 *)i)->label_2->setText("RecReq::Thread start");
    //sleep(2);
    while(1){
        if(MAXSEM1 > mysemval(0)){

            // Sem1 Wait
            //mysemp(0);

            // Add request in msg queue
        	char str[200];
        	strcpy(str,msgreceive());
            // sem1 release
            mysemv(0);
            QString qstr = "AddReq:: Semaphore Increment" +QString::number(mysemval(0)) + QString::fromUtf8(str);
            ((Ui::MainWindow2 *)i)->label_2->setText(qstr);
            //((Ui::MainWindow2 *)i)->label_2->setText("RecReq::Thread End");
            sleep(2);
        }
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
