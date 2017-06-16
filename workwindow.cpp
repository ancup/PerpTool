#include "workwindow.h"
#include "ui_workwindow.h"
#include <QDebug>

WorkWindow::WorkWindow(QWidget *parent) ://///WorkWindow::WorkWindow(QMainWindow *parent) :
    QMainWindow(parent),
    ui(new Ui::WorkWindow)
{
    ui->setupUi(this);
//###############################################################################
    infoWindow = new InfoWindow();


//################################################################################
}

WorkWindow::~WorkWindow()
{
    delete ui;
}


//################################################################################


void WorkWindow::on_pushButton_workwindow_close_pressed()
{
    this->close();      // Закрываем окно
    emit open_startWindow(); // И вызываем сигнал на открытие главного окна
}

void WorkWindow::on_pushButton_info_pressed()
{

    infoWindow->show();
}
