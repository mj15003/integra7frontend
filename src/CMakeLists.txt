cmake_minimum_required(VERSION 3.5)

project(Integra7Frontend VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_NAME Integra7Frontend)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

# Check for ALSA libraries.
pkg_check_modules (ALSA REQUIRED IMPORTED_TARGET alsa)
if (ALSA_FOUND)
  find_library (ALSA_LIBRARY NAMES ${ALSA_LIBRARIES} HINTS ${ALSA_LIBDIR})
endif ()
if (ALSA_LIBRARY)
  set (CONFIG_LIBASOUND 1)
 #set (CMAKE_REQUIRED_LIBRARIES "${ALSA_LIBRARY};${CMAKE_REQUIRED_LIBRARIES}")
else ()
  message (FATAL_ERROR "*** ALSA library not found.")
  set (CONFIG_LIBASOUND 0)
endif ()

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(PROJECT_SOURCES
        integra7frontend.cpp
        integra7mainwindow.cpp
        integra7mainwindow.h
        integra7mainwindow.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(${PROJECT_NAME}
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        integra7device.h integra7device.cpp
        midiengine.h midiengine.cpp
        integra7setup.h integra7setup.cpp
        integra7frontend.qrc
        integra7part.h integra7part.cpp
        integra7parameterset.h integra7parameterset.cpp
        notenameselector.h notenameselector.cpp
        portamentoselector.h portamentoselector.cpp
        specialtextnumselector.h specialtextnumselector.cpp
        integra7studiosetcommon.h integra7studiosetcommon.cpp
        integra7mastereq.h integra7mastereq.cpp
        integra7parteq.h integra7parteq.cpp
        integra7systemcommon.h integra7systemcommon.cpp
        colorcheckbutton.h colorcheckbutton.cpp
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET Integra7Frontend APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(${PROJECT_NAME} SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(${PROJECT_NAME}
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(${PROJECT_NAME} PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(${PROJECT_NAME} PRIVATE PkgConfig::ALSA)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.Integra7Frontend)
endif()
set_target_properties(Integra7Frontend PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS ${PROJECT_NAME}
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(${PROJECT_NAME})
endif()
