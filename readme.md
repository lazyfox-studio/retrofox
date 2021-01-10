[![](https://lazyfox.dev/user/pages/03.projects/retrofox/Full%20logo%20colored%202048.png)](https://retrofox.lazyfox.dev)

Cross-platform (Windows, Linux, Raspberry Pi) launcher for old console games.

[![Build Status](https://travis-ci.com/lazyfox-studio/retrofox.svg?branch=master)](https://travis-ci.com/lazyfox-studio/retrofox)
[![Build status](https://ci.appveyor.com/api/projects/status/bh75mg5h19rd0qhj/branch/master?svg=true)](https://ci.appveyor.com/project/vla5924/retrofox/branch/master)


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

Deploy **vcpkg** with these commands:

```sh
git clone https://github.com/microsoft/vcpkg.git
cd vcpkg
.\bootstrap-vcpkg.bat -disableMetrics
```

Then, install required packages:

```sh
vcpkg install python3:x64-windows sqlite3:x64-windows qt5:x64-windows
```

Note: since package manager will build all the libraries from the source code directly on your machine, this can take a long time.

After installing dependencies, run build with these commands:

```sh
mkdir build && cd build
cmake -DCMAKE_TOOLCHAIN_FILE=[path to vcpkg root]/scripts/buildsystems/vcpkg.cmake -DBUILD_CORE=ON ..
cmake --build .
```

## Linux

We recommend to use system package manager to handle with dependencies (but you still can use **vcpkg** as in manual for Windows).
You also need to install [CMake](https://cmake.org/download/) (3.14 or newer), and latest GCC and Make.

You can install dependencies by executing the corresponding command to your distribution:

* Debian/Ubuntu
  ```bash
  sudo apt install python3-dev libsqlite3-dev qtbase5-dev qtdeclarative5-dev qttools5-dev libsdl2-dev libsdl2-ttf-dev
  ```
* Arch/Manjaro
  ```bash
  sudo pacman -S python3 libsqlite3-dev qt5-base qt5-declarative qt5-tools sdl2 sdl2_ttf
  ```

After installing dependencies, run build with these commands:

```sh
mkdir build && cd build
cmake -DBUILD_CORE=ON ..
make
```
