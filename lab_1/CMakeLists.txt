# André Falk Edetun & Kevin Güvenal
cmake_minimum_required(VERSION 3.7)
project(lab_1)

set(CMAKE_C_STANDARD 11)
set(dir ${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${dir}/build)

add_executable(${PROJECT_NAME}
        src/main.c
        src/list/list.h
        src/list/list.c
        src/stack/stack.c
        src/stack/stack.h
        src/queue/queue.c
        src/queue/queue.h)

add_executable(testlist
        src/list/list.h
        src/list/list.c
        tests/testlist/testlist.c)

add_executable(teststack
        src/list/list.h
        src/list/list.c
        src/stack/stack.c
        src/stack/stack.h
        tests/teststack/teststack.c)

add_executable(testqueue
        src/list/list.h
        src/list/list.c
        src/queue/queue.c
        src/queue/queue.h
        tests/testqueue/testqueue.c)

add_executable(presentationTest
        src/list/list.h
        src/list/list.c
        src/stack/stack.c
        src/stack/stack.h
        src/queue/queue.c
        src/queue/queue.h
        tests/presentationTest/presentationTest.c)