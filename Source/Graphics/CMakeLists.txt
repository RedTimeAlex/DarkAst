cmake_minimum_required(VERSION 3.10)

#project(Graphics VERSION 0.1 LANGUAGES CXX)

add_library(graphics OBJECT CreateContext.cpp)

target_link_libraries(graphics glfw)

target_include_directories(graphics PRIVATE ${CMAKE_SOURCE_DIR}/Headers)
