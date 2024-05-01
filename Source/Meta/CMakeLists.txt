cmake_minimum_required(VERSION 3.10)

#project(Graphics VERSION 0.1 LANGUAGES CXX)

add_library(meta OBJECT Check.cpp LoadWindowOptions.cpp)

target_include_directories(meta PRIVATE ${CMAKE_SOURCE_DIR}/Headers)
