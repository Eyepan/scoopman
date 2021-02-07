SOURCEFILES = src\*.cpp
TARGET = bin\pacman.exe
INCLUDEPATH = include\

all:
	cl /EHsc  /I$(INCLUDEPATH) $(SOURCEFILES) /c /Fo"bin/"
	link bin\*.obj /out:$(TARGET)

clean:
	Remove-Item bin -Recurse
	New-Item -ItemType directory bin