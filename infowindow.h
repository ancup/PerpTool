#ifndef INFOWINDOW_H
#define INFOWINDOW_H

#include <QWidget>
#include <QMainWindow>
#include "value.h"


namespace Ui {
class InfoWindow;
}

class InfoWindow : public QWidget
{
    Q_OBJECT

public:
    explicit InfoWindow(QWidget *parent = 0);
    ~InfoWindow();

private slots:
    void on_pushButton_recieveData_pressed();

private:
    Ui::InfoWindow *ui;





};



#endif // INFOWINDOW_H
