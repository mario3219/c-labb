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
CMAKE_SOURCE_DIR = /home/jonathan/git-repositories/EDAF50/lab/lab1/cmake-list-coding

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jonathan/git-repositories/EDAF50/lab/lab1/cmake-list-coding/build

# Include any dependencies generated for this target.
include CMakeFiles/ltest.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/ltest.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ltest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ltest.dir/flags.make

CMakeFiles/ltest.dir/ltest.cc.o: CMakeFiles/ltest.dir/flags.make
CMakeFiles/ltest.dir/ltest.cc.o: /home/jonathan/git-repositories/EDAF50/lab/lab1/cmake-list-coding/ltest.cc
CMakeFiles/ltest.dir/ltest.cc.o: CMakeFiles/ltest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/jonathan/git-repositories/EDAF50/lab/lab1/cmake-list-coding/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ltest.dir/ltest.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ltest.dir/ltest.cc.o -MF CMakeFiles/ltest.dir/ltest.cc.o.d -o CMakeFiles/ltest.dir/ltest.cc.o -c /home/jonathan/git-repositories/EDAF50/lab/lab1/cmake-list-coding/ltest.cc

CMakeFiles/ltest.dir/ltest.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/ltest.dir/ltest.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jonathan/git-repositories/EDAF50/lab/lab1/cmake-list-coding/ltest.cc > CMakeFiles/ltest.dir/ltest.cc.i

CMakeFiles/ltest.dir/ltest.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/ltest.dir/ltest.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jonathan/git-repositories/EDAF50/lab/lab1/cmake-list-coding/ltest.cc -o CMakeFiles/ltest.dir/ltest.cc.s

# Object files for target ltest
ltest_OBJECTS = \
"CMakeFiles/ltest.dir/ltest.cc.o"

# External object files for target ltest
ltest_EXTERNAL_OBJECTS =

ltest: CMakeFiles/ltest.dir/ltest.cc.o
ltest: CMakeFiles/ltest.dir/build.make
ltest: lib/liblib.a
ltest: CMakeFiles/ltest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/jonathan/git-repositories/EDAF50/lab/lab1/cmake-list-coding/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ltest"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ltest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ltest.dir/build: ltest
.PHONY : CMakeFiles/ltest.dir/build

CMakeFiles/ltest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ltest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ltest.dir/clean

CMakeFiles/ltest.dir/depend:
	cd /home/jonathan/git-repositories/EDAF50/lab/lab1/cmake-list-coding/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jonathan/git-repositories/EDAF50/lab/lab1/cmake-list-coding /home/jonathan/git-repositories/EDAF50/lab/lab1/cmake-list-coding /home/jonathan/git-repositories/EDAF50/lab/lab1/cmake-list-coding/build /home/jonathan/git-repositories/EDAF50/lab/lab1/cmake-list-coding/build /home/jonathan/git-repositories/EDAF50/lab/lab1/cmake-list-coding/build/CMakeFiles/ltest.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/ltest.dir/depend

