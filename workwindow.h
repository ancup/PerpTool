#ifndef WORKWINDOW_H
#define WORKWINDOW_H

#include <QtGui>
#include <QMainWindow>
#include <QWidget>
#include "windows.h"
#include "infowindow.h"
#include "value.h"

namespace Ui {
class WorkWindow;
}

class WorkWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit WorkWindow(QWidget *parent = 0); //explicit WorkWindow(QMainWindow *parent = 0);




    ~WorkWindow();

private:
    Ui::WorkWindow *ui;
    InfoWindow *infoWindow;


signals:
    void open_startWindow();


private slots:
    void on_pushButton_workwindow_close_pressed();
    void on_pushButton_info_pressed();
};









#endif // WORKWINDOW_H
