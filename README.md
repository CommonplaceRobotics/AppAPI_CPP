# iRC App Interface Client API for C++
[![Build and Test for Linux x86_64](https://github.com/CommonplaceRobotics/AppAPI_CPP/actions/workflows/build_linux_x86_64.yml/badge.svg)](https://github.com/CommonplaceRobotics/AppAPI_CPP/actions/workflows/build_linux_x86_64.yml)
[![Build and Test for Windows](https://github.com/CommonplaceRobotics/AppAPI_CPP/actions/workflows/build_windows.yml/badge.svg)](https://github.com/CommonplaceRobotics/AppAPI_CPP/actions/workflows/build_windows.yml)
[![Build for RPi](https://github.com/CommonplaceRobotics/AppAPI_CPP/actions/workflows/build_linux_rpi.yml/badge.svg)](https://github.com/CommonplaceRobotics/AppAPI_CPP/actions/workflows/build_linux_rpi.yml)

This library provides a simple C++ interface to the igus Robot Control. It provides functions for observing the state of the robot, issuing motion commands, controlling robot programs, accessing files, updating and handling events from the app user interface, receiving commands from robot programs ("app commands") and much more.

This API is an abstraction for the [gRPC](https://grpc.io/) based app interface. For other languages [the gRPC interface can be generated from the gRPC definition file](https://grpc.io/docs/languages/) in directory ```protos```.

## Content
| Name                          | Description                                                           |
|-------------------------------|-----------------------------------------------------------------------|
| cmake                         | Contains additional files for CMake                                   |
| protos                        | Contains Protobuf / gRPC definition files                             |
| src                           | Contains source and header files                                      |
| tests                         | Contains test source files                                            |
| BUILDING.md                   | Explains how to compile the library                                   |
| CMakeLists.txt                | Defines how the library is build via CMake                            |
| conan.lock                    | Dependency lock file                                                  |
| conan_install_*.sh / *.ps1    | Installs dependencies using Conan 2                                   |
| conanfile.py                  | Defines the dependencies and file structure of the toolchain files    |
| LICENSE                       | License for using this library                                        |
| Licenses_SampleApps.pdf       | Mentions the licenses of used components                              |
| README.md                     | You are reading this file                                             |

## API documentation
The header files in ```src``` are extensively documented. Start by reading the public methods of [AppClient.h](src/AppClient.h), which contains most functions of the app API.

The directory [doc](doc/README.md) contains guides for specific tasks.

## Using this library

We suggest using the [minimal sample app](https://github.com/CommonplaceRobotics/RobotControlApps) as a starting point for your igus Robot Control app. Its documentation also explains how to set up the additional files (e.g. ```rcapp.xml``` and ```ui.xml```) and the package structure.

If you start out from scratch we recommend the following approach:
1. Add the API code to your project, either by including this repository as a git submodule or by copying this code to your project.
2. Include this directory to your ```CMakeLists.txt``` by adding the following line (change the first path so it points to this directory):
    ```CMake
    add_subdirectory(../AppAPI_CPP ${CMAKE_BINARY_DIR}/AppAPI_CPP)
    ```
3. Add ```iRCApp``` as a library to your executable:
    ```CMake
    target_link_libraries(<YourAppTarget>
        PUBLIC
        <YourOtherDependencies>
        iRCApp
    )
    ```
4. Install the dependencies, e.g. using a package manager like Conan, see the next section.

## Compatibility
The API should run on any system that can compile and run the GRPC code.

Any documentation and scripts in this repository have been tested with:
* Visual Studio 2022 and 2026 on Windows 11 (MSVC compiler)
* gcc 11 for x86_64 on Ubuntu 22.04 in WSL
* gcc 10.5 for armv8_32 on Ubuntu 22.04 in WSL

## Installing the dependencies
The App API depends on the following libraries (see the required/recommended versions in ```conanfile.py```):
* gRPC
* gtest (only if building the tests, see CMake option ```BUILD_TESTS```)

While you can manually install the dependencies into your system we recommend using the package manager [Conan](https://conan.io/). Follow Conan's documentation on [how to install and set up Conan](https://docs.conan.io/2/installation.html).

The Conan default profile may work out of the box but for compatiblity with our scripts we suggest installing our profiles. You can find these in directory ```tools/conan/profiles/<Operating System>```. Copy these into your Conan profiles directory (```~/.conan2/profiles``` on Linux, ```C:\Users\<User>\.conan2\profiles``` on Windows).

For cross compiling to let your app run on the embedded control module you will need our cross compilation toolchain:
```bash
mkdir -p /opt/gcc
cd /opt/gcc
sudo wget --quiet https://downloads.cpr-robots.com/Software/CI/gcc_armv8-rpi4-linux-gnueabihf.tar.gz
sudo tar -xf gcc_armv8-rpi4-linux-gnueabihf.tar.gz
```
If you prefer to install it to a different location you will need to change the paths in the Conan profile file ```cpr_linux_rpi4_gcc10```.




# ALT


### Linux native
Follow this approach if you want to test or run your app on a Linux system without cross compiling. This was testet on Ubuntu 22.04 in WSL but should work similarly for different distributions.

1. Make sure the development tools (```gcc```, ```cmake```, ```python3```, ```python3-venv```, etc.) are installed.
2. Copy ```conan_install_linux_native.sh``` to your project and run it to automatically install conan and the dependencis, thencontinue with step 7 OR skip this step to install it manually.
3. Install [Conan 2](https://conan.io/), we suggest you do this in a virtual Python environment (venv):
    ```sh
    python3 -m venv ~/.conan_venv
	source ~/.conan_venv/bin/activate
	python3 -m pip install conan
    ```
    Whenever you want to run Conan you will need to activate the venv:
    ```
    source ~/.conan_venv/bin/activate
    ```
4. Generate the default Conan profile:
    ```sh
    conan profile detect
    ```
5. You can work with the default profile but we suggest installing our custom profiles, which are based on the default profile. To do this copy the files from ```tools/conan/profile/Linux``` to ```~/.conan2/profiles```.
6. In your project directory run the following command to download and build the dependencies and to generate a CMake toolchain file in ```out/conan/Linux/x86_64/Release/generators```.
    ```sh
    conan install . --lockfile-partial --build=missing --profile=cpr_linux_x86_64_release -c tools.cmake.cmake_layout:build_folder_vars="['settings.os', 'settings.arch']"
    ```
    If you do not want to remember this command you may copy ```conan_install_linux_native.sh``` to your project. This file also installs creates the venv and installs conan if necessary.
7. Note that ```CMakeUserPresets.json``` is generated in your project directory (this file should not be checked in to version control). CMake (version 3.19 and newer) can use this to configure and build your app:
    ```sh
    cmake --preset conan-linux-x86_64-release
    cmake --build --preset conan-linux-x86_64-release
    ```
    If you are working on Windows with WSL you can open your project's directory in Visual Studio. It should detect it as a CMake project and find the generated toolchain from ```CMakeUserPresets.json```. Select the toolchain (```conan-linux-x86_64-release``` or ```conan-linux-x86_64-debug```) and the target (your app binary) in the menu above the code editor, then build your app.

The same approach works for editing the API code.

Repeat step 6 after updating the API, this will install the newest dependencies.

### Linux armhf (Embedded Robot Control / Raspberry Pi)

To cross compile for the Embedded Robot Control (Raspberry Pi) you need:
1. Build dependencies and conan for the build system (follow steps 1 - 5 of section "Linux native")
2. Install the cross compiler tool chain (you can not use a generic one due to glibc and libstdc++ dependencies):
    ```sh
	mkdir -p /opt/gcc
	cd /opt/gcc
	sudo wget --quiet https://downloads.cpr-robots.com/Software/CI/gcc_armv8-rpi4-linux-gnueabihf.tar.gz
	sudo tar -xf gcc_armv8-rpi4-linux-gnueabihf.tar.gz
    ```
    You may install it to a different directory, in this case change the paths in the conan profile (```~/.conan2/profiles/cpr_linux_rpi4_gcc10```).
3. In your project directory run the following command to download and build the dependencies and to generate a CMake toolchain file in ```out/conan/Linux/x86_64/Release/generators```.
    ```sh
    conan install . --lockfile-partial --build=missing --profile:host=cpr_linux_rpi4_gcc10_release --profile:build=cpr_linux_x86_64_release -c tools.cmake.cmake_layout:build_folder_vars="['settings.os', 'settings.arch']"
    ```
    If you do not want to remember this command you may copy ```conan_install_linux_native.sh``` to your project. This file also installs creates the venv and installs conan if necessary.
4. Note that ```CMakeUserPresets.json``` is generated in your project directory (this file should not be checked in to version control). CMake (version 3.19 and newer) can use this to configure and build your app:
    ```sh
    cmake --preset conan-linux-x86_64-release
    cmake --build --preset conan-linux-x86_64-release
    ```
