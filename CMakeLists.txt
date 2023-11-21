CMAKE_MINIMUM_REQUIRED(VERSION 3.2)

project(overall-tests)

ADD_SUBDIRECTORY(googletest)

ADD_EXECUTABLE(test
    test.cpp
    MainMenu/menu.cpp
    Credits/credits.cpp
    Settings/settings.cpp
)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)