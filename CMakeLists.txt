cmake_minimum_required(VERSION 3.22.3)
project(cmake_testapp)

set(CMAKE_CXX_STANDARD 17)

add_executable(main main.cpp Student.h maxHeap.h Application.h minHeap.h BST.h AVL.h)