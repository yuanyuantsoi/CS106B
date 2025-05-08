cmake_minimum_required(VERSION 3.0)

project(Chapter9)

set(HOME ${CMAKE_SOURCE_DIR})
set(EXECUTABLE_OUTPUT_PATH ${HOME}/bin)
set(CMAKE_CXX_STANDARD 11)


# Debug setup
set(CMAKE_BUILD_TYPE Debug)

include_directories(
	${HOME}/../cpplib/include
	)

link_directories(
	${HOME}/../cpplib/lib
	)

set(STANFORD_LIBRARIES
	${HOME}/../cpplib/lib/libStanfordCPPLib.a
	)

add_executable(solveMaze ${HOME}/src/SolveMaze/SolveMaze.cpp ${HOME}/src/SolveMaze/maze.cpp)
target_link_libraries(solveMaze PRIVATE ${STANFORD_LIBRARIES})

add_executable(ex01 ${HOME}/src/ex01.cpp ${HOME}/src/SolveMaze/maze.cpp)
target_link_libraries(ex01 PRIVATE ${STANFORD_LIBRARIES})

add_executable(ex01v2 ${HOME}/src/ex01v2.cpp ${HOME}/src/SolveMaze/maze.cpp)
target_link_libraries(ex01v2 PRIVATE ${STANFORD_LIBRARIES})

add_executable(ex02 ${HOME}/src/ex02.cpp ${HOME}/src/SolveMaze/maze.cpp)
target_link_libraries(ex02 PRIVATE ${STANFORD_LIBRARIES})

add_executable(ex03 ${HOME}/src/ex03.cpp ${HOME}/src/SolveMaze/maze.cpp)
target_link_libraries(ex03 PRIVATE ${STANFORD_LIBRARIES})

#add_executable(ex04 ${HOME}/src/ex04.cpp)
#target_link_libraries(ex04 PRIVATE ${STANFORD_LIBRARIES})

add_executable(ex05 ${HOME}/src/ex05.cpp)
target_link_libraries(ex05 PRIVATE ${STANFORD_LIBRARIES})

add_executable(ex05v2 ${HOME}/src/ex05v2.cpp)
target_link_libraries(ex05v2 PRIVATE ${STANFORD_LIBRARIES})

add_executable(ex05update ${HOME}/src/ex05update.cpp)
target_link_libraries(ex05update PRIVATE ${STANFORD_LIBRARIES})

add_executable(ex06 ${HOME}/src/ex06.cpp)
target_link_libraries(ex06 PRIVATE ${STANFORD_LIBRARIES})

add_executable(ex06v2 ${HOME}/src/ex06v2.cpp)
target_link_libraries(ex06v2 PRIVATE ${STANFORD_LIBRARIES})

add_executable(ex07 ${HOME}/src/ex07.cpp)
target_link_libraries(ex07 PRIVATE ${STANFORD_LIBRARIES})

add_executable(ex08 ${HOME}/src/ex08.cpp)
target_link_libraries(ex08 PRIVATE ${STANFORD_LIBRARIES})

add_executable(ex09 ${HOME}/src/ex09.cpp ${HOME}/src/domino.cpp) 
target_link_libraries(ex09 PRIVATE ${STANFORD_LIBRARIES})

#add_executable(ex10 ${HOME}/src/ex10.cpp) 
#target_link_libraries(ex10 PRIVATE ${STANFORD_LIBRARIES})

add_executable(ex11 ${HOME}/src/ex11.cpp) 
target_link_libraries(ex11 PRIVATE ${STANFORD_LIBRARIES})

add_executable(ex12 ${HOME}/src/ex12.cpp) 
target_link_libraries(ex12 PRIVATE ${STANFORD_LIBRARIES})

add_executable(ex13 ${HOME}/src/ex13.cpp) 
target_link_libraries(ex13 PRIVATE ${STANFORD_LIBRARIES})

add_executable(ex13up ${HOME}/src/ex13upgrade.cpp) 
target_link_libraries(ex13up PRIVATE ${STANFORD_LIBRARIES})

add_executable(nim ${HOME}/src/Nim.cpp) 
target_link_libraries(nim PRIVATE ${STANFORD_LIBRARIES})

add_executable(ex14 ${HOME}/src/ex14.cpp) 
target_link_libraries(ex14 PRIVATE ${STANFORD_LIBRARIES})

add_executable(ex15 ${HOME}/src/ex15.cpp) 
target_link_libraries(ex15 PRIVATE ${STANFORD_LIBRARIES})

add_executable(ex16 ${HOME}/src/ex16.cpp) 
target_link_libraries(ex16 PRIVATE ${STANFORD_LIBRARIES})
