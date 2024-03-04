cmake_minimum_required(VERSION 3.24)
project(example)

# you may need these 2 lines, and set your own paths
# set(PYTHON_EXECUTABLE "your/python/path")
# set(PYTHON_INCLUDE_DIRECTORY "your/python/include/path")

add_subdirectory(extern/pybind11)
pybind11_add_module(example example.cpp)
