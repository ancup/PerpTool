#ifndef VALUE_H
#define VALUE_H

#include <QtCore/QObject>
#include <QtGui>
#include <windows.h>
#include <QDebug>

extern QString handle_1; //дескриптор целевого окна
extern DWORD dwPID; //ID процесса
extern DWORD address;
extern DWORD size;

#endif // VALUE_H
