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
CMAKE_SOURCE_DIR = /home/jr/Programs/jrshell/cmake

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jr/Programs/jrshell/cmake

# Include any dependencies generated for this target.
include CMakeFiles/jrshell.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/jrshell.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/jrshell.dir/flags.make

CMakeFiles/jrshell.dir/home/jr/Programs/jrshell/src/jrshell.c.o: CMakeFiles/jrshell.dir/flags.make
CMakeFiles/jrshell.dir/home/jr/Programs/jrshell/src/jrshell.c.o: /home/jr/Programs/jrshell/src/jrshell.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jr/Programs/jrshell/cmake/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/jrshell.dir/home/jr/Programs/jrshell/src/jrshell.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/jrshell.dir/home/jr/Programs/jrshell/src/jrshell.c.o   -c /home/jr/Programs/jrshell/src/jrshell.c

CMakeFiles/jrshell.dir/home/jr/Programs/jrshell/src/jrshell.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/jrshell.dir/home/jr/Programs/jrshell/src/jrshell.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/jr/Programs/jrshell/src/jrshell.c > CMakeFiles/jrshell.dir/home/jr/Programs/jrshell/src/jrshell.c.i

CMakeFiles/jrshell.dir/home/jr/Programs/jrshell/src/jrshell.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/jrshell.dir/home/jr/Programs/jrshell/src/jrshell.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/jr/Programs/jrshell/src/jrshell.c -o CMakeFiles/jrshell.dir/home/jr/Programs/jrshell/src/jrshell.c.s

CMakeFiles/jrshell.dir/home/jr/Programs/jrshell/src/main.c.o: CMakeFiles/jrshell.dir/flags.make
CMakeFiles/jrshell.dir/home/jr/Programs/jrshell/src/main.c.o: /home/jr/Programs/jrshell/src/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jr/Programs/jrshell/cmake/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/jrshell.dir/home/jr/Programs/jrshell/src/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/jrshell.dir/home/jr/Programs/jrshell/src/main.c.o   -c /home/jr/Programs/jrshell/src/main.c

CMakeFiles/jrshell.dir/home/jr/Programs/jrshell/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/jrshell.dir/home/jr/Programs/jrshell/src/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/jr/Programs/jrshell/src/main.c > CMakeFiles/jrshell.dir/home/jr/Programs/jrshell/src/main.c.i

CMakeFiles/jrshell.dir/home/jr/Programs/jrshell/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/jrshell.dir/home/jr/Programs/jrshell/src/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/jr/Programs/jrshell/src/main.c -o CMakeFiles/jrshell.dir/home/jr/Programs/jrshell/src/main.c.s

# Object files for target jrshell
jrshell_OBJECTS = \
"CMakeFiles/jrshell.dir/home/jr/Programs/jrshell/src/jrshell.c.o" \
"CMakeFiles/jrshell.dir/home/jr/Programs/jrshell/src/main.c.o"

# External object files for target jrshell
jrshell_EXTERNAL_OBJECTS =

jrshell: CMakeFiles/jrshell.dir/home/jr/Programs/jrshell/src/jrshell.c.o
jrshell: CMakeFiles/jrshell.dir/home/jr/Programs/jrshell/src/main.c.o
jrshell: CMakeFiles/jrshell.dir/build.make
jrshell: CMakeFiles/jrshell.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jr/Programs/jrshell/cmake/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable jrshell"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/jrshell.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/jrshell.dir/build: jrshell

.PHONY : CMakeFiles/jrshell.dir/build

CMakeFiles/jrshell.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/jrshell.dir/cmake_clean.cmake
.PHONY : CMakeFiles/jrshell.dir/clean

CMakeFiles/jrshell.dir/depend:
	cd /home/jr/Programs/jrshell/cmake && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jr/Programs/jrshell/cmake /home/jr/Programs/jrshell/cmake /home/jr/Programs/jrshell/cmake /home/jr/Programs/jrshell/cmake /home/jr/Programs/jrshell/cmake/CMakeFiles/jrshell.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/jrshell.dir/depend

