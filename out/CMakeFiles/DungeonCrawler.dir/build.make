# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/mnt/c/Users/Elias Viro/Documents/cpp-autumn2021/Project/dungeon-crawler-group-3"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/mnt/c/Users/Elias Viro/Documents/cpp-autumn2021/Project/dungeon-crawler-group-3/out"

# Include any dependencies generated for this target.
include CMakeFiles/DungeonCrawler.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/DungeonCrawler.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DungeonCrawler.dir/flags.make

CMakeFiles/DungeonCrawler.dir/src/TEST_ELIAS.cpp.o: CMakeFiles/DungeonCrawler.dir/flags.make
CMakeFiles/DungeonCrawler.dir/src/TEST_ELIAS.cpp.o: ../src/TEST_ELIAS.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Users/Elias Viro/Documents/cpp-autumn2021/Project/dungeon-crawler-group-3/out/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/DungeonCrawler.dir/src/TEST_ELIAS.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DungeonCrawler.dir/src/TEST_ELIAS.cpp.o -c "/mnt/c/Users/Elias Viro/Documents/cpp-autumn2021/Project/dungeon-crawler-group-3/src/TEST_ELIAS.cpp"

CMakeFiles/DungeonCrawler.dir/src/TEST_ELIAS.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DungeonCrawler.dir/src/TEST_ELIAS.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/mnt/c/Users/Elias Viro/Documents/cpp-autumn2021/Project/dungeon-crawler-group-3/src/TEST_ELIAS.cpp" > CMakeFiles/DungeonCrawler.dir/src/TEST_ELIAS.cpp.i

CMakeFiles/DungeonCrawler.dir/src/TEST_ELIAS.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DungeonCrawler.dir/src/TEST_ELIAS.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/mnt/c/Users/Elias Viro/Documents/cpp-autumn2021/Project/dungeon-crawler-group-3/src/TEST_ELIAS.cpp" -o CMakeFiles/DungeonCrawler.dir/src/TEST_ELIAS.cpp.s

CMakeFiles/DungeonCrawler.dir/src/DungeonGeneration/dungeonroom.cpp.o: CMakeFiles/DungeonCrawler.dir/flags.make
CMakeFiles/DungeonCrawler.dir/src/DungeonGeneration/dungeonroom.cpp.o: ../src/DungeonGeneration/dungeonroom.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Users/Elias Viro/Documents/cpp-autumn2021/Project/dungeon-crawler-group-3/out/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/DungeonCrawler.dir/src/DungeonGeneration/dungeonroom.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DungeonCrawler.dir/src/DungeonGeneration/dungeonroom.cpp.o -c "/mnt/c/Users/Elias Viro/Documents/cpp-autumn2021/Project/dungeon-crawler-group-3/src/DungeonGeneration/dungeonroom.cpp"

CMakeFiles/DungeonCrawler.dir/src/DungeonGeneration/dungeonroom.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DungeonCrawler.dir/src/DungeonGeneration/dungeonroom.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/mnt/c/Users/Elias Viro/Documents/cpp-autumn2021/Project/dungeon-crawler-group-3/src/DungeonGeneration/dungeonroom.cpp" > CMakeFiles/DungeonCrawler.dir/src/DungeonGeneration/dungeonroom.cpp.i

CMakeFiles/DungeonCrawler.dir/src/DungeonGeneration/dungeonroom.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DungeonCrawler.dir/src/DungeonGeneration/dungeonroom.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/mnt/c/Users/Elias Viro/Documents/cpp-autumn2021/Project/dungeon-crawler-group-3/src/DungeonGeneration/dungeonroom.cpp" -o CMakeFiles/DungeonCrawler.dir/src/DungeonGeneration/dungeonroom.cpp.s

CMakeFiles/DungeonCrawler.dir/src/DungeonGeneration/dungeontile.cpp.o: CMakeFiles/DungeonCrawler.dir/flags.make
CMakeFiles/DungeonCrawler.dir/src/DungeonGeneration/dungeontile.cpp.o: ../src/DungeonGeneration/dungeontile.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Users/Elias Viro/Documents/cpp-autumn2021/Project/dungeon-crawler-group-3/out/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/DungeonCrawler.dir/src/DungeonGeneration/dungeontile.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DungeonCrawler.dir/src/DungeonGeneration/dungeontile.cpp.o -c "/mnt/c/Users/Elias Viro/Documents/cpp-autumn2021/Project/dungeon-crawler-group-3/src/DungeonGeneration/dungeontile.cpp"

CMakeFiles/DungeonCrawler.dir/src/DungeonGeneration/dungeontile.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DungeonCrawler.dir/src/DungeonGeneration/dungeontile.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/mnt/c/Users/Elias Viro/Documents/cpp-autumn2021/Project/dungeon-crawler-group-3/src/DungeonGeneration/dungeontile.cpp" > CMakeFiles/DungeonCrawler.dir/src/DungeonGeneration/dungeontile.cpp.i

CMakeFiles/DungeonCrawler.dir/src/DungeonGeneration/dungeontile.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DungeonCrawler.dir/src/DungeonGeneration/dungeontile.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/mnt/c/Users/Elias Viro/Documents/cpp-autumn2021/Project/dungeon-crawler-group-3/src/DungeonGeneration/dungeontile.cpp" -o CMakeFiles/DungeonCrawler.dir/src/DungeonGeneration/dungeontile.cpp.s

CMakeFiles/DungeonCrawler.dir/src/Items/item.cpp.o: CMakeFiles/DungeonCrawler.dir/flags.make
CMakeFiles/DungeonCrawler.dir/src/Items/item.cpp.o: ../src/Items/item.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Users/Elias Viro/Documents/cpp-autumn2021/Project/dungeon-crawler-group-3/out/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/DungeonCrawler.dir/src/Items/item.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DungeonCrawler.dir/src/Items/item.cpp.o -c "/mnt/c/Users/Elias Viro/Documents/cpp-autumn2021/Project/dungeon-crawler-group-3/src/Items/item.cpp"

CMakeFiles/DungeonCrawler.dir/src/Items/item.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DungeonCrawler.dir/src/Items/item.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/mnt/c/Users/Elias Viro/Documents/cpp-autumn2021/Project/dungeon-crawler-group-3/src/Items/item.cpp" > CMakeFiles/DungeonCrawler.dir/src/Items/item.cpp.i

CMakeFiles/DungeonCrawler.dir/src/Items/item.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DungeonCrawler.dir/src/Items/item.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/mnt/c/Users/Elias Viro/Documents/cpp-autumn2021/Project/dungeon-crawler-group-3/src/Items/item.cpp" -o CMakeFiles/DungeonCrawler.dir/src/Items/item.cpp.s

CMakeFiles/DungeonCrawler.dir/src/Characters/character.cpp.o: CMakeFiles/DungeonCrawler.dir/flags.make
CMakeFiles/DungeonCrawler.dir/src/Characters/character.cpp.o: ../src/Characters/character.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Users/Elias Viro/Documents/cpp-autumn2021/Project/dungeon-crawler-group-3/out/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/DungeonCrawler.dir/src/Characters/character.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DungeonCrawler.dir/src/Characters/character.cpp.o -c "/mnt/c/Users/Elias Viro/Documents/cpp-autumn2021/Project/dungeon-crawler-group-3/src/Characters/character.cpp"

CMakeFiles/DungeonCrawler.dir/src/Characters/character.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DungeonCrawler.dir/src/Characters/character.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/mnt/c/Users/Elias Viro/Documents/cpp-autumn2021/Project/dungeon-crawler-group-3/src/Characters/character.cpp" > CMakeFiles/DungeonCrawler.dir/src/Characters/character.cpp.i

CMakeFiles/DungeonCrawler.dir/src/Characters/character.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DungeonCrawler.dir/src/Characters/character.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/mnt/c/Users/Elias Viro/Documents/cpp-autumn2021/Project/dungeon-crawler-group-3/src/Characters/character.cpp" -o CMakeFiles/DungeonCrawler.dir/src/Characters/character.cpp.s

CMakeFiles/DungeonCrawler.dir/src/Characters/enemy.cpp.o: CMakeFiles/DungeonCrawler.dir/flags.make
CMakeFiles/DungeonCrawler.dir/src/Characters/enemy.cpp.o: ../src/Characters/enemy.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Users/Elias Viro/Documents/cpp-autumn2021/Project/dungeon-crawler-group-3/out/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/DungeonCrawler.dir/src/Characters/enemy.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DungeonCrawler.dir/src/Characters/enemy.cpp.o -c "/mnt/c/Users/Elias Viro/Documents/cpp-autumn2021/Project/dungeon-crawler-group-3/src/Characters/enemy.cpp"

CMakeFiles/DungeonCrawler.dir/src/Characters/enemy.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DungeonCrawler.dir/src/Characters/enemy.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/mnt/c/Users/Elias Viro/Documents/cpp-autumn2021/Project/dungeon-crawler-group-3/src/Characters/enemy.cpp" > CMakeFiles/DungeonCrawler.dir/src/Characters/enemy.cpp.i

CMakeFiles/DungeonCrawler.dir/src/Characters/enemy.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DungeonCrawler.dir/src/Characters/enemy.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/mnt/c/Users/Elias Viro/Documents/cpp-autumn2021/Project/dungeon-crawler-group-3/src/Characters/enemy.cpp" -o CMakeFiles/DungeonCrawler.dir/src/Characters/enemy.cpp.s

CMakeFiles/DungeonCrawler.dir/src/Characters/characterplayer.cpp.o: CMakeFiles/DungeonCrawler.dir/flags.make
CMakeFiles/DungeonCrawler.dir/src/Characters/characterplayer.cpp.o: ../src/Characters/characterplayer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Users/Elias Viro/Documents/cpp-autumn2021/Project/dungeon-crawler-group-3/out/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/DungeonCrawler.dir/src/Characters/characterplayer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DungeonCrawler.dir/src/Characters/characterplayer.cpp.o -c "/mnt/c/Users/Elias Viro/Documents/cpp-autumn2021/Project/dungeon-crawler-group-3/src/Characters/characterplayer.cpp"

CMakeFiles/DungeonCrawler.dir/src/Characters/characterplayer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DungeonCrawler.dir/src/Characters/characterplayer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/mnt/c/Users/Elias Viro/Documents/cpp-autumn2021/Project/dungeon-crawler-group-3/src/Characters/characterplayer.cpp" > CMakeFiles/DungeonCrawler.dir/src/Characters/characterplayer.cpp.i

CMakeFiles/DungeonCrawler.dir/src/Characters/characterplayer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DungeonCrawler.dir/src/Characters/characterplayer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/mnt/c/Users/Elias Viro/Documents/cpp-autumn2021/Project/dungeon-crawler-group-3/src/Characters/characterplayer.cpp" -o CMakeFiles/DungeonCrawler.dir/src/Characters/characterplayer.cpp.s

# Object files for target DungeonCrawler
DungeonCrawler_OBJECTS = \
"CMakeFiles/DungeonCrawler.dir/src/TEST_ELIAS.cpp.o" \
"CMakeFiles/DungeonCrawler.dir/src/DungeonGeneration/dungeonroom.cpp.o" \
"CMakeFiles/DungeonCrawler.dir/src/DungeonGeneration/dungeontile.cpp.o" \
"CMakeFiles/DungeonCrawler.dir/src/Items/item.cpp.o" \
"CMakeFiles/DungeonCrawler.dir/src/Characters/character.cpp.o" \
"CMakeFiles/DungeonCrawler.dir/src/Characters/enemy.cpp.o" \
"CMakeFiles/DungeonCrawler.dir/src/Characters/characterplayer.cpp.o"

# External object files for target DungeonCrawler
DungeonCrawler_EXTERNAL_OBJECTS =

DungeonCrawler: CMakeFiles/DungeonCrawler.dir/src/TEST_ELIAS.cpp.o
DungeonCrawler: CMakeFiles/DungeonCrawler.dir/src/DungeonGeneration/dungeonroom.cpp.o
DungeonCrawler: CMakeFiles/DungeonCrawler.dir/src/DungeonGeneration/dungeontile.cpp.o
DungeonCrawler: CMakeFiles/DungeonCrawler.dir/src/Items/item.cpp.o
DungeonCrawler: CMakeFiles/DungeonCrawler.dir/src/Characters/character.cpp.o
DungeonCrawler: CMakeFiles/DungeonCrawler.dir/src/Characters/enemy.cpp.o
DungeonCrawler: CMakeFiles/DungeonCrawler.dir/src/Characters/characterplayer.cpp.o
DungeonCrawler: CMakeFiles/DungeonCrawler.dir/build.make
DungeonCrawler: /usr/lib/x86_64-linux-gnu/libsfml-audio.so.2.5.1
DungeonCrawler: /usr/lib/x86_64-linux-gnu/libsfml-graphics.so.2.5.1
DungeonCrawler: /usr/lib/x86_64-linux-gnu/libsfml-window.so.2.5.1
DungeonCrawler: /usr/lib/x86_64-linux-gnu/libsfml-system.so.2.5.1
DungeonCrawler: CMakeFiles/DungeonCrawler.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/mnt/c/Users/Elias Viro/Documents/cpp-autumn2021/Project/dungeon-crawler-group-3/out/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable DungeonCrawler"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/DungeonCrawler.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DungeonCrawler.dir/build: DungeonCrawler

.PHONY : CMakeFiles/DungeonCrawler.dir/build

CMakeFiles/DungeonCrawler.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/DungeonCrawler.dir/cmake_clean.cmake
.PHONY : CMakeFiles/DungeonCrawler.dir/clean

CMakeFiles/DungeonCrawler.dir/depend:
	cd "/mnt/c/Users/Elias Viro/Documents/cpp-autumn2021/Project/dungeon-crawler-group-3/out" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/mnt/c/Users/Elias Viro/Documents/cpp-autumn2021/Project/dungeon-crawler-group-3" "/mnt/c/Users/Elias Viro/Documents/cpp-autumn2021/Project/dungeon-crawler-group-3" "/mnt/c/Users/Elias Viro/Documents/cpp-autumn2021/Project/dungeon-crawler-group-3/out" "/mnt/c/Users/Elias Viro/Documents/cpp-autumn2021/Project/dungeon-crawler-group-3/out" "/mnt/c/Users/Elias Viro/Documents/cpp-autumn2021/Project/dungeon-crawler-group-3/out/CMakeFiles/DungeonCrawler.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/DungeonCrawler.dir/depend
