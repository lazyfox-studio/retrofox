![](https://lazyfox.dev/user/pages/03.projects/retrofox/Full%20logo%20colored%202048.png)

Cross-platform (Windows, Linux, Raspberry Pi) launcher for old console games.


[![Build Status](https://travis-ci.com/lazyfox-studio/retrofox.svg?branch=master)](https://travis-ci.com/lazyfox-studio/retrofox)

# Documentation

We documented literally every symbol in our code, so you can found documentation [here](https://retrofox.lazyfox.dev/docs).


# Build

The following packages are required:
* Python 3 
* SQLite3
* Qt 5 _(will be replaced with Qt 6 in future RetroFox releases)_
* SDL 2 with TTF plugin _(will become obsolete in future RetroFox releases)_


## Windows

We recommend to use **[vcpkg](https://github.com/Microsoft/vcpkg)** to handle with dependencies.
You also need to install [CMake](https://cmake.org/download/) (3.14 or newer) and [Build Tools for Visual Studio](https://visualstudio.microsoft.com/downloads/) (2019 or newer).

```sh
vcpkg install sqlite3:x64-windows
vcpkg install qt5:x64-windows
```

> Python and SDL development packages can be downloaded from their official webistes.

After installing dependencies, run build with these commands:

```sh
mkdir build && cd build
cmake .. -DCMAKE_TOOLCHAIN_FILE=[path to vcpkg root]/scripts/buildsystems/vcpkg.cmake
cmake --build .
```


## Linux

We recommend to use system package manager to handle with dependencies (but you still can use **vcpkg** as in manual for Windows).
You also need to install [CMake](https://cmake.org/download/) (3.14 or newer) and `build-essential` pack (including GCC and Make).

This is a command for **apt** on Ubuntu:
```bash
sudo apt install python3-dev libsqlite3-dev qtbase5-dev qtdeclarative5-dev qttools5-dev libsdl2-dev libsdl2-ttf-dev
```

After installing dependencies, run build with these commands:

```sh
mkdir build && cd build
cmake ..
make
```
