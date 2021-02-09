SOURCEFILES = src\*.cpp
TARGET = bin\pacman.exe
INCLUDEPATH = include

all:
	if not exist "bin" mkdir bin
	cl /EHsc /I$(INCLUDEPATH) $(SOURCEFILES) /c /Fo"bin/"
	link bin\*.obj /out:$(TARGET)
	copy bin\pacman.exe %userprofile%\scoop\shims\pacman.exe

clean:
	del bin\* /Q
