cmake_minimum_required(VERSION 3.5)
project(cyril_lang_example)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

add_subdirectory(src)
include_directories(${CYRIL_LANG_INCLUDES})

set(SOURCE_FILES main.cpp)
add_executable(cyril_lang_example ${SOURCE_FILES})
target_link_libraries(cyril_lang_example cyril_lang)
