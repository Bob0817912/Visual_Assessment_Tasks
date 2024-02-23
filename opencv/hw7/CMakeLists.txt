cmake_minimum_required(VERSION 3.2)
project(picture)

find_package(OpenCV)

add_executable(code1 code1.cpp)
add_executable(code2 code2.cpp)
target_link_libraries(code1 ${OpenCV_LIBS})
target_link_libraries(code2 ${OpenCV_LIBS})