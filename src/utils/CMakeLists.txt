## Add 'error' component ###############################################################################################
add_subdirectory("error")

## Add 'version' component #############################################################################################
add_subdirectory("version")

## Add 'capi' component ################################################################################################
add_subdirectory("capi")

## Sources #############################################################################################################
# Collect source files of component and add them to relevant targets.
set(SOURCES_LUTILS_CUTILS
    ""
    CACHE INTERNAL ""
)
foreach_target(TARGETS capicpp_client capicpp_server FN target_sources PRIVATE ${SOURCES_LUTILS_CUTILS})

## Includes ############################################################################################################
# Collect include directories of component and add them to relevant targets.
set(INCLUDE_DIRS_LUTILS_CUTILS
    "${CMAKE_CURRENT_SOURCE_DIR}/inc"
    CACHE INTERNAL ""
)
foreach_target(TARGETS capicpp_client capicpp_server FN target_include_directories PRIVATE ${INCLUDE_DIRS_LUTILS_CUTILS})

## All layer sources and include directories ###########################################################################
# Collect source files of layer from its components.
set(SOURCES_LUTILS
    ${SOURCES_LUTILS_CUTILS}
    ${SOURCES_LUTILS_CERROR}
    ${SOURCES_LUTILS_CVERSION}
    ${SOURCES_LUTILS_CCAPI}
    CACHE INTERNAL ""
)

# Collect include directories of layer from its components.
set(INCLUDE_DIRS_LUTILS
    ${INCLUDE_DIRS_LUTILS_CUTILS}
    ${INCLUDE_DIRS_LUTILS_CERROR}
    ${INCLUDE_DIRS_LUTILS_CVERSION}
    ${INCLUDE_DIRS_LUTILS_CCAPI}
    CACHE INTERNAL ""
)
