cmake_minimum_required(VERSION 3.14)

project(Brompton)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

# Fetch the content
FetchContent_MakeAvailable(googletest)

enable_testing()

# Add the executable to run the application 
add_executable(
  brompton
  src/bits.cpp
  src/main.cpp
)

# Executable to run the tests 
add_executable(
  brompton_tests
  test/test_bits.cpp
)

# Include the header files directory
target_include_directories(
  brompton
  PRIVATE ${PROJECT_SOURCE_DIR}/include
)

# Include the header files directory for the tests
target_include_directories(
  brompton_tests
  PRIVATE ${PROJECT_SOURCE_DIR}/include
)

# Link the GoogleTest library
target_link_libraries(
  brompton_tests
  GTest::gtest_main
)

# Discover and register the tests
include(GoogleTest)
gtest_discover_tests(brompton_tests)

