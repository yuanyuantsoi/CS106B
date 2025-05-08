cmake_minimum_required(VERSION 3.0)

project(Chapter12)

set(HOME ${CMAKE_SOURCE_DIR})
set(EXECUTABLE_OUTPUT_PATH ${HOME}/bin)
set(CMAKE_CXX_STANDARD 11)

set(CMAKE_BUILD_TYPE Debug)

include_directories(${HOME}/../cpplib/include)
link_directories(${HOME}/../cpplib/lib)
set(STANFORD_LIBRARIES ${HOME}/../cpplib/lib/libStanfordCPPLib.a)

add_executable(addressBook ${HOME}/src/addressBook.cpp)
target_link_libraries(addressBook PRIVATE ${STANFORD_LIBRARIES})
