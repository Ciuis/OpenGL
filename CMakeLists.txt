cmake_minimum_required(VERSION 3.16)
set(PROJECT_NAME opengl)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 20)

add_executable(${PROJECT_NAME} src/main.cpp
        src/renderer.h
        src/renderer.cpp
        src/vertexBuffer.h
        src/vertexBuffer.cpp
        src/indexBuffer.h
        src/indexBuffer.cpp
        src/vertexArray.h
        src/vertexArray.cpp
        src/vertexBufferLayout.h
        src/shader.h
        src/shader.cpp
        src/debug.h
        src/debug.cpp
        )

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF)

add_subdirectory(include/glfw)
include_directories(include/glew/include)

target_link_libraries(${PROJECT_NAME} glew32 glfw -lOpenGL32 )