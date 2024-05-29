cmake_minimum_required(VERSION 3.9)

project(sort_program)

include_directories(lib)

add_executable(zf_sort 5.6_pointers_in_array.c lib/lines.c lib/qsort.c)