#include "lista.h"
#include "diccionario.h"
#include <iostream>
#include <string>
using namespace std;


// Clase Puntuacion. Sirve para representar la puntuacion final  (nota)
// obtenida por un alumno.
class Puntuacion {
  public:
    string alumno;
    int nota;	
	Puntuacion(const string& nombre, int puntuacion): alumno(nombre), nota(puntuacion) {}
};


void califica(const Lista<string>& bien, const Lista<string>& mal, Lista<Puntuacion>& listado) {
	Diccionario<string, int> dicc;
	Lista<string>::ConstIterator itLista = bien.cbegin();
	Diccionario<string, int>::Iterator itDicc = dicc.begin();
	while (itLista != bien.cend()) {
		itDicc = dicc.busca(itLista.elem());
		if (itDicc != dicc.end())
			itDicc.setVal(itDicc.valor() + 1);
		else
			dicc.inserta(itLista.elem(), 1);
		itLista.next();
	}
	itLista = mal.cbegin();
	while (itLista != mal.cend()) {
		itDicc = dicc.busca(itLista.elem());
		if (itDicc != dicc.end())
			itDicc.setVal(itDicc.valor() - 1);
		else
			dicc.inserta(itLista.elem(), -1);
		itLista.next();
	}
	Diccionario<string, int>::ConstIterator cItDicc = dicc.cbegin();
	while (cItDicc != dicc.cend()) {
		if (cItDicc.valor() != 0)
			listado.pon_final(Puntuacion(cItDicc.clave(), cItDicc.valor()));
		cItDicc.next();
	}
}


void imprimePuntuaciones(Lista<Puntuacion>& listado) {
  Lista<Puntuacion>::ConstIterator i = listado.cbegin();
  Lista<Puntuacion>::ConstIterator e = listado.cend();
  while (i != e) {
	  cout << "[" << i.elem().alumno << ":" << i.elem().nota << "]";
      i.next();	  
  }  
  cout << endl;
}

void leeResultados(Lista<string>& bien, Lista<string>& mal) {
	string nombre;
	do {
		cin >> nombre;
		if (nombre != "#") {
			string resultado;
			cin >> resultado;
			if (resultado == "+")
				bien.pon_final(nombre);
			else
				mal.pon_final(nombre);
		}
	} while (nombre != "#");
}

int main() {
  string comienzo;
  while (cin >> comienzo) {
	 Lista<string> bien;
	 Lista<string> mal;
	 Lista<Puntuacion> listado;
	 leeResultados(bien, mal);
	 califica(bien, mal,listado);
	 imprimePuntuaciones(listado);
  }
  return 0;   
}