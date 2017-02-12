

all: BIGINT

BIGINT: main.o multfunctions.o iodata.o addfunctions.o helper.o definitions.h
	gcc main.o multfunctions.o iodata.o addfunctions.o helper.o definitions.h -o BIGINT

main.o: main.c
	gcc -c main.c

addfunctions.o: addfunctions.c
	gcc -c addfunctions.c  

multfunctions.o: multfunctions.c 
	gcc -c multfunctions.c 

iodata.o: iodata.c
	gcc -c iodata.c 

addfunctions.o: addfunctions.c
	gcc -c addfunctions.c 

helper.o: helper.c
	gcc -c helper.c 

clean:	
	-rm -rf *.o BIGINT


