#
# When building a package or installing otherwise in the system, make
# sure that the variable PREFIX is defined, e.g. make PREFIX=/usr/local
#
PROGNAME=view1090

ifdef PREFIX
BINDIR=$(PREFIX)/bin
SHAREDIR=$(PREFIX)/share/$(PROGNAME)
EXTRACFLAGS=-DHTMLPATH=\"$(SHAREDIR)\"
endif

CFLAGS=-O2 -g -Wall -W
LIBS=-lm -lSDL2 -lSDL2_ttf -lSDL2_gfx 
CC=gcc

all: view1090

%.o: %.c
	$(CC) $(CFLAGS) $(EXTRACFLAGS) -c $<

view1090: view1090.o anet.o interactive.o mode_ac.o mode_s.o net_io.o planeObj.o input.o draw.o font.o init.o mapdata.o status.o list.o parula.o monokai.o allstates.o
	$(CC) -g -o view1090 view1090.o anet.o interactive.o mode_ac.o mode_s.o net_io.o planeObj.o input.o draw.o font.o init.o mapdata.o status.o list.o parula.o monokai.o allstates.o $(LIBS) $(LDFLAGS)

clean:
	rm -f *.o view1090
