cmake_minimum_required(VERSION 3.23)
project(cmenu VERSION 1.0)

# library
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_library(${PROJECT_NAME} STATIC "src/Menu.cpp" "src/__cutils.cpp")

target_include_directories(${PROJECT_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

configure_file("src/Config.h.in" Config.h)

# examples
list(APPEND EXTRA_LIBS include)

add_executable(example1 "examples/example1.cpp")
add_executable(example2 "examples/example2.cpp")

target_link_libraries(example1 PUBLIC cmenu)
target_link_libraries(example2 PUBLIC cmenu)