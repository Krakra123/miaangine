cmake_minimum_required(VERSION 3.5.0)

#########################################
project(mia_demo)

#########################################
add_executable(mia_demo main.cpp)

target_include_directories(mia_demo PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../lib/glfw/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../include
    ${CMAKE_CURRENT_SOURCE_DIR}/../src
)

message(STATUS ${CMAKE_CURRENT_SOURCE_DIR}/../lib/glfw/include)

target_link_libraries(mia_demo PRIVATE mia)
target_compile_definitions(mia_demo PRIVATE MIA_DEBUG)