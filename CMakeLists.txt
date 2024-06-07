cmake_minimum_required(VERSION 3.5.0)
project(mia)

set(CMAKE_CXX_STANDARD 17)

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
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
)

# =========== DEMO ===========

add_executable(miademo ${CMAKE_CURRENT_SOURCE_DIR}/demo/main.cpp)

target_include_directories(mia 
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

target_link_libraries(miademo 
    mia
)

# install(
#     TARGETS MIA
#     LIBRARY DESTINATION lib
#     RUNTIME DESTINATION bin
# )