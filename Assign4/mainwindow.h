#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>


#include <vector>
using namespace std;
#include <pthread.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/sem.h>
#include <unistd.h>

#include "mainwindow1.h"
#include "mainwindow2.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    /*vector<MainWindow1 *> vecptrui1;
    vector<MainWindow2 *> vecptrui2;
public:
    bool delptrinvec(MainWindow1 * ui1)
    {
        bool isdel = false;
        for(unsigned int i=0;i<vecptrui1.size();i++){
            if(ui1 == vecptrui1[i]){
                vecptrui1[i]
                vecptrui1.erase(i);
                i--;
                isdel = ture;
            }
        }
    }*/


};
#endif // MAINWINDOW_H
