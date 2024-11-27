cmake_minimum_required(VERSION 3.5)

project(maze_cpp VERSION 0.1 LANGUAGES CXX)

include(ExternalProject)  # Подключение модуля ExternalProject

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Установка директории сборки для исполняемого файла
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/../build)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

# Добавляем задачу для сборки бэкенда через Makefile
ExternalProject_Add(
    backend_build
    SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../backend
    BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR}/backend_build
    CONFIGURE_COMMAND ""  # Makefile не требует явной конфигурации
    BUILD_COMMAND make -C ${CMAKE_CURRENT_SOURCE_DIR}/.. backend.a
    INSTALL_COMMAND ""  # Устанавливать библиотеку не нужно
)

# Определяем скомпилированную библиотеку как цель
add_library(backend_lib STATIC IMPORTED)
set_target_properties(backend_lib PROPERTIES
    IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/../backend.a
)

set(PROJECT_SOURCES
        view/main.cc
        view/mainwindow.cc
        view/mainwindow.h
        view/mainwindow.ui

        functions/mazewidget.h
        functions/mazewidget.cc
        functions/cavewidget.h
        functions/cavewidget.cc
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(maze_cpp
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
else()
    add_executable(maze_cpp
        ${PROJECT_SOURCES}
    )
endif()

# Добавляем зависимость только после создания цели maze_cpp
add_dependencies(maze_cpp backend_build)

# Связываем фронтенд с бэкендом
target_link_libraries(maze_cpp PRIVATE Qt${QT_VERSION_MAJOR}::Widgets backend_lib)

set_target_properties(maze_cpp PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(maze_cpp)
endif()
