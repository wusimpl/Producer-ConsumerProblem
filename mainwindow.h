#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
#include "conveyor.h"
#include "controller.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow()override;

private:
    Ui::MainWindow *ui;
    //for displaying everything
    QGraphicsView *graphicsView;
    QGraphicsScene *graphicsScene;
    //the conveyor, in this condition, which is the abstract of the the empty buffer area that the producer can read and writes.
    Conveyor *conveyor;
    //each producer or consumer stands for a thread with the ability of producing an item or consuming an item.
    //the controllers below controls these threads' lifecycle.
    Controller *producerController;
    Controller *consumerController;

    // QWidget interface
protected:
    void resizeEvent(QResizeEvent *event) override;
};

#endif // MAINWINDOW_H
