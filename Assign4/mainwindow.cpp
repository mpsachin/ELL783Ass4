#include "mainwindow.h"
#include "./ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    MainWindow1 * ui1 = new MainWindow1();
    //vecptrui1.push_back(ui1);
    ui1->show();
    ui->pushButton->setDisabled(true);
}

void MainWindow::on_pushButton_2_clicked()
{
    MainWindow2 * ui2 = new MainWindow2();
    //vecptrui2.push_back(ui2);
    ui2->show();
    ui->pushButton_2->setDisabled(true);
}

void MainWindow::on_pushButton_3_clicked()
{
    MainWindow2 * ui2 = new MainWindow2();
    //vecptrui2.push_back(ui2);
    ui2->show();
    ui->pushButton_3->setDisabled(true);

}
