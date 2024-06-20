cmake_minimum_required(VERSION 3.10)

project(binary_tree)

include_directories(lib)

add_executable(binary_tree main.c lib/utility.c)