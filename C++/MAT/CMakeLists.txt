cmake_minimum_required(VERSION 3.2)
project(Mat)

aux_source_directory(. DIR_SRCS)
add_executable(mat ${DIR_SRCS})