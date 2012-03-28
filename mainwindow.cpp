#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cmath>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    a.pen = QPen(QColor(255,0,0));
    a << QPointF(0,10) << QPointF(10,11) << QPointF(11,15);
    a.show = true;
    ui->widget->addWykres(&a);

    b.pen = QPen(QColor(0,255,0));
    b.show = true;
    analitycznie(b);
    ui->widget->addWykres(&b);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
}

void MainWindow::on_pushButton_clicked(bool checked)
{
    b.show = checked;
    ui->widget->repaint();
}

void MainWindow::analitycznie(DaneWykresu &dane)
{
    double h = 10/50;

    dane.clear();

    for(double t = 0; t <= 2; t += 0.1)
    {
        dane << QPointF(t, std::exp(-0.5*t));
    }
}
