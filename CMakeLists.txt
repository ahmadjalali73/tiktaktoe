cmake_minimum_required(VERSION 3.5)

project(tiktaktoe)

file(GLOB
    SOURCES
    src/*.cpp)

add_executable(tiktaktoe ${SOURCES})

target_include_directories(tiktaktoe
        PRIVATE
        ${PROJECT_SOURCE_DIR}/include)