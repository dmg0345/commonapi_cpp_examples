########################################################################################################################
# This file provides versioning information, including Git commit and similar values if in a repository.
########################################################################################################################

## Project Versioning ##################################################################################################
set(PROJECT_AUTHOR "Diego Martínez García")
set(PROJECT_CONTACT "dmg0345@gmail.com")
set(PROJECT_URL "https://github.com/dmg0345/commonapi_cpp_examples")
set(PROJECT_DESCRIPTION "Common API C++ Examples")
set(PROJECT_COPYRIGHT "github.com/dmg0345/commonapi_cpp_examples/blob/master/LICENSE")
set(PROJECT_VERSION_MAJOR "0")
set(PROJECT_VERSION_MINOR "0")
set(PROJECT_VERSION_PATCH "3")
set(PROJECT_VERSION "${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}")
string(TIMESTAMP PROJECT_BUILD_TIMESTAMP_UTC "%d-%m-%Y %H:%M:%S (UTC)" UTC)

## Git Versioning ######################################################################################################
# Run Git command to fetch results.
execute_process(COMMAND git rev-parse HEAD
                OUTPUT_VARIABLE PROJECT_VCS_HASH
                ERROR_QUIET
                OUTPUT_STRIP_TRAILING_WHITESPACE
                WORKING_DIRECTORY "${PROJECT_ROOT_DIR}")

if ("${PROJECT_VCS_HASH}" STREQUAL "")
    # Not a git repository (e.g. zipped file)
    set(PROJECT_VCS_HASH "N/A")
    set(PROJECT_VCS_TAG "N/A")
    set(PROJECT_VCS_BRANCH "N/A")
else()
    # Append plus sign if there are working changes.
    execute_process(COMMAND git status --porcelain=v1 --ignore-submodules
                    OUTPUT_VARIABLE GIT_OUTPUT
                    ERROR_QUIET
                    OUTPUT_STRIP_TRAILING_WHITESPACE
                    WORKING_DIRECTORY "${PROJECT_ROOT_DIR}")
    if (NOT "${GIT_OUTPUT}" STREQUAL "")
        set(PROJECT_VCS_HASH "+++${PROJECT_VCS_HASH}+++")
    endif()

    # Get latest tag in branch.
    execute_process(COMMAND git describe --tags
                    OUTPUT_VARIABLE PROJECT_VCS_TAG
                    ERROR_QUIET
                    OUTPUT_STRIP_TRAILING_WHITESPACE
                    WORKING_DIRECTORY "${PROJECT_ROOT_DIR}")

    # Get branch name.
    execute_process(COMMAND git branch --show-current
                    OUTPUT_VARIABLE PROJECT_VCS_BRANCH
                    ERROR_QUIET
                    OUTPUT_STRIP_TRAILING_WHITESPACE
                    WORKING_DIRECTORY "${PROJECT_ROOT_DIR}")
endif()

## Version File ########################################################################################################
# Create versioning file contents.
set(VERSION_INFO "/**
 ***********************************************************************************************************************
 * @file        info.hpp
 * @author      ${PROJECT_AUTHOR} (${PROJECT_CONTACT})
 * @date        ${PROJECT_BUILD_TIMESTAMP_UTC}
 * @version     ${PROJECT_VERSION}
 * @copyright   ${PROJECT_COPYRIGHT}
 ***********************************************************************************************************************
 */

// clang-format off
// THIS FILE IS AUTO-GENERATED, IF MODIFIED, CHANGES WILL BE OVERWRITTEN.

#ifndef LUTILS_CVERSION_INFO_HPP
#define LUTILS_CVERSION_INFO_HPP

namespace Utils::Version
{

/**
 * @rst
 * ${PROJECT_AUTHOR}
 * @endrst
 */
constexpr const char * const AUTHOR = \"${PROJECT_AUTHOR}\";

/**
 * @rst
 * ${PROJECT_CONTACT}
 * @endrst
 */
constexpr const char * const CONTACT = \"${PROJECT_CONTACT}\";

/**
 * @rst
 * ${PROJECT_URL}
 * @endrst
 */
constexpr const char * const URL = \"${PROJECT_URL}\";

/**
 * @rst
 * ${CMAKE_BUILD_TYPE}
 * @endrst
 */
constexpr const char * const BUILD = \"${CMAKE_BUILD_TYPE}\";

/**
 * @rst
 * ${PROJECT_DESCRIPTION}
 * @endrst
 */
constexpr const char * const DESCRIPTION = \"${PROJECT_DESCRIPTION}\";

/**
 * @rst
 * ${PROJECT_VERSION}
 * @endrst
 */
constexpr const char * const VERSION = \"${PROJECT_VERSION}\";

/**
 * @rst
 * ${PROJECT_VCS_HASH}
 * @endrst
 * @note The hash is enclosed in @e +++ characters if the project was built with uncommited changes.
 */
constexpr const char * const COMMIT_HASH = \"${PROJECT_VCS_HASH}\";

/**
 * @rst
 * ${PROJECT_VCS_TAG}
 * @endrst
 */
constexpr const char * const TAG = \"${PROJECT_VCS_TAG}\";

/**
 * @rst
 * ${PROJECT_VCS_BRANCH}
 * @endrst
 */
constexpr const char * const BRANCH = \"${PROJECT_VCS_BRANCH}\";

/**
 * @rst
 * ${PROJECT_BUILD_TIMESTAMP_UTC}
 * @endrst
 */
constexpr const char * const BUILD_TIMESTAMP_UTC = \"${PROJECT_BUILD_TIMESTAMP_UTC}\";

}

#endif /* LUTILS_CVERSION_INFO_HPP */

/******************************************************************************************************END OF FILE*****/")

# Store version contents to file.
set(PROJECT_VERSION_FILE_LOCATION "${PROJECT_ROOT_DIR}/src/utils/version/inc/utils/version/priv/info.hpp")
message(STATUS "Storing project version file list at '${PROJECT_VERSION_FILE_LOCATION}'...")
file(WRITE "${PROJECT_VERSION_FILE_LOCATION}" "${VERSION_INFO}")
configure_file("${PROJECT_VERSION_FILE_LOCATION}" "${PROJECT_VERSION_FILE_LOCATION}")
