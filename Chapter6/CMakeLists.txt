cmake_minimum_required(VERSION 3.0)

project(Chapter6)

set(HOME ${CMAKE_SOURCE_DIR})
set(EXECUTABLE_OUTPUT_PATH ${HOME}/bin)

include_directories(
	${HOME}/../cpplib/include
	)

link_directories(
	${HOME}/../cpplib/lib
	)

set(MY_STATIC_LIBRARIES
	${HOME}/../cpplib/lib/libStanfordCPPLib.a
	)

add_executable(ex01 ${HOME}/src/ex01.cpp ${HOME}/src/domino.cpp)

target_link_libraries(ex01 PRIVATE ${MY_STATIC_LIBRARIES})

