## Add 'error' component ###############################################################################################
add_subdirectory("error")

## Add 'version' component #############################################################################################
add_subdirectory("version")

## All layer sources and include directories ###########################################################################
# Collect source files of all components.
set(SOURCES_UTILS
    ${SOURCES_UTILS_ERROR}
    ${SOURCES_UTILS_VERSION}
    CACHE INTERNAL ""
)

# Collect include dirs of all components.
set(INCLUDE_DIRS_UTILS
    "${CMAKE_CURRENT_SOURCE_DIR}/inc"
    ${INCLUDE_DIRS_UTILS_ERROR}
    ${INCLUDE_DIRS_UTILS_VERSION}
    CACHE INTERNAL ""
)
