cmake_minimum_required( VERSION 3.14 FATAL_ERROR )

#-------------------------------------------------------------------------------

set( MODULE_NAME glfw )
set( MODULE_URL https://github.com/glfw/glfw.git )
set( MODULE_VERSION origin/master )

include( FetchModule.cmake )

#-------------------------------------------------------------------------------

set( MODULE_NAME glew )
set( MODULE_URL https://github.com/Perlmint/glew-cmake.git )
set( MODULE_VERSION origin/master )

add_definitions( -DGLEW_STATIC )
include( FetchModule.cmake )