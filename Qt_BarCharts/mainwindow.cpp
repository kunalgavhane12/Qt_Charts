#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QBarSeries *series = new QBarSeries();
    QBarSet * barSet = new QBarSet("Qt Bar Charts");
    barSet->append(50);
    barSet->append(80);
    barSet->append(90);
    barSet->append(70);
    barSet->append(65);

    QBarSet * barSet1 = new QBarSet("Qt C++ Charts");
    barSet1->append(45);
    barSet1->append(50);
    barSet1->append(60);
    barSet1->append(52);
    barSet1->append(35);

    QBarSet * barSet2 = new QBarSet("Qt and Charts");
    barSet2->append(55);
    barSet2->append(72);
    barSet2->append(35);
    barSet2->append(80);
    barSet2->append(60);

    barSet->setColor(Qt::red);
    barSet1->setColor(Qt::blue);
    barSet2->setColor(Qt::green);

    series->append(barSet);
    series->append(barSet1);
    series->append(barSet2);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Student Data");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QStringList subjectName;
    subjectName.append("English");
    subjectName.append("Maths");
    subjectName.append("Science");
    subjectName.append("GeoGraphy");
    subjectName.append("Physics");

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(subjectName);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(0, 100);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    chart->legend()->setVisible(true);
//    chart->legend()->setAlignment(Qt::AlignBottom);
    chart->legend()->setAlignment(Qt::AlignLeft);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setVisible(true);
    setCentralWidget(chartView);

}

MainWindow::~MainWindow()
{
    delete ui;
}

