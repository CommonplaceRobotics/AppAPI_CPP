# Builds the dependencies and toolchain via conan. This must be called before using CMake.

# Install dependencies
conan install . --lockfile-partial --build=missing --profile=cpr_windows_x86_64_release -c tools.cmake.cmake_layout:build_folder_vars="['settings.os', 'settings.arch']" -s:b compiler.cppstd=17
# Uncomment to build dependencies for debugging
#conan install . --lockfile-partial --build=missing --profile=cpr_windows_x86_64_debug -c tools.cmake.cmake_layout:build_folder_vars="['settings.os', 'settings.arch']" -s:b compiler.cppstd=17

# Clear unused dependencies
conan remove --lru=12w "*"
