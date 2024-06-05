cmake_minimum_required(VERSION 3.9)
project(sort_nrfd_p)
include_directories(lib_exercise517)
add_executable(powerful_sort 517_sort_nrfd_p.c lib_exercise517/qsort.c lib_exercise517/lines.c)