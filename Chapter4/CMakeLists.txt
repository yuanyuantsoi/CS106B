cmake_minimum_required(VERSION 3.0.0)
project(Chapter4)

set(HOME ${PROJECT_SOURCE_DIR})

include_directories(${HOME}/../cpplib/include)

link_directories(${HOME}/../cpplib/lib)
link_libraries(libStanfordCPPLib.a)

set(EXECUTABLE_OUTPUT_PATH ${HOME}/bin)
set(SRC_PATH ${HOME}/src)

add_executable(PrecisionExample ${SRC_PATH}/PrecisionExample.cpp)
add_executable(ShowFileContents ${SRC_PATH}/ShowFileContents.cpp)
add_executable(ex01 ${SRC_PATH}/ex01.cpp)
add_executable(ex02 ${SRC_PATH}/ex02.cpp)
add_executable(ex03 ${SRC_PATH}/ex03.cpp)
add_executable(ex04 ${SRC_PATH}/ex04.cpp)
add_executable(ex05 ${SRC_PATH}/ex05.cpp)
add_executable(ex06 ${SRC_PATH}/ex06.cpp)
add_executable(ex07 ${SRC_PATH}/ex07.cpp)
add_executable(ex08 ${SRC_PATH}/ex08.cpp)
add_executable(ex09 ${SRC_PATH}/ex09.cpp)
add_executable(ex10 ${SRC_PATH}/ex10.cpp)
add_executable(ex11 ${SRC_PATH}/ex11.cpp)
add_executable(ex12 ${SRC_PATH}/ex12.cpp)
