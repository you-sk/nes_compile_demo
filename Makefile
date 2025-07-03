# --- Variables ---
CC = cl65
# Add -m main.map to generate a map file
LDFLAGS = -t nes -C nes.cfg -m main.map

# --- Rules ---
.PHONY: all clean

all: main.nes

# Link the final NES ROM
main.nes: main.o
	$(CC) $(LDFLAGS) -o main.nes main.o

# Compile your C code into an object file
main.o: main.c
	$(CC) -t nes -Os -c main.c -o main.o

# Clean up all generated files
clean:
	rm -f main.o main.nes *.list *.map