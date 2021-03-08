/*
NOMBRE Y APELLIDOS:

*/


#include "Arbin.h"
#include <iostream>
#include <string>
using namespace std;



bool esHoja(Arbin<int> a) {
	return !a.esVacio() && a.hijoIz().esVacio() && a.hijoDer().esVacio();
}

/* Puedes implementar aquí las funciones auxiliares que consideres
   oportuno */
void mejor_renta(Arbin<int> a, int renta, bool& es_rentable, int& renta_maxima) {
	if (!a.esVacio() && renta + a.raiz() > 0) {
		if (esHoja(a)) {
			if (renta + a.raiz() > 0) es_rentable = true;
			if (renta + a.raiz() > renta_maxima) renta_maxima = renta + a.raiz();
		}
		else {
			renta += a.raiz();
			if (!a.hijoIz().esVacio() && renta + a.hijoIz().raiz() > 0) mejor_renta(a.hijoIz(), renta, es_rentable, renta_maxima);
			if (!a.hijoDer().esVacio() && renta + a.hijoDer().raiz() > 0) mejor_renta(a.hijoDer(), renta, es_rentable, renta_maxima);
		}
	}
}

/*
COMPLEJIDAD: Determina justificadamente la complejidad del procedimiento 

*/
void mejor_renta(Arbin<int> a, bool& es_rentable, int& renta_maxima) {
	es_rentable = false;
	renta_maxima = 0;
	mejor_renta(a, 0, es_rentable, renta_maxima);
}


Arbin<int> lee_arbol(istream& in) {
	char c;
	in >> c;
	switch (c) {
	case '#': return Arbin<int>();
	case '[': {
		int raiz;
		in >> raiz;
  		in >> c;
		return Arbin<int>(raiz);
	}
	case '(': {
		Arbin<int> iz = lee_arbol(in);
		int raiz;
		in >> raiz;
		Arbin<int> dr = lee_arbol(in);
		in >> c;
		return Arbin<int>(iz, raiz, dr);
	}
	default: return Arbin<int>();
	}
}

void muestra_solucion(bool rentable, int renta_max) {
  if (rentable) {
	 cout << renta_max << endl; 
  }	
  else {
	 cout << "NO_RENTABLE " << endl; 
  }
}

int main() {
	Arbin<int> arbol;
	while (cin.peek() != EOF)  {
		Arbin<int> a = lee_arbol(cin);
		bool es_rentable;
		int renta_maxima;
		mejor_renta(a,es_rentable,renta_maxima);
		muestra_solucion(es_rentable,renta_maxima);
		string resto_linea;
		getline(cin, resto_linea);
	}
    return 0;       
}