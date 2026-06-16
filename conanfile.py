import os

from conan import ConanFile


class Recipe(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeDeps", "CMakeToolchain"

    def requirements(self):
        # These requirements are linked to the product binary
        self.requires("grpc/1.81.0")

    def build_requirements(self):
        # These requirements are tools or for testing and therefore are not part of the product
        if self.settings.os != "Windows":
            self.tool_requires("cmake/[^3.27.9]")

        # gtest for testing
        self.test_requires("gtest/[^1.13]")

        # We need the GRPC compiler on the host system
        self.tool_requires("grpc/1.81.0")
        # The protobuf version must match the version used by grpc (see conan.io). This explicit declaration is needed to get protoc in PATH.
        self.tool_requires("protobuf/6.33.5")

    def layout(self):
        # Defines the directory structure
        if self.settings.os == "Windows":
            self.folders.generators = os.path.join(
                "out",
                "conan",
                str(self.settings.os),
                str(self.settings.build_type),
                "generators",
            )
            self.folders.build = os.path.join(
                "out", "build", str(self.settings.os), str(self.settings.build_type)
            )
        else:
            # Linux: also distinguish architecture
            self.folders.generators = os.path.join(
                "out",
                "conan",
                str(self.settings.os),
                str(self.settings.arch),
                str(self.settings.build_type),
                "generators",
            )
            self.folders.build = os.path.join(
                "out",
                "build",
                str(self.settings.os),
                str(self.settings.arch),
                str(self.settings.build_type),
            )
