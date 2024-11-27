cmake_minimum_required(VERSION 3.5.0)

#########################################
project(mia VERSION 0.1)

#########################################
set(CMAKE_CXX_STANDARD 20)

#########################################
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/lib/cmake)
list(APPEND CMAKE_PREFIX_PATH ${CMAKE_CURRENT_SOURCE_DIR}/lib/cmake)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(GLFW3 REQUIRED)
find_package(glm REQUIRED)
find_package(SDL2 REQUIRED)

#########################################
file(GLOB_RECURSE MIA_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

add_library(mia STATIC ${MIA_SOURCES})

#########################################
target_include_directories(mia PUBLIC ${OpenGL_INCLUDE_DIR})
target_include_directories(mia PUBLIC ${GLEW_INCLUDE_DIR})
target_include_directories(mia PUBLIC ${GLFW_INCLUDE_DIR})
target_include_directories(mia PUBLIC ${GLM_INCLUDE_DIR})
target_include_directories(mia PUBLIC ${SDL2_INCLUDE_DIRS})

target_include_directories(mia PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

#########################################
target_link_libraries(mia PUBLIC opengl32)
target_link_libraries(mia PUBLIC GLEW::glew)
target_link_libraries(mia PUBLIC glfw)
target_link_libraries(mia PUBLIC glm::glm)
target_link_libraries(mia PUBLIC ${SDL2_STATIC_LIBRARIES})

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
