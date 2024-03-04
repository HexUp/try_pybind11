cmake_minimum_required(VERSION 3.5)
project(toy_matrix)

# you may need these 2 lines, and set your own paths
# set(PYTHON_EXECUTABLE "your/python/path")
# set(PYTHON_INCLUDE_DIRECTORY "your/python/include/path")

# add_subdirectory(extern/pybind11)
# pybind11_add_module(toy_matrix matrix.cpp)
set(CMAKE_CXX_STANDARD 11)
set(MAKE_CXX_STANDARD_REQUIRED True)

add_executable(TestMatrix main.cpp matrix.cpp)
