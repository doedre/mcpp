cmake_minimum_required(VERSION 3.28)

project(mcpp
  VERSION 0.0.1
  DESCRIPTION ""
  HOMEPAGE_URL ""
  LANGUAGES CXX
)

add_subdirectory(core)

add_subdirectory(examples)

include(CTest)
enable_testing()
add_subdirectory(tests)

