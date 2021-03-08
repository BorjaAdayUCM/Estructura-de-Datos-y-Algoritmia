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
/*int num_navegables(Arbin<int> a, int &numNavegables) {
	if (esHoja(a)) return 1;
	int izq = 0, der = 0;
	if(!a.hijoIz().esVacio()) izq = num_navegables(a.hijoIz(), numNavegables);
	if (!a.hijoDer().esVacio()) der = num_navegables(a.hijoDer(), numNavegables);
	if (izq >= 3) numNavegables++;
	if (der >= 3) numNavegables++;
	return izq + der + a.raiz();
}*/

/*
COMPLEJIDAD: Determina justificadamente la complejidad del procedimiento 

*/
/*int num_navegables(Arbin<int> a) {
	int numNavegables = 0;
	num_navegables(a, numNavegables);
	return numNavegables;
} */

int num_navegables(Arbin<int> a, int sumaAnt, int& numNavegables) {
	if (a.esVacio()) return 0;
	if (esHoja(a)) {
		if (sumaAnt == 0) numNavegables++;
		return a.raiz();
	}
	int izq = num_navegables(a.hijoIz(), sumaAnt + a.raiz(), numNavegables);
	int der = num_navegables(a.hijoDer(), sumaAnt + a.raiz(), numNavegables);
	if (sumaAnt == izq + der) numNavegables++;
	return izq + der + a.raiz();
}

/*
COMPLEJIDAD: Determina justificadamente la complejidad del procedimiento

*/
int num_navegables(Arbin<int> a) {
	int numNavegables = 0;
	num_navegables(a, 0, numNavegables);
	return numNavegables;
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
		cout << num_navegables(a) << endl;
		string resto_linea;
		getline(cin, resto_linea);
	}
	return 0;
}