cmake_minimum_required (VERSION 3.8)
project ("DungeonCrawler")
include_directories("src")
add_subdirectory("src")


file(GLOB DungeonCrawler_SRC 
"src/*.hpp" 
"src/*.cpp" 
"src/DungeonGeneration/*.hpp" 
"src/DungeonGeneration/*.cpp" 
"src/Items/*.hpp" "src/Items/*.cpp")

# test_instructions.txt
# This (below) is the line that tells CMake which .cpp file the executable is created for.
# Define the path to the cpp file of your choice inside the quotation marks.
# For example, "tests/my_test.cpp" ---> once you compile the project using CMake, the executable
# is created for your test cpp which you can then run.
####################################\  /#######
#####################################\/########
add_executable(DungeonCrawler ${DungeonCrawler_SRC})

#add_executable(DungeonCrawler ${SOURCES})

#####################################/\########
####################################/  \#######

#file(GLOB SOURCES src/*.cpp src/DungeonGeneration/*.cpp src/Items/*.cpp)

set(CMAKE_BUILD_TYPE Debug)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)
target_link_libraries(DungeonCrawler sfml-audio sfml-graphics sfml-window)