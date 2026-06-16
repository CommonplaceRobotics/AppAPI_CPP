# iRC App interface API for C++

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

## Installing the dependencies
The App API depends on the following libraries (see the required/recommended versions in ```conanfile.py```):
* gRPC
* gtest (only if building the tests)

When cross compiling the gRPC and Protobuf compilers are required on the build system.

We assume that you are compiling on Windows with MSVC (the Visual Studio Compiler) and cross-compiling for armhf (Raspberry Pi 4) on Ubuntu in WSL. Compiling on a native Linux system should work in the same way.

We suggest using Conan 2 for installing the dependencies, but you can also use other approaches like vcpkg or natively installed packages. If you use Conan set up a ```conanfile.py``` in your project with the given dependencies (you may copy the file from this repository).

The following sections explain how to install the toolchain and dependencies using Conan 2. Note that compiling the dependencies (especially gRPC) may take a long time (15-30 minutes or more).

### Windows
Follow this approach if you want to compile your app for Windows, e.g. for testing, for running it in simulation or to run it on a Windows PC while letting the app connect to a real robot.

1. Install [Visual Studio](https://visualstudio.microsoft.com)
2. Run the following commands in a Developer Powershell: In Visual Studio's menu bar click "Tools -> Command Line -> Developer PowerShell". This makes sure all development tools are found.
3. Install [Conan 2](https://conan.io/)
4. Generate the default Conan profile:
    ```sh
    conan profile detect
    ```
5. You can work with the default profile but we suggest installing our custom profiles, which are based on the default profile. To do this copy the files from ```tools/conan/profile/Windows``` to ```C:\Users\YourUserName\.conan2\profiles```.
6. In your project directory run the following command to download and build the dependencies and to generate a CMake toolchain file in ```out\conan\Windows\Release\generators```.
    ```sh
    conan install . --lockfile-partial --build=missing --profile=cpr_windows_x86_64_release -c tools.cmake.cmake_layout:build_folder_vars="['settings.os', 'settings.arch']" -s:b compiler.cppstd=17
    ```
    If you do not want to remember this command you may copy ```conan_install_windows.ps1``` to your project.
7. Note that ```CMakeUserPresets.json``` is generated in your project directory (this file should not be checked in to version control). CMake (version 3.19 and newer) can use this to configure and build your app:
    ```sh
    cmake --preset conan-windows-x86_64-release
    cmake --build --preset conan-windows-x86_64-release
    ```
    Alternatively you can open your project's directory in Visual Studio. It should detect it as a CMake project and find the generated toolchain from ```CMakeUserPresets.json```. Select the toolchain (```conan-windows-x86_64-release``` or ```conan-windows-x86_64-debug```) and the target (your app binary) in the menu above the code editor, then build your app.

The same approach works for editing the API code.

Repeat step 6 after updating the API, this will install the newest dependencies.

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
