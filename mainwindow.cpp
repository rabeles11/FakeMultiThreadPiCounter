#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "QTimer"
#include "QDebug"
#include "QTimeLine"
#include <unistd.h>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    pause = true;
    connect(timer,SIGNAL(timeout()),this,SLOT(myfunction()));
    counter = 0;
    sum = 0.0;
    sign = 1;
    step = 0;
    //final = 45;
    ui->progressBar->setValue(counter);
    ui->progressBar->setMaximum(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    counter = 0;
    timer->start(100);
}

void MainWindow::on_pushButton_2_clicked()
{
    timer->stop();
    counter = 0;
    sum = 0.0;
    sign = 1;
    step = 0;
    qDebug() << "Zastaveno";
}

void MainWindow::on_pushButton_3_clicked()
{
    if(pause){
        int remaining = timer->remainingTime();
        timer->stop();
        timer->setInterval(remaining);
        qDebug() << "Pozastaveno";
        pause = false;
    }
    else
    {
        timer->start(100);
        pause = true;
        qDebug() << "Resume";
    }
}

void MainWindow::myfunction()
{
    counter++;
    qDebug() << "Sem tu";
    ui->progressBar->setValue(counter);
    sum += sign/(2.0*step+1.0);
    sign *= -1;
    step ++;
    QString valueAsString = QString::number(4*sum);
    ui->label->setText(valueAsString);
    qDebug() << "Update";
}

double MainWindow::pi(int n)
{
    double sum = 0.0;
    int sign = 1;
    for (int i = 0; i < n; ++i) {
        sum += sign/(2.0*i+1.0);
        sign *= -1;
        qDebug() << sum;
        qDebug() << "počítám";
        sleep(1);
        QString valueAsString = QString::number(sum);
        ui->label->setText(valueAsString);
    }
    return 4.0*sum;
}

void MainWindow::on_pushButton_4_clicked()
{
    double test = pi(40);
    qDebug() << test;
}

void MainWindow::on_pushButton_5_clicked()
{

}

void MainWindow::on_pushButton_6_clicked()
{

}
