###############################################################################
# This is a sample CMakeLists.txt. Replace all instances of "minimalapp" with
# the name of your app.
# If necessary add your source files and libraries in the Target Definition
# section. Define files to copy to the output in the Copy Data section.
###############################################################################
cmake_minimum_required (VERSION 3.16)

project(iRC_App_API
	VERSION 14.6.7
    LANGUAGES C CXX
)
# Version suffix, should be empty for release versions
set(PROJECT_VERSION_SUFFIX "")
# Life cycle information for the SBOM
set(RELEASE_DATE "2026-05-08")
set(SUPPORT_PERIOD_END "2000-00-00") # TODO: define support period
set(END_OF_LIFE "2000-00-00") # TODO: define end of life
configure_file(src/Version.h.in src/Version.h)
configure_file(sbomify.json.in sbomify.json)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

option(BUILD_TESTS "Compile tests" ON)

###############################################################################
# Generating gRPC C++-Sources
###############################################################################

find_package(Protobuf REQUIRED)
find_package(gRPC REQUIRED)

include(cmake/gRPC.cmake)
file(GLOB PROTOS
    "${CMAKE_CURRENT_SOURCE_DIR}/protos/*.proto"
)

set(PROTO_SRC_DIR "${CMAKE_CURRENT_BINARY_DIR}/generated_protos")

protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS ${PROTO_SRC_DIR} ${PROTOS})
grpc_generate_cpp(GRPC_SRCS GRPC_HDRS ${PROTO_SRC_DIR} ${PROTOS})

list(APPEND INCLUDE_DIRS
    ${PROTO_SRC_DIR}
)

list(APPEND GRPC_SOURCES
    ${GRPC_SRCS}
    ${PROTO_SRCS}
)

###############################################################################
# Target definition - define the app source and dependencies here!
###############################################################################

file(GLOB APP_SOURCES src/*.cpp)
file(GLOB APP_SOURCES_DATATYPES src/DataTypes/*.cpp)
file(GLOB SOURCES_tests_DataTypes tests/DataTypes/*.cpp)

add_library(iRCApp
	${GRPC_SOURCES}
	${APP_SOURCES}
	${APP_SOURCES_DATATYPES}
)

target_include_directories(iRCApp
	PUBLIC
	src
    ${PROTO_SRC_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}/src/
)

include(CMakePrintHelpers)
cmake_print_variables(CMAKE_CURRENT_BINARY_DIR)

target_link_libraries(iRCApp
    PUBLIC
    protobuf::libprotobuf
    gRPC::grpc++
	PRIVATE
	Threads::Threads
)

if(UNIX OR MINGW)
	target_compile_options(iRCApp
		PRIVATE
		# More warnings:
		-Wall -Wextra -pedantic
		# More errors:
		-Werror=parentheses -Werror=return-type
	)
elseif(MSVC)
endif()

###############################################################################
# Unit Tests
###############################################################################

# Avoid warning about DOWNLOAD_EXTRACT_TIMESTAMP in CMake 3.24:
if (CMAKE_VERSION VERSION_GREATER_EQUAL "3.24.0")
	cmake_policy(SET CMP0135 NEW)
endif()

if (BUILD_TESTS)
    enable_testing()
    find_package(GTest REQUIRED)
    # Include the GoogleTest module for gtest_discover_tests()
    include(GoogleTest)

    add_executable(iRCApp_Tests
        ${SOURCES_tests_DataTypes}
    )

    target_include_directories(iRCApp_Tests
		PRIVATE
        ${INCLUDE_DIRS}
	)

    target_link_libraries(iRCApp_Tests
		PRIVATE
		iRCApp
        GTest::gtest_main
		GTest::gmock
	)

    if(UNIX OR MINGW)
        target_compile_options(iRCApp_Tests
			PRIVATE
            # More warnings:
            -Wall -Wextra -pedantic
			# More errors:
			-Werror=parentheses -Werror=return-type
        )
    elseif(MSVC)
    endif()

    # Detect test cases (this does not work when cross compiling as it executes the binary)
    if(!CMAKE_CROSSCOMPILING)
        gtest_discover_tests(iRCApp_Tests)
    endif()
endif()
