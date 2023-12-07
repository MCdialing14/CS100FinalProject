cmake_minimum_required(VERSION 3.20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/src")
add_subdirectory(googletest)

include_directories(
  ${CMAKE_SOURCE_DIR}/include
  ${CMAKE_SOURCE_DIR}/src  # Include the src directory for sourceFiles
  ${CMAKE_SOURCE_DIR}/test/src/googletest/include/
  ${CMAKE_SOURCE_DIR}/test/src/googlemock/include/
)

set(TEST_FILES ./tester.cpp ./blockTests.cpp ./coordinateTests.cpp ./boardTests.cpp ./blockSpawnerTests.cpp ./blockShifterTests.cpp ./mainMenuTests.cpp ./gameOverTests.cpp)
add_executable(test ${TEST_FILES} ${SOURCE_FILES})

target_link_libraries(test gmock gtest gtest_main sourceFiles)