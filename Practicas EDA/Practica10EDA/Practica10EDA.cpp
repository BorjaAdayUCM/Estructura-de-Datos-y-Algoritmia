#include <iostream>
using namespace std;

#define MAX_OBRAS 30

void vueltaAtras(int n, int presupuesto, int precio[], int valor[], int precioAcumulado, int bellezaAcumulada, int bellezaRestante, int k, bool solParcial[], int mejorSol[], int &valorMejor, int &contador) {
	if (k >= n) {
		if (bellezaAcumulada >= valorMejor) {
			contador = 0;
			valorMejor = bellezaAcumulada;
			for (int i = 0; i < MAX_OBRAS; i++) {
				if (solParcial[i]) {
					mejorSol[contador] = i + 1;
					contador++;
				}
			}
		}
		return;
	}

	if ((presupuesto >= precioAcumulado + precio[k]) && ((k % 2 == 0) || (!solParcial[k - 1]))) {
		solParcial[k] = true;
		vueltaAtras(n, presupuesto, precio, valor, precioAcumulado + precio[k], bellezaAcumulada + valor[k], bellezaRestante - valor[k], k + 1, solParcial, mejorSol, valorMejor, contador);
	}

	if (bellezaAcumulada + bellezaRestante - valor[k] > valorMejor) {
		solParcial[k] = false;
		vueltaAtras(n, presupuesto, precio, valor, precioAcumulado, bellezaAcumulada, bellezaRestante - valor[k], k + 1, solParcial, mejorSol, valorMejor, contador);
	}
}

void seleccionaYEscribeCompra(int n, int presupuesto, int precio[], int valor[], int bellezaRestante) {
	bool solParcial[MAX_OBRAS];
	int mejorSol[MAX_OBRAS];
	for (int i = 0; i < MAX_OBRAS; i++) {
		solParcial[i] = false;
		mejorSol[i] = false;
	}
	int valorMejor = 0, contador = 0, mostrados = 0;
	vueltaAtras(n, presupuesto, precio, valor, 0, 0, bellezaRestante, 0, solParcial, mejorSol, valorMejor, contador);
	cout << valorMejor << ": ";
	if (contador > 0) {
		for (int i = 0; i < contador - 1; i++) {
			cout << mejorSol[i] << " ";
		}
		cout << mejorSol[contador - 1] << '\n';
	}
	else cout << '\n';
}

bool resuelve() {

	int n;
	int precio[MAX_OBRAS];
	int valor[MAX_OBRAS];
	int presupuesto;
	int bellezaRestante = 0;

	cin >> n >> presupuesto;

	if (!cin)
		return false;

	for (int i = 0; i < n; ++i) {
		cin >> precio[i];
		cin >> valor[i];
		bellezaRestante += valor[i];
	}

	seleccionaYEscribeCompra(n, presupuesto, precio, valor, bellezaRestante);

	return true;

} // resuelve

int main() {

	// Resolvemos
	while (resuelve())
		;

	return 0;

} // main