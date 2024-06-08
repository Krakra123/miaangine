cmake_minimum_required(VERSION 3.5.0)
project(mia VERSION 0.1)

set(CMAKE_CXX_STANDARD 17)

set(GLFW3_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lib/glfw-3.4)

find_package(OpenGL REQUIRED)
find_package(GLFW3 REQUIRED)

file(GLOB_RECURSE MIA_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
)
file(GLOB_RECURSE MIA_HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.h
)

add_library(mia SHARED ${MIA_SOURCES} ${MIA_HEADERS})

target_include_directories(mia 
    PUBLIC
        ${GLFW3_INCLUDE_DIRS}
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
)

target_link_libraries(mia
    PUBLIC
        ${OPENGL_LIBRARIES}
        ${GLFW3_LIBRARIES}
)

# =========== DEMO ===========

add_executable(miademo ${CMAKE_CURRENT_SOURCE_DIR}/demo/main.cpp)

target_include_directories(miademo
    PUBLIC
        ${GLFW3_INCLUDE_DIRS}
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

target_link_libraries(miademo 
    mia
)

install(
    TARGETS mia
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
)