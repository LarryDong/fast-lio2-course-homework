cmake_minimum_required(VERSION 3.0)
project(kalmanfilter)


# Eigen
include_directories("/usr/include/eigen3")


add_executable(kalmanfilter kalmanfilter.cpp)