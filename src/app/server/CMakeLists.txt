## Sources #############################################################################################################
# Collect source files of component and add them to relevant targets.
set(SOURCES_LAPP_CSERVER
    "${CMAKE_CURRENT_SOURCE_DIR}/server.cpp"
    CACHE INTERNAL ""
)
target_sources(capicpp_server PRIVATE ${SOURCES_LAPP_CSERVER})

## Includes ############################################################################################################
# Collect include directories of component and add them to relevant targets.
set(INCLUDE_DIRS_LAPP_CSERVER
    "${CMAKE_CURRENT_SOURCE_DIR}/inc"
    CACHE INTERNAL ""
)
target_include_directories(capicpp_server PRIVATE ${INCLUDE_DIRS_LAPP_CSERVER})
