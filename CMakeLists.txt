project(qAlarmClock)
cmake_minimum_required(VERSION 3.1 FATAL_ERROR)

set(QT_MINIMUM_REQUIRED "5.6.1")
set(QALARMCLOCK_VERSION "0.0.1")

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# additional cmake files
set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH}" "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

include(GNUInstallDirs)             # Standard directories for installation
include(CompilerSettings NO_POLICY_SCOPE)

find_package(Qt5 ${QT_MINIMUM_REQUIRED} CONFIG REQUIRED Widgets LinguistTools)

add_subdirectory(src)
