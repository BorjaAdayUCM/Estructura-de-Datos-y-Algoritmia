#include <iostream>
#include "Clases.h"

using namespace std;

int main() {
	Ventas ventas = Ventas();
	string op;
	cin >> op;

	while (op != "salir") {
		if (op == "concierto") {
			string nombreConcierto;
			cin >> nombreConcierto;
			ventas.agregarConcierto(nombreConcierto);
		}
		else if (op == "cliente") {
			string nombreConcierto, nombreCliente;
			cin >> nombreConcierto >> nombreCliente;
			ventas.agregarCliente(nombreConcierto, nombreCliente);
		}
		else if (op == "venta") {
			string nombreConcierto;
			cin >> nombreConcierto;
			ventas.vende(nombreConcierto);
		}
		cin >> op;
		ventas.mostrar();
	}


	return 0;
}