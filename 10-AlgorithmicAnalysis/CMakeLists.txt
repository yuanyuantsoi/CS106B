cmake_minimum_required(VERSION 3.0)
project(AlgorithmicAnalysis)
set(HOME ${CMAKE_SOURCE_DIR})

include_directories(${HOME}/../cpplib/include)
link_directories(${HOME}/../cpplib/lib)
link_libraries(libStanfordCPPLib.a)

set(EXECUTABLE_OUTPUT_PATH ${HOME}/bin)

add_executable(sorting ${HOME}/src/sortingalgor.cpp)
