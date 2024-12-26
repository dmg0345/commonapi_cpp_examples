# Builds both GoogleTest and GoogleMock, making them available as targets, based on:
#     - https://google.github.io/googletest/quickstart-cmake.html

# Fetch contents if not already present.
git_shallow_clone(
    googletest
    "https://github.com/google/googletest.git"
    "v1.14.0"
    "${CMAKE_CURRENT_SOURCE_DIR}/googletest"
)

# Configure GoogleTest and GoogleMock and build them.
set(BUILD_GMOCK "ON")
set(INSTALL_GTEST "OFF")
set(GTEST_HAS_ABSL "OFF")
set(gmock_build_tests "OFF")
set(gtest_force_shared_crt "OFF")
set(gtest_build_tests "OFF")
set(gtest_build_samples "OFF")
set(gtest_disable_pthreads "OFF")
set(gtest_hide_internal_symbols "OFF")
add_subdirectory("googletest")
