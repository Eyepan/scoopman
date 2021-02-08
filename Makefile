SOURCEFILES = src\*.cpp
TARGET = bin\pacman.exe
INCLUDEPATH = include\

all:
	cl /EHsc  /I$(INCLUDEPATH) $(SOURCEFILES) /c /Fo"bin/"
	link bin\*.obj /out:$(TARGET)

clean:
	del bin\* /Q