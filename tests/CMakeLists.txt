# @brief Creates a test suite for 'googletest' and adds it to 'ctest', each test suite maps to an executable target.
# @param[in] The name of the test suite to create.
function(define_test_suite TEST_SUITE_NAME)
    # Create executable for the test suite.
    add_executable(${TEST_SUITE_NAME})

    # Link against GoogleTest and GoogleMock.
    target_link_libraries(${TEST_SUITE_NAME} PRIVATE gtest gmock)

    # Add additional test utilities.
    target_sources(${TEST_SUITE_NAME} PRIVATE
        "${PROJECT_ROOT_DIR}/tests/tests/test_utils/test_utils.cpp"
        "${PROJECT_ROOT_DIR}/tests/tests/test_utils/googletest.cpp"
    )

    # Add include directories to the test utilities.
    target_include_directories(${TEST_SUITE_NAME} PRIVATE
        "${PROJECT_ROOT_DIR}/tests/tests/test_utils/inc"
    )

    # Set installation runtime directories.
    install(TARGETS ${TEST_SUITE_NAME} RUNTIME DESTINATION "${CMAKE_INSTALL_RUNTIMEDIR}")

    # If running on CI, then enable XML output on GoogleTest, otherwise use the default standard output.
    if((DEFINED CFG_CI) AND (${CFG_CI}))
        set(TEST_XML_DIR "${PROJECT_ROOT_DIR}/tests/.test_results/")
        target_compile_definitions(${TEST_SUITE_NAME} PRIVATE "GOOGLETEST_JUNIT_XML_OUTPUT=\"${TEST_XML_DIR}\"")
    endif()

    # Add sanitizers to the compiled tests.
    #   - fsanitize=leak: LeakSanitizer, a memory leak detector.
    #   - fsanitize=address: AddressSanitizer, a fast memory error detector.
    #   - fsanitize=undefined: UndefinedBehaviorSanitizer, a fast undefined behavior detector.
    # Refer to https://stackoverflow.com/a/50163972 for details on the implementation.
    if(${CFG_TESTS_ENABLE_SANITIZERS} STREQUAL "ON")
        set(TEST_SAN_FLAGS "-fsanitize=leak,address,undefined")
        target_compile_options(${TEST_SUITE_NAME} PRIVATE ${TEST_SAN_FLAGS})
        target_link_libraries(${TEST_SUITE_NAME} PRIVATE ${TEST_SAN_FLAGS})
    endif()

    # Add coverage if enabled.
    if(${CFG_TESTS_ENABLE_COVERAGE} STREQUAL "ON")
        target_link_libraries(${TEST_SUITE_NAME} PRIVATE "gcov")
        target_compile_options(${TEST_SUITE_NAME} PRIVATE "-ftest-coverage" "-fprofile-arcs")
    endif()

    # Ensure main function is disabled in the application.
    target_compile_definitions(${TEST_SUITE_NAME} PRIVATE "DISABLE_MAIN")

    # Add generic components.
    target_sources(${TEST_SUITE_NAME} PRIVATE ${SOURCES_LUTILS})
    target_include_directories(${TEST_SUITE_NAME} PRIVATE ${INCLUDE_DIRS_LUTILS})

    # Add test suite to CTest.
    add_test(NAME ${TEST_SUITE_NAME} COMMAND ${TEST_SUITE_NAME})
endfunction()

## GoogleTest / GoogleMock Test Harness ################################################################################
add_subdirectory("googletest")

## Tests ###############################################################################################################
add_subdirectory("tests")
