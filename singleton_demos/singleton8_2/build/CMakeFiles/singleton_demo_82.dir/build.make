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
CMAKE_SOURCE_DIR = /home/q/SingletonPattern/singleton_demos/singleton8_2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/q/SingletonPattern/singleton_demos/singleton8_2/build

# Include any dependencies generated for this target.
include CMakeFiles/singleton_demo_82.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/singleton_demo_82.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/singleton_demo_82.dir/flags.make

CMakeFiles/singleton_demo_82.dir/main.cpp.o: CMakeFiles/singleton_demo_82.dir/flags.make
CMakeFiles/singleton_demo_82.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/q/SingletonPattern/singleton_demos/singleton8_2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/singleton_demo_82.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/singleton_demo_82.dir/main.cpp.o -c /home/q/SingletonPattern/singleton_demos/singleton8_2/main.cpp

CMakeFiles/singleton_demo_82.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/singleton_demo_82.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/q/SingletonPattern/singleton_demos/singleton8_2/main.cpp > CMakeFiles/singleton_demo_82.dir/main.cpp.i

CMakeFiles/singleton_demo_82.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/singleton_demo_82.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/q/SingletonPattern/singleton_demos/singleton8_2/main.cpp -o CMakeFiles/singleton_demo_82.dir/main.cpp.s

CMakeFiles/singleton_demo_82.dir/sing.cpp.o: CMakeFiles/singleton_demo_82.dir/flags.make
CMakeFiles/singleton_demo_82.dir/sing.cpp.o: ../sing.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/q/SingletonPattern/singleton_demos/singleton8_2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/singleton_demo_82.dir/sing.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/singleton_demo_82.dir/sing.cpp.o -c /home/q/SingletonPattern/singleton_demos/singleton8_2/sing.cpp

CMakeFiles/singleton_demo_82.dir/sing.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/singleton_demo_82.dir/sing.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/q/SingletonPattern/singleton_demos/singleton8_2/sing.cpp > CMakeFiles/singleton_demo_82.dir/sing.cpp.i

CMakeFiles/singleton_demo_82.dir/sing.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/singleton_demo_82.dir/sing.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/q/SingletonPattern/singleton_demos/singleton8_2/sing.cpp -o CMakeFiles/singleton_demo_82.dir/sing.cpp.s

# Object files for target singleton_demo_82
singleton_demo_82_OBJECTS = \
"CMakeFiles/singleton_demo_82.dir/main.cpp.o" \
"CMakeFiles/singleton_demo_82.dir/sing.cpp.o"

# External object files for target singleton_demo_82
singleton_demo_82_EXTERNAL_OBJECTS =

singleton_demo_82: CMakeFiles/singleton_demo_82.dir/main.cpp.o
singleton_demo_82: CMakeFiles/singleton_demo_82.dir/sing.cpp.o
singleton_demo_82: CMakeFiles/singleton_demo_82.dir/build.make
singleton_demo_82: CMakeFiles/singleton_demo_82.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/q/SingletonPattern/singleton_demos/singleton8_2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable singleton_demo_82"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/singleton_demo_82.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/singleton_demo_82.dir/build: singleton_demo_82

.PHONY : CMakeFiles/singleton_demo_82.dir/build

CMakeFiles/singleton_demo_82.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/singleton_demo_82.dir/cmake_clean.cmake
.PHONY : CMakeFiles/singleton_demo_82.dir/clean

CMakeFiles/singleton_demo_82.dir/depend:
	cd /home/q/SingletonPattern/singleton_demos/singleton8_2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/q/SingletonPattern/singleton_demos/singleton8_2 /home/q/SingletonPattern/singleton_demos/singleton8_2 /home/q/SingletonPattern/singleton_demos/singleton8_2/build /home/q/SingletonPattern/singleton_demos/singleton8_2/build /home/q/SingletonPattern/singleton_demos/singleton8_2/build/CMakeFiles/singleton_demo_82.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/singleton_demo_82.dir/depend

