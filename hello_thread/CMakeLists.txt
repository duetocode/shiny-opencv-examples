cmake_minimum_required(VERSION 3.0.0)
project(hello_thread VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 11)

find_package( Threads )

add_executable(hello_thread main.cpp)
target_link_libraries( hello_thread ${CMAKE_THREAD_LIBS_INIT} )
