CMAKE_MINIMUM_REQUIRED(VERSION 3.2)

project(menu-tests)

ADD_SUBDIRECTORY(googletest)

ADD_EXECUTABLE(test
    test.cpp
    menu.cpp
)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)