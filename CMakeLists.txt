cmake_minimum_required(VERSION 3.18)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_COLOR_MAKEFILE   ON)

project("hangman")

add_executable("${PROJECT_NAME}" "${PROJECT_NAME}/include/Util.h" "${PROJECT_NAME}/include/Main.h" "${PROJECT_NAME}/src/Main.cpp" "${PROJECT_NAME}/src/Util.cpp")

configure_file("words.txt" "${CMAKE_CURRENT_BINARY_DIR}" COPYONLY)

target_include_directories("${PROJECT_NAME}" PUBLIC "${PROJECT_NAME}/include")