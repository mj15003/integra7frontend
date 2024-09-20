/*************************************************************************
   Copyright (C) 2024  Miroslav Kovac

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program. If not, see <https://www.gnu.org/licenses/>
*************************************************************************/

#ifndef TWORGANEDITOR_H
#define TWORGANEDITOR_H

#include <QWidget>
#include <integra7tone.h>

namespace Ui {
class TWOrganEditor;
}

class TWOrganEditor : public QWidget
{
    Q_OBJECT

public:
    explicit TWOrganEditor(QWidget *parent = nullptr);
    ~TWOrganEditor();

    void ConnectSignals(Integra7Tone *tone);
    void DisconnectSignals(Integra7Tone *tone);

private:
    Ui::TWOrganEditor *ui;
};

#endif // TWORGANEDITOR_H
