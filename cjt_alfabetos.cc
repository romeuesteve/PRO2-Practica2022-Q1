#include "cjt_alfabetos.hh"
#include <iostream>
using namespace std;

Cjt_alfabetos::Cjt_alfabetos() {}
Cjt_alfabetos::~Cjt_alfabetos() {}

void Cjt_alfabetos::nuevo_alfabeto(const string& ida) {
	string s;/* = string(27, ' ');
	for (int i = 0; i < 27; ++i) cin >> s[i];*/
	getline(cin, s);
	alfabetos[ida] = s;
	++A;
}
void Cjt_alfabetos::leer_alfabetos(const int& n) {
	A = n;
	for (int i = 0; i < n; ++i) {
		string ida;
		cin >> ida;
		nuevo_alfabeto(ida);
		cout << "alfabeto " << ida << " leido" << endl;
	}
}
void Cjt_alfabetos::borra_alfabeto(const string& ida) {
	map<string, string>::iterator it = alfabetos.find(ida);
	if (it != alfabetos.end()) {
		alfabetos.erase(it);
		A--;
	}
	else cout << "error! El alfabeto no existe" << endl;
}
void Cjt_alfabetos::listar_alfabetos() {
	for (map<string, string>::const_iterator it = alfabetos.begin(); it != alfabetos.end(); ++it) {
		cout << it->first << ' ' << it->second << endl;
	}
}
