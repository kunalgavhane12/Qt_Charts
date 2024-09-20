#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QLineSeries *series = new QLineSeries();
    series->append(0,1);
    series->append(1,2);
    series->append(2,3);
    series->append(3,4);
    series->append(4,5);
    series->append(5,6);
    series->append(6,6);
    series->append(7,6);
    series->append(8,6);
    series->append(9,6);
    series->append(10,6);

    QChart *chart = new QChart();
    chart->legend()->hide();
    chart->setTitle("MyChart");
    chart->addSeries(series);
    chart->createDefaultAxes();
    chart->axes(Qt::Vertical).first()->setRange(0,10);
    chart->axes(Qt::Horizontal).first()->setRange(0, 12);
    chart->setVisible(true);
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setVisible(true);

    setCentralWidget(chartView);
}

MainWindow::~MainWindow()
{
    delete ui;
}

