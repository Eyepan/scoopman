SOURCEFILES = src\*.cpp
TARGET = bin\pacman.exe

all:
	mkdir bin
	cl /EHsc $(SOURCEFILES) /c /Fo"bin/"
	link bin\*.obj /out:$(TARGET)
	copy bin\pacman.exe %userprofile%\scoop\shims\pacman.exe

clean:
	del bin\* /Q
