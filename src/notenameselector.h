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

#ifndef NOTENAMESELECTOR_H
#define NOTENAMESELECTOR_H

#include <QSpinBox>

class NoteNameSelector : public QSpinBox
{
public:
    explicit NoteNameSelector(QWidget *parent = nullptr);

protected:
    QString textFromValue(int value) const;
    int valueFromText(const QString &text) const;
    QValidator::State validate(QString &text, int &pos) const;

    static QStringList& NoteNames() {
        static QStringList list = {
            #include "presets/NoteNames.inc"
        };
        return list;
    }
};

#endif // NOTENAMESELECTOR_H
