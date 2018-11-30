cmake_minimum_required(VERSION 3.10)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/inc)

if(UNIX)
    add_compile_options(-ggdb3)
endif(UNIX)

add_executable(GLEWCoreExample example.cpp src/glew.c)

target_link_libraries(GLEWCoreExample GL glfw)
