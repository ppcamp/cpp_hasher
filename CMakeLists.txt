cmake_minimum_required(VERSION 3.0.0)
message(NOTICE "CMAKE_VERSION: ${CMAKE_VERSION}")

project(cpp_hasher VERSION 0.1.0)
message(NOTICE "PROJECT_NAME: ${PROJECT_NAME}")

set(main ${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
message(NOTICE "CMAKE_CXX_STANDARD: ${CMAKE_CXX_STANDARD}")

set(LIBRARIES
    fmt::fmt
    absl::any absl::log absl::base absl::bits
    CACHE INTERNAL "")
message(NOTICE "LIBRARIES: ${LIBRARIES}")

# set(SOURCES src/lib/map/map.cpp CACHE INTERNAL "")
file(GLOB_RECURSE MATCHED_CPPS src/lib/*/*.cpp)
set(SOURCES ${MATCHED_CPPS} CACHE INTERNAL "")
message(NOTICE "SOURCES: ${SOURCES}")

set(CMAKE_TOOLCHAIN_FILE ./vcpkg/scripts/buildsystems/vcpkg.cmake CACHE STRING "Vcpkg toolchain file")
set(CMAKE_PREFIX_PATH ./vcpkg_installed/x64-linux/share)
message(NOTICE "CMAKE_PREFIX_PATH: ${CMAKE_PREFIX_PATH}")

add_executable(main src/main.cpp ${SOURCES})

message(STATUS "Adding internal libraries")
target_include_directories(main PRIVATE src/lib)

message(STATUS "Finding Packages")
find_package(fmt CONFIG REQUIRED)
find_package(absl CONFIG REQUIRED)

message(STATUS "Adding external libraries")
target_link_libraries(main PRIVATE ${LIBRARIES})

message(STATUS "Setting up tests")
include(CTest)
include(GoogleTest)
enable_testing()
include(src/tests/CMakeLists.txt)

message(STATUS "Setting up benchmarks")
include(src/benchmarks/CMakeLists.txt)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
