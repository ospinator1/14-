cmake_minimum_required(VERSION 3.26)
project(untitled7 C)

set(CMAKE_C_STANDARD 11)

add_executable(untitled7 main.c
        libs/algorithms/array/array.c
        libs/algorithms/algorithm.c
        libs/data_structures/bitset/bitset.c
        libs/data_structures/bitset/bitset.h
        libs/algorithms/array/array.h
        libs/data_structures/bitset/bitset.c
        libs/data_structures/bitset/bitset.h
        libs/algorithms/algorithm.h
        libs/test1.h
)

add_subdirectory(libs)
target_link_libraries(untitled7 data_structures)
target_link_libraries(untitled7 algorithms)