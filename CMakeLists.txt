cmake_minimum_required(VERSION 3.20)
project(sortAlgorithms C)

set(CMAKE_C_STANDARD 99)

set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -DDEBUG")
#set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -z 67108864")
add_executable(sortAlgorithms main.c sort.h include include/arrayFunctions.h include/arrayFunctions.c sort.c)
