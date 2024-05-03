cmake_minimum_required(VERSION 3.26)
project(untitled7 C)

set(CMAKE_C_STANDARD 11)

add_executable (untitled7 main.c
        libs/algorithms/array/array.c
        libs/algorithms/algorithm.c
        libs/data_structures/bitset/bitset.c
        libs/data_structures/bitset/bitset.h
        libs/algorithms/array/array.h
        libs/data_structures/bitset/bitset.c
        libs/data_structures/bitset/bitset.h
        libs/algorithms/algorithm.h
        libs/strings/string/string_.c
        libs/strings/string/string_.h
        libs/strings/string/tasks/tasks1/tasks1.h
        libs/file/tasks/task1/tasks1.h
        libs/file/tasks/task2/tasks2.h
        libs/file/tasks/task3/tasks3.h
        libs/file/tasks/task4/task4.h
        libs/file/tasks/task6/task6.h
        libs/file/tasks/tasks/task5.h
        libs/file/tasks/task7/tasks7.h
        libs/file/tasks/task8/task8.h
        libs/file/tasks/task9/task9.h
        libs/file/tasks/task10/task10.h
)

add_subdirectory(libs)
target_link_libraries(untitled7 data_structures)
target_link_libraries(untitled7 algorithms)
target_link_libraries(strings)