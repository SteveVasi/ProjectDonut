# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

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
CMAKE_COMMAND = /home/stefan/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/213.7172.20/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/stefan/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/213.7172.20/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/stefan/programming/donut

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/stefan/programming/donut/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/donut.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/donut.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/donut.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/donut.dir/flags.make

CMakeFiles/donut.dir/main.c.o: CMakeFiles/donut.dir/flags.make
CMakeFiles/donut.dir/main.c.o: ../main.c
CMakeFiles/donut.dir/main.c.o: CMakeFiles/donut.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/stefan/programming/donut/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/donut.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/donut.dir/main.c.o -MF CMakeFiles/donut.dir/main.c.o.d -o CMakeFiles/donut.dir/main.c.o -c /home/stefan/programming/donut/main.c

CMakeFiles/donut.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/donut.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/stefan/programming/donut/main.c > CMakeFiles/donut.dir/main.c.i

CMakeFiles/donut.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/donut.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/stefan/programming/donut/main.c -o CMakeFiles/donut.dir/main.c.s

CMakeFiles/donut.dir/matrix.c.o: CMakeFiles/donut.dir/flags.make
CMakeFiles/donut.dir/matrix.c.o: ../matrix.c
CMakeFiles/donut.dir/matrix.c.o: CMakeFiles/donut.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/stefan/programming/donut/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/donut.dir/matrix.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/donut.dir/matrix.c.o -MF CMakeFiles/donut.dir/matrix.c.o.d -o CMakeFiles/donut.dir/matrix.c.o -c /home/stefan/programming/donut/matrix.c

CMakeFiles/donut.dir/matrix.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/donut.dir/matrix.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/stefan/programming/donut/matrix.c > CMakeFiles/donut.dir/matrix.c.i

CMakeFiles/donut.dir/matrix.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/donut.dir/matrix.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/stefan/programming/donut/matrix.c -o CMakeFiles/donut.dir/matrix.c.s

# Object files for target donut
donut_OBJECTS = \
"CMakeFiles/donut.dir/main.c.o" \
"CMakeFiles/donut.dir/matrix.c.o"

# External object files for target donut
donut_EXTERNAL_OBJECTS =

donut: CMakeFiles/donut.dir/main.c.o
donut: CMakeFiles/donut.dir/matrix.c.o
donut: CMakeFiles/donut.dir/build.make
donut: CMakeFiles/donut.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/stefan/programming/donut/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable donut"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/donut.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/donut.dir/build: donut
.PHONY : CMakeFiles/donut.dir/build

CMakeFiles/donut.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/donut.dir/cmake_clean.cmake
.PHONY : CMakeFiles/donut.dir/clean

CMakeFiles/donut.dir/depend:
	cd /home/stefan/programming/donut/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/stefan/programming/donut /home/stefan/programming/donut /home/stefan/programming/donut/cmake-build-debug /home/stefan/programming/donut/cmake-build-debug /home/stefan/programming/donut/cmake-build-debug/CMakeFiles/donut.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/donut.dir/depend

