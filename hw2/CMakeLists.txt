cmake_minimum_required(VERSION 3.0)
project(BCH_verify)

# 为使用 sophus，需要使用find_package命令找到它
find_package(Sophus REQUIRED)

# Eigen
include_directories(
    /usr/include/eigen3
    ${Sophus_INCLUDE_DIRS}
)

add_executable(BCH_verify BCH_verify.cpp)
target_link_libraries(BCH_verify ${Sophus_LIBRARIES} Sophus)

