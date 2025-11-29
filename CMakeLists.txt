cmake_minimum_required(VERSION 3.30)
project(SequentialList)

set(CMAKE_CXX_STANDARD 20)

add_library(SequentialList INTERFACE)

target_include_directories(SequentialList INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)
