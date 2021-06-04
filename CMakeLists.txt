cmake_minimum_required(VERSION 3.16)
project(alg_3mod)

set(CMAKE_CXX_STANDARD 17)

include_directories(problem_1)


add_library( problem_1_lib problem_1/ListGraph.cpp problem_1/MatrixGraph.cpp problem_1/SetGraph.cpp problem_1/ArcGraph.cpp )
add_executable(problem_1 main_1.cpp)
target_link_libraries(problem_1 problem_1_lib)

add_executable(problem_2 problem_2.cpp)

add_executable(problem_3 problem_3.cpp)

