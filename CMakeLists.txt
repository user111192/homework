cmake_minimum_required(VERSION 3.23)
project(homework)

set(CMAKE_CXX_STANDARD 14)

add_executable(homework main.cpp libraries.h app/framework.cpp app/lib/std.cpp.h app/String.cpp app/String.h fastutil.h)
