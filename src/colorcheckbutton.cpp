#include "colorcheckbutton.h"

ColorCheckButton::ColorCheckButton(QWidget *parent):
    QPushButton(parent)
{
    QBrush OffBrush(QColor(73, 73, 73));
    OffBrush.setStyle(Qt::SolidPattern);
    OffBtnPalette.setBrush(QPalette::Active, QPalette::Button, OffBrush);

    QBrush OnBrush(QColor(184, 38, 52));
    OnBrush.setStyle(Qt::SolidPattern);
    OnBtnPalette.setBrush(QPalette::Active, QPalette::Button, OnBrush);

    QObject::connect(this,&QAbstractButton::toggled,
                     this,&ColorCheckButton::toggle);
}

void ColorCheckButton::toggle(bool checked)
{
    if (checked)
        setPalette(OnBtnPalette);
    else
        setPalette(OffBtnPalette);
}
