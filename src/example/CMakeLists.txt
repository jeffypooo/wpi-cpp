
message(STATUS "Configuring examples...")

set(EXAMPLE_SRC main.cpp)
add_executable(SPIExample ${EXAMPLE_SRC})
target_link_libraries(SPIExample rpispi)

# Deploy example to your RPi
if (NOT DEFINED RPI_IP_ADDR)
    message(STATUS "RPI_IP_ADDR not set, deployment will be skipped.")
else()
    message(STATUS "RPi IP = ${RPI_IP_ADDR}. Examples will be deployed to the home directory.")
    add_custom_command(TARGET SPIExample POST_BUILD
            COMMAND scp "$<TARGET_FILE:SPIExample>" pi@${RPI_IP_ADDR}:SPIExample
            COMMENT "Deploying to raspberry pi via scp")
endif ()
