cmake_minimum_required(VERSION 3.2)
project(picture)

find_package(OpenCV)

add_executable(code code.cpp)
target_link_libraries(code ${OpenCV_LIBS})