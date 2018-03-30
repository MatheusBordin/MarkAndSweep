cmake_minimum_required(VERSION 3.10)
project(MarkAndSweep)

set(CMAKE_CXX_STANDARD 17)

add_executable(MarkAndSweep main.cpp State.h Gc.h node.h ldde.cpp ldde.h)