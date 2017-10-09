#James Kiernan
#C00125728

EXE=Signal.exe
CC=g++
CFLAGS= -std=c++11 -pthread
CFILES=Signal.cpp Semaphore.cpp
HFILES=Semaphore.h

ALL: $(CFILES) $(HFILES)
	$(CC) $(CFLAGS) $(CFILES) -o $(EXE)
DEBUG:
	gdb $(EXE)
CLEAN:
	rm *.o
