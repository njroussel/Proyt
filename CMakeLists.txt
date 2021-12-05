cmake_minimum_required(VERSION 3.19)
project(
  Proyt
  VERSION 0.1
  DESCRIPTION "A memory-layout centric language"
  LANGUAGES CXX)

# option(PROYT_TESTS "Build the tests" ON) if(PROYT_TESTS) enable_testing()
# include(GoogleTest) add_subdirectory(tests) endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if (NOT CMAKE_BUILD_TYPE)
  message(STATUS "Build type was not specified, using \"Release\".")
  set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type." FORCE)
endif()

# Good practices
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wshadow-all")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fsanitize=address")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wconversion")

# Enable all instruction subsets supported by the local machine
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=native")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")

add_executable(proytc src/main.cpp src/lexer.cpp)
target_include_directories(proytc PUBLIC include)
