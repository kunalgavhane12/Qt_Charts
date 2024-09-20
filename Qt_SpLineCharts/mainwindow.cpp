#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QSplineSeries *series = new QSplineSeries();

    series->append(0,10);
    series->append(1,15);
    series->append(2,13);
    series->append(3,20);
    series->append(4,15);
    series->append(5,9);
    series->append(6,10);
    series->append(7,15);
    series->append(8,2);
    series->append(9,18);

    QChart *charts = new QChart();
    charts->legend()->hide();
    charts->addSeries(series);
    charts->createDefaultAxes();
    charts->axes(Qt::Vertical).first()->setRange(0,30);
    charts->axes(Qt::Horizontal).first()->setRange(0,11);
    charts->setVisible(true);

    QChartView *chartsView = new QChartView(charts);
    chartsView->setRenderHint(QPainter::Antialiasing);
    chartsView->setVisible(true);
    setCentralWidget(chartsView);
}

MainWindow::~MainWindow()
{
    delete ui;
}

