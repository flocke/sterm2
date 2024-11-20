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

#include <QDebug>
#include <QSettings>

#include "qtermwidget.h"

#include "Settings.hpp"

namespace STerm2 {
    QVariant Settings::getValue(QString key, QVariant defaultValue)
    {
        QSettings store(QSettings::IniFormat, QSettings::UserScope, "sterm2", "sterm2");
        return store.value(key, defaultValue);
    }

    QString Settings::getString(QString key, QString defaultValue)
    {
        return getValue(key, defaultValue).toString();
    }

    int Settings::getInt(QString key, int defaultValue)
    {
        return getValue(key, defaultValue).toInt();
    }

    qreal Settings::getReal(QString key, qreal defaultValue)
    {
        return getValue(key, defaultValue).toReal();
    }

    QFont Settings::getFont()
    {
        return QFont(getString("theme/font", "monospace"), getInt("theme/font_size", 11));
    }

    qreal Settings::getOpacity()
    {
        return getReal("theme/opacity", 1);
    }

    QTermWidget::ScrollBarPosition Settings::getScrollbarPosition()
    {
        QString position = getString("theme/scrollbar", "right");

        if(position == "left") {
            return QTermWidget::ScrollBarPosition::ScrollBarLeft;
        } else if(position == "right") {
            return QTermWidget::ScrollBarPosition::ScrollBarRight;
        } else if(position == "none") {
            return QTermWidget::ScrollBarPosition::NoScrollBar;
        } else {
            qWarning() << "Unknown scrollbar position:" << position;
            return QTermWidget::ScrollBarPosition::NoScrollBar;
        }
    }

    QTermWidget::KeyboardCursorShape Settings::getCursorShape()
    {
        QString cursor = getString("theme/cursor", "block");

        if(cursor == "block") {
            return QTermWidget::KeyboardCursorShape::BlockCursor;
        } else if(cursor == "underline") {
            return QTermWidget::KeyboardCursorShape::UnderlineCursor;
        } else if(cursor == "beam") {
            return QTermWidget::KeyboardCursorShape::IBeamCursor;
        } else {
            qWarning() << "Unknown cursor shape:" << cursor;
            return QTermWidget::KeyboardCursorShape::BlockCursor;
        }
    }
}
