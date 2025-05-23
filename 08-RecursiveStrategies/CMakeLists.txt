cmake_minimum_required(VERSION 3.0)

project(Chapter8)

set(HOME ${CMAKE_SOURCE_DIR})
set(EXECUTABLE_OUTPUT_PATH ${HOME}/bin)
set(CMAKE_CXX_STANDARD 11)

include_directories(
	${HOME}/../cpplib/include
	)

link_directories(
	${HOME}/../cpplib/lib
	)

set(STANFORD_LIBRARIES
	${HOME}/../cpplib/lib/libStanfordCPPLib.a
	)

add_executable(ex01 ${HOME}/src/ex01.cpp)
target_link_libraries(ex01 PRIVATE ${STANFORD_LIBRARIES})

add_executable(ex03 ${HOME}/src/ex03.cpp)
target_link_libraries(ex03 PRIVATE ${STANFORD_LIBRARIES})

add_executable(ex03v2 ${HOME}/src/ex03v2.cpp)
target_link_libraries(ex03v2 PRIVATE ${STANFORD_LIBRARIES})

add_executable(ex04 ${HOME}/src/ex04.cpp)
target_link_libraries(ex04 PRIVATE ${STANFORD_LIBRARIES})

add_executable(ex04v2 ${HOME}/src/ex04v2.cpp)
target_link_libraries(ex04v2 PRIVATE ${STANFORD_LIBRARIES})

add_executable(ex05 ${HOME}/src/ex05.cpp)
target_link_libraries(ex05 PRIVATE ${STANFORD_LIBRARIES})

add_executable(ex05v2 ${HOME}/src/ex05v2.cpp)
target_link_libraries(ex05v2 PRIVATE ${STANFORD_LIBRARIES})

add_executable(ex06 ${HOME}/src/ex06.cpp)
target_link_libraries(ex06 PRIVATE ${STANFORD_LIBRARIES})

add_executable(ex07 ${HOME}/src/ex07.cpp ${HOME}/src/card.cpp)
target_link_libraries(ex07 PRIVATE ${STANFORD_LIBRARIES})

add_executable(ex07v2 ${HOME}/src/ex07v2.cpp ${HOME}/src/card.cpp)
target_link_libraries(ex07v2 PRIVATE ${STANFORD_LIBRARIES})

add_executable(ex08 ${HOME}/src/ex08.cpp)
target_link_libraries(ex08 PRIVATE ${STANFORD_LIBRARIES})

add_executable(ex09 ${HOME}/src/ex09.cpp)
target_link_libraries(ex09 PRIVATE ${STANFORD_LIBRARIES})

add_executable(ex092 ${HOME}/src/ex092.cpp)
target_link_libraries(ex092 PRIVATE ${STANFORD_LIBRARIES})

add_executable(ex09v2 ${HOME}/src/ex09v2.cpp)
target_link_libraries(ex09v2 PRIVATE ${STANFORD_LIBRARIES})

add_executable(ex10 ${HOME}/src/ex10.cpp)
target_link_libraries(ex10 PRIVATE ${STANFORD_LIBRARIES})

add_executable(ex10v2 ${HOME}/src/ex10v2.cpp)
target_link_libraries(ex10v2 PRIVATE ${STANFORD_LIBRARIES})

add_executable(ex11 ${HOME}/src/ex11.cpp)
target_link_libraries(ex11 PRIVATE ${STANFORD_LIBRARIES})

add_executable(ex11v2 ${HOME}/src/ex11v2.cpp)
target_link_libraries(ex11v2 PRIVATE ${STANFORD_LIBRARIES})

add_executable(ex12 ${HOME}/src/ex12.cpp)
target_link_libraries(ex12 PRIVATE ${STANFORD_LIBRARIES})

add_executable(ex13 ${HOME}/src/ex13.cpp)
target_link_libraries(ex13 PRIVATE ${STANFORD_LIBRARIES})

add_executable(ex14 ${HOME}/src/ex14.cpp)
target_link_libraries(ex14 PRIVATE ${STANFORD_LIBRARIES})

add_executable(ex14v2 ${HOME}/src/ex14v2.cpp)
target_link_libraries(ex14v2 PRIVATE ${STANFORD_LIBRARIES})

add_executable(ex15 ${HOME}/src/ex15.cpp)
target_link_libraries(ex15 PRIVATE ${STANFORD_LIBRARIES})

add_executable(ex15v2 ${HOME}/src/ex15v2.cpp)
target_link_libraries(ex15v2 PRIVATE ${STANFORD_LIBRARIES})

add_executable(ex16 ${HOME}/src/ex16.cpp)
target_link_libraries(ex16 PRIVATE ${STANFORD_LIBRARIES})

add_executable(ex17 ${HOME}/src/ex17.cpp)
target_link_libraries(ex17 PRIVATE ${STANFORD_LIBRARIES})

add_executable(ex17v2 ${HOME}/src/ex17v2.cpp)
target_link_libraries(ex17v2 PRIVATE ${STANFORD_LIBRARIES})

add_executable(ex17ori ${HOME}/src/ex17orign.cpp)
target_link_libraries(ex17ori PRIVATE ${STANFORD_LIBRARIES})

add_executable(ex18 ${HOME}/src/ex18.cpp)
target_link_libraries(ex18 PRIVATE ${STANFORD_LIBRARIES})

add_executable(ex18v2 ${HOME}/src/ex18v2.cpp)
target_link_libraries(ex18v2 PRIVATE ${STANFORD_LIBRARIES})

add_executable(ex18bp ${HOME}/src/ex18bp.cpp)
target_link_libraries(ex18bp PRIVATE ${STANFORD_LIBRARIES})
