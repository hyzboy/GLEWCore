cmake_minimum_required(VERSION 3.10)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/inc)

add_library(GLEWCore src/glew.c)

add_executable(GLEWCoreExample example.cpp src/glew.c)

IF(WIN32)
	target_link_libraries(GLEWCoreExample opengl32 glfw)
ELSE()
	target_link_libraries(GLEWCoreExample GL glfw)
ENDIF()
