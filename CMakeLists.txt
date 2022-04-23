cmake_minimum_required(VERSION 3.23)

project(menu VERSION 1.0)

configure_file("src/Config.h.in" Config.h)

add_subdirectory(cmenulib)

list(APPEND EXTRA_LIBS cmenulib)

add_executable(menu "src/main.cpp")

target_link_libraries(menu PUBLIC cmenu)

target_include_directories(menu PUBLIC 
"${PROJECT_BINARY_DIR}"
)