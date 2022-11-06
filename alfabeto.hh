#ifndef ALFABETO
#define ALFABETO

#include <iostream>
#include <map>
using namespace std;

class Alfabeto {
	private:
		map<char, char> charmap;
		bool especial = true;
		string alfabeto;
		int mensajes = 0;

	public:
		Alfabeto();
		~Alfabeto();

		Alfabeto(const string& alfabeto);
		void listar_alfabeto();
		void sumar_mensajes(const int& n);
		bool sin_mensajes();
		bool es_especial();
		char encontrar_pos_char(const char& c);
		char encontrar_char_pos(const char& c);
		char size();
};

#endif
