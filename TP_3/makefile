CC=gcc
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=main.c toolbox.c ex1/tp3ex1.c ex2/tp3ex2.c ex3/tp3ex3.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=main
.PHONY: clean
all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@
.c.o:
	$(CC) $(CFLAGS) $< -o $@
clean:
	rm -f $(OBJECTS) $(EXECUTABLE)