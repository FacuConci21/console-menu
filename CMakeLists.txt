cmake_minimum_required(VERSION 3.23)

project(menu VERSION 1.0)


add_subdirectory(cmenulib)
list(APPEND EXTRA_LIBS cmenulib)

add_executable(menu "src/main.cpp")
add_executable(example1 "src/example1.cpp")

configure_file("src/Config.h.in" Config.h)

target_link_libraries(menu PUBLIC cmenu)
target_link_libraries(example1 PUBLIC cmenu)

target_include_directories(menu PUBLIC 
"${PROJECT_BINARY_DIR}"
)