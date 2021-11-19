cmake_minimum_required (VERSION 3.8)
project ("DungeonCrawler")

file(GLOB SOURCES 
    "src/*.cpp"
    "src/Characters/*.cpp"
    "src/DungeonGeneration/*.cpp"
    "src/Items/*.cpp"
)

set(HEADER_FILES src/Characters src/DungeonGeneration src/Items)

# test_instructions.txt
# This (below) is the line that tells CMake which .cpp file the executable is created for.
# Define the path to the cpp file of your choice inside the quotation marks.
# For example, "tests/my_test.cpp" ---> once you compile the project using CMake, the executable
# is created for your test cpp which you can then run.
####################################\  /#######
#####################################\/########

add_executable(DungeonCrawler ${SOURCES} ${HEADER_FILES})
#add_executable(DungeonCrawler src/random_test.cpp src/DungeonGeneration/dungeontile.cpp src/DungeonGeneration/dungeontile.hpp)

#####################################/\########
####################################/  \#######

#file(GLOB SOURCES src/*.cpp src/DungeonGeneration/*.cpp src/Items/*.cpp)

set(CMAKE_BUILD_TYPE Debug)

find_package(SFML 2.5 COMPONENTS audio graphics window system REQUIRED)
target_link_libraries(DungeonCrawler sfml-audio sfml-graphics sfml-window sfml-system)
target_include_directories(DungeonCrawler PUBLIC ${HEADER_FILES})
#target_precompile_headers(DungeonCrawler PUBLIC "src/DungeonGeneration/dungeonlevel.hpp")