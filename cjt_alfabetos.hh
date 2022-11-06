#ifndef CJT_ALFABETOS
#define CJT_ALFABETOS

#include "alfabeto.hh"
#include <iostream>
#include <map>
using namespace std;

class Cjt_alfabetos {
	private:
		int A = 0;
		map<string, Alfabeto> alfabetos;

		//Sustitucion
		char codificar_char(Alfabeto alfabeto, const char& a, const char& b);
		char descodificar_char(Alfabeto alfabeto, const char& c, const char& b);

	public:
		Cjt_alfabetos();
		~Cjt_alfabetos();

		void nuevo_alfabeto(const string& ida);
		void leer_alfabetos(const int& n);
		void borra_alfabeto(const string& ida);
		void listar_alfabetos();
		void sumar_mensajes(const string& ida, const int& n);
		bool existe_alfabeto(const string& ida);

		//Sustitucion
		void codificar_sustitucion(const string& ida, const string& t, const string& c);
		void descodificar_sustitucion(const string& ida, const string& e, const string& c);


};
#endif
