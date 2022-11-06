OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

all: program.exe

program.exe: program.o cjt_alfabetos.o permutacion.o cjt_mensajes.o alfabeto.o
	g++ -o program.exe *.o

program.o: program.cc
	g++ -c program.cc $(OPCIONS)

cjt_alfabetos.o: cjt_alfabetos.cc
	g++ -c cjt_alfabetos.cc $(OPCIONS)

cjt_mensajes.o: cjt_mensajes.cc
	g++ -c cjt_mensajes.cc $(OPCIONS)

permutacion.o: permutacion.cc
	g++ -c permutacion.cc $(OPCIONS)

alfabeto.o: alfabeto.cc
	g++ -c alfabeto.cc $(OPCIONS)

clean:
	rm *.o *.exe
