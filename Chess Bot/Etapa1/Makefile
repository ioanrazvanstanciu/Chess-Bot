ENGINE = Ocult_Records
SOURCES = ENGINE.cpp FCT.cpp
CFLAGS = -Wall -std=c++11
CC = g++

build:
	$(CC) $(CFLAGS) $(SOURCES) -o $(ENGINE)
run:
	./$(ENGINE)
noDebug:
	xboard -fcp "./$(ENGINE)"
debug:
	xboard -fcp "./$(ENGINE)" -debug
clean:
	rm -f $(ENGINE)
	rm -f xboard.debug
