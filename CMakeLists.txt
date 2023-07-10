cmake_minimum_required(VERSION 3.24)
project(monopoly)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(
        monopoly
        main.cpp

        # Qt files
        qt/mainwindow.cpp qt/mainwindow.h qt/mainwindow.ui

        # Sources
        sources/game.cpp sources/game.h
        sources/player.cpp sources/player.h
        sources/field.cpp sources/field.h
        sources/cards.cpp sources/cards.h
)

target_link_libraries(
        monopoly
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
)

