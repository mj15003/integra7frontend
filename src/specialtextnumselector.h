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

#ifndef SPECIALTEXTNUMSELECTOR_H
#define SPECIALTEXTNUMSELECTOR_H

#include <QSpinBox>

class SpecialTextNumSelector : public QSpinBox
{
public:
    explicit SpecialTextNumSelector(QWidget *parent = nullptr);
    void SetMinText(QString text) { MinText = text;}
    void SetMaxText(QString text) { MaxText = text;}

protected:
    QString textFromValue(int value) const;
    int valueFromText(const QString &text) const;
    QValidator::State validate(QString &text, int &pos) const;

    QString MinText;
    QString MaxText;
};

#endif // SPECIALTEXTNUMSELECTOR_H
