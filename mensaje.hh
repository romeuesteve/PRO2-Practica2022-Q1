#ifndef MENSAJE
#define MENSAJE

#include <iostream>
using namespace std;

class Mensaje {
	private:
		string mensaje;
		string ida;

	public:
		Mensaje();
		~Mensaje();

		Mensaje(const string& ida, const string& mensaje);
		//string ida();
};

#endif
