cmake_minimum_required(VERSION 3.0.0)

message(STATUS "Test sources: ${TEST_SOURCES}")
message(STATUS "Test libraries: ${TEST_LIBRARIES}")
add_executable(bench ${SOURCES} src/benchmarks/bench.cpp)

message(STATUS "Adding libraries")
target_include_directories(bench PRIVATE src/lib src/benchmarks)
target_link_libraries(bench PRIVATE ${LIBRARIES})