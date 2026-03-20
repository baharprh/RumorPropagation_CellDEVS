cmake_minimum_required(VERSION 3.16)

set(projectName "rumor_sim")
project(${projectName})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

add_executable(${projectName} src/main.cpp)

set(CADMIUM_DIR $ENV{CADMIUM})

target_include_directories(${projectName} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CADMIUM_DIR}
    ${CADMIUM_DIR}/../json/include
)

target_compile_options(${projectName} PUBLIC -std=gnu++2b)