cmake_minimum_required(VERSION 3.18)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_COLOR_MAKEFILE   ON)

project("hangman")

add_executable("${PROJECT_NAME}" "hangman/include/Util.h" "hangman/include/Main.h" "hangman/src/Main.cpp" "hangman/src/Util.cpp")

target_include_directories("${PROJECT_NAME}" PUBLIC "${PROJECT_NAME}/include")