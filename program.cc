#include <iostream>
#include "cjt_mensajes.hh"
#include "cjt_alfabetos.hh"
#include "permutacion.hh"
//#include ""
using namespace std;

int main() {
	//lectura del conjunto inicial de alfabetos
	Cjt_alfabetos alfabetos;
	int A; //numero inicial de alfabetos
	cin >> A;
	alfabetos.leer_alfabetos(A);
	//lectura del conjunto inicial de mensajes
	int M; //numero inicial de mensajes
	cin >> M;
	Cjt_mensajes mensajes;
	//mensajes.leer_mensajes(M);
	for (int i = 0; i < M; ++i) {
		string idm, ida;
		cin >> idm >> ida;
		mensajes.nuevo_mensaje(idm, ida);
		alfabetos.sumar_mensajes(ida, 1);
	}
	//lee comando
	string comando;
	cin >> comando;
	while (comando != "fin") {
		cout << '#' << comando << endl;
		//procesa comando
		if (comando == "nuevo_mensaje" || comando == "nm") {
			string idm, ida;
			cin >> idm >> ida;
			alfabetos.sumar_mensajes(ida, 1);
			mensajes.nuevo_mensaje(idm, ida);
		}
		else if (comando == "nuevo_alfabeto" || comando == "na") {
			string ida;
			cin >> ida;
			alfabetos.nuevo_alfabeto(ida);
		}
		else if (comando == "borra_mensaje" || comando == "bm") {
			string idm;
			cin >> idm;
			alfabetos.sumar_mensajes(mensajes.get_ida(idm), -1);
			mensajes.borra_mensaje(idm);
		}
		else if (comando == "borra_alfabeto" || comando == "ba") {
			string ida;
			cin >> ida;
			alfabetos.borra_alfabeto(ida);
		}
		else if (comando == "listar_mensajes" || comando == "lm") {
			mensajes.listar_mensajes();
		}
		else if (comando == "listar_alfabetos" || comando == "la") {
			alfabetos.listar_alfabetos();
		}
		else if (comando == "codificar_sustitucion_guardado" || comando == "csg") {
			string idm, cl;
			cin >> idm;
			cin.ignore();
			getline(cin, cl);
			if (mensajes.existe(idm)) {
				string s = mensajes.get_mensaje(idm);
				string ida = mensajes.get_ida(idm);
				alfabetos.codificar_sustitucion(ida, s, cl);
			}
			else cout << "Error: El id del mensaje no existe" << endl;

		}
		else if (comando == "codificar_sustitucion" || comando == "cs") {
			string ida, cl;
			cin >> ida;
			cin.ignore();
			getline(cin, cl);
			if (alfabetos.existe_alfabeto(ida)) {
				string s;
				getline(cin, s);
				alfabetos.codificar_sustitucion(ida, s, cl);
			}
			else cout << "Error: El id del alfabeto no existe" << endl;
		}
		else if (comando == "decodificar_sustitucion" || comando == "ds") {
			string ida, cl;
			cin >> ida;
			cin.ignore();
			getline(cin, cl);
			if (alfabetos.existe_alfabeto(ida)) {
				string s;
				getline(cin, s);
				alfabetos.descodificar_sustitucion(ida, s, cl);
			}
			else cout << "Error: El id del alfabeto no existe" << endl;
		}
		else if (comando == "codificar_permutacion_guardado" || comando == "cpg") {
			string idm;
			int b;
			cin >> idm >> b;
			if (mensajes.existe(idm)) {
				idm = mensajes.get_mensaje(idm);
				Permutacion p;
				p.codificar_permutacion(idm, b);
			}
			else cout << "Error: El id del mensaje no existe" << endl;

		}
		else if (comando == "codificar_permutacion" || comando == "cp" || comando == "decodificar_permutacion" || comando == "dp") {
			string s;
			cin.ignore(256, '\n');
			getline(cin, s);
			int b;
			cin >> b;
			Permutacion p;
			p.codificar_permutacion(s, b);
		}
		/* A priori decodificar hace el mismo proceso que codificar, asi que lo pongo en la misma funcion
		 * else if (comando == "decodificar_permutacion" || comando == "dp") {
			string ida;
			int b;
			cin >> ida >> b;
		}
		*/
		//lee comando
		cin >> comando;
	}
}







