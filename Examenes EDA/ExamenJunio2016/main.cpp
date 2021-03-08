#include "Arbin.h"
#include <iostream>
#include <string>


using namespace std;

template <class T>
bool esHoja(const Arbin<T> &a) {
	return !a.esVacio() && a.hijoIz().esVacio() && a.hijoDer().esVacio();
}

/**
  COMPLEJIDAD: Explica aquí justificadamente cuál es la complejidad de 
               esta función
			   ***A COMPLETAR***
			   es lineal O(n) porque solo se pasa una vez por cada nodo.
*/



unsigned int num_navegables(const Arbin<int> a, int &navegables) {
	if (a.esVacio()) return 0;
	if (esHoja(a)) {
		return 1;
	}
	int sumaIzq = num_navegables(a.hijoIz(), navegables);
	int sumaDer = num_navegables(a.hijoDer(), navegables);
	if (sumaIzq + sumaDer + a.raiz() >= 3) navegables++;
	return sumaIzq + sumaDer + a.raiz();
} 

unsigned int num_navegables(const Arbin<int> a) {
	int navegables = 0;
	if (num_navegables(a, navegables) >= 3) navegables--;
	return navegables;
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
	while (cin.peek() != EOF)  {
		Arbin<int> a = lee_arbol(cin);		
		cout << num_navegables(a) << endl;
		string resto_linea;
		getline(cin, resto_linea);
	}
	return 0;
}
