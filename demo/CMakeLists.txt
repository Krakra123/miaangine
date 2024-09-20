cmake_minimum_required(VERSION 3.5.0)

#########################################
project(mia_demo)

#########################################
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(GLFW3 REQUIRED PATHS ${CMAKE_CURRENT_SOURCE_DIR}/../lib/glfw)

#########################################
add_executable(mia_demo main.cpp)

target_include_directories(mia_demo PRIVATE ${OpenGL_INCLUDE_DIR})
target_include_directories(mia_demo PRIVATE ${GLEW_INCLUDE_DIR})
target_include_directories(mia_demo PRIVATE ${GLFW3_INCLUDE_DIR})
target_include_directories(mia_demo PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../include
    ${CMAKE_CURRENT_SOURCE_DIR}/../src
)

target_link_libraries(mia_demo PRIVATE mia)
target_compile_definitions(mia_demo PRIVATE MIA_DEBUG)