# Create client and server executable targets.
add_executable(capicpp_client)
add_executable(capicpp_server)

# Install configuration for executable targets.
install(TARGETS capicpp_client capicpp_server RUNTIME DESTINATION "${CMAKE_INSTALL_RUNTIMEDIR}")

## Include third party #################################################################################################
add_subdirectory("third_party")

## Include utils #######################################################################################################
add_subdirectory("utils")

## Include application #################################################################################################
add_subdirectory("app")
