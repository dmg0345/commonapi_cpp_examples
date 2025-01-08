# Link libraries to client.
target_link_libraries(capicpp_client PRIVATE capicpp_core_proxy)
# Provide compile definition to identify a client target in the code.
target_compile_definitions(capicpp_client PRIVATE "CAPICPP_CLIENT")
# Set RUNPATH in the executable.
set_target_properties(capicpp_client PROPERTIES INSTALL_RPATH "$ORIGIN;$ORIGIN/core")

# Link libraries to server.
target_link_libraries(capicpp_server PRIVATE capicpp_core_skel)
# Provide compile definition to identify a server target in the code.
target_compile_definitions(capicpp_server PRIVATE "CAPICPP_SERVER")
# Set RUNPATH in the executable.
set_target_properties(capicpp_server PROPERTIES INSTALL_RPATH "$ORIGIN;$ORIGIN/core")

## Sources #############################################################################################################
# Collect source files of component relevant to a client and add them to relevant targets.
set(SOURCES_LUTILS_CCAPI_CLIENT
    "${CMAKE_CURRENT_SOURCE_DIR}/runtime.cpp"
)
target_sources(capicpp_client PRIVATE ${SOURCES_LUTILS_CCAPI_CLIENT})

# Collect source files of component relevant to a server and add them to relevant targets.
set(SOURCES_LUTILS_CCAPI_SERVER
    "${CMAKE_CURRENT_SOURCE_DIR}/runtime.cpp"
)
target_sources(capicpp_server PRIVATE ${SOURCES_LUTILS_CCAPI_SERVER})

# Collect source files of component.
set(SOURCES_LUTILS_CCAPI
    ${SOURCES_LUTILS_CCAPI_CLIENT}
    ${SOURCES_LUTILS_CCAPI_SERVER}
    CACHE INTERNAL ""
)

## Includes ############################################################################################################
# Collect include directories of component and add them to relevant targets.
set(INCLUDE_DIRS_LUTILS_CCAPI
    "${CMAKE_CURRENT_SOURCE_DIR}/inc"
    CACHE INTERNAL ""
)
foreach_target(TARGETS capicpp_client capicpp_server FN target_include_directories PRIVATE ${INCLUDE_DIRS_LUTILS_CCAPI})
