# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/luka/Downloads/a2-login

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/luka/Downloads/a2-login/build

# Include any dependencies generated for this target.
include CMakeFiles/bench.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/bench.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/bench.dir/flags.make

CMakeFiles/bench.dir/src/bench.cpp.o: CMakeFiles/bench.dir/flags.make
CMakeFiles/bench.dir/src/bench.cpp.o: ../src/bench.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/luka/Downloads/a2-login/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/bench.dir/src/bench.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/bench.dir/src/bench.cpp.o -c /home/luka/Downloads/a2-login/src/bench.cpp

CMakeFiles/bench.dir/src/bench.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bench.dir/src/bench.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/luka/Downloads/a2-login/src/bench.cpp > CMakeFiles/bench.dir/src/bench.cpp.i

CMakeFiles/bench.dir/src/bench.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bench.dir/src/bench.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/luka/Downloads/a2-login/src/bench.cpp -o CMakeFiles/bench.dir/src/bench.cpp.s

CMakeFiles/bench.dir/src/bench.cpp.o.requires:

.PHONY : CMakeFiles/bench.dir/src/bench.cpp.o.requires

CMakeFiles/bench.dir/src/bench.cpp.o.provides: CMakeFiles/bench.dir/src/bench.cpp.o.requires
	$(MAKE) -f CMakeFiles/bench.dir/build.make CMakeFiles/bench.dir/src/bench.cpp.o.provides.build
.PHONY : CMakeFiles/bench.dir/src/bench.cpp.o.provides

CMakeFiles/bench.dir/src/bench.cpp.o.provides.build: CMakeFiles/bench.dir/src/bench.cpp.o


# Object files for target bench
bench_OBJECTS = \
"CMakeFiles/bench.dir/src/bench.cpp.o"

# External object files for target bench
bench_EXTERNAL_OBJECTS =

bench: CMakeFiles/bench.dir/src/bench.cpp.o
bench: CMakeFiles/bench.dir/build.make
bench: libdictionary.a
bench: /usr/local/lib/libbenchmark.a
bench: /usr/lib/x86_64-linux-gnu/librt.so
bench: CMakeFiles/bench.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/luka/Downloads/a2-login/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable bench"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/bench.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/bench.dir/build: bench

.PHONY : CMakeFiles/bench.dir/build

CMakeFiles/bench.dir/requires: CMakeFiles/bench.dir/src/bench.cpp.o.requires

.PHONY : CMakeFiles/bench.dir/requires

CMakeFiles/bench.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/bench.dir/cmake_clean.cmake
.PHONY : CMakeFiles/bench.dir/clean

CMakeFiles/bench.dir/depend:
	cd /home/luka/Downloads/a2-login/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/luka/Downloads/a2-login /home/luka/Downloads/a2-login /home/luka/Downloads/a2-login/build /home/luka/Downloads/a2-login/build /home/luka/Downloads/a2-login/build/CMakeFiles/bench.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/bench.dir/depend

