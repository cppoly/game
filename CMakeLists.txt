cmake_minimum_required(VERSION 3.24)
project(monopoly)

file(GLOB source_cpp sources/*.cpp)
file(GLOB source_h sources/*.h)
file(GLOB interface_cpp interface/*.cpp)
file(GLOB interface_h interface/*.h)


set(
        SOURCES
        ${source_cpp}
        ${source_h}
        ${interface_cpp}
        ${interface_h}
)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(
        monopoly
        ${SOURCES}
        main.cpp
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

target_include_directories(${PROJECT_NAME} PRIVATE "include" "lib")

if (WIN32 OR WIN64)
    set(SFML_STATIC_LIBRARIES TRUE)
    set(SFML_DIR C:/SFML/lib/cmake/SFML)
    include_directories(C:/SFML/include/SFML)
endif ()
if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    set(SFML_STATIC_LIBRARIES FALSE)
endif()

find_package(SFML COMPONENTS system window graphics audio network REQUIRED)
target_link_libraries(monopoly sfml-system sfml-window sfml-graphics sfml-audio)

