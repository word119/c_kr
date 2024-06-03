# 5.11_pointer_function.c

cmake_minimum_required(VERSION 3.10)

project(find_with_pointer)

include_directories(lib)

add_executable(find_func_pointer 5.11_pointer_function.c lib/qsort_function_pointer.c lib/lines.c)