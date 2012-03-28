#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "wykres.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_pushButton_clicked();

    void on_pushButton_clicked(bool checked);

private:
    void analitycznie(DaneWykresu &);

    DaneWykresu a, b;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
