cmake_minimum_required(VERSION 3.23)

project(menu VERSION 1.0)

add_subdirectory(cmenulib)
list(APPEND EXTRA_LIBS cmenulib)

add_executable(example1 "src/example1.cpp")
add_executable(example2 "src/example2.cpp")

configure_file("src/Config.h.in" Config.h)

target_link_libraries(example1 PUBLIC cmenu)
target_link_libraries(example2 PUBLIC cmenu)
