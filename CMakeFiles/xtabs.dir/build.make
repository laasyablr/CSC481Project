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
CMAKE_COMMAND = /home/lele/Downloads/cmake-3.10.1/bin/cmake

# The command to remove a file.
RM = /home/lele/Downloads/cmake-3.10.1/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/lele/Pictures/lass/emp-sh2pc

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lele/Pictures/lass/emp-sh2pc

# Include any dependencies generated for this target.
include CMakeFiles/xtabs.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/xtabs.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/xtabs.dir/flags.make

CMakeFiles/xtabs.dir/test/xtabs.cpp.o: CMakeFiles/xtabs.dir/flags.make
CMakeFiles/xtabs.dir/test/xtabs.cpp.o: test/xtabs.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lele/Pictures/lass/emp-sh2pc/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/xtabs.dir/test/xtabs.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/xtabs.dir/test/xtabs.cpp.o -c /home/lele/Pictures/lass/emp-sh2pc/test/xtabs.cpp

CMakeFiles/xtabs.dir/test/xtabs.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/xtabs.dir/test/xtabs.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lele/Pictures/lass/emp-sh2pc/test/xtabs.cpp > CMakeFiles/xtabs.dir/test/xtabs.cpp.i

CMakeFiles/xtabs.dir/test/xtabs.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/xtabs.dir/test/xtabs.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lele/Pictures/lass/emp-sh2pc/test/xtabs.cpp -o CMakeFiles/xtabs.dir/test/xtabs.cpp.s

CMakeFiles/xtabs.dir/test/xtabs.cpp.o.requires:

.PHONY : CMakeFiles/xtabs.dir/test/xtabs.cpp.o.requires

CMakeFiles/xtabs.dir/test/xtabs.cpp.o.provides: CMakeFiles/xtabs.dir/test/xtabs.cpp.o.requires
	$(MAKE) -f CMakeFiles/xtabs.dir/build.make CMakeFiles/xtabs.dir/test/xtabs.cpp.o.provides.build
.PHONY : CMakeFiles/xtabs.dir/test/xtabs.cpp.o.provides

CMakeFiles/xtabs.dir/test/xtabs.cpp.o.provides.build: CMakeFiles/xtabs.dir/test/xtabs.cpp.o


# Object files for target xtabs
xtabs_OBJECTS = \
"CMakeFiles/xtabs.dir/test/xtabs.cpp.o"

# External object files for target xtabs
xtabs_EXTERNAL_OBJECTS =

bin/xtabs: CMakeFiles/xtabs.dir/test/xtabs.cpp.o
bin/xtabs: CMakeFiles/xtabs.dir/build.make
bin/xtabs: /usr/lib/x86_64-linux-gnu/libssl.so
bin/xtabs: /usr/lib/x86_64-linux-gnu/libcrypto.so
bin/xtabs: /usr/lib/x86_64-linux-gnu/libboost_system.so
bin/xtabs: /usr/lib/x86_64-linux-gnu/libgmp.so
bin/xtabs: /usr/local/lib/libemp-tool.so
bin/xtabs: CMakeFiles/xtabs.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lele/Pictures/lass/emp-sh2pc/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable bin/xtabs"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/xtabs.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/xtabs.dir/build: bin/xtabs

.PHONY : CMakeFiles/xtabs.dir/build

CMakeFiles/xtabs.dir/requires: CMakeFiles/xtabs.dir/test/xtabs.cpp.o.requires

.PHONY : CMakeFiles/xtabs.dir/requires

CMakeFiles/xtabs.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/xtabs.dir/cmake_clean.cmake
.PHONY : CMakeFiles/xtabs.dir/clean

CMakeFiles/xtabs.dir/depend:
	cd /home/lele/Pictures/lass/emp-sh2pc && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lele/Pictures/lass/emp-sh2pc /home/lele/Pictures/lass/emp-sh2pc /home/lele/Pictures/lass/emp-sh2pc /home/lele/Pictures/lass/emp-sh2pc /home/lele/Pictures/lass/emp-sh2pc/CMakeFiles/xtabs.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/xtabs.dir/depend

