cmake_minimum_required(VERSION 3.22)
project(MoviesScroller)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(QT_VERSION 5)
set(REQUIRED_LIBS Core Gui Widgets)
set(REQUIRED_LIBS_QUALIFIED Qt5::Core Qt5::Gui Qt5::Widgets)

configure_file(assets/raw/test.jpg assets/raw/test.jpg COPYONLY)

add_executable(MoviesScroller main.cpp Window.cpp Window.hpp PerpendicularShadowEffect.cpp PerpendicularShadowEffect.hpp PosterWidget.cpp PosterWidget.hpp)

find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)
target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED})