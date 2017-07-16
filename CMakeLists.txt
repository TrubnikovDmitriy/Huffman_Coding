cmake_minimum_required(VERSION 3.6)
project(_)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp MinHeap.hpp MinHeap.cpp CodeTree.hpp CodeTree.cpp CodeDictionary.hpp Utils.hpp CodeDictionary.cpp BinaryWriter.hpp BinaryWriter.cpp)
add_executable(_ ${SOURCE_FILES})