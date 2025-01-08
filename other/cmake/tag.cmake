########################################################################################################################
# This file tags all the application, library and test files with data such as the project author and timestamps.
########################################################################################################################

# Collect all '.fidl', '.cpp', '.fdepl' and '.hpp' files from relevant folders for tagging.
file(GLOB_RECURSE PROJECT_SOURCE_FILES
    "${PROJECT_ROOT_DIR}/src/*.cpp"
    "${PROJECT_ROOT_DIR}/src/*.hpp"
    "${PROJECT_ROOT_DIR}/src/*.fidl"
    "${PROJECT_ROOT_DIR}/src/*.fdepl"
    "${PROJECT_ROOT_DIR}/tests/tests/*.cpp"
    "${PROJECT_ROOT_DIR}/tests/tests/*.hpp"
)

# Check if tagging files.
if(${CFG_TAG} STREQUAL "ON")
    # Print a summary of relevant variables for tagging.
    message(STATUS "########## Relevant Tagging Values ######################")
    message(STATUS "PROJECT_AUTHOR: '${PROJECT_AUTHOR}'")
    message(STATUS "PROJECT_CONTACT: '${PROJECT_CONTACT}'")
    message(STATUS "PROJECT_BUILD_TIMESTAMP_UTC: '${PROJECT_BUILD_TIMESTAMP_UTC}'")
    message(STATUS "PROJECT_VERSION: '${PROJECT_VERSION}'")
    message(STATUS "#########################################################")
    # Loop each file in the project source files and tag it.
    foreach(PROJECT_SOURCE_FILE ${PROJECT_SOURCE_FILES})
        # Fetch the filename for the current file.
        get_filename_component(PROJECT_FILENAME ${PROJECT_SOURCE_FILE} NAME)
        # Replace tags in the file with known values.
        message(STATUS "Tagging '${PROJECT_SOURCE_FILE}' if not already tagged...")
        configure_file("${PROJECT_SOURCE_FILE}" "${PROJECT_SOURCE_FILE}")
    endforeach()
elseif(${CFG_TAG} STREQUAL "RESTORE")
    # Loop each file in the project source files and extract all the lines and restore tagging placeholders.
    foreach(PROJECT_SOURCE_FILE ${PROJECT_SOURCE_FILES})
        # Read all lines of file and erase its contents, handling lines that end in backslash.
        file(STRINGS "${PROJECT_SOURCE_FILE}" LINES NEWLINE_CONSUME ENCODING UTF-8)
        string(REGEX REPLACE "\\\\\n" "\\\\\\\\ \n" LINES "${LINES}") # Handle lines that end in backslash.
        string(REGEX REPLACE "\n" ";" LINES "${LINES}") # Convert contents to to CMake list.
        list(LENGTH LINES LINES_LENGTH)
        math(EXPR LINES_LAST_INDEX "${LINES_LENGTH}-1")
        # Empty contents of file, afterwards
        file(WRITE "${PROJECT_SOURCE_FILE}" "")
        # Loop all lines, performing replacements where necessary.
        foreach(LINE_INDEX RANGE ${LINES_LAST_INDEX})
            list(GET LINES ${LINE_INDEX} LINE)
            # Perform tag restoration for the first ten lines of the files, where the template is.
            if(${LINE_INDEX} LESS 10)
                string(REGEX REPLACE "^.*@author.*$"    " * @author      \${PROJECT_AUTHOR} (\${PROJECT_CONTACT})" LINE "${LINE}")
                string(REGEX REPLACE "^.*@date.*$"      " * @date        \${PROJECT_BUILD_TIMESTAMP_UTC}" LINE "${LINE}")
                string(REGEX REPLACE "^.*@version.*$"   " * @version     \${PROJECT_VERSION}" LINE "${LINE}")
                string(REGEX REPLACE "^.*@copyright.*$" " * @copyright   \${PROJECT_COPYRIGHT}" LINE "${LINE}")
            endif()
            # Restore lines that end in backslash to original, and store it to file.
            string(REGEX REPLACE "\\\\\\\\ $" "\\\\" LINE "${LINE}")
            file(APPEND "${PROJECT_SOURCE_FILE}" "${LINE}")
            # Add line ending except for the last line.
            if (NOT (${LINE_INDEX} EQUAL ${LINES_LAST_INDEX}))
                file(APPEND "${PROJECT_SOURCE_FILE}" "\n")
            endif()
        endforeach()
         message(STATUS "Untagging '${PROJECT_SOURCE_FILE}', if not already untagged...")
    endforeach()
else()
    message(FATAL_ERROR "CFG_TAG value '${CFG_TAG}' is not a valid value.")
endif()
