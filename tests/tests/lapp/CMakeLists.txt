# Define test suites, both will have client and server running in the same executable.
define_test_suite(test_lapp_dbus)
define_test_suite(test_lapp_someip)

# Link libraries for test suite, one for DBus binding and the other one for SomeIP binding.
target_link_libraries(test_lapp_dbus PRIVATE capicpp_core_proxy capicpp_core_skel)
target_link_libraries(test_lapp_someip PRIVATE capicpp_core_proxy capicpp_core_skel)

# Set proper environment variables for test suite that uses DBus binding.
string(CONCAT ENVIRONMENT_STR
    "COMMONAPI_CONFIG=./dbus/commonapi.ini;"
    "COMMONAPI_DBUS_CONFIG=./dbus/commonapi-dbus.ini;"
    "DBUS_SESSION_BUS_ADDRESS=unix:path=/tmp/dbus-commonapi;"
    "DLT_LOG_MODE=4" # Set Diagnostics Log And Trace log mode to DLT_LOG_MODE_DROPPED by default.
)
set_tests_properties(test_lapp_dbus PROPERTIES
    ENVIRONMENT "${ENVIRONMENT_STR}"
    WORKING_DIRECTORY "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}"
)

# Set proper environment variables for test suite that uses SomeIP binding.
string(CONCAT ENVIRONMENT_STR
    "COMMONAPI_CONFIG=./someip/commonapi.ini;"
    "COMMONAPI_SOMEIP_CONFIG=./someip/commonapi-someip.ini;"
    "VSOMEIP_CONFIGURATION=./someip/vsomeip.json;"
    "DLT_LOG_MODE=4" # Set Diagnostics Log And Trace log mode to DLT_LOG_MODE_DROPPED by default.
)
set_tests_properties(test_lapp_someip PROPERTIES
    ENVIRONMENT "${ENVIRONMENT_STR}"
    WORKING_DIRECTORY "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}"
)

## Code Under Test sources and includes ################################################################################
foreach_target(TARGETS test_lapp_dbus test_lapp_someip FN target_sources 
    PRIVATE ${SOURCES_LAPP_CCLIENT} ${SOURCES_LAPP_CSERVER}
)

foreach_target(TARGETS test_lapp_dbus test_lapp_someip FN target_include_directories 
    PRIVATE ${INCLUDE_DIRS_LAPP_CCLIENT} ${INCLUDE_DIRS_LAPP_CSERVER}
)

## Test sources and includes ###########################################################################################
foreach_target(TARGETS test_lapp_dbus test_lapp_someip FN target_sources 
    PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/test_lapp.cpp"
)

foreach_target(TARGETS test_lapp_dbus test_lapp_someip FN target_include_directories 
    PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}"
)
