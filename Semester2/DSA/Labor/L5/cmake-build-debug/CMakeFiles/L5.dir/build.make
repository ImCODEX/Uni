# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.19

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


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

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.1.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.1.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Razvan\OneDrive\Documents\UBBIG\Semester2\DSA\Labor\L5

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Razvan\OneDrive\Documents\UBBIG\Semester2\DSA\Labor\L5\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles\L5.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\L5.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\L5.dir\flags.make

CMakeFiles\L5.dir\App.cpp.obj: CMakeFiles\L5.dir\flags.make
CMakeFiles\L5.dir\App.cpp.obj: ..\App.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Razvan\OneDrive\Documents\UBBIG\Semester2\DSA\Labor\L5\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/L5.dir/App.cpp.obj"
	C:\PROGRA~2\MICROS~2\2019\BUILDT~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\L5.dir\App.cpp.obj /FdCMakeFiles\L5.dir\ /FS -c C:\Users\Razvan\OneDrive\Documents\UBBIG\Semester2\DSA\Labor\L5\App.cpp
<<

CMakeFiles\L5.dir\App.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/L5.dir/App.cpp.i"
	C:\PROGRA~2\MICROS~2\2019\BUILDT~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe > CMakeFiles\L5.dir\App.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Razvan\OneDrive\Documents\UBBIG\Semester2\DSA\Labor\L5\App.cpp
<<

CMakeFiles\L5.dir\App.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/L5.dir/App.cpp.s"
	C:\PROGRA~2\MICROS~2\2019\BUILDT~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\L5.dir\App.cpp.s /c C:\Users\Razvan\OneDrive\Documents\UBBIG\Semester2\DSA\Labor\L5\App.cpp
<<

CMakeFiles\L5.dir\Bag.cpp.obj: CMakeFiles\L5.dir\flags.make
CMakeFiles\L5.dir\Bag.cpp.obj: ..\Bag.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Razvan\OneDrive\Documents\UBBIG\Semester2\DSA\Labor\L5\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/L5.dir/Bag.cpp.obj"
	C:\PROGRA~2\MICROS~2\2019\BUILDT~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\L5.dir\Bag.cpp.obj /FdCMakeFiles\L5.dir\ /FS -c C:\Users\Razvan\OneDrive\Documents\UBBIG\Semester2\DSA\Labor\L5\Bag.cpp
<<

CMakeFiles\L5.dir\Bag.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/L5.dir/Bag.cpp.i"
	C:\PROGRA~2\MICROS~2\2019\BUILDT~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe > CMakeFiles\L5.dir\Bag.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Razvan\OneDrive\Documents\UBBIG\Semester2\DSA\Labor\L5\Bag.cpp
<<

CMakeFiles\L5.dir\Bag.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/L5.dir/Bag.cpp.s"
	C:\PROGRA~2\MICROS~2\2019\BUILDT~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\L5.dir\Bag.cpp.s /c C:\Users\Razvan\OneDrive\Documents\UBBIG\Semester2\DSA\Labor\L5\Bag.cpp
<<

CMakeFiles\L5.dir\BagIterator.cpp.obj: CMakeFiles\L5.dir\flags.make
CMakeFiles\L5.dir\BagIterator.cpp.obj: ..\BagIterator.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Razvan\OneDrive\Documents\UBBIG\Semester2\DSA\Labor\L5\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/L5.dir/BagIterator.cpp.obj"
	C:\PROGRA~2\MICROS~2\2019\BUILDT~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\L5.dir\BagIterator.cpp.obj /FdCMakeFiles\L5.dir\ /FS -c C:\Users\Razvan\OneDrive\Documents\UBBIG\Semester2\DSA\Labor\L5\BagIterator.cpp
<<

CMakeFiles\L5.dir\BagIterator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/L5.dir/BagIterator.cpp.i"
	C:\PROGRA~2\MICROS~2\2019\BUILDT~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe > CMakeFiles\L5.dir\BagIterator.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Razvan\OneDrive\Documents\UBBIG\Semester2\DSA\Labor\L5\BagIterator.cpp
<<

CMakeFiles\L5.dir\BagIterator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/L5.dir/BagIterator.cpp.s"
	C:\PROGRA~2\MICROS~2\2019\BUILDT~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\L5.dir\BagIterator.cpp.s /c C:\Users\Razvan\OneDrive\Documents\UBBIG\Semester2\DSA\Labor\L5\BagIterator.cpp
<<

CMakeFiles\L5.dir\ExtendedTest.cpp.obj: CMakeFiles\L5.dir\flags.make
CMakeFiles\L5.dir\ExtendedTest.cpp.obj: ..\ExtendedTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Razvan\OneDrive\Documents\UBBIG\Semester2\DSA\Labor\L5\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/L5.dir/ExtendedTest.cpp.obj"
	C:\PROGRA~2\MICROS~2\2019\BUILDT~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\L5.dir\ExtendedTest.cpp.obj /FdCMakeFiles\L5.dir\ /FS -c C:\Users\Razvan\OneDrive\Documents\UBBIG\Semester2\DSA\Labor\L5\ExtendedTest.cpp
<<

CMakeFiles\L5.dir\ExtendedTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/L5.dir/ExtendedTest.cpp.i"
	C:\PROGRA~2\MICROS~2\2019\BUILDT~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe > CMakeFiles\L5.dir\ExtendedTest.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Razvan\OneDrive\Documents\UBBIG\Semester2\DSA\Labor\L5\ExtendedTest.cpp
<<

CMakeFiles\L5.dir\ExtendedTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/L5.dir/ExtendedTest.cpp.s"
	C:\PROGRA~2\MICROS~2\2019\BUILDT~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\L5.dir\ExtendedTest.cpp.s /c C:\Users\Razvan\OneDrive\Documents\UBBIG\Semester2\DSA\Labor\L5\ExtendedTest.cpp
<<

CMakeFiles\L5.dir\ShortTest.cpp.obj: CMakeFiles\L5.dir\flags.make
CMakeFiles\L5.dir\ShortTest.cpp.obj: ..\ShortTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Razvan\OneDrive\Documents\UBBIG\Semester2\DSA\Labor\L5\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/L5.dir/ShortTest.cpp.obj"
	C:\PROGRA~2\MICROS~2\2019\BUILDT~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\L5.dir\ShortTest.cpp.obj /FdCMakeFiles\L5.dir\ /FS -c C:\Users\Razvan\OneDrive\Documents\UBBIG\Semester2\DSA\Labor\L5\ShortTest.cpp
<<

CMakeFiles\L5.dir\ShortTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/L5.dir/ShortTest.cpp.i"
	C:\PROGRA~2\MICROS~2\2019\BUILDT~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe > CMakeFiles\L5.dir\ShortTest.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Razvan\OneDrive\Documents\UBBIG\Semester2\DSA\Labor\L5\ShortTest.cpp
<<

CMakeFiles\L5.dir\ShortTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/L5.dir/ShortTest.cpp.s"
	C:\PROGRA~2\MICROS~2\2019\BUILDT~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\L5.dir\ShortTest.cpp.s /c C:\Users\Razvan\OneDrive\Documents\UBBIG\Semester2\DSA\Labor\L5\ShortTest.cpp
<<

# Object files for target L5
L5_OBJECTS = \
"CMakeFiles\L5.dir\App.cpp.obj" \
"CMakeFiles\L5.dir\Bag.cpp.obj" \
"CMakeFiles\L5.dir\BagIterator.cpp.obj" \
"CMakeFiles\L5.dir\ExtendedTest.cpp.obj" \
"CMakeFiles\L5.dir\ShortTest.cpp.obj"

# External object files for target L5
L5_EXTERNAL_OBJECTS =

L5.exe: CMakeFiles\L5.dir\App.cpp.obj
L5.exe: CMakeFiles\L5.dir\Bag.cpp.obj
L5.exe: CMakeFiles\L5.dir\BagIterator.cpp.obj
L5.exe: CMakeFiles\L5.dir\ExtendedTest.cpp.obj
L5.exe: CMakeFiles\L5.dir\ShortTest.cpp.obj
L5.exe: CMakeFiles\L5.dir\build.make
L5.exe: CMakeFiles\L5.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Razvan\OneDrive\Documents\UBBIG\Semester2\DSA\Labor\L5\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable L5.exe"
	"C:\Program Files\JetBrains\CLion 2021.1.1\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\L5.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100190~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100190~1.0\x86\mt.exe --manifests -- C:\PROGRA~2\MICROS~2\2019\BUILDT~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\L5.dir\objects1.rsp @<<
 /out:L5.exe /implib:L5.lib /pdb:C:\Users\Razvan\OneDrive\Documents\UBBIG\Semester2\DSA\Labor\L5\cmake-build-debug\L5.pdb /version:0.0 /machine:X86 /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\L5.dir\build: L5.exe

.PHONY : CMakeFiles\L5.dir\build

CMakeFiles\L5.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\L5.dir\cmake_clean.cmake
.PHONY : CMakeFiles\L5.dir\clean

CMakeFiles\L5.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\Users\Razvan\OneDrive\Documents\UBBIG\Semester2\DSA\Labor\L5 C:\Users\Razvan\OneDrive\Documents\UBBIG\Semester2\DSA\Labor\L5 C:\Users\Razvan\OneDrive\Documents\UBBIG\Semester2\DSA\Labor\L5\cmake-build-debug C:\Users\Razvan\OneDrive\Documents\UBBIG\Semester2\DSA\Labor\L5\cmake-build-debug C:\Users\Razvan\OneDrive\Documents\UBBIG\Semester2\DSA\Labor\L5\cmake-build-debug\CMakeFiles\L5.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\L5.dir\depend

