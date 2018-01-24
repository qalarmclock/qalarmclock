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

#include "qalarmclockapp.h"

#include "qalarmclocksystray.h"

QAlarmClockApp::QAlarmClockApp(int &argc, char **argv)
    : QApplication(argc, argv),
      m_tray(nullptr)

{
    m_tray = new QAlarmClockSysTray(this);
    m_tray->show();

}

QAlarmClockApp::~QAlarmClockApp()
{
    m_tray->deleteLater();
}
