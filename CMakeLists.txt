cmake_minimum_required(VERSION 3.0.0)
project(cpp_hasher VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(main ${PROJECT_NAME})

include(CTest)
enable_testing()

set(SOURCES src/lib/hash/hasher.cpp)

message(NOTICE "SOURCES: ${SOURCES}")

set(CMAKE_TOOLCHAIN_FILE /opt/microsoft/vcpkg/scripts/buildsystems/vcpkg.cmake CACHE STRING "Vcpkg toolchain file")
set(CMAKE_PREFIX_PATH /opt/microsoft/vcpkg/installed/x64-linux/share)

add_executable(main src/main.cpp ${SOURCES})
add_executable(tester src/tests/test.cpp ${SOURCES})
message(STATUS "Added executable main")

target_include_directories(main PRIVATE src/lib)
target_include_directories(tester PRIVATE src/lib)

find_package(fmt CONFIG REQUIRED)
target_link_libraries(main PRIVATE fmt::fmt)
target_link_libraries(tester PRIVATE fmt::fmt)

add_test(TestSomething tester)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
