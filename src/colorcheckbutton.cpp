/*************************************************************************
   Copyright (C) 2023-2024  Miroslav Kovac

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program. If not, see <https://www.gnu.org/licenses/>
*************************************************************************/

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
