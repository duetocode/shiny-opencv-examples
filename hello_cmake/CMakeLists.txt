cmake_minimum_required(VERSION 3.15)

project( Hello_CMake VERSION 0.1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(OpenCV REQUIRED)

include_directories( ${OpenCV_INCLUDE_DIRS} )
add_executable( main main.cpp)
add_custom_command(
    TARGET main POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
            ${CMAKE_SOURCE_DIR}/assets/ada-lovelace.jpeg
            $(CMAKE_BINARY_DIR)/assets/ada-lovelace.jpeg)

target_link_libraries( main ${OpenCV_LIBS} )