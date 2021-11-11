cmake_minimum_required (VERSION 3.8)

project ("DungeonCrawler")

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

add_subdirectory ("src")

# test_instructions.txt
# This (below) is the line that tells CMake which .cpp file the executable is created for.
# Define the path to the cpp file of your choice inside the quotation marks.
# For example, "tests/my_test.cpp" ---> once you compile the project using CMake, the executable
# is created for your test cpp which you can then run.
####################################\  /#######
#####################################\/########
add_executable(DungeonCrawler "tests/dungeonleveltest.cpp")
#####################################/\########
####################################/  \#######

target_link_libraries(DungeonCrawler sfml-audio sfml-graphics)