cmake_minimum_required(VERSION 3.23)

project(menu VERSION 1.0)

add_subdirectory(cmenulib)

add_executable(menu "src/main.cpp")

configure_file("src/Config.h.in" Config.h)

target_link_libraries(menu PUBLIC cmenu)

target_include_directories(menu PUBLIC 
"${PROJECT_BINARY_DIR}"
"${PROJECT_SOURCE_DIR}/cmenulib"
)