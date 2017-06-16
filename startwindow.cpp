#include "startwindow.h"
#include "ui_startwindow.h"
#include <QDebug>

StartWindow::StartWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StartWindow)
{
    ui->setupUi(this);

 workWindow = new WorkWindow();  // создаем и Инициализируем рабочее окно
  //this->workWindow->show();// одновременное второе окно

 // подключаем к слоту запуска главного окна по кнопке во втором окне
   connect(workWindow, &WorkWindow::open_startWindow, this, &StartWindow::window_top);

   //_____Регистрируем HotKey "F3"____________________________________________________________

   RegisterHotKey((HWND)StartWindow::winId(),   // Устанавливаем системный идентификатор окна виджета, который будет обрабатывать HotKey
                 100,                         // Устанавливаем идентификатор HotKey
                   0 /*MOD_ALT | MOD_SHIFT*/,         // Устанавливаем модификаторы
                VK_F3);                        // Определяем Горячую Клавишу для HotKey
   //__________________________________________________________________________________________________


}

StartWindow::~StartWindow()
{
    delete ui;
}
//_____Функции

void StartWindow::on_pushButton_refresh_pressed()  //кнопка обновить
{
    ui->comboBox_target->clear();
    EnumWindows(StaticEnumWindowsProc, reinterpret_cast<LPARAM>(this));
}

BOOL StartWindow::StaticEnumWindowsProc(HWND hwnd, LPARAM lParam)
{
    StartWindow *pThis = reinterpret_cast<StartWindow*>(lParam);
    return pThis->EnumWindowsProc(hwnd);
}

BOOL StartWindow::EnumWindowsProc(HWND hwnd)
{
    WCHAR title[255];

    if ((GetWindowLongPtr(hwnd, GWL_STYLE) & (WS_VISIBLE | WS_CAPTION)) == (WS_VISIBLE | WS_CAPTION))
        {
             if ((GetWindowText(hwnd, title, 255)) > 0)
             {
                 ui->comboBox_target->addItem(QString::fromWCharArray(title));

             }
        }

    return TRUE;
}

void StartWindow::on_comboBox_target_currentIndexChanged(int index)
{
    QString itemStr = ui->comboBox_target->itemText (index);
    bool ok;
    int value = itemStr.toInt(&ok);
    if (!ok) return;
    int result =value;
    ui->label_conect->setText( QString::number( result ) );

}

void StartWindow::on_comboBox_target_currentIndexChanged(const QString &arg1)//сохранить заголовок нужного окна
{
    handle_1 = arg1;
}

void StartWindow::on_pushButton_conect_pressed()//соединение
{
    LPCWSTR handle_2 = (const wchar_t*)handle_1.utf16(); //приведение типа заголовка
    HWND win = FindWindow(0, handle_2 ); //получение дескриптора окна
    GetWindowThreadProcessId( win, &dwPID); // получение ID процесса

    // statusBar()->addWidget(p);
     //statusBar()->addPermanentWidget(p);
     statusBar()->clearMessage();
     statusBar()->showMessage("ID: "+QString().setNum(dwPID));
     qDebug()<< dwPID;
     //SetForegroundWindow(win);
     //qDebug()<< handle_1;
     // qDebug()<< win;
}

void StartWindow::on_pushButton_work_pressed()
{
    workWindow->showNormal();  // Показываем второе окно
    this->hide();    // Скрываем основное окно
}

// Установка окна видимым и верхним
void StartWindow::window_top()
{
    StartWindow::setWindowFlags(Qt::WindowStaysOnTopHint);
    StartWindow::show();
    StartWindow::activateWindow();
}


bool StartWindow::nativeEvent(const QByteArray &eventType, void *message, long *result)
{
    Q_UNUSED(eventType)
    Q_UNUSED(result)
    // Преобразуем указатель message в MSG WinAPI
    MSG* msg = reinterpret_cast<MSG*>(message);

    // Если сообщение является HotKey, то ...
    if(msg->message == WM_HOTKEY){
        // ... проверяем идентификатор HotKey
        if(msg->wParam == 100){
            // Сообщаем об этом в консоль
            qDebug() << "HotKey worked";
            return true;
        }
    }
    return false;
}
