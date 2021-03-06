cmake_minimum_required( VERSION 3.14 FATAL_ERROR )

project(
    imgui
    VERSION 0.0.0
    DESCRIPTION "Dear ImGui GLFW/OpenGL3 Template"
    LANGUAGES CXX
)

add_subdirectory( dependencies )

add_library( ${PROJECT_NAME} STATIC
    src/imgui/imgui_demo.cpp
    src/imgui/imgui_draw.cpp
    src/imgui/imgui_impl_glfw.cpp
    src/imgui/imgui_impl_opengl3.cpp
    src/imgui/imgui_tables.cpp
    src/imgui/imgui_widgets.cpp
    src/imgui/imgui.cpp
)

target_include_directories( ${PROJECT_NAME}
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/imgui>
        $<INSTALL_INTERFACE:include>
        $<INSTALL_INTERFACE:include/imgui>
)

target_link_libraries( ${PROJECT_NAME}
    PUBLIC
        glfw
        libglew_static
)

set( CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR} )
set( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR} )
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR} )

install(
    DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/res
    DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
)

#-------------------------------------------------------------------------------

add_executable( ${PROJECT_NAME}-demo
    main.cpp
)

target_link_libraries( ${PROJECT_NAME}-demo
    PUBLIC
        imgui
)