########################################################################################################################
# Generic utilities and functionality for CMake.
########################################################################################################################

# @brief Converts a boolean to integer.
# @param[in] BOOL_VAR The name of the variable with the boolean value.
# @param[out] INT_VAR The name of the variable where the resulting integer will be stored.
# @example bool2int(BOOL_VARIABLE INT_VARIABLE)
function(bool2int BOOL_VAR INT_VAR)
    if(${BOOL_VAR})
        set(${INT_VAR} 1 PARENT_SCOPE)
    else()
        set(${INT_VAR} 0 PARENT_SCOPE)
    endif()
endfunction()

# @brief Downloads a tag/branch in a Git repository to a source directory if it doesn't exist.
# @param[in] IDENTIFIER A name or identifier to the process.
# @param[in] GIT_REPOSITORY The repository to clone.
# @param[in] GIT_TAG The tag or branch to clone.
# @param[in] SOURCE_DIR The directory where to clone the repository.
# @example git_clone(cmocka https://gitlab.com/cmocka/cmocka.git cmocka-1.1.7 "${CMAKE_CURRENT_SOURCE_DIR}/cmocka")
# @note Requires FetchContent API, add ``include(FetchContent)`` in your *CMakeLists* file.
function(git_shallow_clone IDENTIFIER GIT_REPOSITORY GIT_TAG SOURCE_DIR)
    # Check if the directory already exists, in which case, skip it.
    if(EXISTS "${SOURCE_DIR}")
        message(STATUS "Not cloning '${IDENTIFIER}' as source directory '${SOURCE_DIR}' already exists...")
    else()
        message(STATUS "Cloning '${IDENTIFIER}'...")

        # Checkout tag/branch and clone submodules recursively if any, clone with a random string so that
        # there are no conflicts with FindPackage.
        string(RANDOM LENGTH 10 RAND_STRING)
        FetchContent_Declare(
            "${IDENTIFIER}_${RAND_STRING}"
            GIT_REPOSITORY "${GIT_REPOSITORY}"
            GIT_TAG "${GIT_TAG}"
            GIT_SHALLOW ON
            GIT_PROGRESS ON
            GIT_SUBMODULES_RECURSE ON
            SOURCE_DIR "${SOURCE_DIR}"
            EXCLUDE_FROM_ALL
            OVERRIDE_FIND_PACKAGE
        )

        # Populate contents, without running any configure, build steps if presend in the project.
        message(STATUS "Populating '${SOURCE_DIR}' with '${IDENTIFIER}'...")
        FetchContent_Populate("${IDENTIFIER}_${RAND_STRING}")
    endif()
endfunction()

# @brief Calls a specified function on each of the targets provided with the specified arguments.
# @param[in] TARGETS The list of targets on which @p FN will be called.
# @param[in] FN The function that will execute on each target.
# @param[in] ARGN The remaining arguments passed to this function are passed to @p FN verbatim.
# @example foreach_target(TARGETS capicpp_client capicpp_server FN target_sources PRIVATE ${SOURCES_LAPP_CSTARTUP})
# @note Target must be the first positional parameter in @p FN, which is the case for 'target_*' functions.
function(foreach_target)
    set(OPTIONS "")
    set(ONE_VALUE_ARGS FN)
    set(MULTI_VALUE_ARGS TARGETS)
    cmake_parse_arguments(PARSED "${OPTIONS}" "${ONE_VALUE_ARGS}" "${MULTI_VALUE_ARGS}" ${ARGN})

    foreach(TARGET IN LISTS PARSED_TARGETS)
        cmake_language(CALL ${PARSED_FN} ${TARGET} ${PARSED_UNPARSED_ARGUMENTS})
    endforeach()
endfunction()
