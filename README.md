# London Racer Decompilation

This project reverse engineers the binary spel.dat from the game London Racer. This binary only contains the game part of the game, not the menu or the launcher. Those will have their own projects.

This project uses the following tools to get this work done:
- [Ghidra](https://github.com/NationalSecurityAgency/ghidra) for reverse engineering the code.
- [Reccmp](https://github.com/isledecomp/reccmp) for comparing the written code with the same function in the original binary.
- [MSVC++ 6](https://github.com/itsmattkc/MSVC600) as the compiler.
- [CMake](https://cmake.org/) for letting the compiler know what to do.

Currently this project is build on and for Windows, like the original binary.

## Building

To be able to build, first make sure the following programs are installed:
- [Git](https://git-scm.com/install/windows)
- [CMake](https://cmake.org/download/)

Open powershell where you'd like to build the code and clone the repositories (right click on the directory -> open powershell window here). Then run the following commands:

```
git clone https://github.com/itsmattkc/MSVC600.git
git clone https://github.com/Davilex-Reverse-Engineering/london-racer-decomp.git
```

That has to only be done once.

Now to build, run the following commands from the directory `london-racer-decomp` (you can go there with `cd london-racer-decomp` if you just did the following step):

```
cmd
call ..\msvc600\VC98\Bin\VCVARS32.BAT
cmake -B build -DCMAKE_BUILD_TYPE=RelWithDebInfo -G "NMake Makefiles"
cmake --build build
```

Now you can make changes and build again with the `cmake --build build` command.

## Verifying the build

To verify the build, make sure you have Python 3.14 installed first, then run the following command in the `london-racer-decomp` directory first to set up the tools:

```
python3 -m venv venv
.\venv\Scripts\Activate.ps1
pip install reccmp
```

Now you can run the following command to compare the build with the original game executable:

```
reccmp-reccmp --target SPEL
```

In a new powershell window, you'll have to run `.\venv\Scripts\Activate.ps1` once before running this the first time again.

Do keep in ming that `reccmp-reccmp` only knows about functions that have been added to this project already. It doesn't know how many functions are there in total.

## Adding new functions

Adding new functions requires looking at what the original function does in [Ghidra](https://github.com/NationalSecurityAgency/ghidra) and then adding them to this project. Make sure to annotate functions/classes/globals/strings with the offset you see in Ghidra following [these instructions](https://github.com/isledecomp/reccmp/blob/v0.1.6/docs/annotations.md).

## License

This project is licensed under the GPLv3 with the exception of the original directory.
