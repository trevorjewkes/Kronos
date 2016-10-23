cmake_minimum_required (VERSION 2.8)
project(CardsDemo)

if(CMAKE_COMPILER_IS_GNUCXX)
  set(CMAKE_CXX_FLAGS "-std=c++11 -Ofast -Wall -Werror -pedantic -Wextra ${CMAKE_CXX_FLAGS}")
  MESSAGE(STATUS "GNU CXX Flags: " ${CMAKE_CXX_FLAGS})
endif()

add_executable(CardsDemo
  main.cpp
  deck.cpp
  deck.h
  card.cpp
  card.h
  player.cpp
  player.h
)
