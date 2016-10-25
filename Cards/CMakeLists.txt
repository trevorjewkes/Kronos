cmake_minimum_required (VERSION 2.8)
project(CardsDemo)

if(CMAKE_COMPILER_IS_GNUCXX)
  set(CMAKE_CXX_FLAGS "-std=c++11 -Ofast -Wall -pedantic -Wextra ${CMAKE_CXX_FLAGS}")
  MESSAGE(STATUS "GNU CXX Flags: " ${CMAKE_CXX_FLAGS})
endif()

file(GLOB_RECURSE sources "src/*.cpp")
file(GLOB_RECURSE test_src "src/*.cpp" "test/*.cpp")
list(REMOVE_ITEM test_src "${CMAKE_CURRENT_LIST_DIR}/src/main.cpp")

add_executable(CardsDemo ${sources})
target_include_directories(CardsDemo PUBLIC include)

add_executable(CardsTest ${test_src})
target_include_directories(CardsTest PUBLIC lib include)
