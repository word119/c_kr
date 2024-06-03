# 5.11_pointer_function.c

cmake_minimum_required(VERSION 3.10)

project(sort_with_pointer)

include_directories(lib)

add_executable(sort 5.11_pointer_function.c lib/qsort_function_pointer.c lib/lines.c)