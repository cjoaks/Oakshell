all: manifest.o main.o 
	gcc -Wall main.o manifest.o -o ../../installer
main.o: main.c 
	gcc -Wall -c main.c -o main.o
manifest.o: installer.rc 
	windres -v installer.rc manifest.o
	