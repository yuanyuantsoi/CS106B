cmake_minimum_required(VERSION 3.0)

project(Chapter6)

set(HOME ${CMAKE_SOURCE_DIR})
set(EXECUTABLE_OUTPUT_PATH ${HOME}/bin)

include_directories(${HOME}/../cpplib/include)
link_directories(${HOME}/../cpplib/lib)

include_directories(${HOME}/../myLib/include)
link_directories(${HOME}/../myLib/lib)

add_executable(ex01 ${HOME}/src/ex01.cpp)

target_link_libraries(ex01 PRIVATE ${HOME}/../myLib/lib/libdomino.a ${HOME}/../cpplib/lib/libStanfordCPPLib.a)

