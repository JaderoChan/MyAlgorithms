cmake_minimum_required(VERSION 3.17)

project(K-Means LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(MSVC)
    add_compile_options(/utf-8)
endif()

set(SRCS kmeans.hpp kmeans.cpp)
add_library(kmeans STATIC ${SRCS})

target_include_directories(kmeans PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(example)
