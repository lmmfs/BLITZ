# Engine/CMakeLists.txt
project(Engine)

# Automatically include all .cpp files in the src directory
file(GLOB_RECURSE ENGINE_SOURCE_FILES 
    src/*.cpp 
    vendor/spdlog/src/*.cpp
    vendor/spdlog/include/*.h
)

# Exclude spdlog benchmark files
file(GLOB_RECURSE EXCLUDED_FILES vendor/spdlog/bench/*.cpp)
list(REMOVE_ITEM ENGINE_SOURCE_FILES ${EXCLUDED_FILES})

# Set the OpenGL preference to GLVND
cmake_policy(SET CMP0072 NEW)

# Add SPDLOG
# Set options to disable spdlog benchmarks and tests
#set(SPDLOG_BUILD_BENCH OFF CACHE BOOL "Build spdlog benchmarks" FORCE)
#set(SPDLOG_BUILD_TESTS OFF CACHE BOOL "Build spdlog tests" FORCE)
#set(SPDLOG_INSTALL OFF CACHE BOOL "Generate the install target" FORCE)
add_subdirectory(vendor/spdlog)


# Add GLFW
set(GLFW_BUILD_DOCS OFF CACHE BOOL "GLFW lib only")
set(GLFW_BUILD_TESTS OFF CACHE BOOL "GLFW lib only")
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "GLFW lib only")
set(GLFW_BUILD_WAYLAND OFF CACHE BOOL "Do not use Wayland backend")
set(GLFW_BUILD_X11 ON CACHE BOOL "Build X11 backend")
add_subdirectory(vendor/glfw)

# Add GLAD
add_library(glad STATIC vendor/glad/src/glad.c)
target_include_directories(glad PUBLIC vendor/glad/include)

# Include directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR}
                    ${CMAKE_CURRENT_SOURCE_DIR}/vendor/glfw/include 
                    ${CMAKE_CURRENT_SOURCE_DIR}/vendor/glad/include
                    ${CMAKE_CURRENT_SOURCE_DIR}/vendor/spdlog/include)

# Create a shared library
# Define the ENGINE_EXPORTS macro for the engine target
add_library(Engine SHARED ${ENGINE_SOURCE_FILES})
target_compile_definitions(Engine PRIVATE ENGINE_EXPORTS)

# Link libraries
#target_link_libraries(Engine glfw glad spdlog ${CMAKE_DL_LIBS})
target_link_libraries(Engine glfw glad ${CMAKE_DL_LIBS})

# Find OpenGL
find_package(OpenGL REQUIRED)
if (OPENGL_FOUND)
    include_directories(${OPENGL_INCLUDE_DIRS})
    target_link_libraries(Engine ${OPENGL_LIBRARIES})
endif()
