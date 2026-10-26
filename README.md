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

### Toolchain
While you can manually install the dependencies into your system we recommend using the package manager [Conan](https://conan.io/). Follow Conan's documentation on [how to install and set up Conan](https://docs.conan.io/2/installation.html).

The Conan default profile may work out of the box but for compatiblity with our scripts we suggest installing our profiles. You can find these in directory ```tools/conan/profiles/<Operating System>```. Copy these into your Conan profiles directory (```~/.conan2/profiles``` on Linux, ```C:\Users\<User>\.conan2\profiles``` on Windows).

### Cross Compilation Toolchain

For cross compiling to let your app run on the embedded control module you will need our cross compilation toolchain:
```bash
mkdir -p /opt/gcc
cd /opt/gcc
sudo wget --quiet https://downloads.cpr-robots.com/Software/CI/gcc_armv8-rpi4-linux-gnueabihf.tar.gz
sudo tar -xf gcc_armv8-rpi4-linux-gnueabihf.tar.gz
```
If you prefer to install it to a different location you will need to change the paths in the Conan profile file ```cpr_linux_rpi4_gcc10```.

### Building the dependencies using Conan

Next you will need to build the dependencies. We prepared the scripts ```conan_install_linux*.sh``` and ```conan_install_windows.ps1``` to make this as easy as possible. These build and install the dependencies to the ```build``` directory. The Linux scripts first install conan (if not installed yet) in a Python venv. To install the dependencies to your app's repository call the scripts from your base directory. When compiling for the first time this may take around 30 minutes or more.

You will need to call the script whenever dependencies changed (e.g. when you update the API or add your own dependencies).

Note that debug versions of the dependencies may be commented out in the script files for faster compilation. If you need to do debug builds remove the ```#``` from the line.

Now you are ready for compiling your application. If you open the repositry as folder in Visual Studio it will detect the build profiles from the generated ```CMakeUserPresets.json```. If you got a sufficiently new version of CMake you can also use its command line parameters to generate and build with the CMake presets.
