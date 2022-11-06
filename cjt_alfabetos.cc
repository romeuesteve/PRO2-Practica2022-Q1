#include "cjt_alfabetos.hh"
#include <iostream>
using namespace std;

Cjt_alfabetos::Cjt_alfabetos() {}
Cjt_alfabetos::~Cjt_alfabetos() {}


void Cjt_alfabetos::nuevo_alfabeto(const string& ida) {
	cin.ignore(256, '\n');
	string s;
	getline(cin, s);
	alfabetos[ida] = Alfabeto(s);
	++A;
}
void Cjt_alfabetos::leer_alfabetos(const int& n) {
	A = n;
	for (int i = 0; i < n; ++i) {
		string ida;
		cin >> ida;
		nuevo_alfabeto(ida);
	}
}
void Cjt_alfabetos::borra_alfabeto(const string& ida) {
	map<string, Alfabeto>::iterator it = alfabetos.find(ida);
	if (it != alfabetos.end()) {
		if (it->second.sin_mensajes()) {
			alfabetos.erase(it);
			A--;
		}
		else cout << "error! Hay mensajes con este alfabeto" << endl;
	}
	else cout << "error! El alfabeto no existe" << endl;
}
void Cjt_alfabetos::listar_alfabetos() {
	int i = 1;
	for (map<string, Alfabeto>::iterator it = alfabetos.begin(); it != alfabetos.end(); ++it) {
		cout << i << ". " << it->first << endl;
		it->second.listar_alfabeto();
		i++;
	}
}

void Cjt_alfabetos::sumar_mensajes(const string& ida, const int& n) {
	alfabetos[ida].sumar_mensajes(n);
}

char Cjt_alfabetos::codificar_char(Alfabeto alfabeto, const char& a, const char& b) {
	if (alfabeto.es_especial()) {
		return (a + b - 2*alfabeto.encontrar_pos_char(0))%alfabeto.size() + alfabeto.encontrar_pos_char(0);
	}
	else {
		return alfabeto.encontrar_char_pos((alfabeto.encontrar_pos_char(a) + alfabeto.encontrar_pos_char(b))%alfabeto.size());
	}
}

char Cjt_alfabetos::descodificar_char(Alfabeto alfabeto, const char& c, const char& b) {
	if (alfabeto.es_especial()) {
		char a = c- b;
		if (a < 0) a += alfabeto.size();
		return a + alfabeto.encontrar_pos_char(0);
	}
	else {
		char a = alfabeto.encontrar_pos_char(c) - alfabeto.encontrar_pos_char(b);
		if (a < 0) a += alfabeto.size();
		return alfabeto.encontrar_char_pos(a);
	}
}

void Cjt_alfabetos::codificar_sustitucion(const string& ida, const string& t, const string& c) {
	Alfabeto a = alfabetos[ida];
	int n = t.size();
	int n_c = c.size();
	string e = t;
	for (int i = 0; i < n; ++i) {
		e[i] = codificar_char(a, t[i], c[i%n_c]);
	}
	cout << e << endl;
}

void Cjt_alfabetos::descodificar_sustitucion(const string& ida, const string& e, const string& c) {
	Alfabeto a = alfabetos[ida];
	int n = e.size();
	int n_c = c.size();
	string t = e;
	for (int i = 0; i < n; ++i) {
		t[i] = descodificar_char(a, e[i], c[i%n_c]);
	}
	cout << t << endl;
}

bool Cjt_alfabetos::existe_alfabeto(const string& ida) {
	return alfabetos.find(ida) != alfabetos.end();
}
