set(QALARMCLOCK_SRCS
    main.cpp
    qalarmclockapp.cpp
    qalarmclocksystray.cpp
)

add_executable(qalarmclock
    ${QALARMCLOCK_SRCS}
)

target_link_libraries(qalarmclock
    Qt5::Widgets
)

set_property(TARGET qalarmclock PROPERTY CXX_STANDARD 11)
set_property(TARGET qalarmclock PROPERTY CXX_STANDARD_REQUIRED ON)
