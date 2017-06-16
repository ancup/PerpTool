#include "infowindow.h"
#include "ui_infowindow.h"


InfoWindow::InfoWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InfoWindow)
{
    ui->setupUi(this);





}

InfoWindow::~InfoWindow()
{
    delete ui;
}



void InfoWindow::on_pushButton_recieveData_pressed()
{

qDebug()<< dwPID;
   ui->id_process->setText(QString().setNum(dwPID));

}
