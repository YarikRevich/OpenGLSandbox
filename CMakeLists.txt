cmake_minimum_required(VERSION 3.8)
project(opengl VERSION 0.0.1 LANGUAGES CXX)
set(CMAKE_CXX_FLAGS "-std=c++17")

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

message(${CMAKE_CURRENT_SOURCE_DIR})

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/vendor/glfw/include/
    ${CMAKE_CURRENT_SOURCE_DIR}/vendor/glad/include/
    ${CMAKE_CURRENT_SOURCE_DIR}/vendor/glew/include/
    ${CMAKE_CURRENT_SOURCE_DIR}/vendor/glm/include/)
link_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/vendor/glfw/lib/
    ${CMAKE_CURRENT_SOURCE_DIR}/vendor/glad/lib/
    ${CMAKE_CURRENT_SOURCE_DIR}/vendor/glew/lib/)

add_executable(opengl src/main.cpp src/loader.cpp src/error.cpp src/renderer.cpp src/indexBuffer.cpp src/vertexBuffer.cpp)
target_link_libraries(opengl 
libglfw.3.3.dylib
libglad.a
)
