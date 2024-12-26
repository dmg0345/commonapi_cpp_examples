## Sources #############################################################################################################
# Collect sources and add them to target.
set(SOURCES_APP_STARTUP
    "${CMAKE_CURRENT_SOURCE_DIR}/startup.cpp"
    CACHE INTERNAL ""
)
target_sources(app PRIVATE ${SOURCES_APP_STARTUP})

## Includes ############################################################################################################
# Collect include directories and add them to target.
set(INCLUDE_DIRS_APP_STARTUP
    "${CMAKE_CURRENT_SOURCE_DIR}/inc"
    CACHE INTERNAL ""
)
target_include_directories(app PRIVATE ${INCLUDE_DIRS_APP_STARTUP})
