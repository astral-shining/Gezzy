cmake_minimum_required(VERSION 3.14)

project(
    "gezzy"
    DESCRIPTION ""
    HOMEPAGE_URL ""
)

set(OpenGL_GL_PREFERENCE LEGACY)
find_package(OpenGL REQUIRED)
link_libraries(OpenGL::GL)

add_subdirectory(lib/cpputils)
add_subdirectory(lib/cppmaths)
add_subdirectory(lib/glabs)
add_subdirectory(lib/ecs)
add_subdirectory(lib/glad)

find_package(glfw3 REQUIRED)
link_libraries(glfw)

file(GLOB_RECURSE GEZZY_SOURCES src/*.cpp)

add_library(${PROJECT_NAME} STATIC ${GEZZY_SOURCES})
add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})
target_include_directories(${PROJECT_NAME} PUBLIC include)
target_link_libraries(${PROJECT_NAME} PUBLIC glfw cpputils::cpputils cppmaths::cppmaths glad::glad glabs::glabs ecs::ecs)
