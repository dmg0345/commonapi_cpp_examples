## Include 'startup' component #########################################################################################
add_subdirectory("startup")

## Include 'client' component ##########################################################################################
# add_subdirectory("client")

## Include 'server' component ##########################################################################################
# add_subdirectory("server")

## Sources #############################################################################################################
# Collect source files of component and add them to relevant targets.
set(SOURCES_LAPP_CAPP
    ""
    CACHE INTERNAL ""
)
foreach_target(TARGETS capicpp_client capicpp_server FN target_sources PRIVATE ${SOURCES_LAPP_CAPP})

## Includes ############################################################################################################
# Collect include directories of component and add them to relevant targets.
set(INCLUDE_DIRS_LAPP_CAPP
    "${CMAKE_CURRENT_SOURCE_DIR}/inc"
    CACHE INTERNAL ""
)
foreach_target(TARGETS capicpp_client capicpp_server FN target_include_directories PRIVATE ${INCLUDE_DIRS_LAPP_CAPP})

## All layer sources and include directories ###########################################################################
# Collect source files of layer from its components.
set(SOURCES_LAPP
    ${SOURCES_LAPP_CAPP}
    ${SOURCES_LAPP_CSTARTUP}
    ${SOURCES_LAPP_CCLIENT}
    ${SOURCES_LAPP_CSERVER}
    CACHE INTERNAL ""
)

# Collect include directories of layer from its components.
set(INCLUDE_DIRS_LAPP
    ${INCLUDE_DIRS_LAPP_CAPP}
    ${INCLUDE_DIRS_LAPP_CSTARTUP}
    ${INCLUDE_DIRS_LAPP_CCLIENT}
    ${INCLUDE_DIRS_LAPP_CSERVER}
    CACHE INTERNAL ""
)
