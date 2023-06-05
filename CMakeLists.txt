cmake_minimum_required(VERSION 3.0.0)
project(cpp_hasher VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(main ${PROJECT_NAME})
include(CTest)
enable_testing()

set(CMAKE_TOOLCHAIN_FILE /opt/microsoft/vcpkg/scripts/buildsystems/vcpkg.cmake CACHE STRING "Vcpkg toolchain file")
set(CMAKE_PREFIX_PATH /opt/microsoft/vcpkg/installed/x64-linux/share)
add_executable(main src/main.cpp)

find_package(fmt CONFIG REQUIRED)
target_link_libraries(main PRIVATE fmt::fmt)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
