# Create client and server targets, and build them in the next steps.
add_executable(capicpp_client)
add_executable(capicpp_server)

# Install target configuration.
install(TARGETS capicpp_client capicpp_server RUNTIME DESTINATION "${CMAKE_INSTALL_RUNTIMEDIR}")

## Include utils #######################################################################################################
add_subdirectory("utils")

## Include application #################################################################################################
add_subdirectory("app")
