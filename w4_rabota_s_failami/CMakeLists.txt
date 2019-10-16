file(COPY input.txt
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_executable(main_1 main_1.cpp)
add_executable(main_2 main_2.cpp)