cmake_minimum_required(VERSION 3.20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/src")
add_subdirectory(googletest)

include_directories(
  ${CMAKE_SOURCE_DIR}/include
  ${CMAKE_SOURCE_DIR}/src  # Include the src directory for simpleLibrary
  ${CMAKE_SOURCE_DIR}/test/src/googletest/include/
  ${CMAKE_SOURCE_DIR}/test/src/googlemock/include/
)

add_executable(runAllTests
  test.cpp 
)

target_link_libraries(runAllTests gmock gtest gtest_main simpleLibrary)