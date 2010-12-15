CC = g++
CFLAGS = -c -Wall -g -dM
LDFLAGS =
SOURCES = main.cpp Supermarket.cpp Client.cpp Cashier.cpp kbhit.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = dia

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o dia
	rm -rf *.155r.mach
