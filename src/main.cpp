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

#include <mutex>
#include <QSharedMemory>
#include <QTimer>
#include <QApplication>
#include <QSettings>
#include <QDebug>

#include "global.h"
#include "qalarmclockapp.h"

int main(int argc, char *argv[])
{
    QAlarmClockApp app{argc, argv};
    /*
     * Single Application code taken from qlipper
     * Author: palinek https://github.com/palinek
     */

    // Note1: Allow only one instance of qlipper.
    // Note2: We can't use QSystemSemaphore as it doesn't provide
    //        non-blocking API.
    // Note2: On unix the underlying memory segment can outlive the
    //        QSharedMemory object(s) if the application crashes.
    //        So we're refreshing the "alive" timestamp each 5 sec.
    QSharedMemory single(QL1S("qalarmclock"));
    QTimer refresh_timer;
    refresh_timer.setSingleShot(false);
    refresh_timer.setInterval(5000);
    QObject::connect(&refresh_timer, &QTimer::timeout, [&single] { std::lock_guard<QSharedMemory> guard(single); time(static_cast<time_t *>(single.data())); });
    if (single.create(sizeof(time_t)))
    {
        std::lock_guard<QSharedMemory> guard(single);
        time(static_cast<time_t *>(single.data()));
        refresh_timer.start();
    } else if (single.attach())
    {
        std::lock_guard<QSharedMemory> guard(single);
        time_t refresh = *static_cast<const time_t *>(single.data());
        if (refresh > time(nullptr) - 10)
        {
            qWarning("An instance of qAlarmClock is already running!");
            return 0;
        }
        time(static_cast<time_t *>(single.data()));
        refresh_timer.start();
    } else
    {
        qWarning().noquote() << "Unable to create/attach shared memory(" << single.errorString()
            << "), singleinstance behaviour will not work";
    }
    app.setAttribute(Qt::AA_EnableHighDpiScaling);
    app.setAttribute(Qt::AA_UseHighDpiPixmaps);
    app.setApplicationName(QL1S("qalarmclock"));
    app.setOrganizationName(QL1S("qalarmclock"));
    app.setOrganizationDomain(QSL("qalarmclock.org"));
    app.setQuitOnLastWindowClosed(false);

    QSettings::setDefaultFormat(QSettings::IniFormat);

    return app.exec();
}
