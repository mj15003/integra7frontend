/*************************************************************************
   Copyright (C) 2024 Miroslav Kovac

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

#ifndef ASYNCOPERATIONS_H
#define ASYNCOPERATIONS_H

#include "QFile"
#include "QRunnable"
#include "QThreadPool"

#include "integra7device.h"
#include "integra7mainwindow.h"

class ReadRequest : public QRunnable
{
public:
    explicit ReadRequest(Integra7Device *i7dev);
    explicit ReadRequest(Integra7Device *i7dev, const uint8_t *rqdata);
private:
    Integra7Device *dev;
    uint8_t req[8];
    bool RequestDataSpecified = false;
    void run() override;
};

class DumpFileReader : public QRunnable
{
public:
    explicit DumpFileReader(Integra7Device *pdev, integra7MainWindow *pwin, QString& fname);
private:
    QString fileName;
    integra7MainWindow *win;
    Integra7Device *dev;
    void run() override;
};

#endif // ASYNCOPERATIONS_H
