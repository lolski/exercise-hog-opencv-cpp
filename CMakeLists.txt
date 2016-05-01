cmake_minimum_required(VERSION 3.5)
project(hello_opencv_cpp)

# opencv3
# brew install opencv3 --with-contrib
set(CMAKE_PREFIX_PATH "/usr/local/Cellar/opencv3/3.1.0_3/share/OpenCV")
set(OpenCV_INCLUDE_DIRS "/usr/local/Cellar/opencv3/3.1.0_3/include")
set(OpenCV_LIBS "/usr/local/Cellar/opencv3/3.1.0_3/lib")
find_package(OpenCV REQUIRED)

#libconfig
# brew install libconfig
#set(CMAKE_PREFIX_PATH "/usr/local/Cellar/libconfig/1.5")
#set(LibConfig_DIR "/usr/local/Cellar/libconfig/1.5")
#set(LibConfig_INCLUDE_DIRS "/usr/local/Cellar/libconfig/1.5/include")
set(LibConfig_LIBS "/usr/local/Cellar/libconfig/1.5/lib")
#find_package(LibConfig REQUIRED)

# compilation
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
set(SOURCE_FILES main.cpp image.h svm.h image.h util.h)
include_directories(${OpenCV_INCLUDE_DIRS})
#include_directories(${LibConfig_INCLUDE_DIRS})
add_executable(hello_opencv_cpp ${SOURCE_FILES})
target_link_libraries(hello_opencv_cpp ${OpenCV_LIBS})
target_link_libraries(hello_opencv_cpp ${LibConfig_LIBS})