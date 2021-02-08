# scoopman
An PACMAN like wrapper for SCOOP written in C++.

Please note that https://github.com/Eyepan/scoopyman is a much much better alternative to this one.  
And so is https://github.com/rami3l/pacaptr which is written in Rust and is honestly well coded than me. That being said if you do plan to stick around, please follow these instructions.

# INSTRUCTIONS TO USE

`git clone https://github.com/Eyepan/scoopman.git`

If you have C++ BuildTools/Visual Studio C++ installed:
1. Create a Developer CMD instance and `cd` to the directory where you cloned scoopman
2. `nmake`  
(Nmake automatically copies the file for you, so you don't have to do anything)

If you have gcc/mingw installed:
1. cd to the folder you have cloned scoopman
2. `mkdir bin`
3. `g++ src\*.cpp -o bin\pacman.exe`
4. Copy the file `bin\pacman.exe` to `~\scoop\shims`

If you don't have a C++ compiler you can download the latest release from https://github.com/Eyepan/scoopman/releases
1. Copy the file `pacman.exe` to `~\scoop\shims`

I can add any and all functionality that is required.
You can also install Scoop from https://scoop.sh
