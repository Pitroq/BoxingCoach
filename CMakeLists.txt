cmake_minimum_required(VERSION 3.20.0)
project(BoxingCoach)

set(CMAKE_CXX_STANDARD 23)

set(SOURCES 
    src/main.cpp
    src/boxing_sequence_generator.cpp
)

add_executable(
    ${PROJECT_NAME}
    ${SOURCES}
)

target_include_directories(
    ${PROJECT_NAME}
    PRIVATE 
    ${PROJECT_SOURCE_DIR}/include
)
add_subdirectory(test)
add_subdirectory(lib/googletest)

target_link_libraries(${PROJECT_NAME} PRIVATE winmm)
file(COPY ${CMAKE_SOURCE_DIR}/audio/ DESTINATION ${CMAKE_BINARY_DIR}/audio)