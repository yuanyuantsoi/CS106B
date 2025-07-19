cmake_minimum_required(VERSION 3.0)
project(pointersandarrays)
set(HOME ${CMAKE_SOURCE_DIR})

include_directories(${HOME}/../cpplib/include)
link_directories(${HOME}/../cpplib/lib)
link_libraries(libStanfordCPPLib.a)

set(STANFORDLIB ${HOME}/../cpplib/lib/libStanfordCPPLib.a)

set(EXECUTABLE_OUTPUT_PATH ${HOME}/bin)

add_executable(ex01 ${HOME}/src/ex01.cpp)
add_executable(ex02 ${HOME}/src/ex02.cpp)
add_executable(ex03 ${HOME}/src/ex03.cpp)
add_executable(ex04 ${HOME}/src/ex04.cpp ${HOME}/src/strlibx.cpp)
add_executable(ex05 ${HOME}/src/ex05.cpp)
add_executable(ex06 ${HOME}/src/ex06.cpp)
add_executable(ex07 ${HOME}/src/ex07.cpp)
add_executable(ex08 ${HOME}/src/ex08.cpp)
