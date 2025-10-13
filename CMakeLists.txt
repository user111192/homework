cmake_minimum_required(VERSION 3.23)
#set(CMAKE_OSX_SYSROOT /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX15.2
#.sdk)
project(homework DESCRIPTION "")

set(CMAKE_CXX_STANDARD 23)
message(STATUS "Set C++ Standard: C++ ${CMAKE_CXX_STANDARD}")




message("CMAKE_MINIMUM_REQUIRED_VERSION: ${CMAKE_MINIMUM_REQUIRED_VERSION}")


message(STATUS "Project Source Directory: ${PROJECT_SOURCE_DIR}")

message(DEBUG "Adding Executable...")
#add_compile_options(-Wextra)
add_compile_options(-Wall)


add_compile_options(-lm)

add_compile_options(-fsanitize=undefined)
add_link_options(-fsanitize=undefined)
add_compile_options(-g)
add_compile_definitions(DEBUGON)
add_compile_definitions(LOCAL)
message(STATUS "Add Math Library")
add_executable(homework main.cpp libraries.h app/framework.cpp app/String.cpp
        app/String.h app/lib/std.cpp.h fastutil.h
        competitive.h
        BoolArray.cpp
        BoolArray.h
        basic_string_plus.cpp
        basic_string_plus.h
        string_plus1.h
        dsu.cpp
        dsu.h
        BigInt.h
        Answer.cpp
        Answer.h
        myhash.h
        echo.cpp)
message(STATUS "Added Executable.")

