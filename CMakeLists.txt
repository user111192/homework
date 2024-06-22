cmake_minimum_required(VERSION 3.23)
project(homework DESCRIPTION "")

set(CMAKE_CXX_STANDARD 20)
message(STATUS "Set C++ Standard: C++ 20")




message("CMAKE_MINIMUM_REQUIRED_VERSION: ${CMAKE_MINIMUM_REQUIRED_VERSION}")


message(STATUS "Project Source Directory: ${PROJECT_SOURCE_DIR}")

message(DEBUG "Adding Executable...")
#add_compile_options(-Wall -Wextra)
add_compile_options(-lm)
add_compile_definitions(DEBUGON)
message(STATUS "Add Math Library")
add_executable(homework main.cpp libraries.h app/framework.cpp app/String.cpp
        app/String.h app/lib/std.cpp.h fastutil.h)
message(STATUS "Added Executable.")
