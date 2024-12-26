## Sources #############################################################################################################
# Collect sources and add them to target.
set(SOURCES_UTILS_VERSION
    ""
    CACHE INTERNAL ""
)
target_sources(app PRIVATE ${SOURCES_UTILS_VERSION})

## Includes ############################################################################################################
# Collect include directories and add them to target.
set(INCLUDE_DIRS_UTILS_VERSION
    "${CMAKE_CURRENT_SOURCE_DIR}/inc"
    CACHE INTERNAL ""
)
target_include_directories(app PRIVATE ${INCLUDE_DIRS_UTILS_VERSION})
