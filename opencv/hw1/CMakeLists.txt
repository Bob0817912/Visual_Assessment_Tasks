cmake_minimum_required(VERSION 3.2)
project(picture)

find_package(OpenCV)

add_executable(method1 method1.cpp)
add_executable(method2 method2.cpp)
add_executable(method3 method3.cpp)
target_link_libraries(method1 ${OpenCV_LIBS})
target_link_libraries(method2 ${OpenCV_LIBS})
target_link_libraries(method3 ${OpenCV_LIBS})