cmake_minimum_required(VERSION 3.14)

project(
    "gezzy"
    DESCRIPTION ""
    HOMEPAGE_URL ""
)

set(OpenGL_GL_PREFERENCE LEGACY)
find_package(OpenGL REQUIRED)
link_libraries(OpenGL::GL)

find_package(glfw3 REQUIRED)
include_directories(${GLFW_INCLUDE_DIRS})
link_libraries(glfw)

add_subdirectory(cpputils)
add_subdirectory(glabs)
add_subdirectory(ecs)

add_subdirectory(glad)
add_subdirectory(src)

add_library(${PROJECT_NAME} STATIC ${GEZZY_SOURCES})
add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})
target_include_directories(${PROJECT_NAME} PUBLIC include)
target_link_libraries(${PROJECT_NAME} PUBLIC cpputils::cpputils glad::glad glabs::glabs ecs::ecs)
