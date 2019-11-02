# CMakeList.txt : CMake project for VenisEngineSource, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

file(GLOB_RECURSE source_files ("VenisEngineSource.cpp" "VenisEngineSource.h" "VenisEngineExecutable/*.cpp" "VenisEngineExecutable/*.h"))

# Add source to this project's executable.
add_executable (VenisEngineSource ${source_files})
# TODO: Add tests and install targets if needed.
