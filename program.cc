#include <iostream>
//#include "cjt_mensajes.hh"
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
	//Cjt_mensajes mensajes;
	//mensajes.read();
	//lee comando
	string comando;
	cin >> comando;
	while (comando != "fin") {
		//procesa comando
		if (comando == "nuevo_mensaje" || comando == "nm") {
			string idm, ida;
			cin >> idm >> ida;
		}
		else if (comando == "nuevo_alfabeto" || comando == "na") {
			string ida;
			cin >> ida;
			alfabetos.nuevo_alfabeto(ida);
		}
		else if (comando == "borra_mensaje" || comando == "bm") {
			string idm;
			cin >> idm;
		}
		else if (comando == "borra_alfabeto" || comando == "ba") {
			string ida;
			cin >> ida;
			alfabetos.borra_alfabeto(ida);
		}
		else if (comando == "listar_mensajes" || comando == "lm") {
		}
		else if (comando == "listar_alfabetos" || comando == "la") {
			alfabetos.listar_alfabetos();
		}
		else if (comando == "codificar_sustitucion_guardado" || comando == "csg") {
			string ida, cl;
			cin >> ida >> cl;
		}
		else if (comando == "codificar_sustitucion" || comando == "cs") {
			string ida, cl;
			cin >> ida >> cl;
			//if ida not exists
			cout << "error: El alfabeto no existe" << endl;
		}
		else if (comando == "decodificar_sustitucion" || comando == "ds") {
			string ida, cl;
			cin >> ida >> cl;
		}
		else if (comando == "codificar_permutacion_guardado" || comando == "cpg") {
			string idm;
			int b;
			cin >> idm >> b;

			/*
			 * if (cjt_mensajes.exists(idm)) {
			 * 		string& s = cjt_mensajes.get(idm);
			 * 		Permutacion p;
			 * 		p.codificar(s, b);
			 * }
			 * else cout << "Error: id del mensaje no encontrado" << endl;

			*/

		}
		else if (comando == "codificar_permutacion" || comando == "cp" || comando == "decodificar_permutacion" || comando == "dp") {
			string s;
			//getline(cin, s);
			cin >> s;
			int b;
			cin >> b;
			Permutacion p;
			p.codificar(s, b);
		}
		/* Decodificar hace el mismo proceso que codificar
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







