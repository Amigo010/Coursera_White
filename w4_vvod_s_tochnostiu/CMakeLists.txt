file(COPY input.txt
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_executable(main main.cpp)