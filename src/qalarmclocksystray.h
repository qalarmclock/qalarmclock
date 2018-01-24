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

#ifndef QALARMCLOCKSYSTRAY_H
#define QALARMCLOCKSYSTRAY_H

#include <QSystemTrayIcon>

class QMenu;

class QAlarmClockSysTray : public QSystemTrayIcon {
    Q_OBJECT
public:

    explicit QAlarmClockSysTray(QObject *parent = 0);
    ~QAlarmClockSysTray();

private:
    QMenu *mContextMenu;

private Q_SLOTS:
    void about();
    void preferences();
};

#endif // QALARMCLOCKSYSTRAY_H
