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
CMAKE_SOURCE_DIR = /home/atte/cpp_projects/DungeonCrawler/libs/SFML-2.5.1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/atte/cpp_projects/DungeonCrawler/libs/SFML-2.5.1_build

# Include any dependencies generated for this target.
include src/SFML/Network/CMakeFiles/sfml-network.dir/depend.make

# Include the progress variables for this target.
include src/SFML/Network/CMakeFiles/sfml-network.dir/progress.make

# Include the compile flags for this target's objects.
include src/SFML/Network/CMakeFiles/sfml-network.dir/flags.make

src/SFML/Network/CMakeFiles/sfml-network.dir/Ftp.cpp.o: src/SFML/Network/CMakeFiles/sfml-network.dir/flags.make
src/SFML/Network/CMakeFiles/sfml-network.dir/Ftp.cpp.o: /home/atte/cpp_projects/DungeonCrawler/libs/SFML-2.5.1/src/SFML/Network/Ftp.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/atte/cpp_projects/DungeonCrawler/libs/SFML-2.5.1_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/SFML/Network/CMakeFiles/sfml-network.dir/Ftp.cpp.o"
	cd /home/atte/cpp_projects/DungeonCrawler/libs/SFML-2.5.1_build/src/SFML/Network && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sfml-network.dir/Ftp.cpp.o -c /home/atte/cpp_projects/DungeonCrawler/libs/SFML-2.5.1/src/SFML/Network/Ftp.cpp

src/SFML/Network/CMakeFiles/sfml-network.dir/Ftp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sfml-network.dir/Ftp.cpp.i"
	cd /home/atte/cpp_projects/DungeonCrawler/libs/SFML-2.5.1_build/src/SFML/Network && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/atte/cpp_projects/DungeonCrawler/libs/SFML-2.5.1/src/SFML/Network/Ftp.cpp > CMakeFiles/sfml-network.dir/Ftp.cpp.i

src/SFML/Network/CMakeFiles/sfml-network.dir/Ftp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sfml-network.dir/Ftp.cpp.s"
	cd /home/atte/cpp_projects/DungeonCrawler/libs/SFML-2.5.1_build/src/SFML/Network && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/atte/cpp_projects/DungeonCrawler/libs/SFML-2.5.1/src/SFML/Network/Ftp.cpp -o CMakeFiles/sfml-network.dir/Ftp.cpp.s

src/SFML/Network/CMakeFiles/sfml-network.dir/Http.cpp.o: src/SFML/Network/CMakeFiles/sfml-network.dir/flags.make
src/SFML/Network/CMakeFiles/sfml-network.dir/Http.cpp.o: /home/atte/cpp_projects/DungeonCrawler/libs/SFML-2.5.1/src/SFML/Network/Http.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/atte/cpp_projects/DungeonCrawler/libs/SFML-2.5.1_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/SFML/Network/CMakeFiles/sfml-network.dir/Http.cpp.o"
	cd /home/atte/cpp_projects/DungeonCrawler/libs/SFML-2.5.1_build/src/SFML/Network && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sfml-network.dir/Http.cpp.o -c /home/atte/cpp_projects/DungeonCrawler/libs/SFML-2.5.1/src/SFML/Network/Http.cpp

src/SFML/Network/CMakeFiles/sfml-network.dir/Http.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sfml-network.dir/Http.cpp.i"
	cd /home/atte/cpp_projects/DungeonCrawler/libs/SFML-2.5.1_build/src/SFML/Network && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/atte/cpp_projects/DungeonCrawler/libs/SFML-2.5.1/src/SFML/Network/Http.cpp > CMakeFiles/sfml-network.dir/Http.cpp.i

src/SFML/Network/CMakeFiles/sfml-network.dir/Http.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sfml-network.dir/Http.cpp.s"
	cd /home/atte/cpp_projects/DungeonCrawler/libs/SFML-2.5.1_build/src/SFML/Network && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/atte/cpp_projects/DungeonCrawler/libs/SFML-2.5.1/src/SFML/Network/Http.cpp -o CMakeFiles/sfml-network.dir/Http.cpp.s

src/SFML/Network/CMakeFiles/sfml-network.dir/IpAddress.cpp.o: src/SFML/Network/CMakeFiles/sfml-network.dir/flags.make
src/SFML/Network/CMakeFiles/sfml-network.dir/IpAddress.cpp.o: /home/atte/cpp_projects/DungeonCrawler/libs/SFML-2.5.1/src/SFML/Network/IpAddress.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/atte/cpp_projects/DungeonCrawler/libs/SFML-2.5.1_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/SFML/Network/CMakeFiles/sfml-network.dir/IpAddress.cpp.o"
	cd /home/atte/cpp_projects/DungeonCrawler/libs/SFML-2.5.1_build/src/SFML/Network && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sfml-network.dir/IpAddress.cpp.o -c /home/atte/cpp_projects/DungeonCrawler/libs/SFML-2.5.1/src/SFML/Network/IpAddress.cpp

src/SFML/Network/CMakeFiles/sfml-network.dir/IpAddress.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sfml-network.dir/IpAddress.cpp.i"
	cd /home/atte/cpp_projects/DungeonCrawler/libs/SFML-2.5.1_build/src/SFML/Network && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/atte/cpp_projects/DungeonCrawler/libs/SFML-2.5.1/src/SFML/Network/IpAddress.cpp > CMakeFiles/sfml-network.dir/IpAddress.cpp.i

src/SFML/Network/CMakeFiles/sfml-network.dir/IpAddress.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sfml-network.dir/IpAddress.cpp.s"
	cd /home/atte/cpp_projects/DungeonCrawler/libs/SFML-2.5.1_build/src/SFML/Network && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/atte/cpp_projects/DungeonCrawler/libs/SFML-2.5.1/src/SFML/Network/IpAddress.cpp -o CMakeFiles/sfml-network.dir/IpAddress.cpp.s

src/SFML/Network/CMakeFiles/sfml-network.dir/Packet.cpp.o: src/SFML/Network/CMakeFiles/sfml-network.dir/flags.make
src/SFML/Network/CMakeFiles/sfml-network.dir/Packet.cpp.o: /home/atte/cpp_projects/DungeonCrawler/libs/SFML-2.5.1/src/SFML/Network/Packet.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/atte/cpp_projects/DungeonCrawler/libs/SFML-2.5.1_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/SFML/Network/CMakeFiles/sfml-network.dir/Packet.cpp.o"
	cd /home/atte/cpp_projects/DungeonCrawler/libs/SFML-2.5.1_build/src/SFML/Network && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sfml-network.dir/Packet.cpp.o -c /home/atte/cpp_projects/DungeonCrawler/libs/SFML-2.5.1/src/SFML/Network/Packet.cpp

src/SFML/Network/CMakeFiles/sfml-network.dir/Packet.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sfml-network.dir/Packet.cpp.i"
	cd /home/atte/cpp_projects/DungeonCrawler/libs/SFML-2.5.1_build/src/SFML/Network && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/atte/cpp_projects/DungeonCrawler/libs/SFML-2.5.1/src/SFML/Network/Packet.cpp > CMakeFiles/sfml-network.dir/Packet.cpp.i

src/SFML/Network/CMakeFiles/sfml-network.dir/Packet.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sfml-network.dir/Packet.cpp.s"
	cd /home/atte/cpp_projects/DungeonCrawler/libs/SFML-2.5.1_build/src/SFML/Network && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/atte/cpp_projects/DungeonCrawler/libs/SFML-2.5.1/src/SFML/Network/Packet.cpp -o CMakeFiles/sfml-network.dir/Packet.cpp.s

src/SFML/Network/CMakeFiles/sfml-network.dir/Socket.cpp.o: src/SFML/Network/CMakeFiles/sfml-network.dir/flags.make
src/SFML/Network/CMakeFiles/sfml-network.dir/Socket.cpp.o: /home/atte/cpp_projects/DungeonCrawler/libs/SFML-2.5.1/src/SFML/Network/Socket.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/atte/cpp_projects/DungeonCrawler/libs/SFML-2.5.1_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/SFML/Network/CMakeFiles/sfml-network.dir/Socket.cpp.o"
	cd /home/atte/cpp_projects/DungeonCrawler/libs/SFML-2.5.1_build/src/SFML/Network && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sfml-network.dir/Socket.cpp.o -c /home/atte/cpp_projects/DungeonCrawler/libs/SFML-2.5.1/src/SFML/Network/Socket.cpp

src/SFML/Network/CMakeFiles/sfml-network.dir/Socket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sfml-network.dir/Socket.cpp.i"
	cd /home/atte/cpp_projects/DungeonCrawler/libs/SFML-2.5.1_build/src/SFML/Network && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/atte/cpp_projects/DungeonCrawler/libs/SFML-2.5.1/src/SFML/Network/Socket.cpp > CMakeFiles/sfml-network.dir/Socket.cpp.i

src/SFML/Network/CMakeFiles/sfml-network.dir/Socket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sfml-network.dir/Socket.cpp.s"
	cd /home/atte/cpp_projects/DungeonCrawler/libs/SFML-2.5.1_build/src/SFML/Network && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/atte/cpp_projects/DungeonCrawler/libs/SFML-2.5.1/src/SFML/Network/Socket.cpp -o CMakeFiles/sfml-network.dir/Socket.cpp.s

src/SFML/Network/CMakeFiles/sfml-network.dir/SocketSelector.cpp.o: src/SFML/Network/CMakeFiles/sfml-network.dir/flags.make
src/SFML/Network/CMakeFiles/sfml-network.dir/SocketSelector.cpp.o: /home/atte/cpp_projects/DungeonCrawler/libs/SFML-2.5.1/src/SFML/Network/SocketSelector.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/atte/cpp_projects/DungeonCrawler/libs/SFML-2.5.1_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object src/SFML/Network/CMakeFiles/sfml-network.dir/SocketSelector.cpp.o"
	cd /home/atte/cpp_projects/DungeonCrawler/libs/SFML-2.5.1_build/src/SFML/Network && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sfml-network.dir/SocketSelector.cpp.o -c /home/atte/cpp_projects/DungeonCrawler/libs/SFML-2.5.1/src/SFML/Network/SocketSelector.cpp

src/SFML/Network/CMakeFiles/sfml-network.dir/SocketSelector.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sfml-network.dir/SocketSelector.cpp.i"
	cd /home/atte/cpp_projects/DungeonCrawler/libs/SFML-2.5.1_build/src/SFML/Network && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/atte/cpp_projects/DungeonCrawler/libs/SFML-2.5.1/src/SFML/Network/SocketSelector.cpp > CMakeFiles/sfml-network.dir/SocketSelector.cpp.i

src/SFML/Network/CMakeFiles/sfml-network.dir/SocketSelector.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sfml-network.dir/SocketSelector.cpp.s"
	cd /home/atte/cpp_projects/DungeonCrawler/libs/SFML-2.5.1_build/src/SFML/Network && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/atte/cpp_projects/DungeonCrawler/libs/SFML-2.5.1/src/SFML/Network/SocketSelector.cpp -o CMakeFiles/sfml-network.dir/SocketSelector.cpp.s

src/SFML/Network/CMakeFiles/sfml-network.dir/TcpListener.cpp.o: src/SFML/Network/CMakeFiles/sfml-network.dir/flags.make
src/SFML/Network/CMakeFiles/sfml-network.dir/TcpListener.cpp.o: /home/atte/cpp_projects/DungeonCrawler/libs/SFML-2.5.1/src/SFML/Network/TcpListener.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/atte/cpp_projects/DungeonCrawler/libs/SFML-2.5.1_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object src/SFML/Network/CMakeFiles/sfml-network.dir/TcpListener.cpp.o"
	cd /home/atte/cpp_projects/DungeonCrawler/libs/SFML-2.5.1_build/src/SFML/Network && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sfml-network.dir/TcpListener.cpp.o -c /home/atte/cpp_projects/DungeonCrawler/libs/SFML-2.5.1/src/SFML/Network/TcpListener.cpp

src/SFML/Network/CMakeFiles/sfml-network.dir/TcpListener.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sfml-network.dir/TcpListener.cpp.i"
	cd /home/atte/cpp_projects/DungeonCrawler/libs/SFML-2.5.1_build/src/SFML/Network && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/atte/cpp_projects/DungeonCrawler/libs/SFML-2.5.1/src/SFML/Network/TcpListener.cpp > CMakeFiles/sfml-network.dir/TcpListener.cpp.i

src/SFML/Network/CMakeFiles/sfml-network.dir/TcpListener.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sfml-network.dir/TcpListener.cpp.s"
	cd /home/atte/cpp_projects/DungeonCrawler/libs/SFML-2.5.1_build/src/SFML/Network && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/atte/cpp_projects/DungeonCrawler/libs/SFML-2.5.1/src/SFML/Network/TcpListener.cpp -o CMakeFiles/sfml-network.dir/TcpListener.cpp.s

src/SFML/Network/CMakeFiles/sfml-network.dir/TcpSocket.cpp.o: src/SFML/Network/CMakeFiles/sfml-network.dir/flags.make
src/SFML/Network/CMakeFiles/sfml-network.dir/TcpSocket.cpp.o: /home/atte/cpp_projects/DungeonCrawler/libs/SFML-2.5.1/src/SFML/Network/TcpSocket.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/atte/cpp_projects/DungeonCrawler/libs/SFML-2.5.1_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object src/SFML/Network/CMakeFiles/sfml-network.dir/TcpSocket.cpp.o"
	cd /home/atte/cpp_projects/DungeonCrawler/libs/SFML-2.5.1_build/src/SFML/Network && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sfml-network.dir/TcpSocket.cpp.o -c /home/atte/cpp_projects/DungeonCrawler/libs/SFML-2.5.1/src/SFML/Network/TcpSocket.cpp

src/SFML/Network/CMakeFiles/sfml-network.dir/TcpSocket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sfml-network.dir/TcpSocket.cpp.i"
	cd /home/atte/cpp_projects/DungeonCrawler/libs/SFML-2.5.1_build/src/SFML/Network && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/atte/cpp_projects/DungeonCrawler/libs/SFML-2.5.1/src/SFML/Network/TcpSocket.cpp > CMakeFiles/sfml-network.dir/TcpSocket.cpp.i

src/SFML/Network/CMakeFiles/sfml-network.dir/TcpSocket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sfml-network.dir/TcpSocket.cpp.s"
	cd /home/atte/cpp_projects/DungeonCrawler/libs/SFML-2.5.1_build/src/SFML/Network && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/atte/cpp_projects/DungeonCrawler/libs/SFML-2.5.1/src/SFML/Network/TcpSocket.cpp -o CMakeFiles/sfml-network.dir/TcpSocket.cpp.s

src/SFML/Network/CMakeFiles/sfml-network.dir/UdpSocket.cpp.o: src/SFML/Network/CMakeFiles/sfml-network.dir/flags.make
src/SFML/Network/CMakeFiles/sfml-network.dir/UdpSocket.cpp.o: /home/atte/cpp_projects/DungeonCrawler/libs/SFML-2.5.1/src/SFML/Network/UdpSocket.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/atte/cpp_projects/DungeonCrawler/libs/SFML-2.5.1_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object src/SFML/Network/CMakeFiles/sfml-network.dir/UdpSocket.cpp.o"
	cd /home/atte/cpp_projects/DungeonCrawler/libs/SFML-2.5.1_build/src/SFML/Network && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sfml-network.dir/UdpSocket.cpp.o -c /home/atte/cpp_projects/DungeonCrawler/libs/SFML-2.5.1/src/SFML/Network/UdpSocket.cpp

src/SFML/Network/CMakeFiles/sfml-network.dir/UdpSocket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sfml-network.dir/UdpSocket.cpp.i"
	cd /home/atte/cpp_projects/DungeonCrawler/libs/SFML-2.5.1_build/src/SFML/Network && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/atte/cpp_projects/DungeonCrawler/libs/SFML-2.5.1/src/SFML/Network/UdpSocket.cpp > CMakeFiles/sfml-network.dir/UdpSocket.cpp.i

src/SFML/Network/CMakeFiles/sfml-network.dir/UdpSocket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sfml-network.dir/UdpSocket.cpp.s"
	cd /home/atte/cpp_projects/DungeonCrawler/libs/SFML-2.5.1_build/src/SFML/Network && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/atte/cpp_projects/DungeonCrawler/libs/SFML-2.5.1/src/SFML/Network/UdpSocket.cpp -o CMakeFiles/sfml-network.dir/UdpSocket.cpp.s

src/SFML/Network/CMakeFiles/sfml-network.dir/Unix/SocketImpl.cpp.o: src/SFML/Network/CMakeFiles/sfml-network.dir/flags.make
src/SFML/Network/CMakeFiles/sfml-network.dir/Unix/SocketImpl.cpp.o: /home/atte/cpp_projects/DungeonCrawler/libs/SFML-2.5.1/src/SFML/Network/Unix/SocketImpl.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/atte/cpp_projects/DungeonCrawler/libs/SFML-2.5.1_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object src/SFML/Network/CMakeFiles/sfml-network.dir/Unix/SocketImpl.cpp.o"
	cd /home/atte/cpp_projects/DungeonCrawler/libs/SFML-2.5.1_build/src/SFML/Network && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sfml-network.dir/Unix/SocketImpl.cpp.o -c /home/atte/cpp_projects/DungeonCrawler/libs/SFML-2.5.1/src/SFML/Network/Unix/SocketImpl.cpp

src/SFML/Network/CMakeFiles/sfml-network.dir/Unix/SocketImpl.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sfml-network.dir/Unix/SocketImpl.cpp.i"
	cd /home/atte/cpp_projects/DungeonCrawler/libs/SFML-2.5.1_build/src/SFML/Network && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/atte/cpp_projects/DungeonCrawler/libs/SFML-2.5.1/src/SFML/Network/Unix/SocketImpl.cpp > CMakeFiles/sfml-network.dir/Unix/SocketImpl.cpp.i

src/SFML/Network/CMakeFiles/sfml-network.dir/Unix/SocketImpl.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sfml-network.dir/Unix/SocketImpl.cpp.s"
	cd /home/atte/cpp_projects/DungeonCrawler/libs/SFML-2.5.1_build/src/SFML/Network && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/atte/cpp_projects/DungeonCrawler/libs/SFML-2.5.1/src/SFML/Network/Unix/SocketImpl.cpp -o CMakeFiles/sfml-network.dir/Unix/SocketImpl.cpp.s

# Object files for target sfml-network
sfml__network_OBJECTS = \
"CMakeFiles/sfml-network.dir/Ftp.cpp.o" \
"CMakeFiles/sfml-network.dir/Http.cpp.o" \
"CMakeFiles/sfml-network.dir/IpAddress.cpp.o" \
"CMakeFiles/sfml-network.dir/Packet.cpp.o" \
"CMakeFiles/sfml-network.dir/Socket.cpp.o" \
"CMakeFiles/sfml-network.dir/SocketSelector.cpp.o" \
"CMakeFiles/sfml-network.dir/TcpListener.cpp.o" \
"CMakeFiles/sfml-network.dir/TcpSocket.cpp.o" \
"CMakeFiles/sfml-network.dir/UdpSocket.cpp.o" \
"CMakeFiles/sfml-network.dir/Unix/SocketImpl.cpp.o"

# External object files for target sfml-network
sfml__network_EXTERNAL_OBJECTS =

lib/libsfml-network-s.a: src/SFML/Network/CMakeFiles/sfml-network.dir/Ftp.cpp.o
lib/libsfml-network-s.a: src/SFML/Network/CMakeFiles/sfml-network.dir/Http.cpp.o
lib/libsfml-network-s.a: src/SFML/Network/CMakeFiles/sfml-network.dir/IpAddress.cpp.o
lib/libsfml-network-s.a: src/SFML/Network/CMakeFiles/sfml-network.dir/Packet.cpp.o
lib/libsfml-network-s.a: src/SFML/Network/CMakeFiles/sfml-network.dir/Socket.cpp.o
lib/libsfml-network-s.a: src/SFML/Network/CMakeFiles/sfml-network.dir/SocketSelector.cpp.o
lib/libsfml-network-s.a: src/SFML/Network/CMakeFiles/sfml-network.dir/TcpListener.cpp.o
lib/libsfml-network-s.a: src/SFML/Network/CMakeFiles/sfml-network.dir/TcpSocket.cpp.o
lib/libsfml-network-s.a: src/SFML/Network/CMakeFiles/sfml-network.dir/UdpSocket.cpp.o
lib/libsfml-network-s.a: src/SFML/Network/CMakeFiles/sfml-network.dir/Unix/SocketImpl.cpp.o
lib/libsfml-network-s.a: src/SFML/Network/CMakeFiles/sfml-network.dir/build.make
lib/libsfml-network-s.a: src/SFML/Network/CMakeFiles/sfml-network.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/atte/cpp_projects/DungeonCrawler/libs/SFML-2.5.1_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking CXX static library ../../../lib/libsfml-network-s.a"
	cd /home/atte/cpp_projects/DungeonCrawler/libs/SFML-2.5.1_build/src/SFML/Network && $(CMAKE_COMMAND) -P CMakeFiles/sfml-network.dir/cmake_clean_target.cmake
	cd /home/atte/cpp_projects/DungeonCrawler/libs/SFML-2.5.1_build/src/SFML/Network && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sfml-network.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/SFML/Network/CMakeFiles/sfml-network.dir/build: lib/libsfml-network-s.a

.PHONY : src/SFML/Network/CMakeFiles/sfml-network.dir/build

src/SFML/Network/CMakeFiles/sfml-network.dir/clean:
	cd /home/atte/cpp_projects/DungeonCrawler/libs/SFML-2.5.1_build/src/SFML/Network && $(CMAKE_COMMAND) -P CMakeFiles/sfml-network.dir/cmake_clean.cmake
.PHONY : src/SFML/Network/CMakeFiles/sfml-network.dir/clean

src/SFML/Network/CMakeFiles/sfml-network.dir/depend:
	cd /home/atte/cpp_projects/DungeonCrawler/libs/SFML-2.5.1_build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/atte/cpp_projects/DungeonCrawler/libs/SFML-2.5.1 /home/atte/cpp_projects/DungeonCrawler/libs/SFML-2.5.1/src/SFML/Network /home/atte/cpp_projects/DungeonCrawler/libs/SFML-2.5.1_build /home/atte/cpp_projects/DungeonCrawler/libs/SFML-2.5.1_build/src/SFML/Network /home/atte/cpp_projects/DungeonCrawler/libs/SFML-2.5.1_build/src/SFML/Network/CMakeFiles/sfml-network.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/SFML/Network/CMakeFiles/sfml-network.dir/depend

