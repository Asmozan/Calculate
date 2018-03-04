find_package(Threads REQUIRED)
find_package(GTest REQUIRED)

# Enable ExternalProject CMake module
include(ExternalProject)

# Download and install GoogleTest

# Create a libgtest target to be used as a dependency by test programs

add_subdirectory(srcTests)
