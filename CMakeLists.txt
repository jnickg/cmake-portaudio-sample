cmake_minimum_required(VERSION 3.28)

project(portaudio-sample
    VERSION 0.0.1
    DESCRIPTION "Audio explorations in C++"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)

# Adds the portaudio project as an available link target
# CMake does this by detecting portaudio's own CMakeLists tree,
# and adding it to the build system.
#
# Then it will automatically be built from source and linked into
# anything you build that links against it
add_subdirectory(portaudio)

# Make an executable target. Below we specify the source files, and
# later on we specify the libraries we want to link against
add_executable(portaudio-sample
    main.cpp
)

# You can also call target_include_directories to explicitly say
# you want to include the portaudio headers, but the below call
# implicitly does that for you
target_link_libraries(portaudio-sample
    PRIVATE
        portaudio
)