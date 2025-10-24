# This toolchain file forces the MSVC compiler settings needed for C++23 Modules.
include_guard(GLOBAL)

# Set the target system, which is standard for a toolchain file.
set(CMAKE_SYSTEM_NAME Windows)

# Force-enable experimental 'import std;' support.
# This bypasses CMake's faulty automatic detection and creates the necessary
# "__CMAKE::CXX23" target that the build process requires.
set(CMAKE_EXPERIMENTAL_CXX_MODULE_STD ON)