SOURCEFILES = src\*.cpp
TARGET = bin\paman.exe
INCLUDEPATH = include\

all:
	New-Item -ItemType directory bin
	cl /EHsc  /I$(INCLUDEPATH) $(SOURCEFILES) /c /Fo"bin/"
	link bin\*.obj /out:$(TARGET)

clean:
	Remove-Item bin -Recurse
	New-Item -ItemType directory bin

move:
	Copy-Item $(TARGET) $env:SCOOP\shims\pacman.exe