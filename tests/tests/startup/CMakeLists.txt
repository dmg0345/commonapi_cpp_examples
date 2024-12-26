# Define test suite.
define_test_suite(test_startup)

## Code Under Test sources and includes ################################################################################
target_sources(test_startup PRIVATE ${SOURCES_APP_STARTUP})
target_include_directories(test_startup PRIVATE ${INCLUDE_DIRS_APP_STARTUP})

## Test sources and includes ###########################################################################################
target_sources(test_startup PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/test_startup.cpp")
target_include_directories(test_startup PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
