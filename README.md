# scoopman
An PACMAN like wrapper for SCOOP written in C++.

Please note that https://github.com/rami3l/pacaptr written in Rust, is much better, and is honestly well coded than this project.  

That being said this is a much simpler/beginner-oriented project and if you do plan to stick around, please follow these instructions.

# INSTRUCTIONS TO INSTALL

You can install Scoop from following the instructions on  https://scoop.sh

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


# USAGE INSTRUCTIONS

|Flags|Use Case|Scoop Equivalent|
|-----|--------|----------------|
|-(or) -h| Show this page|`scoop help`|
|-S|Install an/multiple apps|`scoop install`|
|-Syu|Update all installed apps and install additional apps if necessary|`scoop update * && scoop install`|
|-Q|List all installed apps|`scoop list`|
|-Qe|Search for installed apps|`scoop which`|
|-Ss|Searches online for apps|`scoop search`|
|-R|Removes/Uninstalls an app|`scoop uninstall`|
|Anything else|Invalid option|`scoop help`|

I can add any and all functionality that is required. Feel free to raise an issue!