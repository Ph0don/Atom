cmake_minimum_required(VERSION 3.10)

add_subdirectory(glfw)
target_include_directories(Atom PRIVATE glfw/include)
