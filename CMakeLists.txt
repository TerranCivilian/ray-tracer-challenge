cmake_minimum_required(VERSION 3.14)
project(ray-tracer-challenge)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/f8d7d77c06936315286eb55f8de22cd23c188571.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

include_directories(include)

set(sources
  src/main.cpp
  src/Tuple.cpp
  src/Canvas.cpp
)

add_executable(main ${sources})

add_executable(
  TupleTest
  test/TupleTest.cpp
  src/Tuple.cpp
)
target_link_libraries(
  TupleTest
  GTest::gtest_main
)

add_executable(
  ColorTest
  test/ColorTest.cpp
  src/Tuple.cpp
)
target_link_libraries(
  ColorTest
  GTest::gtest_main
)

add_executable(
  CanvasTest
  test/CanvasTest.cpp
  src/Canvas.cpp
  src/Tuple.cpp
)
target_link_libraries(
  CanvasTest
  GTest::gtest_main
)

add_executable(
  MatrixTest
  test/MatrixTest.cpp
  src/Tuple.cpp
)
target_link_libraries(
  MatrixTest
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(TupleTest)
gtest_discover_tests(ColorTest)
gtest_discover_tests(CanvasTest)
gtest_discover_tests(MatrixTest)
