SOURCEFILES = src\*.cpp
TARGET = bin\pacman.exe

all:
	cl /EHsc $(SOURCEFILES) /c /Fo"bin/"
	link bin\*.obj /out:$(TARGET)

clean:
	del bin\* /Q