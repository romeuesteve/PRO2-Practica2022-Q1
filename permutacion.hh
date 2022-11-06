#ifndef PERMUTACION
#define PERMUTACION

#include <iostream>
#include <vector>
#include "BinTree.hh"
#include "alfabeto.hh"
using namespace std;

class Permutacion {
	private:
		//Permutacion
		BinTree<char> crear_arbol(const string& s);
		string leer_arbol(const BinTree<char> t);

		//Sustitucion
		//char codificar_char(Alfabeto alfabeto, const char& a, const char& b);
		//char descodificar_char(Alfabeto alfabeto, const char& c, const char& b);
	public:
		Permutacion();
		~Permutacion();

		//Permutacion
		void codificar_permutacion(string& s, const int& b);

		//Sustitucion
		//void codificar_sustitucion(const Alfabeto& alfabeto, const string& t, const string& c);
		//void descodificar_sustitucion(const Alfabeto& alfabeto, const string& e, const string& c);
};

#endif
