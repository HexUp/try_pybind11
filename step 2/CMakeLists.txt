cmake_minimum_required(VERSION 3.5)
project(toy_matrix)

set(CMAKE_CXX_STANDARD 17)
set(MAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

# you may need these 2 lines, and set your own paths
# set(PYTHON_EXECUTABLE "your/python/path")
# set(PYTHON_INCLUDE_DIRECTORY "your/python/include/path")

add_subdirectory(extern/pybind11)

add_executable(TestMatrix main.cpp matrix.cpp)
pybind11_add_module(toy_matrix bind.cpp matrix.cpp)
