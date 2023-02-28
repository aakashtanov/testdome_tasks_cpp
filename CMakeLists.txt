cmake_minimum_required(VERSION 3.21)
project(testdome_tasks)

set(CMAKE_CXX_STANDARD 14)

set(ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${ROOT_DIR})

add_subdirectory(merge_names)
add_subdirectory(quadratic_equation)
add_subdirectory(binary_search_tree)
add_subdirectory(song)
add_subdirectory(user_input)
add_subdirectory(two_sum)
add_subdirectory(pipeline)
add_subdirectory(multiple_choice_test)
add_subdirectory(sorted_search)
add_subdirectory(train_composition)
add_subdirectory(route_planner)