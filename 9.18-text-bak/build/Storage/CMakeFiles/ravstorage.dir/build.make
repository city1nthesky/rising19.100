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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/dong/rising/Source_Code/9.18-text/UnixRav3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dong/rising/Source_Code/9.18-text/build

# Include any dependencies generated for this target.
include Storage/CMakeFiles/ravstorage.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include Storage/CMakeFiles/ravstorage.dir/compiler_depend.make

# Include the progress variables for this target.
include Storage/CMakeFiles/ravstorage.dir/progress.make

# Include the compile flags for this target's objects.
include Storage/CMakeFiles/ravstorage.dir/flags.make

Storage/CMakeFiles/ravstorage.dir/storage.cpp.o: Storage/CMakeFiles/ravstorage.dir/flags.make
Storage/CMakeFiles/ravstorage.dir/storage.cpp.o: /home/dong/rising/Source_Code/9.18-text/UnixRav3/Storage/storage.cpp
Storage/CMakeFiles/ravstorage.dir/storage.cpp.o: Storage/CMakeFiles/ravstorage.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dong/rising/Source_Code/9.18-text/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Storage/CMakeFiles/ravstorage.dir/storage.cpp.o"
	cd /home/dong/rising/Source_Code/9.18-text/build/Storage && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Storage/CMakeFiles/ravstorage.dir/storage.cpp.o -MF CMakeFiles/ravstorage.dir/storage.cpp.o.d -o CMakeFiles/ravstorage.dir/storage.cpp.o -c /home/dong/rising/Source_Code/9.18-text/UnixRav3/Storage/storage.cpp

Storage/CMakeFiles/ravstorage.dir/storage.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ravstorage.dir/storage.cpp.i"
	cd /home/dong/rising/Source_Code/9.18-text/build/Storage && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dong/rising/Source_Code/9.18-text/UnixRav3/Storage/storage.cpp > CMakeFiles/ravstorage.dir/storage.cpp.i

Storage/CMakeFiles/ravstorage.dir/storage.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ravstorage.dir/storage.cpp.s"
	cd /home/dong/rising/Source_Code/9.18-text/build/Storage && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dong/rising/Source_Code/9.18-text/UnixRav3/Storage/storage.cpp -o CMakeFiles/ravstorage.dir/storage.cpp.s

Storage/CMakeFiles/ravstorage.dir/cinifile.cpp.o: Storage/CMakeFiles/ravstorage.dir/flags.make
Storage/CMakeFiles/ravstorage.dir/cinifile.cpp.o: /home/dong/rising/Source_Code/9.18-text/UnixRav3/Storage/cinifile.cpp
Storage/CMakeFiles/ravstorage.dir/cinifile.cpp.o: Storage/CMakeFiles/ravstorage.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dong/rising/Source_Code/9.18-text/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object Storage/CMakeFiles/ravstorage.dir/cinifile.cpp.o"
	cd /home/dong/rising/Source_Code/9.18-text/build/Storage && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Storage/CMakeFiles/ravstorage.dir/cinifile.cpp.o -MF CMakeFiles/ravstorage.dir/cinifile.cpp.o.d -o CMakeFiles/ravstorage.dir/cinifile.cpp.o -c /home/dong/rising/Source_Code/9.18-text/UnixRav3/Storage/cinifile.cpp

Storage/CMakeFiles/ravstorage.dir/cinifile.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ravstorage.dir/cinifile.cpp.i"
	cd /home/dong/rising/Source_Code/9.18-text/build/Storage && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dong/rising/Source_Code/9.18-text/UnixRav3/Storage/cinifile.cpp > CMakeFiles/ravstorage.dir/cinifile.cpp.i

Storage/CMakeFiles/ravstorage.dir/cinifile.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ravstorage.dir/cinifile.cpp.s"
	cd /home/dong/rising/Source_Code/9.18-text/build/Storage && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dong/rising/Source_Code/9.18-text/UnixRav3/Storage/cinifile.cpp -o CMakeFiles/ravstorage.dir/cinifile.cpp.s

Storage/CMakeFiles/ravstorage.dir/Entry/settingentry.cpp.o: Storage/CMakeFiles/ravstorage.dir/flags.make
Storage/CMakeFiles/ravstorage.dir/Entry/settingentry.cpp.o: /home/dong/rising/Source_Code/9.18-text/UnixRav3/Storage/Entry/settingentry.cpp
Storage/CMakeFiles/ravstorage.dir/Entry/settingentry.cpp.o: Storage/CMakeFiles/ravstorage.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dong/rising/Source_Code/9.18-text/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object Storage/CMakeFiles/ravstorage.dir/Entry/settingentry.cpp.o"
	cd /home/dong/rising/Source_Code/9.18-text/build/Storage && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Storage/CMakeFiles/ravstorage.dir/Entry/settingentry.cpp.o -MF CMakeFiles/ravstorage.dir/Entry/settingentry.cpp.o.d -o CMakeFiles/ravstorage.dir/Entry/settingentry.cpp.o -c /home/dong/rising/Source_Code/9.18-text/UnixRav3/Storage/Entry/settingentry.cpp

Storage/CMakeFiles/ravstorage.dir/Entry/settingentry.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ravstorage.dir/Entry/settingentry.cpp.i"
	cd /home/dong/rising/Source_Code/9.18-text/build/Storage && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dong/rising/Source_Code/9.18-text/UnixRav3/Storage/Entry/settingentry.cpp > CMakeFiles/ravstorage.dir/Entry/settingentry.cpp.i

Storage/CMakeFiles/ravstorage.dir/Entry/settingentry.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ravstorage.dir/Entry/settingentry.cpp.s"
	cd /home/dong/rising/Source_Code/9.18-text/build/Storage && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dong/rising/Source_Code/9.18-text/UnixRav3/Storage/Entry/settingentry.cpp -o CMakeFiles/ravstorage.dir/Entry/settingentry.cpp.s

Storage/CMakeFiles/ravstorage.dir/SQLite3/sqlite3.c.o: Storage/CMakeFiles/ravstorage.dir/flags.make
Storage/CMakeFiles/ravstorage.dir/SQLite3/sqlite3.c.o: /home/dong/rising/Source_Code/9.18-text/UnixRav3/Storage/SQLite3/sqlite3.c
Storage/CMakeFiles/ravstorage.dir/SQLite3/sqlite3.c.o: Storage/CMakeFiles/ravstorage.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dong/rising/Source_Code/9.18-text/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object Storage/CMakeFiles/ravstorage.dir/SQLite3/sqlite3.c.o"
	cd /home/dong/rising/Source_Code/9.18-text/build/Storage && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT Storage/CMakeFiles/ravstorage.dir/SQLite3/sqlite3.c.o -MF CMakeFiles/ravstorage.dir/SQLite3/sqlite3.c.o.d -o CMakeFiles/ravstorage.dir/SQLite3/sqlite3.c.o -c /home/dong/rising/Source_Code/9.18-text/UnixRav3/Storage/SQLite3/sqlite3.c

Storage/CMakeFiles/ravstorage.dir/SQLite3/sqlite3.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ravstorage.dir/SQLite3/sqlite3.c.i"
	cd /home/dong/rising/Source_Code/9.18-text/build/Storage && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/dong/rising/Source_Code/9.18-text/UnixRav3/Storage/SQLite3/sqlite3.c > CMakeFiles/ravstorage.dir/SQLite3/sqlite3.c.i

Storage/CMakeFiles/ravstorage.dir/SQLite3/sqlite3.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ravstorage.dir/SQLite3/sqlite3.c.s"
	cd /home/dong/rising/Source_Code/9.18-text/build/Storage && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/dong/rising/Source_Code/9.18-text/UnixRav3/Storage/SQLite3/sqlite3.c -o CMakeFiles/ravstorage.dir/SQLite3/sqlite3.c.s

Storage/CMakeFiles/ravstorage.dir/Entry/baseentry.cpp.o: Storage/CMakeFiles/ravstorage.dir/flags.make
Storage/CMakeFiles/ravstorage.dir/Entry/baseentry.cpp.o: /home/dong/rising/Source_Code/9.18-text/UnixRav3/Storage/Entry/baseentry.cpp
Storage/CMakeFiles/ravstorage.dir/Entry/baseentry.cpp.o: Storage/CMakeFiles/ravstorage.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dong/rising/Source_Code/9.18-text/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object Storage/CMakeFiles/ravstorage.dir/Entry/baseentry.cpp.o"
	cd /home/dong/rising/Source_Code/9.18-text/build/Storage && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Storage/CMakeFiles/ravstorage.dir/Entry/baseentry.cpp.o -MF CMakeFiles/ravstorage.dir/Entry/baseentry.cpp.o.d -o CMakeFiles/ravstorage.dir/Entry/baseentry.cpp.o -c /home/dong/rising/Source_Code/9.18-text/UnixRav3/Storage/Entry/baseentry.cpp

Storage/CMakeFiles/ravstorage.dir/Entry/baseentry.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ravstorage.dir/Entry/baseentry.cpp.i"
	cd /home/dong/rising/Source_Code/9.18-text/build/Storage && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dong/rising/Source_Code/9.18-text/UnixRav3/Storage/Entry/baseentry.cpp > CMakeFiles/ravstorage.dir/Entry/baseentry.cpp.i

Storage/CMakeFiles/ravstorage.dir/Entry/baseentry.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ravstorage.dir/Entry/baseentry.cpp.s"
	cd /home/dong/rising/Source_Code/9.18-text/build/Storage && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dong/rising/Source_Code/9.18-text/UnixRav3/Storage/Entry/baseentry.cpp -o CMakeFiles/ravstorage.dir/Entry/baseentry.cpp.s

Storage/CMakeFiles/ravstorage.dir/CPPSQLite/cppsqlite3.cpp.o: Storage/CMakeFiles/ravstorage.dir/flags.make
Storage/CMakeFiles/ravstorage.dir/CPPSQLite/cppsqlite3.cpp.o: /home/dong/rising/Source_Code/9.18-text/UnixRav3/Storage/CPPSQLite/cppsqlite3.cpp
Storage/CMakeFiles/ravstorage.dir/CPPSQLite/cppsqlite3.cpp.o: Storage/CMakeFiles/ravstorage.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dong/rising/Source_Code/9.18-text/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object Storage/CMakeFiles/ravstorage.dir/CPPSQLite/cppsqlite3.cpp.o"
	cd /home/dong/rising/Source_Code/9.18-text/build/Storage && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Storage/CMakeFiles/ravstorage.dir/CPPSQLite/cppsqlite3.cpp.o -MF CMakeFiles/ravstorage.dir/CPPSQLite/cppsqlite3.cpp.o.d -o CMakeFiles/ravstorage.dir/CPPSQLite/cppsqlite3.cpp.o -c /home/dong/rising/Source_Code/9.18-text/UnixRav3/Storage/CPPSQLite/cppsqlite3.cpp

Storage/CMakeFiles/ravstorage.dir/CPPSQLite/cppsqlite3.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ravstorage.dir/CPPSQLite/cppsqlite3.cpp.i"
	cd /home/dong/rising/Source_Code/9.18-text/build/Storage && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dong/rising/Source_Code/9.18-text/UnixRav3/Storage/CPPSQLite/cppsqlite3.cpp > CMakeFiles/ravstorage.dir/CPPSQLite/cppsqlite3.cpp.i

Storage/CMakeFiles/ravstorage.dir/CPPSQLite/cppsqlite3.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ravstorage.dir/CPPSQLite/cppsqlite3.cpp.s"
	cd /home/dong/rising/Source_Code/9.18-text/build/Storage && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dong/rising/Source_Code/9.18-text/UnixRav3/Storage/CPPSQLite/cppsqlite3.cpp -o CMakeFiles/ravstorage.dir/CPPSQLite/cppsqlite3.cpp.s

Storage/CMakeFiles/ravstorage.dir/Entry/virusinfoentry.cpp.o: Storage/CMakeFiles/ravstorage.dir/flags.make
Storage/CMakeFiles/ravstorage.dir/Entry/virusinfoentry.cpp.o: /home/dong/rising/Source_Code/9.18-text/UnixRav3/Storage/Entry/virusinfoentry.cpp
Storage/CMakeFiles/ravstorage.dir/Entry/virusinfoentry.cpp.o: Storage/CMakeFiles/ravstorage.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dong/rising/Source_Code/9.18-text/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object Storage/CMakeFiles/ravstorage.dir/Entry/virusinfoentry.cpp.o"
	cd /home/dong/rising/Source_Code/9.18-text/build/Storage && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Storage/CMakeFiles/ravstorage.dir/Entry/virusinfoentry.cpp.o -MF CMakeFiles/ravstorage.dir/Entry/virusinfoentry.cpp.o.d -o CMakeFiles/ravstorage.dir/Entry/virusinfoentry.cpp.o -c /home/dong/rising/Source_Code/9.18-text/UnixRav3/Storage/Entry/virusinfoentry.cpp

Storage/CMakeFiles/ravstorage.dir/Entry/virusinfoentry.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ravstorage.dir/Entry/virusinfoentry.cpp.i"
	cd /home/dong/rising/Source_Code/9.18-text/build/Storage && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dong/rising/Source_Code/9.18-text/UnixRav3/Storage/Entry/virusinfoentry.cpp > CMakeFiles/ravstorage.dir/Entry/virusinfoentry.cpp.i

Storage/CMakeFiles/ravstorage.dir/Entry/virusinfoentry.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ravstorage.dir/Entry/virusinfoentry.cpp.s"
	cd /home/dong/rising/Source_Code/9.18-text/build/Storage && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dong/rising/Source_Code/9.18-text/UnixRav3/Storage/Entry/virusinfoentry.cpp -o CMakeFiles/ravstorage.dir/Entry/virusinfoentry.cpp.s

Storage/CMakeFiles/ravstorage.dir/Entry/logevententry.cpp.o: Storage/CMakeFiles/ravstorage.dir/flags.make
Storage/CMakeFiles/ravstorage.dir/Entry/logevententry.cpp.o: /home/dong/rising/Source_Code/9.18-text/UnixRav3/Storage/Entry/logevententry.cpp
Storage/CMakeFiles/ravstorage.dir/Entry/logevententry.cpp.o: Storage/CMakeFiles/ravstorage.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dong/rising/Source_Code/9.18-text/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object Storage/CMakeFiles/ravstorage.dir/Entry/logevententry.cpp.o"
	cd /home/dong/rising/Source_Code/9.18-text/build/Storage && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Storage/CMakeFiles/ravstorage.dir/Entry/logevententry.cpp.o -MF CMakeFiles/ravstorage.dir/Entry/logevententry.cpp.o.d -o CMakeFiles/ravstorage.dir/Entry/logevententry.cpp.o -c /home/dong/rising/Source_Code/9.18-text/UnixRav3/Storage/Entry/logevententry.cpp

Storage/CMakeFiles/ravstorage.dir/Entry/logevententry.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ravstorage.dir/Entry/logevententry.cpp.i"
	cd /home/dong/rising/Source_Code/9.18-text/build/Storage && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dong/rising/Source_Code/9.18-text/UnixRav3/Storage/Entry/logevententry.cpp > CMakeFiles/ravstorage.dir/Entry/logevententry.cpp.i

Storage/CMakeFiles/ravstorage.dir/Entry/logevententry.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ravstorage.dir/Entry/logevententry.cpp.s"
	cd /home/dong/rising/Source_Code/9.18-text/build/Storage && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dong/rising/Source_Code/9.18-text/UnixRav3/Storage/Entry/logevententry.cpp -o CMakeFiles/ravstorage.dir/Entry/logevententry.cpp.s

Storage/CMakeFiles/ravstorage.dir/Entry/scheduleentry.cpp.o: Storage/CMakeFiles/ravstorage.dir/flags.make
Storage/CMakeFiles/ravstorage.dir/Entry/scheduleentry.cpp.o: /home/dong/rising/Source_Code/9.18-text/UnixRav3/Storage/Entry/scheduleentry.cpp
Storage/CMakeFiles/ravstorage.dir/Entry/scheduleentry.cpp.o: Storage/CMakeFiles/ravstorage.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dong/rising/Source_Code/9.18-text/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object Storage/CMakeFiles/ravstorage.dir/Entry/scheduleentry.cpp.o"
	cd /home/dong/rising/Source_Code/9.18-text/build/Storage && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Storage/CMakeFiles/ravstorage.dir/Entry/scheduleentry.cpp.o -MF CMakeFiles/ravstorage.dir/Entry/scheduleentry.cpp.o.d -o CMakeFiles/ravstorage.dir/Entry/scheduleentry.cpp.o -c /home/dong/rising/Source_Code/9.18-text/UnixRav3/Storage/Entry/scheduleentry.cpp

Storage/CMakeFiles/ravstorage.dir/Entry/scheduleentry.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ravstorage.dir/Entry/scheduleentry.cpp.i"
	cd /home/dong/rising/Source_Code/9.18-text/build/Storage && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dong/rising/Source_Code/9.18-text/UnixRav3/Storage/Entry/scheduleentry.cpp > CMakeFiles/ravstorage.dir/Entry/scheduleentry.cpp.i

Storage/CMakeFiles/ravstorage.dir/Entry/scheduleentry.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ravstorage.dir/Entry/scheduleentry.cpp.s"
	cd /home/dong/rising/Source_Code/9.18-text/build/Storage && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dong/rising/Source_Code/9.18-text/UnixRav3/Storage/Entry/scheduleentry.cpp -o CMakeFiles/ravstorage.dir/Entry/scheduleentry.cpp.s

Storage/CMakeFiles/ravstorage.dir/Entry/whitelistentry.cpp.o: Storage/CMakeFiles/ravstorage.dir/flags.make
Storage/CMakeFiles/ravstorage.dir/Entry/whitelistentry.cpp.o: /home/dong/rising/Source_Code/9.18-text/UnixRav3/Storage/Entry/whitelistentry.cpp
Storage/CMakeFiles/ravstorage.dir/Entry/whitelistentry.cpp.o: Storage/CMakeFiles/ravstorage.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dong/rising/Source_Code/9.18-text/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object Storage/CMakeFiles/ravstorage.dir/Entry/whitelistentry.cpp.o"
	cd /home/dong/rising/Source_Code/9.18-text/build/Storage && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Storage/CMakeFiles/ravstorage.dir/Entry/whitelistentry.cpp.o -MF CMakeFiles/ravstorage.dir/Entry/whitelistentry.cpp.o.d -o CMakeFiles/ravstorage.dir/Entry/whitelistentry.cpp.o -c /home/dong/rising/Source_Code/9.18-text/UnixRav3/Storage/Entry/whitelistentry.cpp

Storage/CMakeFiles/ravstorage.dir/Entry/whitelistentry.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ravstorage.dir/Entry/whitelistentry.cpp.i"
	cd /home/dong/rising/Source_Code/9.18-text/build/Storage && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dong/rising/Source_Code/9.18-text/UnixRav3/Storage/Entry/whitelistentry.cpp > CMakeFiles/ravstorage.dir/Entry/whitelistentry.cpp.i

Storage/CMakeFiles/ravstorage.dir/Entry/whitelistentry.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ravstorage.dir/Entry/whitelistentry.cpp.s"
	cd /home/dong/rising/Source_Code/9.18-text/build/Storage && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dong/rising/Source_Code/9.18-text/UnixRav3/Storage/Entry/whitelistentry.cpp -o CMakeFiles/ravstorage.dir/Entry/whitelistentry.cpp.s

Storage/CMakeFiles/ravstorage.dir/Entry/commeventlog.cpp.o: Storage/CMakeFiles/ravstorage.dir/flags.make
Storage/CMakeFiles/ravstorage.dir/Entry/commeventlog.cpp.o: /home/dong/rising/Source_Code/9.18-text/UnixRav3/Storage/Entry/commeventlog.cpp
Storage/CMakeFiles/ravstorage.dir/Entry/commeventlog.cpp.o: Storage/CMakeFiles/ravstorage.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dong/rising/Source_Code/9.18-text/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object Storage/CMakeFiles/ravstorage.dir/Entry/commeventlog.cpp.o"
	cd /home/dong/rising/Source_Code/9.18-text/build/Storage && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Storage/CMakeFiles/ravstorage.dir/Entry/commeventlog.cpp.o -MF CMakeFiles/ravstorage.dir/Entry/commeventlog.cpp.o.d -o CMakeFiles/ravstorage.dir/Entry/commeventlog.cpp.o -c /home/dong/rising/Source_Code/9.18-text/UnixRav3/Storage/Entry/commeventlog.cpp

Storage/CMakeFiles/ravstorage.dir/Entry/commeventlog.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ravstorage.dir/Entry/commeventlog.cpp.i"
	cd /home/dong/rising/Source_Code/9.18-text/build/Storage && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dong/rising/Source_Code/9.18-text/UnixRav3/Storage/Entry/commeventlog.cpp > CMakeFiles/ravstorage.dir/Entry/commeventlog.cpp.i

Storage/CMakeFiles/ravstorage.dir/Entry/commeventlog.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ravstorage.dir/Entry/commeventlog.cpp.s"
	cd /home/dong/rising/Source_Code/9.18-text/build/Storage && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dong/rising/Source_Code/9.18-text/UnixRav3/Storage/Entry/commeventlog.cpp -o CMakeFiles/ravstorage.dir/Entry/commeventlog.cpp.s

Storage/CMakeFiles/ravstorage.dir/Entry/quarantinelog.cpp.o: Storage/CMakeFiles/ravstorage.dir/flags.make
Storage/CMakeFiles/ravstorage.dir/Entry/quarantinelog.cpp.o: /home/dong/rising/Source_Code/9.18-text/UnixRav3/Storage/Entry/quarantinelog.cpp
Storage/CMakeFiles/ravstorage.dir/Entry/quarantinelog.cpp.o: Storage/CMakeFiles/ravstorage.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dong/rising/Source_Code/9.18-text/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object Storage/CMakeFiles/ravstorage.dir/Entry/quarantinelog.cpp.o"
	cd /home/dong/rising/Source_Code/9.18-text/build/Storage && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Storage/CMakeFiles/ravstorage.dir/Entry/quarantinelog.cpp.o -MF CMakeFiles/ravstorage.dir/Entry/quarantinelog.cpp.o.d -o CMakeFiles/ravstorage.dir/Entry/quarantinelog.cpp.o -c /home/dong/rising/Source_Code/9.18-text/UnixRav3/Storage/Entry/quarantinelog.cpp

Storage/CMakeFiles/ravstorage.dir/Entry/quarantinelog.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ravstorage.dir/Entry/quarantinelog.cpp.i"
	cd /home/dong/rising/Source_Code/9.18-text/build/Storage && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dong/rising/Source_Code/9.18-text/UnixRav3/Storage/Entry/quarantinelog.cpp > CMakeFiles/ravstorage.dir/Entry/quarantinelog.cpp.i

Storage/CMakeFiles/ravstorage.dir/Entry/quarantinelog.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ravstorage.dir/Entry/quarantinelog.cpp.s"
	cd /home/dong/rising/Source_Code/9.18-text/build/Storage && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dong/rising/Source_Code/9.18-text/UnixRav3/Storage/Entry/quarantinelog.cpp -o CMakeFiles/ravstorage.dir/Entry/quarantinelog.cpp.s

Storage/CMakeFiles/ravstorage.dir/Entry/netaccessentry.cpp.o: Storage/CMakeFiles/ravstorage.dir/flags.make
Storage/CMakeFiles/ravstorage.dir/Entry/netaccessentry.cpp.o: /home/dong/rising/Source_Code/9.18-text/UnixRav3/Storage/Entry/netaccessentry.cpp
Storage/CMakeFiles/ravstorage.dir/Entry/netaccessentry.cpp.o: Storage/CMakeFiles/ravstorage.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dong/rising/Source_Code/9.18-text/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object Storage/CMakeFiles/ravstorage.dir/Entry/netaccessentry.cpp.o"
	cd /home/dong/rising/Source_Code/9.18-text/build/Storage && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Storage/CMakeFiles/ravstorage.dir/Entry/netaccessentry.cpp.o -MF CMakeFiles/ravstorage.dir/Entry/netaccessentry.cpp.o.d -o CMakeFiles/ravstorage.dir/Entry/netaccessentry.cpp.o -c /home/dong/rising/Source_Code/9.18-text/UnixRav3/Storage/Entry/netaccessentry.cpp

Storage/CMakeFiles/ravstorage.dir/Entry/netaccessentry.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ravstorage.dir/Entry/netaccessentry.cpp.i"
	cd /home/dong/rising/Source_Code/9.18-text/build/Storage && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dong/rising/Source_Code/9.18-text/UnixRav3/Storage/Entry/netaccessentry.cpp > CMakeFiles/ravstorage.dir/Entry/netaccessentry.cpp.i

Storage/CMakeFiles/ravstorage.dir/Entry/netaccessentry.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ravstorage.dir/Entry/netaccessentry.cpp.s"
	cd /home/dong/rising/Source_Code/9.18-text/build/Storage && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dong/rising/Source_Code/9.18-text/UnixRav3/Storage/Entry/netaccessentry.cpp -o CMakeFiles/ravstorage.dir/Entry/netaccessentry.cpp.s

Storage/CMakeFiles/ravstorage.dir/Entry/urlruleentry.cpp.o: Storage/CMakeFiles/ravstorage.dir/flags.make
Storage/CMakeFiles/ravstorage.dir/Entry/urlruleentry.cpp.o: /home/dong/rising/Source_Code/9.18-text/UnixRav3/Storage/Entry/urlruleentry.cpp
Storage/CMakeFiles/ravstorage.dir/Entry/urlruleentry.cpp.o: Storage/CMakeFiles/ravstorage.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dong/rising/Source_Code/9.18-text/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object Storage/CMakeFiles/ravstorage.dir/Entry/urlruleentry.cpp.o"
	cd /home/dong/rising/Source_Code/9.18-text/build/Storage && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Storage/CMakeFiles/ravstorage.dir/Entry/urlruleentry.cpp.o -MF CMakeFiles/ravstorage.dir/Entry/urlruleentry.cpp.o.d -o CMakeFiles/ravstorage.dir/Entry/urlruleentry.cpp.o -c /home/dong/rising/Source_Code/9.18-text/UnixRav3/Storage/Entry/urlruleentry.cpp

Storage/CMakeFiles/ravstorage.dir/Entry/urlruleentry.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ravstorage.dir/Entry/urlruleentry.cpp.i"
	cd /home/dong/rising/Source_Code/9.18-text/build/Storage && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dong/rising/Source_Code/9.18-text/UnixRav3/Storage/Entry/urlruleentry.cpp > CMakeFiles/ravstorage.dir/Entry/urlruleentry.cpp.i

Storage/CMakeFiles/ravstorage.dir/Entry/urlruleentry.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ravstorage.dir/Entry/urlruleentry.cpp.s"
	cd /home/dong/rising/Source_Code/9.18-text/build/Storage && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dong/rising/Source_Code/9.18-text/UnixRav3/Storage/Entry/urlruleentry.cpp -o CMakeFiles/ravstorage.dir/Entry/urlruleentry.cpp.s

Storage/CMakeFiles/ravstorage.dir/Entry/sourcelistentry.cpp.o: Storage/CMakeFiles/ravstorage.dir/flags.make
Storage/CMakeFiles/ravstorage.dir/Entry/sourcelistentry.cpp.o: /home/dong/rising/Source_Code/9.18-text/UnixRav3/Storage/Entry/sourcelistentry.cpp
Storage/CMakeFiles/ravstorage.dir/Entry/sourcelistentry.cpp.o: Storage/CMakeFiles/ravstorage.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dong/rising/Source_Code/9.18-text/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object Storage/CMakeFiles/ravstorage.dir/Entry/sourcelistentry.cpp.o"
	cd /home/dong/rising/Source_Code/9.18-text/build/Storage && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Storage/CMakeFiles/ravstorage.dir/Entry/sourcelistentry.cpp.o -MF CMakeFiles/ravstorage.dir/Entry/sourcelistentry.cpp.o.d -o CMakeFiles/ravstorage.dir/Entry/sourcelistentry.cpp.o -c /home/dong/rising/Source_Code/9.18-text/UnixRav3/Storage/Entry/sourcelistentry.cpp

Storage/CMakeFiles/ravstorage.dir/Entry/sourcelistentry.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ravstorage.dir/Entry/sourcelistentry.cpp.i"
	cd /home/dong/rising/Source_Code/9.18-text/build/Storage && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dong/rising/Source_Code/9.18-text/UnixRav3/Storage/Entry/sourcelistentry.cpp > CMakeFiles/ravstorage.dir/Entry/sourcelistentry.cpp.i

Storage/CMakeFiles/ravstorage.dir/Entry/sourcelistentry.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ravstorage.dir/Entry/sourcelistentry.cpp.s"
	cd /home/dong/rising/Source_Code/9.18-text/build/Storage && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dong/rising/Source_Code/9.18-text/UnixRav3/Storage/Entry/sourcelistentry.cpp -o CMakeFiles/ravstorage.dir/Entry/sourcelistentry.cpp.s

Storage/CMakeFiles/ravstorage.dir/__/CommonAPI/commonapi.cpp.o: Storage/CMakeFiles/ravstorage.dir/flags.make
Storage/CMakeFiles/ravstorage.dir/__/CommonAPI/commonapi.cpp.o: /home/dong/rising/Source_Code/9.18-text/UnixRav3/CommonAPI/commonapi.cpp
Storage/CMakeFiles/ravstorage.dir/__/CommonAPI/commonapi.cpp.o: Storage/CMakeFiles/ravstorage.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dong/rising/Source_Code/9.18-text/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building CXX object Storage/CMakeFiles/ravstorage.dir/__/CommonAPI/commonapi.cpp.o"
	cd /home/dong/rising/Source_Code/9.18-text/build/Storage && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Storage/CMakeFiles/ravstorage.dir/__/CommonAPI/commonapi.cpp.o -MF CMakeFiles/ravstorage.dir/__/CommonAPI/commonapi.cpp.o.d -o CMakeFiles/ravstorage.dir/__/CommonAPI/commonapi.cpp.o -c /home/dong/rising/Source_Code/9.18-text/UnixRav3/CommonAPI/commonapi.cpp

Storage/CMakeFiles/ravstorage.dir/__/CommonAPI/commonapi.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ravstorage.dir/__/CommonAPI/commonapi.cpp.i"
	cd /home/dong/rising/Source_Code/9.18-text/build/Storage && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dong/rising/Source_Code/9.18-text/UnixRav3/CommonAPI/commonapi.cpp > CMakeFiles/ravstorage.dir/__/CommonAPI/commonapi.cpp.i

Storage/CMakeFiles/ravstorage.dir/__/CommonAPI/commonapi.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ravstorage.dir/__/CommonAPI/commonapi.cpp.s"
	cd /home/dong/rising/Source_Code/9.18-text/build/Storage && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dong/rising/Source_Code/9.18-text/UnixRav3/CommonAPI/commonapi.cpp -o CMakeFiles/ravstorage.dir/__/CommonAPI/commonapi.cpp.s

# Object files for target ravstorage
ravstorage_OBJECTS = \
"CMakeFiles/ravstorage.dir/storage.cpp.o" \
"CMakeFiles/ravstorage.dir/cinifile.cpp.o" \
"CMakeFiles/ravstorage.dir/Entry/settingentry.cpp.o" \
"CMakeFiles/ravstorage.dir/SQLite3/sqlite3.c.o" \
"CMakeFiles/ravstorage.dir/Entry/baseentry.cpp.o" \
"CMakeFiles/ravstorage.dir/CPPSQLite/cppsqlite3.cpp.o" \
"CMakeFiles/ravstorage.dir/Entry/virusinfoentry.cpp.o" \
"CMakeFiles/ravstorage.dir/Entry/logevententry.cpp.o" \
"CMakeFiles/ravstorage.dir/Entry/scheduleentry.cpp.o" \
"CMakeFiles/ravstorage.dir/Entry/whitelistentry.cpp.o" \
"CMakeFiles/ravstorage.dir/Entry/commeventlog.cpp.o" \
"CMakeFiles/ravstorage.dir/Entry/quarantinelog.cpp.o" \
"CMakeFiles/ravstorage.dir/Entry/netaccessentry.cpp.o" \
"CMakeFiles/ravstorage.dir/Entry/urlruleentry.cpp.o" \
"CMakeFiles/ravstorage.dir/Entry/sourcelistentry.cpp.o" \
"CMakeFiles/ravstorage.dir/__/CommonAPI/commonapi.cpp.o"

# External object files for target ravstorage
ravstorage_EXTERNAL_OBJECTS =

3.0.0.1/lib/libravstorage.so: Storage/CMakeFiles/ravstorage.dir/storage.cpp.o
3.0.0.1/lib/libravstorage.so: Storage/CMakeFiles/ravstorage.dir/cinifile.cpp.o
3.0.0.1/lib/libravstorage.so: Storage/CMakeFiles/ravstorage.dir/Entry/settingentry.cpp.o
3.0.0.1/lib/libravstorage.so: Storage/CMakeFiles/ravstorage.dir/SQLite3/sqlite3.c.o
3.0.0.1/lib/libravstorage.so: Storage/CMakeFiles/ravstorage.dir/Entry/baseentry.cpp.o
3.0.0.1/lib/libravstorage.so: Storage/CMakeFiles/ravstorage.dir/CPPSQLite/cppsqlite3.cpp.o
3.0.0.1/lib/libravstorage.so: Storage/CMakeFiles/ravstorage.dir/Entry/virusinfoentry.cpp.o
3.0.0.1/lib/libravstorage.so: Storage/CMakeFiles/ravstorage.dir/Entry/logevententry.cpp.o
3.0.0.1/lib/libravstorage.so: Storage/CMakeFiles/ravstorage.dir/Entry/scheduleentry.cpp.o
3.0.0.1/lib/libravstorage.so: Storage/CMakeFiles/ravstorage.dir/Entry/whitelistentry.cpp.o
3.0.0.1/lib/libravstorage.so: Storage/CMakeFiles/ravstorage.dir/Entry/commeventlog.cpp.o
3.0.0.1/lib/libravstorage.so: Storage/CMakeFiles/ravstorage.dir/Entry/quarantinelog.cpp.o
3.0.0.1/lib/libravstorage.so: Storage/CMakeFiles/ravstorage.dir/Entry/netaccessentry.cpp.o
3.0.0.1/lib/libravstorage.so: Storage/CMakeFiles/ravstorage.dir/Entry/urlruleentry.cpp.o
3.0.0.1/lib/libravstorage.so: Storage/CMakeFiles/ravstorage.dir/Entry/sourcelistentry.cpp.o
3.0.0.1/lib/libravstorage.so: Storage/CMakeFiles/ravstorage.dir/__/CommonAPI/commonapi.cpp.o
3.0.0.1/lib/libravstorage.so: Storage/CMakeFiles/ravstorage.dir/build.make
3.0.0.1/lib/libravstorage.so: Storage/CMakeFiles/ravstorage.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dong/rising/Source_Code/9.18-text/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Linking CXX shared library ../3.0.0.1/lib/libravstorage.so"
	cd /home/dong/rising/Source_Code/9.18-text/build/Storage && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ravstorage.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Storage/CMakeFiles/ravstorage.dir/build: 3.0.0.1/lib/libravstorage.so
.PHONY : Storage/CMakeFiles/ravstorage.dir/build

Storage/CMakeFiles/ravstorage.dir/clean:
	cd /home/dong/rising/Source_Code/9.18-text/build/Storage && $(CMAKE_COMMAND) -P CMakeFiles/ravstorage.dir/cmake_clean.cmake
.PHONY : Storage/CMakeFiles/ravstorage.dir/clean

Storage/CMakeFiles/ravstorage.dir/depend:
	cd /home/dong/rising/Source_Code/9.18-text/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dong/rising/Source_Code/9.18-text/UnixRav3 /home/dong/rising/Source_Code/9.18-text/UnixRav3/Storage /home/dong/rising/Source_Code/9.18-text/build /home/dong/rising/Source_Code/9.18-text/build/Storage /home/dong/rising/Source_Code/9.18-text/build/Storage/CMakeFiles/ravstorage.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Storage/CMakeFiles/ravstorage.dir/depend
