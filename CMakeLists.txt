cmake_minimum_required(VERSION 3.21)
project(rbini)

if(MSVC)
    add_definitions(/MP)
endif()

if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
    message(FATAL_ERROR "In-source builds not allowed.
    Please make a new directory (called a build directory)
	and run CMake from there. You may need to remove CMakeCache.txt.")
endif()

cmake_policy(SET CMP0074 NEW)

option(RBINI_BUILD_TESTS "Build RBIni's tests" OFF)
include(cmake/Base.cmake)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_COLOR_DIAGNOSTICS ON)

file(GLOB_RECURSE INLCS include/rbini/*.hpp)
file(GLOB_RECURSE SRC source/*.cpp)
list(FILTER SRC EXCLUDE REGEX "source/.*main\\.cpp$")


add_library(${PROJECT_NAME} STATIC ${INLCS} ${SRC})
add_executable(${PROJECT_NAME}-exe source/main.cpp)
target_link_libraries(${PROJECT_NAME}-exe ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PUBLIC
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
        INTERFACE
        "$<INSTALL_INTERFACE:include>")

if(RBINI_OS_WIN32)
    target_compile_options(${PROJECT_NAME} PUBLIC "/Zc:__cplusplus")
endif ()

target_include_directories(${PROJECT_NAME} PRIVATE ${LIBS})

if(RBINI_BUILD_TESTS)
    add_subdirectory(tests)
endif()
