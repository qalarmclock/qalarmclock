/*
 * qAlarmClock - A simple Alarm Clock written using Qt
 * Copyright (C) 2018  Luís Pereira <luis.artur.pereira@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#include "qalarmclocksystray.h"

#include "global.h"

#include <QApplication>
#include <QDebug>
#include <QMenu>
#include <QMessageBox>


QAlarmClockSysTray::QAlarmClockSysTray(QObject *parent)
    : QSystemTrayIcon(parent),
      mContextMenu(nullptr)
{
    setIcon(QIcon::fromTheme(QL1S("clock")));

    mContextMenu = new QMenu();

    mContextMenu->addAction(QIcon::fromTheme(QSL("configure")), tr("&Configure")
        ,this, &QAlarmClockSysTray::preferences);
    mContextMenu->addSeparator();
    mContextMenu->addAction(QIcon::fromTheme(QSL("help-about")), tr("&About qAlarmClock...")
        ,this, &QAlarmClockSysTray::about);
    mContextMenu->addAction(QIcon::fromTheme(QSL("application-exit")), tr("&Quit")
        ,qApp, &QCoreApplication::quit);

    setContextMenu(mContextMenu);
}

QAlarmClockSysTray::~QAlarmClockSysTray()
{
    mContextMenu->deleteLater();
}

void QAlarmClockSysTray::about()
{
    QMessageBox msgBox;
    msgBox.setWindowIcon(QIcon::fromTheme(QL1S("clock")));
    msgBox.setIconPixmap(QIcon::fromTheme(QL1S("clock")).pixmap(128,128));
    msgBox.setWindowTitle(tr("About qAlarmClock"));
    msgBox.setText(QString::fromLatin1("<h1><strong>qAlarmClock</strong> %1</h1>").arg(qApp->applicationVersion()));
    msgBox.setInformativeText(tr("A simple and cross-platform Alarm Clock.<p>"
                                  "Copyright&nbsp;(C)&nbsp;2018&nbsp;Luís&nbsp;Pereira&nbsp;&lt;luis.artur.pereira@gmail.com&gt;<p>"
                                  "<a href=\"https://github.com/qalarmclock\"><https://github.com/qalarmclock/a>"));
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.exec();
}

void QAlarmClockSysTray::preferences()
{
}
