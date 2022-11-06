#ifndef CJT_MENSAJES
#define CJT_MENSAJES

#include <iostream>
#include <map>
using namespace std;

typedef pair<string, string> mensaje;

class Cjt_mensajes {
	private:
		int M = 0;
		map<string, mensaje> mensajes;

	public:
		Cjt_mensajes();
		~Cjt_mensajes();

		void nuevo_mensaje(const string& idm, const string& ida);
		void leer_mensajes(const int& n);
		void borra_mensaje(const string& idm);
		void listar_mensajes();
		string get_mensaje(const string& idm);
		string get_ida(const string& idm);
		bool existe(const string& idm);

};

#endif
