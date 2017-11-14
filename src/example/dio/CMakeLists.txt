
set(TARGET_NAME DIOExample)
set(DIO_EX_SRC dio_main.cpp)
add_executable(${TARGET_NAME} ${DIO_EX_SRC})
target_link_libraries(${TARGET_NAME} wpi-cpp)

SCP_DEPLOY(${TARGET_NAME})
