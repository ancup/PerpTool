#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QtCore/QObject>
#include <QMainWindow>
#include <QtGui>
#include <QWidget>
#include <windows.h>
#include "workwindow.h"
#include "value.h"


namespace Ui {
class StartWindow;
}

class StartWindow : public QMainWindow
{
    Q_OBJECT

public: //доступ открыт всем, кто видит определение данного класса.
    explicit StartWindow(QWidget *parent = 0);
    ~StartWindow();

    static BOOL CALLBACK StaticEnumWindowsProc(HWND hwnd, LPARAM lParam);
    BOOL EnumWindowsProc(HWND hwnd);



private: //доступ открыт самому классу (т.е. функциям-членам данного класса) и друзьям (friend) данного класса, как функциям, так и классам.
    Ui::StartWindow *ui;
    WorkWindow *workWindow; //указатель на второе окно

protected:

 // Метод для обработки native событий от ОС в Qt
    bool nativeEvent(const QByteArray &eventType, void *message, long *result);
//______________________________________________________________________________

public slots:
    void window_top();


private slots:
    // Слоты от кнопок главного окна
    void on_pushButton_refresh_pressed();// обновить
    void on_pushButton_conect_pressed();// соединение
    void on_comboBox_target_currentIndexChanged(int index);
    void on_comboBox_target_currentIndexChanged(const QString &arg1);
    void on_pushButton_work_pressed();//запуск

signals:





};

#endif // STARTWINDOW_H
