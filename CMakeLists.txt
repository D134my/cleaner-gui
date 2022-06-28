cmake_minimum_required(VERSION 3.16)

project(cleaner-gui VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 20)
find_package(Qt6 6.2 COMPONENTS Quick REQUIRED)

qt_add_executable(appcleaner-gui
    main.cpp cleaner/clean.cpp cleaner/clean.hpp cleaner/types.hpp
    bridge.hpp bridge.cpp
)

qt_add_qml_module(appcleaner-gui
    URI cleaner-gui
    VERSION 1.0
    QML_FILES main.qml 
)

set_target_properties(appcleaner-gui PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_compile_definitions(appcleaner-gui
    PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(appcleaner-gui
    PRIVATE Qt6::Quick)
