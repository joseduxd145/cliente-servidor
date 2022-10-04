#gcc flags

CFLAGS = -Wall -g
LIBS = 

#Variables

PROGRAMA = server
CFILES = main.c
OFILES = main.o
HEADERS = main.h files.h

#Cuerpo

PROGRAMA: $(OFILES)
	gcc -o ./build/$(PROGRAMA) $(CFLAGS) $(LIBS) $(OFILES)
	rm *.o
$(OFILES): $(CFILES) $(HEADERS)
	gcc -c $(CFLAGS) $(LIBS) $(CFILES)
Makedir:
	mkdir build

