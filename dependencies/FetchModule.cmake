cmake_minimum_required( VERSION 3.11 FATAL_ERROR )

include( FetchContent )
set( FETCHCONTENT_BASE_DIR ${CMAKE_CURRENT_BINARY_DIR} )

message( "adding ${MODULE_NAME} ..." )

FetchContent_Declare( ${MODULE_NAME}
    GIT_REPOSITORY ${MODULE_URL}
    GIT_TAG ${MODULE_VERSION}
)

FetchContent_GetProperties( ${MODULE_NAME} )

if ( NOT ${${MODULE_NAME}_POPULATED} )

    message( "fetching ${MODULE_URL} @${MODULE_VERSION} ..." )

    FetchContent_Populate( ${MODULE_NAME} )

    add_subdirectory(
        ${${MODULE_NAME}_SOURCE_DIR}
        ${${MODULE_NAME}_BINARY_DIR}
        EXCLUDE_FROM_ALL
    )

endif()