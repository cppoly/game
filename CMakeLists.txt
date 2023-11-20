cmake_minimum_required(VERSION 3.24)
project(monopoly)

set(CMAKE_CXX_STANDARD 17)


add_executable(
        monopoly
        main.cpp

        # Sources
        sources/game.cpp sources/game.h
        sources/player.cpp sources/player.h
        sources/field.cpp sources/field.h
        sources/cards.cpp sources/cards.h
)


