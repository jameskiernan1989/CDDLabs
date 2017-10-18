#James Kiernan
#C00125728

EXE=Mutex
CC=g++
CFLAGS= -std=c++11 -pthread
CFILES=Mutex.cpp Semaphore.cpp
HFILES=Semaphore.h

ALL: $(CFILES) $(HFILES)
	$(CC) $(CFLAGS) $(CFILES) -o $(EXE)
DEBUG:
	gdb $(EXE)
CLEAN:
	rm *.o
