cmake_minimum_required(VERSION 3.7)
project(lab4)

set(CMAKE_C_STANDARD 11)
set(dir ${CMAKE_CURRENT_SOURCE_DIR})
set(src ${dir}/src)
set(tests ${CMAKE_CURRENT_SOURCE_DIR}/tests)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${dir}/build)

add_subdirectory(${src}/list)
add_subdirectory(${src}/graph)
add_subdirectory(${src}/bellmanford)

add_executable(${PROJECT_NAME} ${src}/main.c)
add_executable(graphTests ${tests}/graph/graphtest.c)
add_executable(bellmanTests ${tests}/bellman/bellmantest.c)
add_executable(presentationTests ${tests}/presentation/presentation.c)

target_link_libraries(${PROJECT_NAME} list graph bellmanford)
target_link_libraries(graphTests list list graph)
target_link_libraries(bellmanTests list list graph bellmanford)
target_link_libraries(presentationTests list list graph bellmanford)