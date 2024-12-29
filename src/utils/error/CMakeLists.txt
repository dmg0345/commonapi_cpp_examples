## Sources #############################################################################################################
# Collect source files of component and add them to relevant targets.
set(SOURCES_LUTILS_CERROR
    ""
    CACHE INTERNAL ""
)
foreach_target(TARGETS capicpp_client capicpp_server FN target_sources PRIVATE ${SOURCES_LUTILS_CERROR})

## Includes ############################################################################################################
# Collect include directories of component and add them to relevant targets.
set(INCLUDE_DIRS_LUTILS_CERROR
    "${CMAKE_CURRENT_SOURCE_DIR}/inc"
    CACHE INTERNAL ""
)
foreach_target(TARGETS capicpp_client capicpp_server FN target_include_directories PRIVATE ${INCLUDE_DIRS_LUTILS_CERROR})
