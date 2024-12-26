## Include 'startup' component #########################################################################################
add_subdirectory("startup")

## All layer sources and include directories ###########################################################################
# Collect source files of all components.
set(SOURCES_APP
    ${SOURCES_APP_STARTUP}
    CACHE INTERNAL ""
)

# Collect include dirs of all components.
set(INCLUDE_DIRS_APP
    "${CMAKE_CURRENT_SOURCE_DIR}/inc"
    ${INCLUDE_DIRS_APP_STARTUP}
    CACHE INTERNAL ""
)
