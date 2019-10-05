#ifndef QSSUTIL_H
#define QSSUTIL_H
#include <QString>
#include <QWidget>
#include <QFile>
#include <QTextStream>
#include <QDebug>

class QSSUtil
{
public:
    QSSUtil();

    static void setStylesheetForQWidget(QString sheetFilePath,QWidget *widget);
};

#endif // QSSUTIL_H
