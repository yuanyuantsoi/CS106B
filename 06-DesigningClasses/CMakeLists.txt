cmake_minimum_required(VERSION 3.0)

project(Chapter6)

set(HOME ${CMAKE_SOURCE_DIR})
set(EXECUTABLE_OUTPUT_PATH ${HOME}/bin)
set(CMAKE_CXX_STANDARD 11)

include_directories(${HOME}/../cpplib/include)
link_directories(${HOME}/../cpplib/lib)
set(STANFORD_LIBRARIES ${HOME}/../cpplib/lib/libStanfordCPPLib.a)

add_executable(ex01 ${HOME}/src/ex01.cpp ${HOME}/src/domino.cpp)
target_link_libraries(ex01 PRIVATE ${STANFORD_LIBRARIES})

add_executable(ex02 ${HOME}/src/ex02.cpp ${HOME}/src/card.cpp)
target_link_libraries(ex02 PRIVATE ${STANFORD_LIBRARIES})

add_executable(ex04 ${HOME}/src/ex04.cpp)
target_link_libraries(ex04 PRIVATE ${STANFORD_LIBRARIES})

add_executable(ex05 ${HOME}/src/ex05.cpp ${HOME}/src/calendar.cpp)
target_link_libraries(ex05 PRIVATE ${STANFORD_LIBRARIES})

add_executable(ex06 ${HOME}/src/ex06.cpp ${HOME}/src/calendar.cpp)
target_link_libraries(ex06 PRIVATE ${STANFORD_LIBRARIES})

add_executable(ex07 ${HOME}/src/ex07.cpp ${HOME}/src/labelgen.cpp)
target_link_libraries(ex07 PRIVATE ${STANFORD_LIBRARIES})
