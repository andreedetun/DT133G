cmake_minimum_required(VERSION 3.7)
project(lab4)

set(CMAKE_C_STANDARD 11)
set(dir ${CMAKE_CURRENT_SOURCE_DIR})
set(src ${dir}/src)
# set(tests ${CMAKE_CURRENT_SOURCE_DIR}/tests)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${dir}/build)

add_subdirectory(${src}/list)
add_subdirectory(${src}/graph)

add_executable(${PROJECT_NAME} ${src}/main.c)

target_link_libraries(${PROJECT_NAME} list graph)