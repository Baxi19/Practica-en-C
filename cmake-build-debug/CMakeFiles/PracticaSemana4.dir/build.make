# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.3.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.3.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\Baxi\Documents\C Proyects\PracticaSemana4"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Baxi\Documents\C Proyects\PracticaSemana4\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/PracticaSemana4.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/PracticaSemana4.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/PracticaSemana4.dir/flags.make

CMakeFiles/PracticaSemana4.dir/main.c.obj: CMakeFiles/PracticaSemana4.dir/flags.make
CMakeFiles/PracticaSemana4.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Baxi\Documents\C Proyects\PracticaSemana4\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/PracticaSemana4.dir/main.c.obj"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\PracticaSemana4.dir\main.c.obj   -c "C:\Users\Baxi\Documents\C Proyects\PracticaSemana4\main.c"

CMakeFiles/PracticaSemana4.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/PracticaSemana4.dir/main.c.i"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\Baxi\Documents\C Proyects\PracticaSemana4\main.c" > CMakeFiles\PracticaSemana4.dir\main.c.i

CMakeFiles/PracticaSemana4.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/PracticaSemana4.dir/main.c.s"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\Baxi\Documents\C Proyects\PracticaSemana4\main.c" -o CMakeFiles\PracticaSemana4.dir\main.c.s

# Object files for target PracticaSemana4
PracticaSemana4_OBJECTS = \
"CMakeFiles/PracticaSemana4.dir/main.c.obj"

# External object files for target PracticaSemana4
PracticaSemana4_EXTERNAL_OBJECTS =

PracticaSemana4.exe: CMakeFiles/PracticaSemana4.dir/main.c.obj
PracticaSemana4.exe: CMakeFiles/PracticaSemana4.dir/build.make
PracticaSemana4.exe: CMakeFiles/PracticaSemana4.dir/linklibs.rsp
PracticaSemana4.exe: CMakeFiles/PracticaSemana4.dir/objects1.rsp
PracticaSemana4.exe: CMakeFiles/PracticaSemana4.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Baxi\Documents\C Proyects\PracticaSemana4\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable PracticaSemana4.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\PracticaSemana4.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/PracticaSemana4.dir/build: PracticaSemana4.exe

.PHONY : CMakeFiles/PracticaSemana4.dir/build

CMakeFiles/PracticaSemana4.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\PracticaSemana4.dir\cmake_clean.cmake
.PHONY : CMakeFiles/PracticaSemana4.dir/clean

CMakeFiles/PracticaSemana4.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Baxi\Documents\C Proyects\PracticaSemana4" "C:\Users\Baxi\Documents\C Proyects\PracticaSemana4" "C:\Users\Baxi\Documents\C Proyects\PracticaSemana4\cmake-build-debug" "C:\Users\Baxi\Documents\C Proyects\PracticaSemana4\cmake-build-debug" "C:\Users\Baxi\Documents\C Proyects\PracticaSemana4\cmake-build-debug\CMakeFiles\PracticaSemana4.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/PracticaSemana4.dir/depend
