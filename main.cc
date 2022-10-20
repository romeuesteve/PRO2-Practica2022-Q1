#include <iostream>
using namespace std;

int main() {
	//lectura del conjunto inicial de mensajes;
	
	//lectura del conjunto inicial de alfabetos;
	
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
		}
		else if (comando == "borra_mensaje" || comando == "bm") {
			string idm;
			cin >> idm;
		}
		else if (comando == "borra_alfabeto" || comando == "ba") {
			string ida;
			cin >> ida;
			
		}
		else if (comando == "listar_mensajes" || comando == "lm") {
			
		}
		else if (comando == "listar_alfabetos" || comando == "la") {
			
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
			string ida;
			int b;
			cin >> ida >> b;
		}
		else if (comando == "codificar_permutacion" || comando == "cp") {
			string ida;
			int b;
			cin >> ida >> b;
		}
		else if (comando == "decodificar_permutacion" || comando == "dp") {
			string ida;
			int b;
			cin >> ida >> b;
		}

		//lee comando
		cin >> comando
	}
}






