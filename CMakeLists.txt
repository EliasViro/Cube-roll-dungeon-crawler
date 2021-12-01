cmake_minimum_required (VERSION 3.8)

project ("DungeonCrawler")

set(CMAKE_BUILD_TYPE Release)

set(SFML_DIR "./libs/SFML-2.5.1_build")
set(SFML_STATIC_LIBRARIES TRUE)
find_package(SFML 2.5.1 COMPONENTS graphics window system audio REQUIRED)

file(GLOB SOURCES 
    "src/*.cpp"
    "src/Characters/*.cpp"
    "src/DungeonGeneration/*.cpp"
    "src/Items/*.cpp"
)

set(HEADER_FILES src/Characters src/DungeonGeneration src/Items src/Graphics libs/SFML-2.5.1/include/SFML)

# test_instructions.txt
# Use the line 'add_executable' below to configure CMake for your test setting.
# The fist argument defines the name of the executable.
# Other arguments define all the files that will be compiled. There must be: 1. the test.cpp which has your main() function 2. all the .cpps and .hpps that the test depends on.
####################################\  /################################################################
#####################################\/#################################################################
#add_executable(DungeonCrawler src/TEST_ELIAS.cpp src/DungeonGeneration/dungeonlevel.hpp src/DungeonGeneration/dungeonlevel.cpp src/DungeonGeneration/dungeonroom.cpp src/DungeonGeneration/dungeonroom.hpp src/DungeonGeneration/dungeontile.cpp src/DungeonGeneration/dungeontile.hpp src/Items/item.cpp src/Items/item.hpp src/Characters/character.hpp src/Characters/character.cpp src/Characters/enemy.cpp src/Characters/enemy.hpp src/Characters/characterplayer.hpp src/Characters/characterplayer.cpp)
#####################################/\#################################################################
####################################/  \################################################################

# This line creates makefiles to compile the whole project. Dont't change it, only comment it out if you are running tests with your test.cpp.
add_executable(DungeonCrawler ${SOURCES} ${HEADER_FILES})
#########################################################################################################



#find_package(OpenGL COMPONENTS OpenGL REQUIRED)
#set(OpenGL_GL_PREFERENCE GLVND)
#target_link_libraries(DungeonCrawler sfml-audio sfml-graphics sfml-window sfml-system OpenGL)

target_link_libraries(DungeonCrawler sfml-graphics sfml-window sfml-system sfml-audio)
target_include_directories(DungeonCrawler PUBLIC ${HEADER_FILES})