#include "cjt_mensajes.hh"
#include <iostream>
using namespace std;

Cjt_mensajes::Cjt_mensajes() {}
Cjt_mensajes::~Cjt_mensajes() {}


void Cjt_mensajes::nuevo_mensaje(const string& idm, const string& ida) {
	cin.ignore(256, '\n');
	string s;
	getline(cin, s);
	//cin >> s;
	mensajes[idm] = mensaje{s, ida};
	M++;
}
void Cjt_mensajes::leer_mensajes(const int& n) {
	for (int i = 0; i < n; ++i) {
		string idm, ida;
		cin >> idm >> ida;
		nuevo_mensaje(idm, ida);
	}
}
void Cjt_mensajes::borra_mensaje(const string& idm) {
	map<string, mensaje>::iterator it = mensajes.find(idm);
	if (it != mensajes.end()) {
		mensajes.erase(it);
		M--;
	}
	else cout << "error! El mensaje no existe" << endl;
}
void Cjt_mensajes::listar_mensajes() {
	int i = 1;
	for (map<string, mensaje>::const_iterator it = mensajes.begin(); it != mensajes.end(); ++it) {
		cout << i << ". " << it->first << endl << it->second.second << endl << '"'<< it->second.first << '"'<< endl;
		i++;
	}
}
string Cjt_mensajes::get_mensaje(const string& idm) {
	return mensajes[idm].first;
}
string Cjt_mensajes::get_ida(const string& idm) {
	return mensajes[idm].second;
}
bool Cjt_mensajes::existe(const string& idm) {
	return mensajes.find(idm) != mensajes.end();
}
