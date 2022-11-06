#ifndef PERMUTACION
#define PERMUTACION

#include <iostream>
#include <vector>
#include "BinTree.hh"
#include "alfabeto.hh"
using namespace std;

class Permutacion {
	private:
		BinTree<char> crear_arbol(const string& s);
		string leer_arbol(const BinTree<char> t);
	public:
		Permutacion();
		~Permutacion();

		void codificar_permutacion(string& s, const int& b);
};

#endif
