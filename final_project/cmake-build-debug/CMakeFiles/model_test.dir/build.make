# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.22

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2022.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2022.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\dakot\Documents\HW - CS211\final_project"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\dakot\Documents\HW - CS211\final_project\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/model_test.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/model_test.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/model_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/model_test.dir/flags.make

CMakeFiles/model_test.dir/src/model.cxx.obj: CMakeFiles/model_test.dir/flags.make
CMakeFiles/model_test.dir/src/model.cxx.obj: CMakeFiles/model_test.dir/includes_CXX.rsp
CMakeFiles/model_test.dir/src/model.cxx.obj: ../src/model.cxx
CMakeFiles/model_test.dir/src/model.cxx.obj: CMakeFiles/model_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\dakot\Documents\HW - CS211\final_project\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/model_test.dir/src/model.cxx.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/model_test.dir/src/model.cxx.obj -MF CMakeFiles\model_test.dir\src\model.cxx.obj.d -o CMakeFiles\model_test.dir\src\model.cxx.obj -c "C:\Users\dakot\Documents\HW - CS211\final_project\src\model.cxx"

CMakeFiles/model_test.dir/src/model.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/model_test.dir/src/model.cxx.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\dakot\Documents\HW - CS211\final_project\src\model.cxx" > CMakeFiles\model_test.dir\src\model.cxx.i

CMakeFiles/model_test.dir/src/model.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/model_test.dir/src/model.cxx.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\dakot\Documents\HW - CS211\final_project\src\model.cxx" -o CMakeFiles\model_test.dir\src\model.cxx.s

CMakeFiles/model_test.dir/src/game_config.cxx.obj: CMakeFiles/model_test.dir/flags.make
CMakeFiles/model_test.dir/src/game_config.cxx.obj: CMakeFiles/model_test.dir/includes_CXX.rsp
CMakeFiles/model_test.dir/src/game_config.cxx.obj: ../src/game_config.cxx
CMakeFiles/model_test.dir/src/game_config.cxx.obj: CMakeFiles/model_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\dakot\Documents\HW - CS211\final_project\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/model_test.dir/src/game_config.cxx.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/model_test.dir/src/game_config.cxx.obj -MF CMakeFiles\model_test.dir\src\game_config.cxx.obj.d -o CMakeFiles\model_test.dir\src\game_config.cxx.obj -c "C:\Users\dakot\Documents\HW - CS211\final_project\src\game_config.cxx"

CMakeFiles/model_test.dir/src/game_config.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/model_test.dir/src/game_config.cxx.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\dakot\Documents\HW - CS211\final_project\src\game_config.cxx" > CMakeFiles\model_test.dir\src\game_config.cxx.i

CMakeFiles/model_test.dir/src/game_config.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/model_test.dir/src/game_config.cxx.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\dakot\Documents\HW - CS211\final_project\src\game_config.cxx" -o CMakeFiles\model_test.dir\src\game_config.cxx.s

CMakeFiles/model_test.dir/src/player.cxx.obj: CMakeFiles/model_test.dir/flags.make
CMakeFiles/model_test.dir/src/player.cxx.obj: CMakeFiles/model_test.dir/includes_CXX.rsp
CMakeFiles/model_test.dir/src/player.cxx.obj: ../src/player.cxx
CMakeFiles/model_test.dir/src/player.cxx.obj: CMakeFiles/model_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\dakot\Documents\HW - CS211\final_project\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/model_test.dir/src/player.cxx.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/model_test.dir/src/player.cxx.obj -MF CMakeFiles\model_test.dir\src\player.cxx.obj.d -o CMakeFiles\model_test.dir\src\player.cxx.obj -c "C:\Users\dakot\Documents\HW - CS211\final_project\src\player.cxx"

CMakeFiles/model_test.dir/src/player.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/model_test.dir/src/player.cxx.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\dakot\Documents\HW - CS211\final_project\src\player.cxx" > CMakeFiles\model_test.dir\src\player.cxx.i

CMakeFiles/model_test.dir/src/player.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/model_test.dir/src/player.cxx.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\dakot\Documents\HW - CS211\final_project\src\player.cxx" -o CMakeFiles\model_test.dir\src\player.cxx.s

CMakeFiles/model_test.dir/src/platform.cxx.obj: CMakeFiles/model_test.dir/flags.make
CMakeFiles/model_test.dir/src/platform.cxx.obj: CMakeFiles/model_test.dir/includes_CXX.rsp
CMakeFiles/model_test.dir/src/platform.cxx.obj: ../src/platform.cxx
CMakeFiles/model_test.dir/src/platform.cxx.obj: CMakeFiles/model_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\dakot\Documents\HW - CS211\final_project\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/model_test.dir/src/platform.cxx.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/model_test.dir/src/platform.cxx.obj -MF CMakeFiles\model_test.dir\src\platform.cxx.obj.d -o CMakeFiles\model_test.dir\src\platform.cxx.obj -c "C:\Users\dakot\Documents\HW - CS211\final_project\src\platform.cxx"

CMakeFiles/model_test.dir/src/platform.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/model_test.dir/src/platform.cxx.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\dakot\Documents\HW - CS211\final_project\src\platform.cxx" > CMakeFiles\model_test.dir\src\platform.cxx.i

CMakeFiles/model_test.dir/src/platform.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/model_test.dir/src/platform.cxx.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\dakot\Documents\HW - CS211\final_project\src\platform.cxx" -o CMakeFiles\model_test.dir\src\platform.cxx.s

CMakeFiles/model_test.dir/test/model_test.cxx.obj: CMakeFiles/model_test.dir/flags.make
CMakeFiles/model_test.dir/test/model_test.cxx.obj: CMakeFiles/model_test.dir/includes_CXX.rsp
CMakeFiles/model_test.dir/test/model_test.cxx.obj: ../test/model_test.cxx
CMakeFiles/model_test.dir/test/model_test.cxx.obj: CMakeFiles/model_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\dakot\Documents\HW - CS211\final_project\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/model_test.dir/test/model_test.cxx.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/model_test.dir/test/model_test.cxx.obj -MF CMakeFiles\model_test.dir\test\model_test.cxx.obj.d -o CMakeFiles\model_test.dir\test\model_test.cxx.obj -c "C:\Users\dakot\Documents\HW - CS211\final_project\test\model_test.cxx"

CMakeFiles/model_test.dir/test/model_test.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/model_test.dir/test/model_test.cxx.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\dakot\Documents\HW - CS211\final_project\test\model_test.cxx" > CMakeFiles\model_test.dir\test\model_test.cxx.i

CMakeFiles/model_test.dir/test/model_test.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/model_test.dir/test/model_test.cxx.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\dakot\Documents\HW - CS211\final_project\test\model_test.cxx" -o CMakeFiles\model_test.dir\test\model_test.cxx.s

# Object files for target model_test
model_test_OBJECTS = \
"CMakeFiles/model_test.dir/src/model.cxx.obj" \
"CMakeFiles/model_test.dir/src/game_config.cxx.obj" \
"CMakeFiles/model_test.dir/src/player.cxx.obj" \
"CMakeFiles/model_test.dir/src/platform.cxx.obj" \
"CMakeFiles/model_test.dir/test/model_test.cxx.obj"

# External object files for target model_test
model_test_EXTERNAL_OBJECTS =

model_test.exe: CMakeFiles/model_test.dir/src/model.cxx.obj
model_test.exe: CMakeFiles/model_test.dir/src/game_config.cxx.obj
model_test.exe: CMakeFiles/model_test.dir/src/player.cxx.obj
model_test.exe: CMakeFiles/model_test.dir/src/platform.cxx.obj
model_test.exe: CMakeFiles/model_test.dir/test/model_test.cxx.obj
model_test.exe: CMakeFiles/model_test.dir/build.make
model_test.exe: .cs211/lib/catch/libcatch.a
model_test.exe: .cs211/lib/ge211/src/libge211.a
model_test.exe: C:/MinGW/lib/libSDL2.dll.a
model_test.exe: C:/MinGW/lib/libSDL2_image.dll.a
model_test.exe: C:/MinGW/lib/libSDL2_mixer.dll.a
model_test.exe: C:/MinGW/lib/libSDL2_ttf.dll.a
model_test.exe: CMakeFiles/model_test.dir/linklibs.rsp
model_test.exe: CMakeFiles/model_test.dir/objects1.rsp
model_test.exe: CMakeFiles/model_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\dakot\Documents\HW - CS211\final_project\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable model_test.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\model_test.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/model_test.dir/build: model_test.exe
.PHONY : CMakeFiles/model_test.dir/build

CMakeFiles/model_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\model_test.dir\cmake_clean.cmake
.PHONY : CMakeFiles/model_test.dir/clean

CMakeFiles/model_test.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\dakot\Documents\HW - CS211\final_project" "C:\Users\dakot\Documents\HW - CS211\final_project" "C:\Users\dakot\Documents\HW - CS211\final_project\cmake-build-debug" "C:\Users\dakot\Documents\HW - CS211\final_project\cmake-build-debug" "C:\Users\dakot\Documents\HW - CS211\final_project\cmake-build-debug\CMakeFiles\model_test.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/model_test.dir/depend
