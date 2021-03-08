
#include <iostream>
#include "lista.h"
using namespace std;

/**
Este programa lee por la entrada est�ndar l�neas con el siguiente formato:
- Una secuencia de enteros (excluido el -1), que se interpreta como una
cola.
- El -1 (centinela que marca el final de la cola)
- Una posici�n (entero >= 0)
Entonces, ejecuta la operaci�n 'llevarAlPrincipio' sobre la cola indicada, y escribe
por pantalla el resultado (o POSICION_INVALIDA en caso de que la posici�n no sea v�lida)

Ejemplo de entrada:
1 2 3 4 5 -1 1
1 2 3 4 5 -1 2
1 2 3 4 5 -1 3
1 2 3 4 5 -1 4
1 2 3 4 5 -1 5
1 2 3 4 5 -1 0
1 2 3 4 5 -1 6
-1 1

Salida producida:
1 2 3 4 5
2 1 3 4 5
3 1 2 4 5
4 1 2 3 5
5 1 2 3 4
POSICION_INVALIDA
POSICION_INVALIDA
POSICION_INVALIDA

*/

bool lee_lista(Lista<char>& lista) {
	char v;
	if (cin >> v) {
		while (v != 'x') {
			lista.pon_final(v);
			cin >> v;
		}
		return true;
	}
	else return false;
}


int main() {
	Lista<char> lista;
	lee_lista(lista);
	lista.invierte();
	lista.print();
	system("pause");
}