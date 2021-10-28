cmake_minimum_required (VERSION 2.6)
project (DungeonCrawler)
include_directories("src")

# Set the name of the executable to be produced
set(EXECUTABLE_NAME DungeonCrawler)

# Add all .cpp - files under src/ directory
#file(GLOB SOURCES src/*.cpp)

# For learning/testing purposes, add only test_main.cpp
file(GLOB SOURCES src/test_main.cpp)

# Add executable file
add_executable(${EXECUTABLE_NAME} ${SOURCES})
set(CMAKE_BUILD_TYPE Debug)




# I created a new folder 'out' for all the build files to keep the project folder tidy and organized.
# Below you can see an example of terminal commands to compile into 'out' and run the executable.

###### Terminal #########
# cd out
# cmake ..
# make
# ./DungeonCrawler