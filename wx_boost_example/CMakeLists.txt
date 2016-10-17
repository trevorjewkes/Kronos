cmake_minimum_required (VERSION 2.8)
project (wxNetwork CXX)

file(GLOB_RECURSE sources "src/*.cpp")
file(GLOB_RECURSE test_src "src/*.cpp" "test/*.cpp")
list(REMOVE_ITEM test_src "${CMAKE_CURRENT_LIST_DIR}/src/main.cpp")
find_package(wxWidgets COMPONENTS net gl core base)
include(${wxWidgets_USE_FILE})

add_executable(run ${sources})
target_compile_options(run PUBLIC -std=c++11 -g -Werror -Wall -pedantic)
target_include_directories(run PUBLIC include )
target_link_libraries(run ${wxWidgets_LIBRARIES} ${Boost_LIBRARIES})

add_executable(test ${test_src})
target_compile_options(test PUBLIC -std=c++11 -g -Wall -pedantic)
target_include_directories(test PUBLIC lib include test)
target_link_libraries(test ${wxWidgets_LIBRARIES} ${Boost_LIBRARIES})
