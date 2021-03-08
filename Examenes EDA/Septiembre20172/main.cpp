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
void profundidad(Arbin<int> a, int k, int prof, int &nodosProfundidad) {
	if (esHoja(a) && prof > k) nodosProfundidad++;
	if (!a.hijoIz().esVacio()) profundidad(a.hijoIz(), k, prof + 1, nodosProfundidad);
	if (!a.hijoDer().esVacio()) profundidad(a.hijoDer(), k, prof + 1, nodosProfundidad);
}

/*
COMPLEJIDAD: Determina justificadamente la complejidad del procedimiento 

*/
int profundidad(Arbin<int> a) {
	int nodosProfundidad = 0;
	profundidad(a, 3, 0, nodosProfundidad);
	return nodosProfundidad;
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



/**
((([1]2#)3([4]5[6]))7((#8([9]10[11]))12[13]))
(((([0]0[0])0([0]-1[0]))-2#)0(([0]0[0])0[0]))
*/


int main() {
	Arbin<int> arbol;
	while (cin.peek() != EOF) {
		Arbin<int> a = lee_arbol(cin);
		cout << profundidad(a) << endl;
		string resto_linea;
		getline(cin, resto_linea);
	}
	return 0;
}