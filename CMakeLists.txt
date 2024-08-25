cmake_minimum_required(VERSION 3.5.0)

#########################################
project(mia VERSION 0.1)

#########################################
set(CMAKE_CXX_STANDARD 20)

OPTION(BUILD_SAMPLES "Builds samples" ON)
OPTION(BUILD_TESTS "Builds tests" ON)

OPTION(OPENGL_DEBUG "Enables debug mode for OpenGL" ON)
OPTION(OPENGL_NO_EXTENSIONS "Disables all extensions" OFF)
OPTION(OPENGL_SHADER_OUTPUT "Outputs all source shaders for GLSLANG testing" OFF)

#########################################
file(GLOB_RECURSE MIA_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

#########################################
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/lib/glfw")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/lib/glew/build/cmake")

target_compile_options(glfw PUBLIC -O3)
target_compile_options(glew PUBLIC -O3)

#########################################
add_library(mia SHARED ${MIA_SOURCES})

#########################################
target_include_directories(mia PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/lib/glfw/include)
target_include_directories(mia PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/lib/glew/include)

target_include_directories(mia PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
)

#########################################
target_link_libraries(mia PUBLIC glfw ${GLFW_LIBRARIES})
target_link_libraries(mia PUBLIC glew ${GLEW_LIBRARIES})

#########################################
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_options(mia PRIVATE -O0 -ggdb -Wpedantic -Wextra -Wall -Wunused -Wno-attributes)
    target_compile_definitions(mia PUBLIC MIA_DEBUG)
endif()

if (CMAKE_BUILD_TYPE STREQUAL "Release")
    target_compile_options(mia PRIVATE -O3 -Wpedantic -Wextra -Wall -Wunused -Wno-attributes)
endif()

if (OPENGL_DEBUG)
    target_compile_definitions(mia PUBLIC MIA_DEBUG)
endif()

#########################################
install(TARGETS mia
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
)

#########################################
add_subdirectory(demo)
