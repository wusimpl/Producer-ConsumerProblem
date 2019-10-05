#include "qssutil.h"

QSSUtil::QSSUtil()
{

}

void QSSUtil::setStylesheetForQWidget(QString sheetFilePath,QWidget *widget){
    QFile file(sheetFilePath);
    if(!file.open(QFile::ReadOnly)){
        qDebug()<<"stylesheet file open failed";
        return;
    }
    assert(widget != nullptr);
    QTextStream fileText(&file);
    QString stylesheet = fileText.readAll();
    widget->setStyleSheet(stylesheet);
}
