#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPieSeries *series = new QPieSeries();
    series->append("English", 52);
    series->append("Physics", 35);
    series->append("Chemistry", 35);
    series->append("Maths", 48);
    series->append("Geography", 35);

    QPieSlice *slice_1 = series->slices().at(0);
    slice_1->setExploded(true);
    slice_1->setLabelVisible(true);
    slice_1->setPen(QPen(Qt::red, 1));
    slice_1->setColor(Qt::red);

    QPieSlice *slice_2 = series->slices().at(1);
    slice_2->setExploded(true);
    slice_2->setLabelVisible(true);
    slice_2->setPen(QPen(Qt::green, 1));
    slice_2->setColor(Qt::green);

    QPieSlice *slice_3 = series->slices().at(4);
    slice_3->setExploded(true);
    slice_3->setLabelVisible(true);
    slice_3->setPen(QPen(Qt::blue, 1));
    slice_3->setColor(Qt::blue);
    /*
    QPieSlice *slice_4 = series->slices().at(0);
    slice_4->setExploded(true);
    slice_4->setLabelVisible(true);
    slice_4->setPen(QPen(Qt::red, 1));
    slice_4->setColor(Qt::red);

    QPieSlice *slice_5 = series->slices().at(0);
    slice_5->setExploded(true);
    slice_5->setLabelVisible(true);
    slice_5->setPen(QPen(Qt::red, 1));
    slice_5->setColor(Qt::red);*/

    QChart *chart = new QChart();
    chart->setTitle("Student Marks");
    chart->addSeries(series);
    chart->setVisible(true);
    chart->legend()->hide();

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setVisible(true);
    setCentralWidget(chartView);

}

MainWindow::~MainWindow()
{
    delete ui;
}

