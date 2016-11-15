cmake_minimum_required (VERSION 2.8)
project (hearts CXX)

if(CMAKE_COMPILER_IS_GNUCXX)
	set(CMAKE_CXX_FLAGS "-std=c++11 -Ofast -Wall -pedantic -Wextra -Wuninitialized -Wmaybe-uninitialized ${CMAKE_CXX_FLAGS}")
	MESSAGE(STATUS "GNU CXX Flags: " ${CMAKE_CXX_FLAGS})	
endif()

file(GLOB_RECURSE sources "src/*.cpp" "PlayerAPI/src/*.cpp")
file(GLOB_RECURSE test_src "src/*.cpp" "test/*.cpp" "PlayerAPI/src/*.cpp")
list(REMOVE_ITEM test_src "${CMAKE_CURRENT_LIST_DIR}/src/app.cpp")
find_package(wxWidgets COMPONENTS core base)
include(${wxWidgets_USE_FILE})

add_executable(${PROJECT_NAME} ${sources})
target_include_directories(${PROJECT_NAME} PUBLIC include PlayerAPI/include)
target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES} ${Boost_LIBRARIES})

#add_executable(wxTest ${test_src})
#target_include_directories(wxTest PUBLIC lib include test PlayerAPI/include)
#target_link_libraries(wxTest ${wxWidgets_LIBRARIES} ${Boost_LIBRARIES})
