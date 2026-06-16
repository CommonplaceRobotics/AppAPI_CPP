#!/bin/bash
# Builds the dependencies and toolchain via conan. This must be called before using CMake.

echo "Checking whether the Conan venv exists..."

# Install Python venv, if not installed
if [ `dpkg --get-selections | grep -c python3-venv` == "0" ]; then
	echo "python3-venv is not installed, installing it..."
	sudo apt install python3-venv
fi

# Create the Python venv, if it does not exist
if [ ! -e ~/.conan_venv/bin/activate ]; then
	echo "Python venv does not exist, creating it..."
	python3 -m venv ~/.conan_venv
	source ~/.conan_venv/bin/activate
	python3 -m pip install conan
fi

SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )

# Install Conan in Python venv if it is not installed globally(this is intended for local development)
IS_CONAN_INSTALLED_GLOBALLY=`command -v conan`
if [ ! "$IS_CONAN_INSTALLED_GLOBALLY" ]; then
	$SCRIPT_DIR/conan_install_venv.sh
	source ~/.conan_venv/bin/activate
fi

echo "Building release dependencies..."
conan install . --lockfile-partial --build=missing --profile:host=cpr_linux_rpi4_gcc10_release --profile:build=cpr_linux_x86_64_release -c tools.cmake.cmake_layout:build_folder_vars="['settings.os', 'settings.arch']"
# Uncomment to build dependencies for debugging
#conan install . --lockfile-partial --build=missing --profile:host=cpr_linux_rpi4_gcc10_debug --profile:build=cpr_linux_x86_64_release -c tools.cmake.cmake_layout:build_folder_vars="['settings.os', 'settings.arch']"

echo "Clearing unused dependencies..."
conan remove --lru=12w "*"
