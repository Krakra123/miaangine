cmake_minimum_required(VERSION 3.5.0)
project(mag)

set(CMAKE_CXX_STANDARD 17)

add_executable(magdemo ${CMAKE_CURRENT_SOURCE_DIR}/demo/main.cpp)

# install(
#     TARGETS mag
#     LIBRARY DESTINATION lib
#     RUNTIME DESTINATION bin
# )