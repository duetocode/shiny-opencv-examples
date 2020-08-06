cmake_minimum_required(VERSION 3.0)

project( gst_rtsp_server VERSION 0.1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(PkgConfig)
pkg_check_modules(GST REQUIRED gstreamer-1.0>=1.4 gstreamer-rtsp-1.0>1.4 gstreamer-rtsp-server-1.0>1.4)

message( ${GST_LIBRARIES} )

include_directories( ${GST_INCLUDE_DIRS} )
add_executable( main main.cpp)
target_link_libraries( main ${GST_LIBRARIES} )
