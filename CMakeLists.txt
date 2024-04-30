#CMake min version
cmake_minimum_required(VERSION 3.10)

#projet propirties
project(DarkAst VERSION 1.0 LANGUAGES CXX)

#set output directs
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

#add subdirectoryes
add_subdirectory(Source/Meta)

add_subdirectory(Source/Graphics)

#set DarkAst propities
add_executable(DarkAst.out Source/main.cpp)

target_link_libraries(DarkAst.out graphics meta)

target_include_directories(DarkAst.out PRIVATE "Headers")
