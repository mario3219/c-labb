# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jonathan/git-repositories/EDAF50/lab/lab1/buggy_programs

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jonathan/git-repositories/EDAF50/lab/lab1/buggy_programs/build-dbg

# Include any dependencies generated for this target.
include CMakeFiles/bounds-heap.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/bounds-heap.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/bounds-heap.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/bounds-heap.dir/flags.make

CMakeFiles/bounds-heap.dir/bounds-heap.cc.o: CMakeFiles/bounds-heap.dir/flags.make
CMakeFiles/bounds-heap.dir/bounds-heap.cc.o: /home/jonathan/git-repositories/EDAF50/lab/lab1/buggy_programs/bounds-heap.cc
CMakeFiles/bounds-heap.dir/bounds-heap.cc.o: CMakeFiles/bounds-heap.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/jonathan/git-repositories/EDAF50/lab/lab1/buggy_programs/build-dbg/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/bounds-heap.dir/bounds-heap.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/bounds-heap.dir/bounds-heap.cc.o -MF CMakeFiles/bounds-heap.dir/bounds-heap.cc.o.d -o CMakeFiles/bounds-heap.dir/bounds-heap.cc.o -c /home/jonathan/git-repositories/EDAF50/lab/lab1/buggy_programs/bounds-heap.cc

CMakeFiles/bounds-heap.dir/bounds-heap.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/bounds-heap.dir/bounds-heap.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jonathan/git-repositories/EDAF50/lab/lab1/buggy_programs/bounds-heap.cc > CMakeFiles/bounds-heap.dir/bounds-heap.cc.i

CMakeFiles/bounds-heap.dir/bounds-heap.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/bounds-heap.dir/bounds-heap.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jonathan/git-repositories/EDAF50/lab/lab1/buggy_programs/bounds-heap.cc -o CMakeFiles/bounds-heap.dir/bounds-heap.cc.s

# Object files for target bounds-heap
bounds__heap_OBJECTS = \
"CMakeFiles/bounds-heap.dir/bounds-heap.cc.o"

# External object files for target bounds-heap
bounds__heap_EXTERNAL_OBJECTS =

bounds-heap: CMakeFiles/bounds-heap.dir/bounds-heap.cc.o
bounds-heap: CMakeFiles/bounds-heap.dir/build.make
bounds-heap: CMakeFiles/bounds-heap.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/jonathan/git-repositories/EDAF50/lab/lab1/buggy_programs/build-dbg/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable bounds-heap"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/bounds-heap.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/bounds-heap.dir/build: bounds-heap
.PHONY : CMakeFiles/bounds-heap.dir/build

CMakeFiles/bounds-heap.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/bounds-heap.dir/cmake_clean.cmake
.PHONY : CMakeFiles/bounds-heap.dir/clean

CMakeFiles/bounds-heap.dir/depend:
	cd /home/jonathan/git-repositories/EDAF50/lab/lab1/buggy_programs/build-dbg && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jonathan/git-repositories/EDAF50/lab/lab1/buggy_programs /home/jonathan/git-repositories/EDAF50/lab/lab1/buggy_programs /home/jonathan/git-repositories/EDAF50/lab/lab1/buggy_programs/build-dbg /home/jonathan/git-repositories/EDAF50/lab/lab1/buggy_programs/build-dbg /home/jonathan/git-repositories/EDAF50/lab/lab1/buggy_programs/build-dbg/CMakeFiles/bounds-heap.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/bounds-heap.dir/depend

