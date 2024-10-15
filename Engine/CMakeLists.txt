# Engine/CMakeLists.txt
project(Engine)

# Automatically include all .cpp files in the src directory
file(GLOB_RECURSE ENGINE_SOURCE_FILES src/*.cpp)

# Set the OpenGL preference to GLVND
cmake_policy(SET CMP0072 NEW)

# Add SPDLOG
# Set options to disable spdlog benchmarks and tests
add_subdirectory(vendor/spdlog)
target_compile_options(spdlog PRIVATE -fPIC)


# Add GLFW
set(GLFW_BUILD_DOCS OFF CACHE BOOL "GLFW lib only")
set(GLFW_BUILD_TESTS OFF CACHE BOOL "GLFW lib only")
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "GLFW lib only")
set(GLFW_BUILD_WAYLAND OFF CACHE BOOL "Do not use Wayland backend")
set(GLFW_BUILD_X11 ON CACHE BOOL "Build X11 backend")

add_subdirectory(vendor/GLFW)

# Add GLAD
add_library(glad STATIC vendor/glad/src/glad.c)
target_include_directories(glad PUBLIC vendor/glad/include)
target_compile_options(glad PRIVATE -fPIC)

# Ensure glad is compiled with -fPIC
set_target_properties(glad PROPERTIES POSITION_INDEPENDENT_CODE ON)

# Add ImGui
file(GLOB IMGUI_SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/vendor/imgui/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/vendor/imgui/backends/imgui_impl_glfw.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/vendor/imgui/backends/imgui_impl_opengl3.cpp
)

add_library(imgui STATIC ${IMGUI_SRC})

target_include_directories(imgui PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/vendor/imgui
    ${CMAKE_CURRENT_SOURCE_DIR}/vendor/imgui/backends
)

# Include directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}
                    ${CMAKE_CURRENT_SOURCE_DIR}/vendor/GLFW/include 
                    ${CMAKE_CURRENT_SOURCE_DIR}/vendor/glad/include
                    ${CMAKE_CURRENT_SOURCE_DIR}/vendor/spdlog/include
                    ${CMAKE_CURRENT_SOURCE_DIR}/vendor/imgui)

# Create a shared library
# Define the ENGINE_EXPORTS macro for the engine target
add_library(Engine SHARED ${ENGINE_SOURCE_FILES})
target_compile_definitions(Engine PRIVATE ENGINE_EXPORTS GLFW_INCLUDE_NONE)

# Add precompiled header
target_precompile_headers(Engine PRIVATE src/blpch.h)

# Link libraries
target_link_libraries(Engine glfw glad spdlog imgui ${CMAKE_DL_LIBS})

# Find OpenGL
find_package(OpenGL REQUIRED)
if (OPENGL_FOUND)
    include_directories(${OPENGL_INCLUDE_DIRS})
    target_link_libraries(Engine ${OPENGL_LIBRARIES})
endif()
