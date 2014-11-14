INCLUDE_DIRS = 
LIB_DIRS = 
CC=gcc

CDEFS=
CFLAGS= -O0 -g $(INCLUDE_DIRS) $(CDEFS)
LIBS=

HFILES=  brighten.h
CFILES= brighten.c luminosityGray.c PSFBlur.c pipeline.c pipeTest.c

SRCS= ${HFILES} ${CFILES}
OBJS= ${CFILES:.c=.o}

all:	pipeTest brightc.asm

clean:
	-rm -f *.o *.d brighter*.ppm brightc.asm gray*.ppm
	-rm -f pipeline

distclean:
	-rm -f *.o *.d

imagetest:	${OBJS}
	$(CC) $(LDFLAGS) $(CFLAGS) -o $@ $(OBJS) $(LIBS)
	
pipeTest:	${OBJS}
	$(CC) $(LDFLAGS) $(CFLAGS) -o $@ $(OBJS) $(LIBS)

brightc.asm: brightc.c
	$(CC) -O0 -S $< -o $@

depend:

.c.o:
	$(CC) $(CFLAGS) -c $<
