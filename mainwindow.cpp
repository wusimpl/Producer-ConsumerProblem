#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsProxyWidget>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setGeometry(0,0,1920,1080);
    this->setWindowTitle("Producer And Consumer Problem");
    //init the container of all items needed be painted.
    graphicsView = new QGraphicsView(this);
    graphicsView->setGeometry(0,0,1920,1080);
    graphicsScene = new QGraphicsScene(graphicsView);
    graphicsView->setScene(graphicsScene);
    //draw the conveyor
    conveyor = new Conveyor();
    graphicsScene->addItem(conveyor);
    //draw controllers
    producerController = new Controller();
    producerController->setGeometry(0,50,500,20);
    consumerController = new Controller();
    consumerController->setGeometry(1400,800,500,20);
    graphicsScene->addWidget(producerController);
    graphicsScene->addWidget(consumerController);
}

MainWindow::~MainWindow()
{
    delete ui;

    delete graphicsView;
    delete graphicsScene;
    delete conveyor;
}


void MainWindow::resizeEvent(QResizeEvent *)
{
     graphicsView->setSceneRect(0,0,this->width(),this->height());
}
