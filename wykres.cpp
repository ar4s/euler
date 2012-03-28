#include "wykres.h"
#include <QPainter>
#include <QDebug>

Wykres::Wykres(QWidget *parent) : QWidget(parent)
{
    xp = -10;
    xk = 50;
    yp = -10;
    yk = 50;
}


Wykres::Wykres(double x_min, double y_min, double x_max, double y_max, QWidget *parent) :
    QWidget(parent), xp(x_min), xk(x_max), yp(y_min), yk(y_max)
{
}

void Wykres::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    p.setBrush(Qt::white);
    p.setPen(QColor(255,255,255));
    p.drawRect(this->rect());

    p.setPen(QColor(150,150,150));
    p.drawLine(ex(xp),ey(0),ex(xk),ey(0));

    float skalaX = (qMin(xp,xk)/qMax(xp,xk));
    skalaX = skalaX > 0 ? skalaX : -skalaX;
    float skalaY = (qMin(yp,yk)/qMax(yp,yk));
    skalaY = skalaY > 0 ? skalaY : -skalaY;


    for(int i = xp; i < xk; i++)
        if(i%10 || i == 0) p.drawLine(ex(i), ey(skalaY), ex(i), ey(-skalaY));
        else
        {
            p.drawLine(ex(i), ey(skalaY), ex(i), ey(-(skalaY+skalaY*3)));
            p.drawText(QRectF(ex(i-0.5), ey(-1), 15, 10), Qt::AlignCenter, QString("%1").arg(i));
        }

    p.drawLine(ex(0),ey(yp),ex(0),ey(yk));
    for(int i = yp; i < yk; i++)
        if(i%10 || i == 0) p.drawLine(ex(skalaX), ey(i), ex(-skalaX), ey(i));
        else
        {
            p.drawLine(ex(skalaX+skalaX*3), ey(i), ex(-skalaX), ey(i));
            p.drawText(QRectF(ex(+1), ey(i+0.5), 15, 10), Qt::AlignCenter, QString("%1").arg(i));
        }

    foreach(DaneWykresu* wykres, wykresy)
    {
        if(wykres->show)
        {
            p.setPen(wykres->pen);
            p.drawPolyline(transformData(wykres));
        }
    }
    p.setPen(QColor(0,0,0));
}

void Wykres::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
}

void Wykres::addWykres(DaneWykresu *wykres)
{
    qDebug() << wykres;
    wykresy.append(wykres);
}

QPolygonF Wykres::transformData(DaneWykresu* wykres)
{
    QPolygonF result;

    QVectorIterator<QPointF> iter(*static_cast<QVector<QPointF> *>(wykres));

    while(iter.hasNext())
    {
        QPointF punkt(iter.next());
        result << QPointF(ex(punkt.x()), ey(punkt.y()));
    }

    return result;

}

