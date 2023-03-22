cmake_minimum_required(VERSION 3.14)

project(AndroidSslSupport VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(ANDROID AND ANDROID_SSL_PATH AND NOT ANDROID_SSL_PATH STREQUAL "")
  include(${ANDROID_SSL_PATH}/CMakeLists.txt)
else()
  message(FATAL_ERROR "SSL library not provided, provide location of SSL library via ANDROID_SSL_PATH variable")
endif()

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Quick Network)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Quick Network)

set(PROJECT_SOURCES
    main.cpp
    qrc_qml.qrc
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(AndroidSslSupport
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
else()
    if(ANDROID)
        add_library(AndroidSslSupport SHARED ${PROJECT_SOURCES})
    else()
        add_executable(AndroidSslSupport ${PROJECT_SOURCES})
    endif()
endif()

target_link_libraries(AndroidSslSupport
  PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Quick Qt${QT_VERSION_MAJOR}::Network)

install(TARGETS AndroidSslSupport
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_import_qml_plugins(AndroidSslSupport)
    qt_finalize_executable(AndroidSslSupport)
endif()
