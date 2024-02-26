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

#include "notenameselector.h"

NoteNameSelector::NoteNameSelector(QWidget *parent) {}

inline QString NoteNameSelector::textFromValue(int value) const
{
    return NoteNames()[value];
}

inline int NoteNameSelector::valueFromText(const QString &text) const
{
    return NoteNames().indexOf(text);
}

QValidator::State NoteNameSelector::validate(QString &text, int &pos) const
{
    int p = pos - 1;

    if (pos == 1) {

        if (text.at(p) >= 'A' && text.at(p) <= 'G')
            return QValidator::Intermediate;

    } else if (pos == 2) {

        if (text.at(p) >= '0' && text.at(p) <= '9')
            return QValidator::Acceptable;
        else if (text.at(p) == '#' || text.at(p) == '-')
            return QValidator::Intermediate;

    } else if (pos == 3) {

        if (text.at(p) >= '0' && text.at(p) <= '9')
            return QValidator::Acceptable;
        else if (text.at(p) == '-')
            return QValidator::Intermediate;

    } else if (pos == 4) {

        if (text.at(p) == '1')
            return QValidator::Acceptable;

    }
    return QValidator::Invalid;
}

