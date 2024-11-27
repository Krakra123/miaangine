cmake_minimum_required(VERSION 3.5.0)

#########################################
project(mia_demo)

#########################################
add_executable(mia_demo main.cpp)

target_link_libraries(mia_demo PRIVATE mia)
target_compile_definitions(mia_demo PRIVATE MIA_DEBUG)