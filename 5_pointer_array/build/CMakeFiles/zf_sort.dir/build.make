# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = /home/yh/C-Programming-K-R/5_pointer_array

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/yh/C-Programming-K-R/5_pointer_array/build

# Include any dependencies generated for this target.
include CMakeFiles/zf_sort.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/zf_sort.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/zf_sort.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/zf_sort.dir/flags.make

CMakeFiles/zf_sort.dir/5.6_pointers_in_array.c.o: CMakeFiles/zf_sort.dir/flags.make
CMakeFiles/zf_sort.dir/5.6_pointers_in_array.c.o: ../5.6_pointers_in_array.c
CMakeFiles/zf_sort.dir/5.6_pointers_in_array.c.o: CMakeFiles/zf_sort.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yh/C-Programming-K-R/5_pointer_array/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/zf_sort.dir/5.6_pointers_in_array.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/zf_sort.dir/5.6_pointers_in_array.c.o -MF CMakeFiles/zf_sort.dir/5.6_pointers_in_array.c.o.d -o CMakeFiles/zf_sort.dir/5.6_pointers_in_array.c.o -c /home/yh/C-Programming-K-R/5_pointer_array/5.6_pointers_in_array.c

CMakeFiles/zf_sort.dir/5.6_pointers_in_array.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/zf_sort.dir/5.6_pointers_in_array.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/yh/C-Programming-K-R/5_pointer_array/5.6_pointers_in_array.c > CMakeFiles/zf_sort.dir/5.6_pointers_in_array.c.i

CMakeFiles/zf_sort.dir/5.6_pointers_in_array.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/zf_sort.dir/5.6_pointers_in_array.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/yh/C-Programming-K-R/5_pointer_array/5.6_pointers_in_array.c -o CMakeFiles/zf_sort.dir/5.6_pointers_in_array.c.s

CMakeFiles/zf_sort.dir/lib/lines.c.o: CMakeFiles/zf_sort.dir/flags.make
CMakeFiles/zf_sort.dir/lib/lines.c.o: ../lib/lines.c
CMakeFiles/zf_sort.dir/lib/lines.c.o: CMakeFiles/zf_sort.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yh/C-Programming-K-R/5_pointer_array/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/zf_sort.dir/lib/lines.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/zf_sort.dir/lib/lines.c.o -MF CMakeFiles/zf_sort.dir/lib/lines.c.o.d -o CMakeFiles/zf_sort.dir/lib/lines.c.o -c /home/yh/C-Programming-K-R/5_pointer_array/lib/lines.c

CMakeFiles/zf_sort.dir/lib/lines.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/zf_sort.dir/lib/lines.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/yh/C-Programming-K-R/5_pointer_array/lib/lines.c > CMakeFiles/zf_sort.dir/lib/lines.c.i

CMakeFiles/zf_sort.dir/lib/lines.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/zf_sort.dir/lib/lines.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/yh/C-Programming-K-R/5_pointer_array/lib/lines.c -o CMakeFiles/zf_sort.dir/lib/lines.c.s

CMakeFiles/zf_sort.dir/lib/qsort.c.o: CMakeFiles/zf_sort.dir/flags.make
CMakeFiles/zf_sort.dir/lib/qsort.c.o: ../lib/qsort.c
CMakeFiles/zf_sort.dir/lib/qsort.c.o: CMakeFiles/zf_sort.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yh/C-Programming-K-R/5_pointer_array/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/zf_sort.dir/lib/qsort.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/zf_sort.dir/lib/qsort.c.o -MF CMakeFiles/zf_sort.dir/lib/qsort.c.o.d -o CMakeFiles/zf_sort.dir/lib/qsort.c.o -c /home/yh/C-Programming-K-R/5_pointer_array/lib/qsort.c

CMakeFiles/zf_sort.dir/lib/qsort.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/zf_sort.dir/lib/qsort.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/yh/C-Programming-K-R/5_pointer_array/lib/qsort.c > CMakeFiles/zf_sort.dir/lib/qsort.c.i

CMakeFiles/zf_sort.dir/lib/qsort.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/zf_sort.dir/lib/qsort.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/yh/C-Programming-K-R/5_pointer_array/lib/qsort.c -o CMakeFiles/zf_sort.dir/lib/qsort.c.s

# Object files for target zf_sort
zf_sort_OBJECTS = \
"CMakeFiles/zf_sort.dir/5.6_pointers_in_array.c.o" \
"CMakeFiles/zf_sort.dir/lib/lines.c.o" \
"CMakeFiles/zf_sort.dir/lib/qsort.c.o"

# External object files for target zf_sort
zf_sort_EXTERNAL_OBJECTS =

zf_sort: CMakeFiles/zf_sort.dir/5.6_pointers_in_array.c.o
zf_sort: CMakeFiles/zf_sort.dir/lib/lines.c.o
zf_sort: CMakeFiles/zf_sort.dir/lib/qsort.c.o
zf_sort: CMakeFiles/zf_sort.dir/build.make
zf_sort: CMakeFiles/zf_sort.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/yh/C-Programming-K-R/5_pointer_array/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable zf_sort"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/zf_sort.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/zf_sort.dir/build: zf_sort
.PHONY : CMakeFiles/zf_sort.dir/build

CMakeFiles/zf_sort.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/zf_sort.dir/cmake_clean.cmake
.PHONY : CMakeFiles/zf_sort.dir/clean

CMakeFiles/zf_sort.dir/depend:
	cd /home/yh/C-Programming-K-R/5_pointer_array/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/yh/C-Programming-K-R/5_pointer_array /home/yh/C-Programming-K-R/5_pointer_array /home/yh/C-Programming-K-R/5_pointer_array/build /home/yh/C-Programming-K-R/5_pointer_array/build /home/yh/C-Programming-K-R/5_pointer_array/build/CMakeFiles/zf_sort.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/zf_sort.dir/depend

