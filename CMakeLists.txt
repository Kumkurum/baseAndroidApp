cmake_minimum_required(VERSION 3.19)
project(basicAndroidApp)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 COMPONENTS Quick Core QuickControls2 REQUIRED)

file(GLOB_RECURSE CPP_SOURCES
        src/cpp/*
)
set(PROJECT_SOURCES
        src/qml/qml.qrc
)


qt6_add_executable(${PROJECT_NAME}
        ${PROJECT_SOURCES}
        ${CPP_SOURCES}
)
set_target_properties(${PROJECT_NAME} PROPERTIES
    QT_ANDROID_PACKAGE_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/android/apk
    QT_ANDROID_MIN_SDK_VERSION 26
    QT_ANDROID_TARGET_SDK_VERSION 33
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt6::Quick
    Qt6::Core
        Qt6::CorePrivate
    Qt6::QuickControls2
)

install(TARGETS ${TARGET_NAME}
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
