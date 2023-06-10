cmake_minimum_required(VERSION 3.0.0)

include(CTest)
include(GoogleTest)
enable_testing()

# Include support to show the test scenarios in the IDE
include(FetchContent)
FetchContent_Declare(
 googletest
 URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

message(STATUS "Adding tests")
set(TEST_SOURCES
    src/tests/tests/example_unittest.cpp
    src/tests/tests/hasher_unittest.cpp
    src/tests/tests/map_unittest.cpp
    ${SOURCES})
set(TEST_LIBRARIES
    GTest::gmock GTest::gtest GTest::gmock_main GTest::gtest_main
    ${LIBRARIES})

message(STATUS "Test sources: ${TEST_SOURCES}")
message(STATUS "Test libraries: ${TEST_LIBRARIES}")
add_executable(tester ${TEST_SOURCES})

message(STATUS "Adding libraries")
find_package(GTest CONFIG REQUIRED)
target_include_directories(tester PRIVATE src/lib)
target_link_libraries(tester PRIVATE ${TEST_LIBRARIES})

message(STATUS "Setting CTest")
gtest_discover_tests(tester)