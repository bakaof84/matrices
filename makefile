all: MatCreuse

MatCreuse: Main.o MatCreuse.o
		 g++ -o MatCreuse MatCreuse.o Main.o

Main.o: Main.cpp
		g++ -c Main.cpp

MatCreuse.o: MatCreuse.cpp MatCreuse.h
			g++ -c MatCreuse.cpp

clean:
		rm *.o

mrproper: clean
		rm MatCreuse
