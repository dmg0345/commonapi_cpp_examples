# Define test suites.
define_test_suite(test_lapp_cstartup_client)
define_test_suite(test_lapp_cstartup_server)

# Set compile definitions for each.
target_compile_definitions(test_lapp_cstartup_client PRIVATE "-DCAPICPP_CLIENT")
target_compile_definitions(test_lapp_cstartup_server PRIVATE "-DCAPICPP_SERVER")

## Code Under Test sources and includes ################################################################################
foreach_target(TARGETS test_lapp_cstartup_client test_lapp_cstartup_server FN target_sources PRIVATE ${SOURCES_LAPP_CSTARTUP})
foreach_target(TARGETS test_lapp_cstartup_client test_lapp_cstartup_server FN target_include_directories PRIVATE ${INCLUDE_DIRS_LAPP_CSTARTUP})

## Test sources and includes ###########################################################################################
foreach_target(TARGETS test_lapp_cstartup_client test_lapp_cstartup_server FN target_sources PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/test_lapp_cstartup.cpp")
foreach_target(TARGETS test_lapp_cstartup_client test_lapp_cstartup_server FN target_include_directories PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
