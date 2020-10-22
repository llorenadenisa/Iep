cmake_minimum_required(VERSION 3.5.1)

project(execProg)

add_subdirectory(src)
add_subdirectory(inc)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

find_package(inc REQUIRED)

set(INC_INCLUDE_DIR "inc")

include_directories(${INC_INCLUDE_DIR})

target_include_directories(${PROJECT_NAME} PUBLIC inc)

target_link_directories(${PROJECT_NAME} PRIVATE inc)

target_link_libraries(${PROJECT_NAME} ${MATHLIB_INCLUDE_DIR})