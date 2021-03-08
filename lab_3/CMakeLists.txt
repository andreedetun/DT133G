cmake_minimum_required(VERSION 3.7)
project(lab_3)

set(CMAKE_C_STANDARD 11)
set(dir ${CMAKE_CURRENT_SOURCE_DIR})
set(src ${dir}/src)
set(tests ${CMAKE_CURRENT_SOURCE_DIR}/tests)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${dir}/build)

add_subdirectory(${src}/binarytree)
add_subdirectory(${src}/loadfiles)

add_executable(${PROJECT_NAME} ${src}/main.c)
add_executable(operationTests ${tests}/operations/operations.c)
add_executable(sortingproblemsTests ${tests}/sortingproblems/sortingproblems.c)
add_executable(presentationTests ${tests}/presentation/presentation.c)

target_link_libraries(${PROJECT_NAME} binarytree)
target_link_libraries(operationTests binarytree)
target_link_libraries(sortingproblemsTests binarytree loadfiles)
target_link_libraries(presentationTests binarytree loadfiles)