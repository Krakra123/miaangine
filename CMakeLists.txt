cmake_minimum_required(VERSION 3.5.0)

#########################################
project(mia VERSION 0.1)

#########################################
set(CMAKE_CXX_STANDARD 20)

#########################################
set(GLFW_LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lib/glfw)

#########################################
find_package(OpenGL REQUIRED)
find_package(GLFW3 REQUIRED PATHS ${GLFW_LIB_DIR})

#########################################
file(GLOB_RECURSE MIA_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

add_library(mia STATIC ${MIA_SOURCES})

#########################################
target_include_directories(mia PUBLIC ${OpenGL_INCLUDE_DIR})
target_include_directories(mia PUBLIC ${GLFW3_INCLUDE_DIR})

message(STATUS ${GLFW3_INCLUDE_DIR})

target_include_directories(mia PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
)

#########################################
target_link_libraries(mia PUBLIC ${OpenGL_LIBRARIES})
target_link_libraries(mia PUBLIC ${GLFW3_LIBRARIES})

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
