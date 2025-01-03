## Sources #############################################################################################################
# Collect source files of component and add them to relevant targets.
set(SOURCES_LAPP_CSTARTUP
    "${CMAKE_CURRENT_SOURCE_DIR}/startup.cpp"
    CACHE INTERNAL ""
)
foreach_target(TARGETS capicpp_client capicpp_server FN target_sources PRIVATE ${SOURCES_LAPP_CSTARTUP})

## Includes ############################################################################################################
# Collect include directories of component and add them to relevant targets.
set(INCLUDE_DIRS_LAPP_CSTARTUP
    "${CMAKE_CURRENT_SOURCE_DIR}/inc"
    CACHE INTERNAL ""
)
foreach_target(TARGETS capicpp_client capicpp_server FN target_include_directories PRIVATE ${INCLUDE_DIRS_LAPP_CSTARTUP})
