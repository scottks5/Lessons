cmake_minimum_required(VERSION 3.3)
project(LessonBig5)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(/usr/local/include/)
link_directories(/usr/local/lib)
set(SOURCE_FILES main.cpp Implementation_shape.cpp shape.h)
add_executable(LessonBig5 ${SOURCE_FILES})
target_link_libraries(LessonBig5 gsl)
