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
CMAKE_SOURCE_DIR = /home/atte/cpp_projects/DungeonCrawler

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/atte/cpp_projects/DungeonCrawler/build

# Include any dependencies generated for this target.
include CMakeFiles/DungeonCrawler.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/DungeonCrawler.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DungeonCrawler.dir/flags.make

CMakeFiles/DungeonCrawler.dir/src/Characters/character.cpp.o: CMakeFiles/DungeonCrawler.dir/flags.make
CMakeFiles/DungeonCrawler.dir/src/Characters/character.cpp.o: ../src/Characters/character.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/atte/cpp_projects/DungeonCrawler/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/DungeonCrawler.dir/src/Characters/character.cpp.o"
	/bin/x86_64-linux-gnu-g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DungeonCrawler.dir/src/Characters/character.cpp.o -c /home/atte/cpp_projects/DungeonCrawler/src/Characters/character.cpp

CMakeFiles/DungeonCrawler.dir/src/Characters/character.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DungeonCrawler.dir/src/Characters/character.cpp.i"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/atte/cpp_projects/DungeonCrawler/src/Characters/character.cpp > CMakeFiles/DungeonCrawler.dir/src/Characters/character.cpp.i

CMakeFiles/DungeonCrawler.dir/src/Characters/character.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DungeonCrawler.dir/src/Characters/character.cpp.s"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/atte/cpp_projects/DungeonCrawler/src/Characters/character.cpp -o CMakeFiles/DungeonCrawler.dir/src/Characters/character.cpp.s

CMakeFiles/DungeonCrawler.dir/src/Characters/characterplayer.cpp.o: CMakeFiles/DungeonCrawler.dir/flags.make
CMakeFiles/DungeonCrawler.dir/src/Characters/characterplayer.cpp.o: ../src/Characters/characterplayer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/atte/cpp_projects/DungeonCrawler/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/DungeonCrawler.dir/src/Characters/characterplayer.cpp.o"
	/bin/x86_64-linux-gnu-g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DungeonCrawler.dir/src/Characters/characterplayer.cpp.o -c /home/atte/cpp_projects/DungeonCrawler/src/Characters/characterplayer.cpp

CMakeFiles/DungeonCrawler.dir/src/Characters/characterplayer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DungeonCrawler.dir/src/Characters/characterplayer.cpp.i"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/atte/cpp_projects/DungeonCrawler/src/Characters/characterplayer.cpp > CMakeFiles/DungeonCrawler.dir/src/Characters/characterplayer.cpp.i

CMakeFiles/DungeonCrawler.dir/src/Characters/characterplayer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DungeonCrawler.dir/src/Characters/characterplayer.cpp.s"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/atte/cpp_projects/DungeonCrawler/src/Characters/characterplayer.cpp -o CMakeFiles/DungeonCrawler.dir/src/Characters/characterplayer.cpp.s

CMakeFiles/DungeonCrawler.dir/src/Characters/enemy.cpp.o: CMakeFiles/DungeonCrawler.dir/flags.make
CMakeFiles/DungeonCrawler.dir/src/Characters/enemy.cpp.o: ../src/Characters/enemy.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/atte/cpp_projects/DungeonCrawler/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/DungeonCrawler.dir/src/Characters/enemy.cpp.o"
	/bin/x86_64-linux-gnu-g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DungeonCrawler.dir/src/Characters/enemy.cpp.o -c /home/atte/cpp_projects/DungeonCrawler/src/Characters/enemy.cpp

CMakeFiles/DungeonCrawler.dir/src/Characters/enemy.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DungeonCrawler.dir/src/Characters/enemy.cpp.i"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/atte/cpp_projects/DungeonCrawler/src/Characters/enemy.cpp > CMakeFiles/DungeonCrawler.dir/src/Characters/enemy.cpp.i

CMakeFiles/DungeonCrawler.dir/src/Characters/enemy.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DungeonCrawler.dir/src/Characters/enemy.cpp.s"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/atte/cpp_projects/DungeonCrawler/src/Characters/enemy.cpp -o CMakeFiles/DungeonCrawler.dir/src/Characters/enemy.cpp.s

CMakeFiles/DungeonCrawler.dir/src/DungeonGeneration/dungeonlevel.cpp.o: CMakeFiles/DungeonCrawler.dir/flags.make
CMakeFiles/DungeonCrawler.dir/src/DungeonGeneration/dungeonlevel.cpp.o: ../src/DungeonGeneration/dungeonlevel.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/atte/cpp_projects/DungeonCrawler/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/DungeonCrawler.dir/src/DungeonGeneration/dungeonlevel.cpp.o"
	/bin/x86_64-linux-gnu-g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DungeonCrawler.dir/src/DungeonGeneration/dungeonlevel.cpp.o -c /home/atte/cpp_projects/DungeonCrawler/src/DungeonGeneration/dungeonlevel.cpp

CMakeFiles/DungeonCrawler.dir/src/DungeonGeneration/dungeonlevel.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DungeonCrawler.dir/src/DungeonGeneration/dungeonlevel.cpp.i"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/atte/cpp_projects/DungeonCrawler/src/DungeonGeneration/dungeonlevel.cpp > CMakeFiles/DungeonCrawler.dir/src/DungeonGeneration/dungeonlevel.cpp.i

CMakeFiles/DungeonCrawler.dir/src/DungeonGeneration/dungeonlevel.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DungeonCrawler.dir/src/DungeonGeneration/dungeonlevel.cpp.s"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/atte/cpp_projects/DungeonCrawler/src/DungeonGeneration/dungeonlevel.cpp -o CMakeFiles/DungeonCrawler.dir/src/DungeonGeneration/dungeonlevel.cpp.s

CMakeFiles/DungeonCrawler.dir/src/DungeonGeneration/dungeonroom.cpp.o: CMakeFiles/DungeonCrawler.dir/flags.make
CMakeFiles/DungeonCrawler.dir/src/DungeonGeneration/dungeonroom.cpp.o: ../src/DungeonGeneration/dungeonroom.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/atte/cpp_projects/DungeonCrawler/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/DungeonCrawler.dir/src/DungeonGeneration/dungeonroom.cpp.o"
	/bin/x86_64-linux-gnu-g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DungeonCrawler.dir/src/DungeonGeneration/dungeonroom.cpp.o -c /home/atte/cpp_projects/DungeonCrawler/src/DungeonGeneration/dungeonroom.cpp

CMakeFiles/DungeonCrawler.dir/src/DungeonGeneration/dungeonroom.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DungeonCrawler.dir/src/DungeonGeneration/dungeonroom.cpp.i"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/atte/cpp_projects/DungeonCrawler/src/DungeonGeneration/dungeonroom.cpp > CMakeFiles/DungeonCrawler.dir/src/DungeonGeneration/dungeonroom.cpp.i

CMakeFiles/DungeonCrawler.dir/src/DungeonGeneration/dungeonroom.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DungeonCrawler.dir/src/DungeonGeneration/dungeonroom.cpp.s"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/atte/cpp_projects/DungeonCrawler/src/DungeonGeneration/dungeonroom.cpp -o CMakeFiles/DungeonCrawler.dir/src/DungeonGeneration/dungeonroom.cpp.s

CMakeFiles/DungeonCrawler.dir/src/DungeonGeneration/dungeontile.cpp.o: CMakeFiles/DungeonCrawler.dir/flags.make
CMakeFiles/DungeonCrawler.dir/src/DungeonGeneration/dungeontile.cpp.o: ../src/DungeonGeneration/dungeontile.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/atte/cpp_projects/DungeonCrawler/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/DungeonCrawler.dir/src/DungeonGeneration/dungeontile.cpp.o"
	/bin/x86_64-linux-gnu-g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DungeonCrawler.dir/src/DungeonGeneration/dungeontile.cpp.o -c /home/atte/cpp_projects/DungeonCrawler/src/DungeonGeneration/dungeontile.cpp

CMakeFiles/DungeonCrawler.dir/src/DungeonGeneration/dungeontile.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DungeonCrawler.dir/src/DungeonGeneration/dungeontile.cpp.i"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/atte/cpp_projects/DungeonCrawler/src/DungeonGeneration/dungeontile.cpp > CMakeFiles/DungeonCrawler.dir/src/DungeonGeneration/dungeontile.cpp.i

CMakeFiles/DungeonCrawler.dir/src/DungeonGeneration/dungeontile.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DungeonCrawler.dir/src/DungeonGeneration/dungeontile.cpp.s"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/atte/cpp_projects/DungeonCrawler/src/DungeonGeneration/dungeontile.cpp -o CMakeFiles/DungeonCrawler.dir/src/DungeonGeneration/dungeontile.cpp.s

CMakeFiles/DungeonCrawler.dir/src/Items/item.cpp.o: CMakeFiles/DungeonCrawler.dir/flags.make
CMakeFiles/DungeonCrawler.dir/src/Items/item.cpp.o: ../src/Items/item.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/atte/cpp_projects/DungeonCrawler/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/DungeonCrawler.dir/src/Items/item.cpp.o"
	/bin/x86_64-linux-gnu-g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DungeonCrawler.dir/src/Items/item.cpp.o -c /home/atte/cpp_projects/DungeonCrawler/src/Items/item.cpp

CMakeFiles/DungeonCrawler.dir/src/Items/item.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DungeonCrawler.dir/src/Items/item.cpp.i"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/atte/cpp_projects/DungeonCrawler/src/Items/item.cpp > CMakeFiles/DungeonCrawler.dir/src/Items/item.cpp.i

CMakeFiles/DungeonCrawler.dir/src/Items/item.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DungeonCrawler.dir/src/Items/item.cpp.s"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/atte/cpp_projects/DungeonCrawler/src/Items/item.cpp -o CMakeFiles/DungeonCrawler.dir/src/Items/item.cpp.s

CMakeFiles/DungeonCrawler.dir/src/Items/meleeweapons.cpp.o: CMakeFiles/DungeonCrawler.dir/flags.make
CMakeFiles/DungeonCrawler.dir/src/Items/meleeweapons.cpp.o: ../src/Items/meleeweapons.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/atte/cpp_projects/DungeonCrawler/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/DungeonCrawler.dir/src/Items/meleeweapons.cpp.o"
	/bin/x86_64-linux-gnu-g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DungeonCrawler.dir/src/Items/meleeweapons.cpp.o -c /home/atte/cpp_projects/DungeonCrawler/src/Items/meleeweapons.cpp

CMakeFiles/DungeonCrawler.dir/src/Items/meleeweapons.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DungeonCrawler.dir/src/Items/meleeweapons.cpp.i"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/atte/cpp_projects/DungeonCrawler/src/Items/meleeweapons.cpp > CMakeFiles/DungeonCrawler.dir/src/Items/meleeweapons.cpp.i

CMakeFiles/DungeonCrawler.dir/src/Items/meleeweapons.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DungeonCrawler.dir/src/Items/meleeweapons.cpp.s"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/atte/cpp_projects/DungeonCrawler/src/Items/meleeweapons.cpp -o CMakeFiles/DungeonCrawler.dir/src/Items/meleeweapons.cpp.s

CMakeFiles/DungeonCrawler.dir/src/Items/potions.cpp.o: CMakeFiles/DungeonCrawler.dir/flags.make
CMakeFiles/DungeonCrawler.dir/src/Items/potions.cpp.o: ../src/Items/potions.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/atte/cpp_projects/DungeonCrawler/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/DungeonCrawler.dir/src/Items/potions.cpp.o"
	/bin/x86_64-linux-gnu-g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DungeonCrawler.dir/src/Items/potions.cpp.o -c /home/atte/cpp_projects/DungeonCrawler/src/Items/potions.cpp

CMakeFiles/DungeonCrawler.dir/src/Items/potions.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DungeonCrawler.dir/src/Items/potions.cpp.i"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/atte/cpp_projects/DungeonCrawler/src/Items/potions.cpp > CMakeFiles/DungeonCrawler.dir/src/Items/potions.cpp.i

CMakeFiles/DungeonCrawler.dir/src/Items/potions.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DungeonCrawler.dir/src/Items/potions.cpp.s"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/atte/cpp_projects/DungeonCrawler/src/Items/potions.cpp -o CMakeFiles/DungeonCrawler.dir/src/Items/potions.cpp.s

CMakeFiles/DungeonCrawler.dir/src/Items/rangedweapons.cpp.o: CMakeFiles/DungeonCrawler.dir/flags.make
CMakeFiles/DungeonCrawler.dir/src/Items/rangedweapons.cpp.o: ../src/Items/rangedweapons.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/atte/cpp_projects/DungeonCrawler/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/DungeonCrawler.dir/src/Items/rangedweapons.cpp.o"
	/bin/x86_64-linux-gnu-g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DungeonCrawler.dir/src/Items/rangedweapons.cpp.o -c /home/atte/cpp_projects/DungeonCrawler/src/Items/rangedweapons.cpp

CMakeFiles/DungeonCrawler.dir/src/Items/rangedweapons.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DungeonCrawler.dir/src/Items/rangedweapons.cpp.i"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/atte/cpp_projects/DungeonCrawler/src/Items/rangedweapons.cpp > CMakeFiles/DungeonCrawler.dir/src/Items/rangedweapons.cpp.i

CMakeFiles/DungeonCrawler.dir/src/Items/rangedweapons.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DungeonCrawler.dir/src/Items/rangedweapons.cpp.s"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/atte/cpp_projects/DungeonCrawler/src/Items/rangedweapons.cpp -o CMakeFiles/DungeonCrawler.dir/src/Items/rangedweapons.cpp.s

CMakeFiles/DungeonCrawler.dir/src/Items/shields.cpp.o: CMakeFiles/DungeonCrawler.dir/flags.make
CMakeFiles/DungeonCrawler.dir/src/Items/shields.cpp.o: ../src/Items/shields.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/atte/cpp_projects/DungeonCrawler/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/DungeonCrawler.dir/src/Items/shields.cpp.o"
	/bin/x86_64-linux-gnu-g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DungeonCrawler.dir/src/Items/shields.cpp.o -c /home/atte/cpp_projects/DungeonCrawler/src/Items/shields.cpp

CMakeFiles/DungeonCrawler.dir/src/Items/shields.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DungeonCrawler.dir/src/Items/shields.cpp.i"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/atte/cpp_projects/DungeonCrawler/src/Items/shields.cpp > CMakeFiles/DungeonCrawler.dir/src/Items/shields.cpp.i

CMakeFiles/DungeonCrawler.dir/src/Items/shields.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DungeonCrawler.dir/src/Items/shields.cpp.s"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/atte/cpp_projects/DungeonCrawler/src/Items/shields.cpp -o CMakeFiles/DungeonCrawler.dir/src/Items/shields.cpp.s

CMakeFiles/DungeonCrawler.dir/src/TEST_Atte.cpp.o: CMakeFiles/DungeonCrawler.dir/flags.make
CMakeFiles/DungeonCrawler.dir/src/TEST_Atte.cpp.o: ../src/TEST_Atte.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/atte/cpp_projects/DungeonCrawler/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/DungeonCrawler.dir/src/TEST_Atte.cpp.o"
	/bin/x86_64-linux-gnu-g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DungeonCrawler.dir/src/TEST_Atte.cpp.o -c /home/atte/cpp_projects/DungeonCrawler/src/TEST_Atte.cpp

CMakeFiles/DungeonCrawler.dir/src/TEST_Atte.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DungeonCrawler.dir/src/TEST_Atte.cpp.i"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/atte/cpp_projects/DungeonCrawler/src/TEST_Atte.cpp > CMakeFiles/DungeonCrawler.dir/src/TEST_Atte.cpp.i

CMakeFiles/DungeonCrawler.dir/src/TEST_Atte.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DungeonCrawler.dir/src/TEST_Atte.cpp.s"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/atte/cpp_projects/DungeonCrawler/src/TEST_Atte.cpp -o CMakeFiles/DungeonCrawler.dir/src/TEST_Atte.cpp.s

CMakeFiles/DungeonCrawler.dir/src/TEST_Binh.cpp.o: CMakeFiles/DungeonCrawler.dir/flags.make
CMakeFiles/DungeonCrawler.dir/src/TEST_Binh.cpp.o: ../src/TEST_Binh.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/atte/cpp_projects/DungeonCrawler/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/DungeonCrawler.dir/src/TEST_Binh.cpp.o"
	/bin/x86_64-linux-gnu-g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DungeonCrawler.dir/src/TEST_Binh.cpp.o -c /home/atte/cpp_projects/DungeonCrawler/src/TEST_Binh.cpp

CMakeFiles/DungeonCrawler.dir/src/TEST_Binh.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DungeonCrawler.dir/src/TEST_Binh.cpp.i"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/atte/cpp_projects/DungeonCrawler/src/TEST_Binh.cpp > CMakeFiles/DungeonCrawler.dir/src/TEST_Binh.cpp.i

CMakeFiles/DungeonCrawler.dir/src/TEST_Binh.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DungeonCrawler.dir/src/TEST_Binh.cpp.s"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/atte/cpp_projects/DungeonCrawler/src/TEST_Binh.cpp -o CMakeFiles/DungeonCrawler.dir/src/TEST_Binh.cpp.s

CMakeFiles/DungeonCrawler.dir/src/TEST_EXAMPLE.cpp.o: CMakeFiles/DungeonCrawler.dir/flags.make
CMakeFiles/DungeonCrawler.dir/src/TEST_EXAMPLE.cpp.o: ../src/TEST_EXAMPLE.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/atte/cpp_projects/DungeonCrawler/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/DungeonCrawler.dir/src/TEST_EXAMPLE.cpp.o"
	/bin/x86_64-linux-gnu-g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DungeonCrawler.dir/src/TEST_EXAMPLE.cpp.o -c /home/atte/cpp_projects/DungeonCrawler/src/TEST_EXAMPLE.cpp

CMakeFiles/DungeonCrawler.dir/src/TEST_EXAMPLE.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DungeonCrawler.dir/src/TEST_EXAMPLE.cpp.i"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/atte/cpp_projects/DungeonCrawler/src/TEST_EXAMPLE.cpp > CMakeFiles/DungeonCrawler.dir/src/TEST_EXAMPLE.cpp.i

CMakeFiles/DungeonCrawler.dir/src/TEST_EXAMPLE.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DungeonCrawler.dir/src/TEST_EXAMPLE.cpp.s"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/atte/cpp_projects/DungeonCrawler/src/TEST_EXAMPLE.cpp -o CMakeFiles/DungeonCrawler.dir/src/TEST_EXAMPLE.cpp.s

CMakeFiles/DungeonCrawler.dir/src/TEST_Elias.cpp.o: CMakeFiles/DungeonCrawler.dir/flags.make
CMakeFiles/DungeonCrawler.dir/src/TEST_Elias.cpp.o: ../src/TEST_Elias.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/atte/cpp_projects/DungeonCrawler/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object CMakeFiles/DungeonCrawler.dir/src/TEST_Elias.cpp.o"
	/bin/x86_64-linux-gnu-g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DungeonCrawler.dir/src/TEST_Elias.cpp.o -c /home/atte/cpp_projects/DungeonCrawler/src/TEST_Elias.cpp

CMakeFiles/DungeonCrawler.dir/src/TEST_Elias.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DungeonCrawler.dir/src/TEST_Elias.cpp.i"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/atte/cpp_projects/DungeonCrawler/src/TEST_Elias.cpp > CMakeFiles/DungeonCrawler.dir/src/TEST_Elias.cpp.i

CMakeFiles/DungeonCrawler.dir/src/TEST_Elias.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DungeonCrawler.dir/src/TEST_Elias.cpp.s"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/atte/cpp_projects/DungeonCrawler/src/TEST_Elias.cpp -o CMakeFiles/DungeonCrawler.dir/src/TEST_Elias.cpp.s

CMakeFiles/DungeonCrawler.dir/src/TEST_Selin.cpp.o: CMakeFiles/DungeonCrawler.dir/flags.make
CMakeFiles/DungeonCrawler.dir/src/TEST_Selin.cpp.o: ../src/TEST_Selin.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/atte/cpp_projects/DungeonCrawler/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building CXX object CMakeFiles/DungeonCrawler.dir/src/TEST_Selin.cpp.o"
	/bin/x86_64-linux-gnu-g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DungeonCrawler.dir/src/TEST_Selin.cpp.o -c /home/atte/cpp_projects/DungeonCrawler/src/TEST_Selin.cpp

CMakeFiles/DungeonCrawler.dir/src/TEST_Selin.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DungeonCrawler.dir/src/TEST_Selin.cpp.i"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/atte/cpp_projects/DungeonCrawler/src/TEST_Selin.cpp > CMakeFiles/DungeonCrawler.dir/src/TEST_Selin.cpp.i

CMakeFiles/DungeonCrawler.dir/src/TEST_Selin.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DungeonCrawler.dir/src/TEST_Selin.cpp.s"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/atte/cpp_projects/DungeonCrawler/src/TEST_Selin.cpp -o CMakeFiles/DungeonCrawler.dir/src/TEST_Selin.cpp.s

CMakeFiles/DungeonCrawler.dir/src/main.cpp.o: CMakeFiles/DungeonCrawler.dir/flags.make
CMakeFiles/DungeonCrawler.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/atte/cpp_projects/DungeonCrawler/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Building CXX object CMakeFiles/DungeonCrawler.dir/src/main.cpp.o"
	/bin/x86_64-linux-gnu-g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DungeonCrawler.dir/src/main.cpp.o -c /home/atte/cpp_projects/DungeonCrawler/src/main.cpp

CMakeFiles/DungeonCrawler.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DungeonCrawler.dir/src/main.cpp.i"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/atte/cpp_projects/DungeonCrawler/src/main.cpp > CMakeFiles/DungeonCrawler.dir/src/main.cpp.i

CMakeFiles/DungeonCrawler.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DungeonCrawler.dir/src/main.cpp.s"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/atte/cpp_projects/DungeonCrawler/src/main.cpp -o CMakeFiles/DungeonCrawler.dir/src/main.cpp.s

CMakeFiles/DungeonCrawler.dir/src/textures.cpp.o: CMakeFiles/DungeonCrawler.dir/flags.make
CMakeFiles/DungeonCrawler.dir/src/textures.cpp.o: ../src/textures.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/atte/cpp_projects/DungeonCrawler/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_18) "Building CXX object CMakeFiles/DungeonCrawler.dir/src/textures.cpp.o"
	/bin/x86_64-linux-gnu-g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DungeonCrawler.dir/src/textures.cpp.o -c /home/atte/cpp_projects/DungeonCrawler/src/textures.cpp

CMakeFiles/DungeonCrawler.dir/src/textures.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DungeonCrawler.dir/src/textures.cpp.i"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/atte/cpp_projects/DungeonCrawler/src/textures.cpp > CMakeFiles/DungeonCrawler.dir/src/textures.cpp.i

CMakeFiles/DungeonCrawler.dir/src/textures.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DungeonCrawler.dir/src/textures.cpp.s"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/atte/cpp_projects/DungeonCrawler/src/textures.cpp -o CMakeFiles/DungeonCrawler.dir/src/textures.cpp.s

# Object files for target DungeonCrawler
DungeonCrawler_OBJECTS = \
"CMakeFiles/DungeonCrawler.dir/src/Characters/character.cpp.o" \
"CMakeFiles/DungeonCrawler.dir/src/Characters/characterplayer.cpp.o" \
"CMakeFiles/DungeonCrawler.dir/src/Characters/enemy.cpp.o" \
"CMakeFiles/DungeonCrawler.dir/src/DungeonGeneration/dungeonlevel.cpp.o" \
"CMakeFiles/DungeonCrawler.dir/src/DungeonGeneration/dungeonroom.cpp.o" \
"CMakeFiles/DungeonCrawler.dir/src/DungeonGeneration/dungeontile.cpp.o" \
"CMakeFiles/DungeonCrawler.dir/src/Items/item.cpp.o" \
"CMakeFiles/DungeonCrawler.dir/src/Items/meleeweapons.cpp.o" \
"CMakeFiles/DungeonCrawler.dir/src/Items/potions.cpp.o" \
"CMakeFiles/DungeonCrawler.dir/src/Items/rangedweapons.cpp.o" \
"CMakeFiles/DungeonCrawler.dir/src/Items/shields.cpp.o" \
"CMakeFiles/DungeonCrawler.dir/src/TEST_Atte.cpp.o" \
"CMakeFiles/DungeonCrawler.dir/src/TEST_Binh.cpp.o" \
"CMakeFiles/DungeonCrawler.dir/src/TEST_EXAMPLE.cpp.o" \
"CMakeFiles/DungeonCrawler.dir/src/TEST_Elias.cpp.o" \
"CMakeFiles/DungeonCrawler.dir/src/TEST_Selin.cpp.o" \
"CMakeFiles/DungeonCrawler.dir/src/main.cpp.o" \
"CMakeFiles/DungeonCrawler.dir/src/textures.cpp.o"

# External object files for target DungeonCrawler
DungeonCrawler_EXTERNAL_OBJECTS =

DungeonCrawler: CMakeFiles/DungeonCrawler.dir/src/Characters/character.cpp.o
DungeonCrawler: CMakeFiles/DungeonCrawler.dir/src/Characters/characterplayer.cpp.o
DungeonCrawler: CMakeFiles/DungeonCrawler.dir/src/Characters/enemy.cpp.o
DungeonCrawler: CMakeFiles/DungeonCrawler.dir/src/DungeonGeneration/dungeonlevel.cpp.o
DungeonCrawler: CMakeFiles/DungeonCrawler.dir/src/DungeonGeneration/dungeonroom.cpp.o
DungeonCrawler: CMakeFiles/DungeonCrawler.dir/src/DungeonGeneration/dungeontile.cpp.o
DungeonCrawler: CMakeFiles/DungeonCrawler.dir/src/Items/item.cpp.o
DungeonCrawler: CMakeFiles/DungeonCrawler.dir/src/Items/meleeweapons.cpp.o
DungeonCrawler: CMakeFiles/DungeonCrawler.dir/src/Items/potions.cpp.o
DungeonCrawler: CMakeFiles/DungeonCrawler.dir/src/Items/rangedweapons.cpp.o
DungeonCrawler: CMakeFiles/DungeonCrawler.dir/src/Items/shields.cpp.o
DungeonCrawler: CMakeFiles/DungeonCrawler.dir/src/TEST_Atte.cpp.o
DungeonCrawler: CMakeFiles/DungeonCrawler.dir/src/TEST_Binh.cpp.o
DungeonCrawler: CMakeFiles/DungeonCrawler.dir/src/TEST_EXAMPLE.cpp.o
DungeonCrawler: CMakeFiles/DungeonCrawler.dir/src/TEST_Elias.cpp.o
DungeonCrawler: CMakeFiles/DungeonCrawler.dir/src/TEST_Selin.cpp.o
DungeonCrawler: CMakeFiles/DungeonCrawler.dir/src/main.cpp.o
DungeonCrawler: CMakeFiles/DungeonCrawler.dir/src/textures.cpp.o
DungeonCrawler: CMakeFiles/DungeonCrawler.dir/build.make
DungeonCrawler: ../libs/SFML-2.5.1_build/lib/libsfml-graphics-s.a
DungeonCrawler: ../libs/SFML-2.5.1_build/lib/libsfml-window-s.a
DungeonCrawler: ../libs/SFML-2.5.1_build/lib/libsfml-system-s.a
DungeonCrawler: ../libs/SFML-2.5.1_build/lib/libsfml-audio-s.a
DungeonCrawler: /usr/lib/x86_64-linux-gnu/libudev.so
DungeonCrawler: /usr/lib/x86_64-linux-gnu/libGL.so
DungeonCrawler: /usr/lib/x86_64-linux-gnu/libGLU.so
DungeonCrawler: /usr/lib/x86_64-linux-gnu/libOpenGL.so
DungeonCrawler: /usr/lib/x86_64-linux-gnu/libX11.so
DungeonCrawler: /usr/lib/x86_64-linux-gnu/libXrandr.so
DungeonCrawler: /usr/lib/x86_64-linux-gnu/libX11.so
DungeonCrawler: /usr/lib/x86_64-linux-gnu/libXrandr.so
DungeonCrawler: /usr/lib/x86_64-linux-gnu/libfreetype.so
DungeonCrawler: ../libs/SFML-2.5.1_build/lib/libsfml-system-s.a
DungeonCrawler: /usr/lib/x86_64-linux-gnu/libopenal.so
DungeonCrawler: /usr/lib/x86_64-linux-gnu/libvorbisenc.so
DungeonCrawler: /usr/lib/x86_64-linux-gnu/libvorbisfile.so
DungeonCrawler: /usr/lib/x86_64-linux-gnu/libvorbis.so
DungeonCrawler: /usr/lib/x86_64-linux-gnu/libogg.so
DungeonCrawler: /usr/lib/x86_64-linux-gnu/libvorbisenc.so
DungeonCrawler: /usr/lib/x86_64-linux-gnu/libvorbisfile.so
DungeonCrawler: /usr/lib/x86_64-linux-gnu/libvorbis.so
DungeonCrawler: /usr/lib/x86_64-linux-gnu/libogg.so
DungeonCrawler: /usr/lib/x86_64-linux-gnu/libFLAC.so
DungeonCrawler: CMakeFiles/DungeonCrawler.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/atte/cpp_projects/DungeonCrawler/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_19) "Linking CXX executable DungeonCrawler"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/DungeonCrawler.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DungeonCrawler.dir/build: DungeonCrawler

.PHONY : CMakeFiles/DungeonCrawler.dir/build

CMakeFiles/DungeonCrawler.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/DungeonCrawler.dir/cmake_clean.cmake
.PHONY : CMakeFiles/DungeonCrawler.dir/clean

CMakeFiles/DungeonCrawler.dir/depend:
	cd /home/atte/cpp_projects/DungeonCrawler/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/atte/cpp_projects/DungeonCrawler /home/atte/cpp_projects/DungeonCrawler /home/atte/cpp_projects/DungeonCrawler/build /home/atte/cpp_projects/DungeonCrawler/build /home/atte/cpp_projects/DungeonCrawler/build/CMakeFiles/DungeonCrawler.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/DungeonCrawler.dir/depend

