#include "controller.h"
#include "qssutil.h"

Controller::Controller()
{
    this->setOrientation(Qt::Horizontal);
    this->setMinimum(0);
    this->setMaximum(4);
    this->setSingleStep(1);
    this->setPageStep(1);
    this->setTickPosition(QSlider::TicksAbove);
    //set style for slider
    QSSUtil::setStylesheetForQWidget(":/qss/qslider.qss",this);
}
