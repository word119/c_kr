cmake_minimum_required(VERSION 3.10)

project(binary_tree)

include_directories(lib)

set(SOURCE_FILES main.c lib/utility.c)

add_executable(binary_tree ${SOURCE_FILES})