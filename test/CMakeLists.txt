add_executable(${PROJECT_NAME}Test
    main_test.cpp
    boxing_sequence_generator_test.cpp
    ${PROJECT_SOURCE_DIR}/src/boxing_sequence_generator.cpp
)

target_include_directories(
    ${PROJECT_NAME}Test
    PRIVATE 
    ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(
    ${PROJECT_NAME}Test
    PRIVATE gtest
    gtest_main
)