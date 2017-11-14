
macro(SCP_DEPLOY FNAME)
    if (NOT DEFINED RPI_IP_ADDR)
        message(STATUS "(${FNAME}): RPI_IP_ADDR not set, deployment will be skipped.")
    else ()
        message(STATUS "${FNAME} will be deployed to RPi at ${RPI_IP_ADDR} (HOME)")
        add_custom_command(
                TARGET "${FNAME}" POST_BUILD
                COMMAND scp "$<TARGET_FILE:${FNAME}>" pi@${RPI_IP_ADDR}:${FNAME}
                COMMENT "Deploying ${FNAME} to raspberry pi via scp")
    endif ()
endmacro()