cmake_minimum_required(VERSION 3.22)
project(Library_System)
add_executable(main src/main.cpp src/book.cpp src/user.cpp src/library.cpp)

target_include_directories(main PUBLIC include/)