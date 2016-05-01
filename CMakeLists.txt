cmake_minimum_required(VERSION 3.5)
project(hello_opencv_cpp)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")

# opencv3
# brew install opencv3 --with-contrib
find_package(OpenCV REQUIRED)

# boost property tree
set(Boost_USE_STATIC_LIBS ON)
find_package(Boost 1.60 COMPONENTS REQUIRED)

# compilation
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
set(HEADER_FILES ${OpenCV_INCLUDE_DIRS} ${LibConfig_INCLUDE_DIRS})
set(LIB_FILES ${OpenCV_LIBS} ${LibConfig_LIBS})
set(SOURCE_FILES main.cpp image.h svm.h image.h util.h Setting.h)
include_directories(${HEADER_FILES})
add_executable(hello_opencv_cpp ${SOURCE_FILES})
target_link_libraries(hello_opencv_cpp ${LIB_FILES})