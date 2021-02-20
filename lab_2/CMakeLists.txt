cmake_minimum_required(VERSION 3.7)
project(lab_2)

set(CMAKE_C_STANDARD 11)
set(dir ${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${dir}/build)

add_executable(${PROJECT_NAME}
        src/load_files/load_file.h
        src/load_files/load_file.c
        src/list/list.h
        src/list/list.c
        src/utils/utils.h
        src/utils/utils.c
        src/sort/insertion/insertion.h
        src/sort/insertion/insertion.c
        src/sort/merge/mergelist.h
        src/sort/merge/mergelist.c
        src/main.c)

add_executable(lab1Tests
        src/load_files/load_file.h
        src/load_files/load_file.c
        src/list/list.h
        src/list/list.c
        src/utils/utils.h
        src/utils/utils.c
        src/sort/insertion/insertion.h
        src/sort/insertion/insertion.c
        src/sort/merge/mergelist.h
        src/sort/merge/mergelist.c
        tests/lab1Tests/lab1Tests.c)

add_executable(personalNumberTest
        src/load_files/load_file.h
        src/load_files/load_file.c
        src/list/list.h
        src/list/list.c
        src/utils/utils.h
        src/utils/utils.c
        src/sort/insertion/insertion.h
        src/sort/insertion/insertion.c
        src/sort/merge/mergelist.h
        src/sort/merge/mergelist.c
        tests/personalNumberTest/personalNumberTest.c)