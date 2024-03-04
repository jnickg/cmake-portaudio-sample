# CMake PortAudio Sample

This repo contains a simple example of a project that is buildable via CMake, and which builds its dependencies via CMake.

The only dependency is `portaudio`, which is built from source. It is included as a submodule of the repo.

[`main.cpp`](./main.cpp) Is the main program in this project, which consumes `portaudio` includes, and links against it, to iterate through available audio devices on your system.

See comments in [`CMakeLists.txt`](./CMakeLists.txt) for more explanation

## Building

1. `git clone this-repo`
2. `mkdir build && cd build`
3. `cmake ..` to configure this project with the default generator
4. `cmake --build .` to build all targets in this project. Since the main target, `portaudio-sample`, depends on `portaudio`, the `portaudio` library will also be built.
