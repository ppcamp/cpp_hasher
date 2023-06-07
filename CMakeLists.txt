cmake_minimum_required(VERSION 3.0.0)
message(NOTICE "CMAKE_VERSION: ${CMAKE_VERSION}")

project(cpp_hasher VERSION 0.1.0)
message(NOTICE "PROJECT_NAME: ${PROJECT_NAME}")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
message(NOTICE "CMAKE_CXX_STANDARD: ${CMAKE_CXX_STANDARD}")

set(main ${PROJECT_NAME})
set(LIBRARIES fmt::fmt)

set(SOURCES
    src/lib/hash/hasher.cpp
    CACHE INTERNAL "")
message(NOTICE "SOURCES: ${SOURCES}")

set(CMAKE_TOOLCHAIN_FILE /opt/microsoft/vcpkg/scripts/buildsystems/vcpkg.cmake CACHE STRING "Vcpkg toolchain file")
set(CMAKE_PREFIX_PATH ./vcpkg_installed/x64-linux/share)
message(NOTICE "CMAKE_PREFIX_PATH: ${CMAKE_PREFIX_PATH}")

add_executable(main src/main.cpp ${SOURCES})

message(STATUS "Adding libraries")
target_include_directories(main PRIVATE src/lib)
find_package(fmt CONFIG REQUIRED)
target_link_libraries(main PRIVATE ${LIBRARIES})

message(STATUS "Setting up tests")
include(CTest)
include(GoogleTest)
enable_testing()
include(src/tests/CMakeLists.txt)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
