
set(EXAMPLE_SRC main.cpp)
add_executable(SPIExample ${EXAMPLE_SRC})
target_link_libraries(SPIExample rpispi)