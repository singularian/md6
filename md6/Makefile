CC=gcc
CFLAGS=-O2 -I/usr/local/include
EXECUTABLE=testmd6
# LIBS=-levent -L/usr/local/lib
PKGCONF=pkg-config

OBJ=testMD6.o md6_nist.o md6_mode.o md6_compress.o
DEPS=md6.h md6_nist.h
PREFIX=/usr/local

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ) $(LIBS) 

static: $(EXECUTABLE).static

$(EXECUTABLE).static: $(OBJ)
	$(CC) -static -static-libgcc $(CFLAGS) -o $@ $(OBJ) $(LIBS) 

%.o: %.c $(DEPS)
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	rm -f $(EXECUTABLE) $(EXECUTABLE).static *.o
