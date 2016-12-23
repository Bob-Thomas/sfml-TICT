#Change this if you need to target a specific CMake version
cmake_minimum_required(VERSION 2.6)


# Enable debug symbols by default
# must be done before project() statement
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build (Debug or Release)" FORCE)
endif ()
# (you can also set it on the command line: -D CMAKE_BUILD_TYPE=Release)

project(sfml-demo)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
set(SFML_ROOT "${PROJECT_SOURCE_DIR}/thirdparty/SFML")

# Set version information in a config.h fil
include_directories("${PROJECT_BINARY_DIR}")
SET(BOOST_ROOT "C:/local/boost_1_62_0")
# Define sources and executable
set(EXECUTABLE_NAME "sfml-demo")
add_executable(${EXECUTABLE_NAME} main.cpp src/exceptions.h)


# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
#Find any version 2.X of SFML
#See the FindSFML.cmake file for additional details and instructions
find_package(SFML 2 REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
endif ()


find_package(Boost REQUIRED)
if (BOOST_FOUND)
    include_directories(${BOOST_INCLUDE_DIRS})
    target_link_libraries(${EXECUTABLE_NAME} ${BOOST_LIBRARIES})
endif ()