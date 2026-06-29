cmake_minimum_required(VERSION 3.17)

project(sorts LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(MSVC)
    add_compile_options(/utf-8)
endif()

set(SRCS)
add_library(${PROJECT_NAME} STATIC ${SRCS})

