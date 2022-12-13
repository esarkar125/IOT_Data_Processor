######################################################################
# Filename: Makefile                                                 #
# Author: ezazsarkar                                                 #
######################################################################


SRCDIR = ../src
INCLUDEDIR = ../include
OBJDIR = ../obj
BINDIR = ../bin
CFLAGS = -c -g -Wall -I${INCLUDEDIR}


all:
	gcc ${CFLAGS}  ${SRCDIR}/main.c -o ${OBJDIR}/main.o
	gcc ${CFLAGS}  ${SRCDIR}/utility.c -o ${OBJDIR}/utility.o
	gcc ${CFLAGS}  ${SRCDIR}/menu.c -o ${OBJDIR}/menu.o
	gcc ${CFLAGS}  ${SRCDIR}/average.c -o ${OBJDIR}/average.o
	gcc ${OBJDIR}/main.o ${OBJDIR}/utility.o ${OBJDIR}/menu.o ${OBJDIR}/average.o -o ${BINDIR}/IOTDataProcessor.bin


clean:

	rm ${OBJDIR}/main.o ${OBJDIR}/utility.o ${OBJDIR}/menu.o ${OBJDIR}/average.o ${BINDIR}/IOTDataProcessor.bin


######################################################################
#                     End of Makefile                                #
######################################################################
