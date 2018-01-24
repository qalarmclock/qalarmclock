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

#ifndef GLOBAL_H
#define GLOBAL_H

#if QT_VERSION < QT_VERSION_CHECK(5, 7, 0)
template <typename T>
constexpr typename std::add_const<T>::type &qAsConst(T &t) noexcept { return t; }

// prevent rvalue arguments:
template <typename T>
void qAsConst(const T &&) = delete;
#endif

#ifndef QSL
#define QSL(x) QStringLiteral(x)
#endif

#ifndef QL1S
#define QL1S(x) QLatin1String(x)
#endif

#ifndef QL1C
#define QL1C(x) QLatin1Char(x)
#endif

#endif // GLOBAL_H
