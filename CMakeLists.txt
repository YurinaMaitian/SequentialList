cmake_minimum_required(VERSION 3.30)
project(SequentialList)

set(CMAKE_CXX_STANDARD 20)

add_library(SequentialList STATIC
        src/SequentialList.cpp
)

target_include_directories(SequentialList
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)
