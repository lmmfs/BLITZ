# Sandbox/CMakeLists.txt
project(Sandbox)

# Source file
set(SANDBOX_SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/src/app.cpp)

# Include directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR}
                    ${CMAKE_CURRENT_SOURCE_DIR}/../Engine)

# Add executable
add_executable(Sandbox ${SANDBOX_SOURCE})

# Link the engine library
target_link_libraries(Sandbox Engine)
