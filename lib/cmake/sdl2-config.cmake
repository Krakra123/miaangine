# SDL2 CMake configuration file:
# This file is meant to be placed in a cmake subfolder of SDL2-devel-2.x.y-mingw

if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(sdl2_config_path "${CMAKE_CURRENT_LIST_DIR}/../SDL2/lib/cmake/SDL2/SDL2Config.cmake")
else()
    set(SDL2_FOUND FALSE)
    return()
endif()

if(NOT EXISTS "${sdl2_config_path}")
    message(WARNING "${sdl2_config_path} does not exist: MinGW development package is corrupted")
    set(SDL2_FOUND FALSE)
    return()
endif()

include("${sdl2_config_path}")
