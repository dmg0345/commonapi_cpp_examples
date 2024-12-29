## Common API C++ Runtimes and Libraries ###############################################################################
# Link Common API C++ runtimes and libraries to client and server targets.
foreach_target(TARGETS capicpp_client capicpp_server FN target_link_libraries
    PRIVATE dbus-1
    PRIVATE vsomeip3
    PRIVATE CommonAPI
    PRIVATE CommonAPI-DBus
    PRIVATE CommonAPI-SomeIP
)

# Add include directories to Common API C++ runtimes and libraries to client and server targets.
foreach_target(TARGETS capicpp_client capicpp_server FN target_include_directories PRIVATE
    ${DBUS1_INTERFACE_INCLUDE_DIRS}
    ${VSOMEIP3_INTERFACE_INCLUDE_DIRS}
    ${COMMONAPI_INTERFACE_INCLUDE_DIRS}
    ${COMMONAPI_DBUS_INTERFACE_INCLUDE_DIRS}
    ${COMMONAPI_SOMEIP_INTERFACE_INCLUDE_DIRS}
)

# Provide different compile definitions for each target so that they are identifiable in the code.
target_compile_definitions(capicpp_client PRIVATE "CAPICPP_CLIENT")
target_compile_definitions(capicpp_server PRIVATE "CAPICPP_SERVER")

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
