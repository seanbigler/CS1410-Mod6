cmake_minimum_required(VERSION 3.8)
project(Module6)

set(CMAKE_CXX_STANDARD 11)

#set(SOURCE_FILES Counter.cpp)
#set(SOURCE_FILES Assignment.cpp)
#set(SOURCE_FILES BinaryOperator.cpp)
#set(SOURCE_FILES Casting.cpp)
set(SOURCE_FILES MyTime.cpp)

add_executable(Module6 ${SOURCE_FILES})