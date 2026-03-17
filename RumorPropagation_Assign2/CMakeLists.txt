cmake_minimum_required(VERSION 3.10)
project(rumor_model)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Boost 1.56.0 COMPONENTS system thread REQUIRED)

include_directories(
    ${Boost_INCLUDE_DIRS}
    C:/cadmium-main/cadmium-main/include
    C:/cadmium-main/cadmium-main/json/single_include
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_SOURCE_DIR}/External/cadmium-web-extension/include
    ${CMAKE_CURRENT_SOURCE_DIR}/External/DESTimes/include
)

add_executable(rumor_sim src/main.cpp)
target_link_libraries(rumor_sim PUBLIC ${Boost_LIBRARIES})
