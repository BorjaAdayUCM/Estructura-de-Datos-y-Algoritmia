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



int diametro(const Arbin<int> a, int &lmax) {
	if (a.esVacio()) return 0;
	if (esHoja(a)) return 1;
	int izq = diametro(a.hijoIz(), lmax);
	int der = diametro(a.hijoDer(), lmax);
	if (izq + der + 1 > lmax) lmax = izq + der + 1;
	if (izq > der) return izq + 1;
	else return der + 1;
}

int diametro(const Arbin<int> a) {
	int lmax = 0;
	diametro(a,  lmax);
	return lmax;
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
La entrada al programa consiste de líneas formadas por:
(1) Un árbol de enteros
(2) El valor de k
Los árboles se codifican de acuerdo con las siguientes reglas:
(1) El árbol vacío se codifica como #
(2) Los árboles simples se codifican como [v], con  
    v el valor del nodo
(3) Los árboles complejos se codifican como (IvD),
    con I la codificación del hijo izquierdo,
	v el valor de la raíz, y D la codificación
	del hijo derecho.
Para cada línea leida, escribe en la salida estádar
el número de hojas que están a profundidad mayor que k

	
Ejemplo de entrada:
(([4]3[-3])1[-4])

([2]1([4]3[5])) 0
([2]1([4]3[5])) 1
([2]1([4]3[5])) 2
([2]1([4]3[5])) 3
([2]1([4]3[5])) 4
([2]1([4]3[5])) 100

([2]1([4]3([4]5[3])))

Salida asociada:

3
3
2
0
0
0

*/


int main() {
	Arbin<int> arbol;
	while (cin.peek() != EOF)  {
		Arbin<int> a = lee_arbol(cin);		
		cout << diametro(a) << endl;
		string resto_linea;
		getline(cin, resto_linea);
	}
	return 0;
}
