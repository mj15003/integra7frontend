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

#include "specialtextnumselector.h"

SpecialTextNumSelector::SpecialTextNumSelector(QWidget *parent){
    MinText = QString::number(minimum());
    MaxText = QString::number(maximum());
}

QString SpecialTextNumSelector::textFromValue(int value) const
{
    if (value == minimum())
        return MinText;
    else if (value == maximum())
        return MaxText;
    else
        return QString::number(value);
}

int SpecialTextNumSelector::valueFromText(const QString &text) const
{
    if (text == MinText)
        return minimum();
    else if (text == MaxText)
        return maximum();
    else
        return text.toInt();
}

QValidator::State SpecialTextNumSelector::validate(QString &text, int &pos) const
{
    bool s = false;
    int v = text.toInt(&s);

    if (s) {
        if (v > minimum() && v < maximum())
            return QValidator::Acceptable;
    }
    else if (MinText == text || MaxText == text)
            return QValidator::Acceptable;
    else if (MinText.startsWith(text) || MaxText.startsWith(text))
        return QValidator::Intermediate;

    return QValidator::Invalid;
}
