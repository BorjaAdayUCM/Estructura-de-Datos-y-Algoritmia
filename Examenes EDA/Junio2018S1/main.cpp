
#include <iostream>
#include <string>
#include "Arbin.h"

using namespace std;

template <class T>
bool esHoja(const Arbin<T> &a) {
	return !a.esVacio() && a.hijoIz().esVacio() && a.hijoDer().esVacio();
}

/**
([M]C([D]C([D]C[M])))
([M]C([]C([D]C[M])))
  FUNCION A IMPLEMENTAR.
  Aparte de esta función, puedes implementar todas las funciones auxiliares que
  consideres oportuno. 
  Debes describir y justificar aquí la complejidad de la implementación realizada:
  es lineal O(n) ya que pasamos una única vez por cada nodo.  

*/

int num_a_salvo(const Arbin<char>& a, int monstruos, int& aSalvo) {
	if (a.esVacio()) return 0;
	if (a.raiz() == 'M') monstruos++;
	int izq = num_a_salvo(a.hijoIz(), monstruos, aSalvo);
	int der = num_a_salvo(a.hijoDer(), monstruos, aSalvo);
	if (a.raiz() == 'D' && monstruos <= izq + der) aSalvo++;
	if (a.raiz() == 'C') return izq + der + 1;
	return izq + der;
}



int num_a_salvo(const Arbin<char>& a) {
	/*** A IMPLEMENTAR ***/
	int aSalvo = 0;
	num_a_salvo(a, 0, aSalvo);
	return aSalvo;
}



Arbin<char> lee_arbol(istream& in) {
	char c;
	in >> c;
	switch (c) {
	case '#': return Arbin<char>();
	case '[': {
		char raiz;
		in >> raiz;
  		in >> c;
		return Arbin<char>(raiz);
	}
	case '(': {
		Arbin<char> iz = lee_arbol(in);
		char raiz;
		in >> raiz;
		Arbin<char> dr = lee_arbol(in);
		in >> c;
		return Arbin<char>(iz, raiz, dr);
	}
	default: return Arbin<char>();
	}
}


void escribe_arbol(Arbin<char> a) {
	if (a.esVacio()) cout << "#";
	else if (a.hijoIz().esVacio() && a.hijoDer().esVacio()) cout << "[" << a.raiz() << "]";
	else {
		cout << "("; 
		escribe_arbol(a.hijoIz()); 
		cout << a.raiz(); 
		escribe_arbol(a.hijoDer());
		cout << ")";
	}
}


int main() {
	Arbin<char> arbol;
	while (cin.peek() != EOF)  {
		Arbin<char> mapa = lee_arbol(cin);
		cout << "num_a_salvo ";
		escribe_arbol(mapa);
		cout << " => ";
		cout << num_a_salvo(mapa);
		string resto_linea;
		getline(cin, resto_linea);
		if (cin.peek() != EOF) cout << endl;
	}
	return 0;
}
