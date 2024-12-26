# Create application target, and build it in the next steps.
add_executable(app)
# Install target configuration.
install(TARGETS app
        RUNTIME DESTINATION "${CMAKE_INSTALL_RUNTIMEDIR}")

## Include Third Party libraries #######################################################################################
add_subdirectory("third_party")

## Include utils #######################################################################################################
add_subdirectory("utils")

## Include application #################################################################################################
add_subdirectory("app")
