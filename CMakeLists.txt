cmake_minimum_required(VERSION 3.10)
project(BLITZ)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add subdirectories
add_subdirectory(Engine)
add_subdirectory(Sandbox)
