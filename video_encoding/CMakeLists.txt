cmake_minimum_required(VERSION 3.0)
project(recorder VERSION 0.1.0)

set( CMAKE_CXX_STANDARD 14 )

find_package( OpenCV 4 REQUIRED )

include_directories( ${OpenCV_INCLUDE_DIRS} )

add_executable(recorder main.cpp)
target_link_libraries( recorder ${OpenCV_LIBS} )
