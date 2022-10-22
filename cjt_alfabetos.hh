#ifndef CJT_ALFABETOS
#define CJT_ALFABETOS

#include <iostream>
#include <map>
using namespace std;

class Cjt_alfabetos {
	private:
		int A = 0;
		map<string, string> alfabetos;

	public:
		Cjt_alfabetos();
		~Cjt_alfabetos();

		void nuevo_alfabeto(const string& ida);
		void leer_alfabetos(const int& n);
		void borra_alfabeto(const string& ida);
		void listar_alfabetos();

};

#endif
