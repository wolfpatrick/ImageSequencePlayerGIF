cmake_minimum_required(VERSION 2.8)

SET (PROJECT_NAME SequencePlayerGIF)

PROJECT(${PROJECT_NAME})

FILE( GLOB project_SRCS "*.cpp" "*.h" )

FILE( GLOB project_UI "*.ui"  )

#
# Find the required Qt5 libraries
find_package(Qt5Multimedia)
find_package(Qt5MultimediaWidgets)
find_package(Qt5Xml REQUIRED)
#

set(CMAKE_AUTOMOC ON)
FIND_PACKAGE(Qt5 COMPONENTS Widgets REQUIRED)
QT5_WRAP_UI( project_SRCS ${project_UI})
set(QT_LIBRARIES ${Qt5Core_LIBRARIES} ${Qt5Widgets_LIBRARIES})
IF (WIN32)
	ADD_EXECUTABLE( ${PROJECT_NAME} WIN32 ${project_SRCS} ${project_QRC} )
	TARGET_LINK_LIBRARIES(${PROJECT_NAME} Qt5::WinMain)
ELSE()
	ADD_EXECUTABLE( ${PROJECT_NAME} ${project_SRCS} ${project_QRC} )
ENDIF()

TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${QT_LIBRARIES})
INCLUDE_DIRECTORIES(${Qt5Widgets_INCLUDE_DIRS})
set(QT_USE_QTXML TRUE)
#
# Use the required module from Qt5.
#qt5_use_modules(${PROJECT_NAME} Multimedia MultimediaWidgets)
qt5_use_modules(${PROJECT_NAME} Xml)
#

INCLUDE_DIRECTORIES(${TestProject_BINARY_DIR} )