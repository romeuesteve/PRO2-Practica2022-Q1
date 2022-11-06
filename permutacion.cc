#include <iostream>
#include "permutacion.hh"
using namespace std;

Permutacion::Permutacion() {}
Permutacion::~Permutacion() {}

BinTree<char> Permutacion::crear_arbol(const string& s) {
	if (s.size() == 0) return BinTree<char>();
	int n = s.size();
	int m;
	if (n%2 == 1) m = n/2;
	else m = n/2 - 1;
	BinTree<char> left, right;
	string sleft, sright;
	for (int i = 0; i < m; ++i) sleft.push_back(s[i]);
	for (int i = m + 1; i < n; ++i) sright.push_back(s[i]);

	left = crear_arbol(sleft);
	right = crear_arbol(sright);

	BinTree<char> aux_l, aux_r;
	if (!left.empty()) aux_l = BinTree<char>(right.value(), left.left(), left.right());
	if (!right.empty() && !left.empty()) aux_r = BinTree<char>(left.value(), right.left(), right.right());
	else if (!right.empty()) aux_r = right;

	return BinTree<char>(s[m], aux_l, aux_r);
}

string Permutacion::leer_arbol(const BinTree<char> t) {
	string s, sr;
	if (!t.left().empty()) {
		s = leer_arbol(t.left());
	}
	s.push_back(t.value());
	if (!t.right().empty())  {
		sr = leer_arbol(t.right());
	}
	for (int i = 0; i < sr.size(); ++i) s.push_back(sr[i]);
	return s;
}

void Permutacion::codificar_permutacion(string& s, const int& b) {
	const int size = s.size();
	const int n = size/b + bool(size%b);

	if (n <= 1) {
		const BinTree<char> t = crear_arbol(s);
		cout << leer_arbol(t) << endl;
	}
	else {
		vector<string> v(n);
		int j = 0;
		for (int i = 0; i < n; ++i) {
			v[i].push_back(s[j]);
			j++;
			while (j < size && j%b != 0) v[i].push_back(s[j]), j++;
		}
		vector<BinTree<char>> t(n);
		for (int i = 0; i < n; ++i) t[i] = crear_arbol(v[i]), v[i] = leer_arbol(t[i]);
		for (int i = 0; i < size; ++i) s[i] = v[i/b][i%b];
		cout << s << endl;
	}
}
/*
char Permutacion::codificar_char(Alfabeto alfabeto, const char& a, const char& b) {
	if (alfabeto.es_especial()) {
		return (a + b - 2*alfabeto.encontrar_pos_char(0))%alfabeto.size() + alfabeto.encontrar_pos_char(0);
	}
	else {
		return alfabeto.encontrar_char_pos((alfabeto.encontrar_pos_char(a) + alfabeto.encontrar_pos_char(b))%alfabeto.size());
	}
}

char Permutacion::descodificar_char(Alfabeto alfabeto, const char& c, const char& b) {
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

void Permutacion::codificar_sustitucion(const Alfabeto& alfabeto, const string& t, const string& c) {
	int n = t.size();
	int n_c = c.size();
	string e = t;
	for (int i = 0; i < n; ++i) {
		e[i] = codificar_char(alfabeto, t[i], c[i%n_c]);
	}
	cout << e << endl;
}

void Permutacion::descodificar_sustitucion(const Alfabeto& alfabeto, const string& e, const string& c) {
	int n = e.size();
	int n_c = c.size();
	string t = e;
	for (int i = 0; i < n; ++i) {
		t[i] = descodificar_char(alfabeto, e[i], c[i%n_c]);
	}
	cout << t << endl;
}*/
