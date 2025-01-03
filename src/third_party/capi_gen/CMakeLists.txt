# Create targets for core libraries related to Common API C++.
#   - Core common (header-only or shared) library, required by client and server.
#   - Core proxy header-only library, required by client.
#   - Core stub header-only library, required by server.
#   - Core skeleton header-only library, required by server.
add_library(capicpp_core_common SHARED)
add_library(capicpp_core_proxy INTERFACE)
add_library(capicpp_core_stub INTERFACE)
add_library(capicpp_core_skel INTERFACE)

# Create targets for DBus binding libraries related to Common API C++.
#   - DBus binding common shared library, required by client and server.
#   - DBus binding proxy shared library, required by client.
#   - DBus binding stub shared library, required by server.
add_library(capicpp_dbus_common SHARED)
add_library(capicpp_dbus_proxy SHARED)
add_library(capicpp_dbus_stub SHARED)

# Create targets for SomeIP binding libraries related to Common API C++.
#   - SomeIP binding common shared library, required by client and server.
#   - SomeIP binding proxy shared library, required by client.
#   - SomeIP binding stub shared library, required by server.
add_library(capicpp_someip_common SHARED)
add_library(capicpp_someip_proxy SHARED)
add_library(capicpp_someip_stub SHARED)

## Core Common Library #################################################################################################
# Collect relevant source files and add them to the library.
set(SOURCES_CORE_COMMON
    "${CMAKE_CURRENT_SOURCE_DIR}/fidl/gen/common/app/v0/commonapi/app/App.cpp"
)
target_sources(capicpp_core_common PRIVATE ${SOURCES_CORE_COMMON})

# Collect relevant include directories and add them to the library.
set(INCLUDE_DIRS_CORE_COMMON
    "${CMAKE_CURRENT_SOURCE_DIR}/fidl/gen/common/app"
)
target_include_directories(capicpp_core_common SYSTEM PUBLIC ${INCLUDE_DIRS_CORE_COMMON})

# Link relevant libraries.
target_link_libraries(capicpp_core_common
    PUBLIC CommonAPI
)

# Set installation directories.
install(TARGETS capicpp_core_common
    LIBRARY DESTINATION "${CMAKE_INSTALL_RUNTIMEDIR}/core"
)

# Set additional target properties.
set_target_properties(capicpp_core_common PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/core"
)

## Core Proxy Library ##################################################################################################
# Collect relevant include directories and add them to the library.
set(INCLUDE_DIRS_CORE_PROXY
    "${CMAKE_CURRENT_SOURCE_DIR}/fidl/gen/proxy/app"
)
target_include_directories(capicpp_core_proxy SYSTEM INTERFACE ${INCLUDE_DIRS_CORE_PROXY})

# Link relevant libraries.
target_link_libraries(capicpp_core_proxy
    INTERFACE capicpp_core_common
)

# Set installation directories.
install(TARGETS capicpp_core_proxy
    LIBRARY DESTINATION "${CMAKE_INSTALL_RUNTIMEDIR}/core"
)

# Set additional target properties.
set_target_properties(capicpp_core_proxy PROPERTIES
    INSTALL_RPATH "$ORIGIN"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/core"
)

## Core Stub Library ###################################################################################################
# Collect relevant include directories and add them to the library.
set(INCLUDE_DIRS_CORE_STUB
    "${CMAKE_CURRENT_SOURCE_DIR}/fidl/gen/stub/app"
)
target_include_directories(capicpp_core_stub SYSTEM INTERFACE ${INCLUDE_DIRS_CORE_STUB})

# Link relevant libraries.
target_link_libraries(capicpp_core_stub
    INTERFACE capicpp_core_common
)

# Set installation directories.
install(TARGETS capicpp_core_stub
    LIBRARY DESTINATION "${CMAKE_INSTALL_RUNTIMEDIR}/core"
)

# Set additional target properties.
set_target_properties(capicpp_core_stub PROPERTIES
    INSTALL_RPATH "$ORIGIN"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/core"
)

## Core Stub Skeletons Library #########################################################################################
# Collect relevant include directories and add them to the library.
set(INCLUDE_DIRS_CORE_SKEL
    "${CMAKE_CURRENT_SOURCE_DIR}/fidl/gen/skel/app"
)
target_include_directories(capicpp_core_skel SYSTEM INTERFACE ${INCLUDE_DIRS_CORE_SKEL})

# Link relevant libraries.
target_link_libraries(capicpp_core_skel
    INTERFACE capicpp_core_stub
)

# Set installation directories.
install(TARGETS capicpp_core_skel
    LIBRARY DESTINATION "${CMAKE_INSTALL_RUNTIMEDIR}/core"
)

# Set additional target properties.
set_target_properties(capicpp_core_skel PROPERTIES
    INSTALL_RPATH "$ORIGIN"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/core"
)

## DBus Common Library #################################################################################################
# Collect relevant source files and add them to the library.
set(SOURCES_DBUS_COMMON
    "${CMAKE_CURRENT_SOURCE_DIR}/dbus/gen/common/app/v0/commonapi/app/AppDBusDeployment.cpp"
)
target_sources(capicpp_dbus_common PRIVATE ${SOURCES_DBUS_COMMON})

# Collect relevant include directories and add them to the library.
set(INCLUDE_DIRS_DBUS_COMMON
    "${CMAKE_CURRENT_SOURCE_DIR}/dbus/gen/common/app"
)
target_include_directories(capicpp_dbus_common SYSTEM PUBLIC ${INCLUDE_DIRS_DBUS_COMMON})

# Link relevant libraries.
target_link_libraries(capicpp_dbus_common
    PUBLIC capicpp_core_common CommonAPI-DBus dbus-1
)

# Set installation directories.
install(TARGETS capicpp_dbus_common
    LIBRARY DESTINATION "${CMAKE_INSTALL_RUNTIMEDIR}/dbus"
)

# Set additional target properties.
set_target_properties(capicpp_dbus_common PROPERTIES
    INSTALL_RPATH "$ORIGIN;$ORIGIN/../core"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/dbus"
)

# Install additional files.
install(FILES
    "${CMAKE_CURRENT_SOURCE_DIR}/dbus/commonapi.ini"
    "${CMAKE_CURRENT_SOURCE_DIR}/dbus/commonapi-dbus.ini"
    DESTINATION "${CMAKE_INSTALL_RUNTIMEDIR}/dbus"
)

# Generate additional files on build.
configure_file("${CMAKE_CURRENT_SOURCE_DIR}/dbus/commonapi.ini" "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/dbus/commonapi.ini" COPYONLY)
configure_file("${CMAKE_CURRENT_SOURCE_DIR}/dbus/commonapi-dbus.ini" "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/dbus/commonapi-dbus.ini" COPYONLY)

## DBus Proxy Library ##################################################################################################
# Collect relevant source files and add them to the library.
set(SOURCES_DBUS_PROXY
    "${CMAKE_CURRENT_SOURCE_DIR}/dbus/gen/proxy/app/v0/commonapi/app/AppDBusProxy.cpp"
)
target_sources(capicpp_dbus_proxy PRIVATE ${SOURCES_DBUS_PROXY})

# Collect relevant include directories and add them to the library.
set(INCLUDE_DIRS_DBUS_PROXY
    "${CMAKE_CURRENT_SOURCE_DIR}/dbus/gen/proxy/app"
)
target_include_directories(capicpp_dbus_proxy SYSTEM PUBLIC ${INCLUDE_DIRS_DBUS_PROXY})

# Link relevant libraries.
target_link_libraries(capicpp_dbus_proxy
    PRIVATE capicpp_dbus_common capicpp_core_proxy
)

# Set additional target properties.
set_target_properties(capicpp_dbus_proxy PROPERTIES
    INSTALL_RPATH "$ORIGIN;$ORIGIN/../core"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/dbus"
)

# Set installation directories.
install(TARGETS capicpp_dbus_proxy
    LIBRARY DESTINATION "${CMAKE_INSTALL_RUNTIMEDIR}/dbus"
)

## DBus Stub Library ###################################################################################################
# Collect relevant source files and add them to the library.
set(SOURCES_DBUS_STUB
    "${CMAKE_CURRENT_SOURCE_DIR}/dbus/gen/stub/app/v0/commonapi/app/AppDBusStubAdapter.cpp"
)
target_sources(capicpp_dbus_stub PRIVATE ${SOURCES_DBUS_STUB})

# Collect relevant include directories and add them to the library.
set(INCLUDE_DIRS_DBUS_STUB
    "${CMAKE_CURRENT_SOURCE_DIR}/dbus/gen/stub/app"
)
target_include_directories(capicpp_dbus_stub SYSTEM PUBLIC ${INCLUDE_DIRS_DBUS_STUB})

# Link relevant libraries.
target_link_libraries(capicpp_dbus_stub
    PRIVATE capicpp_dbus_common capicpp_core_stub
)

# Set additional target properties.
set_target_properties(capicpp_dbus_stub PROPERTIES
    INSTALL_RPATH "$ORIGIN;$ORIGIN/../core"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/dbus"
)

# Set installation directories.
install(TARGETS capicpp_dbus_stub
    LIBRARY DESTINATION "${CMAKE_INSTALL_RUNTIMEDIR}/dbus"
)

## SomeIP Common Library ###############################################################################################
# Collect relevant source files and add them to the library.
set(SOURCES_SOMEIP_COMMON
    "${CMAKE_CURRENT_SOURCE_DIR}/someip/gen/common/app/v0/commonapi/app/AppSomeIPDeployment.cpp"
)
target_sources(capicpp_someip_common PRIVATE ${SOURCES_SOMEIP_COMMON})

# Collect relevant include directories and add them to the library.
set(INCLUDE_DIRS_SOMEIP_COMMON
    "${CMAKE_CURRENT_SOURCE_DIR}/someip/gen/common/app"
)
target_include_directories(capicpp_someip_common SYSTEM PUBLIC ${INCLUDE_DIRS_SOMEIP_COMMON})

# Link relevant libraries.
target_link_libraries(capicpp_someip_common
    PUBLIC capicpp_core_common CommonAPI-SomeIP vsomeip3
)

# Set installation directories.
install(TARGETS capicpp_someip_common
    LIBRARY DESTINATION "${CMAKE_INSTALL_RUNTIMEDIR}/someip"
)

# Set additional target properties.
set_target_properties(capicpp_someip_common PROPERTIES
    INSTALL_RPATH "$ORIGIN;$ORIGIN/../core"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/someip"
)

# Install additional files.
install(FILES
    "${CMAKE_CURRENT_SOURCE_DIR}/someip/commonapi.ini"
    "${CMAKE_CURRENT_SOURCE_DIR}/someip/commonapi-someip.ini"
    "${CMAKE_CURRENT_SOURCE_DIR}/someip/vsomeip.json"
    DESTINATION "${CMAKE_INSTALL_RUNTIMEDIR}/someip"
)

# Generate additional files on build.
configure_file("${CMAKE_CURRENT_SOURCE_DIR}/someip/commonapi.ini" "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/someip/commonapi.ini" COPYONLY)
configure_file("${CMAKE_CURRENT_SOURCE_DIR}/someip/commonapi-someip.ini" "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/someip/commonapi-someip.ini" COPYONLY)
configure_file("${CMAKE_CURRENT_SOURCE_DIR}/someip/vsomeip.json" "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/someip/vsomeip.json" COPYONLY)

## SomeIP Proxy Library ################################################################################################
# Collect relevant source files and add them to the library.
set(SOURCES_SOMEIP_PROXY
    "${CMAKE_CURRENT_SOURCE_DIR}/someip/gen/proxy/app/v0/commonapi/app/AppSomeIPProxy.cpp"
)
target_sources(capicpp_someip_proxy PRIVATE ${SOURCES_SOMEIP_PROXY})

# Collect relevant include directories and add them to the library.
set(INCLUDE_DIRS_SOMEIP_PROXY
    "${CMAKE_CURRENT_SOURCE_DIR}/someip/gen/proxy/app"
)
target_include_directories(capicpp_someip_proxy SYSTEM PUBLIC ${INCLUDE_DIRS_SOMEIP_PROXY})

# Link relevant libraries.
target_link_libraries(capicpp_someip_proxy
    PRIVATE capicpp_someip_common capicpp_core_proxy
)

# Set installation directories.
install(TARGETS capicpp_someip_proxy
    LIBRARY DESTINATION "${CMAKE_INSTALL_RUNTIMEDIR}/someip"
)

# Set additional target properties.
set_target_properties(capicpp_someip_proxy PROPERTIES
    INSTALL_RPATH "$ORIGIN;$ORIGIN/../core"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/someip"
)

## SomeIP Stub Library #################################################################################################
# Collect relevant source files and add them to the library.
set(SOURCES_SOMEIP_STUB
    "${CMAKE_CURRENT_SOURCE_DIR}/someip/gen/stub/app/v0/commonapi/app/AppSomeIPStubAdapter.cpp"
)
target_sources(capicpp_someip_stub PRIVATE ${SOURCES_SOMEIP_STUB})

# Collect relevant include directories and add them to the library.
set(INCLUDE_DIRS_SOMEIP_STUB
    "${CMAKE_CURRENT_SOURCE_DIR}/someip/gen/stub/app"
)
target_include_directories(capicpp_someip_stub SYSTEM PUBLIC ${INCLUDE_DIRS_SOMEIP_STUB})

# Link relevant libraries.
target_link_libraries(capicpp_someip_stub
    PRIVATE capicpp_someip_common capicpp_core_stub
)

# Set installation directories.
install(TARGETS capicpp_someip_stub
    LIBRARY DESTINATION "${CMAKE_INSTALL_RUNTIMEDIR}/someip"
)

# Set additional target properties.
set_target_properties(capicpp_someip_stub PROPERTIES
    INSTALL_RPATH "$ORIGIN;$ORIGIN/../core"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/someip"
)
