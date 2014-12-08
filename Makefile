INCLUDE_DIRS = 
LIB_DIRS = 
CC=gcc

CDEFS=
CFLAGS= -O0 -g $(INCLUDE_DIRS) $(CDEFS)
LIBS=

HFILES=  eagleEye.h
CFILES1= read_write.c luminosityGray.c PSFBlur.c  pipeline.c eagleEyeApp.c
CFILES2= read_write.c luminosityGray.c PSFBlur.c  pipeline.c pipeTest.c blurTest.c grayTest.c readLatencyTest.c testDriver.c transformLatencyTest.c  readWriteTest.c invalidLocation.c invalidType.c

SRCS= ${HFILES} ${CFILES}
OBJS1= ${CFILES1:.c=.o}
OBJS2= ${CFILES2:.c=.o}

all:	EagleEye

clean:
	-rm -f *.o *.d *Test*.ppm  new*.ppm
	-rm -f testDriver EagleEye

imgclean:
	-rm -f *Test*.ppm

EagleEye:	${OBJS1}
	$(CC) $(LDFLAGS) $(CFLAGS) -o $@ $(OBJS1) $(LIBS)
	
testDriver:	${OBJS2} 
	$(CC) $(LDFLAGS) $(CFLAGS) -o $@ $(OBJS2) $(LIBS)
	


depend:

.c.o:
	$(CC) $(CFLAGS) -c $<
