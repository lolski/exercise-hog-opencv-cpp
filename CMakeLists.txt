cmake_minimum_required(VERSION 3.5)
project(hello_opencv_cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
set(CMAKE_PREFIX_PATH "/usr/local/Cellar/opencv3/3.1.0_3/share/OpenCV")
set(OpenCV_INCLUDE_DIRS "/usr/local/Cellar/opencv3/3.1.0_3/include")
set(OpenCV_LIBS "/usr/local/Cellar/opencv3/3.1.0_3/lib")
set(SOURCE_FILES main.cpp)

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(hello_opencv_cpp ${SOURCE_FILES})

target_link_libraries(hello_opencv_cpp ${OpenCV_LIBS})