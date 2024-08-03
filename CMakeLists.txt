cmake_minimum_required(VERSION 3.10)
project(BLITZ)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Automatically include all .cpp files in the src directory
#file(GLOB SOURCE_FILES src/*.cpp) this is not workin is not recursive in folders
file(GLOB_RECURSE SOURCE_FILES src/*.cpp)

# Add GLFW
set(GLFW_BUILD_DOCS OFF CACHE BOOL "GLFW lib only")
set(GLFW_BUILD_TESTS OFF CACHE BOOL "GLFW lib only")
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "GLFW lib only")
set(GLFW_BUILD_WAYLAND OFF CACHE BOOL "Do not use Wayland backend")
set(GLFW_BUILD_X11 ON CACHE BOOL "Build X11 backend")
add_subdirectory(Vendor/glfw)

# Add SPDLOG
add_subdirectory(Vendor/spdlog)

# Add GLAD
add_library(glad STATIC Vendor/glad/src/glad.c)
target_include_directories(glad PUBLIC Vendor/glad/include)

# Include directories
include_directories(Vendor/glfw/include 
                    Vendor/glad/include
                    Vendor/spdlog/include
                    src)

# Add executable
add_executable(BLITZ ${SOURCE_FILES})

# Link libraries
target_link_libraries(BLITZ glfw glad ${CMAKE_DL_LIBS})

# Find OpenGL
find_package(OpenGL REQUIRED)
if (OPENGL_FOUND)
    include_directories(${OPENGL_INCLUDE_DIRS})
    target_link_libraries(BLITZ ${OPENGL_LIBRARIES})
endif()
