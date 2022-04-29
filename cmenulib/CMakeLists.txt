cmake_minimum_required(VERSION 3.23)

add_library(cmenu STATIC Menu.cpp __cutils.cpp)

target_include_directories(cmenu INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})