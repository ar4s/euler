#ifndef WYKRES_H
#define WYKRES_H

#include <QWidget>
#include <QPaintEvent>
#include <QVector>
#include <QPen>

class DaneWykresu : public QPolygonF
{
public:
    QPen pen;
    bool show;
};

class Wykres : public QWidget
{
    Q_OBJECT
public:
    explicit Wykres(QWidget *parent = 0);
    explicit Wykres(double x_min, double y_min, double x_max, double y_max, QWidget *parent = 0);

    void paintEvent(QPaintEvent *);
    void resizeEvent(QResizeEvent *);

    void addWykres(DaneWykresu *);

private:
    QVector< DaneWykresu* > wykresy;
    inline int ex(double x){return (x-xp)/(xk-xp)*this->width();}
    inline int ey(double y){return (yk-y)/(yk-yp)*this->height();}

    QPolygonF transformData(DaneWykresu *);

    double xp; // x poczatkowe
    double xk; // x koncowe
    double yp; // y poczatkowe
    double yk; // y koncowe
    
signals:
    
public slots:
    
};

#endif // WYKRES_H
