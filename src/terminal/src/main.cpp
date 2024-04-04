// Copyright (c) 2024 Jakob Nixdorf
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include <QApplication>
#include <QDebug>
#include <QMainWindow>

#include "qtermwidget.h"

#include "settings.hpp"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QMainWindow *mainWindow = new QMainWindow();

    sterm2::settings* settings = new sterm2::settings();

    QTermWidget *console = new QTermWidget();

    console->setTerminalFont(settings->getFont());
    console->setScrollBarPosition(QTermWidget::ScrollBarRight);

    mainWindow->setCentralWidget(console);
    mainWindow->resize(600, 400);

    // real startup
    QObject::connect(console, &QTermWidget::finished, mainWindow, &QMainWindow::close);

    qDebug() << console->getTerminalFont();

    mainWindow->show();
    return app.exec();
}
