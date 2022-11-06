#include "alfabeto.hh"
#include <iostream>
using namespace std;

Alfabeto::Alfabeto() {}
Alfabeto::~Alfabeto() {}

Alfabeto::Alfabeto(const string& s) {
	alfabeto = s;
	int i = 1;
	int n = alfabeto.size();
	while (especial && i < n) {
		if (s[i] != s[i-1] + 1) especial = false;
		i++;
	}
	if (especial) charmap[0] = s[0];
	else for (int i = 0; i < n; ++i) charmap[s[i]] = i;

}
void Alfabeto::listar_alfabeto() {
	if (especial) {
		cout << "especial [" << alfabeto[0] << ".." << alfabeto[alfabeto.size() - 1] << "] ";
	}
	else {
		cout << "normal \"" << alfabeto << "\" ";
	}
	cout << mensajes << " mensajes" << endl;
}
void Alfabeto::sumar_mensajes(const int& n) {
	mensajes += n;
}
bool Alfabeto::sin_mensajes() {
	return mensajes == 0;
}
bool Alfabeto::es_especial() {
	return especial;
}
char Alfabeto::encontrar_pos_char(const char& c) {
	return charmap[c];
	//char i = 0;
	//while (alfabeto[i] != c) ++i;
	//return i;
}
char Alfabeto::encontrar_char_pos(const char& c) {
	return alfabeto[c];
}
char Alfabeto::size() {
	return alfabeto.size();
}
