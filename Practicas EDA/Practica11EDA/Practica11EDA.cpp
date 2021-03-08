#include <iostream>
using namespace std;

#define MAX_OBRAS 30

void vueltaAtras(int n, int masaMinima, int precio[], int masa[], int precioAcumulado, int masaAcumulada, int masaRestante, int k, bool solParcial[], int mejorSol[], int &valorMejor, int &contador) {
	if (k == n) {
		if (precioAcumulado < valorMejor && masaAcumulada >= masaMinima) {
			contador = 0;
			valorMejor = precioAcumulado;
			for (int i = 0; i < MAX_OBRAS; i++) {
				if (solParcial[i]) {
					mejorSol[contador] = i + 1;
					contador++;
				}
			}
		}
		return;
	}

	if ((precioAcumulado + precio[k] < valorMejor) && ((k < 2) || (!solParcial[k - 2]) || !solParcial[k - 1])) {
		solParcial[k] = true;
		vueltaAtras(n, masaMinima, precio, masa, precioAcumulado + precio[k], masaAcumulada + masa[k], masaRestante - masa[k], k + 1, solParcial, mejorSol, valorMejor, contador);
	}

	if (masaAcumulada + masaRestante - masa[k] >= masaMinima) {
		solParcial[k] = false;
		vueltaAtras(n, masaMinima, precio, masa, precioAcumulado, masaAcumulada, masaRestante - masa[k], k + 1, solParcial, mejorSol, valorMejor, contador);
	}
}

void seleccionaYEscribeCompra(int n, int masaMinima, int precioTotal, int precio[], int masa[], int masaRestante) {
	bool solParcial[MAX_OBRAS];
	int mejorSol[MAX_OBRAS];
	for (int i = 0; i < MAX_OBRAS; i++) {
		solParcial[i] = false;
		mejorSol[i] = false;
	}
	int valorMejor = precioTotal + 1, contador = 0, mostrados = 0;
	vueltaAtras(n, masaMinima, precio, masa, 0, 0, masaRestante, 0, solParcial, mejorSol, valorMejor, contador);
	if (contador > 0) {
		cout << valorMejor << ": ";
		for (int i = 0; i < contador - 1; i++) {
			cout << mejorSol[i] << " ";
		}
		cout << mejorSol[contador - 1] << '\n';
	}
	else cout << "NO HAY EXPERIMENTO\n";
}

bool resuelve() {

	int n;
	int precio[MAX_OBRAS];
	int masa[MAX_OBRAS];
	int masaMinima;
	int masaRestante = 0;
	int precioTotal = 0;

	cin >> n >> masaMinima;

	if (!cin)
		return false;

	for (int i = 0; i < n; ++i) {
		cin >> masa[i];
		cin >> precio[i];
		masaRestante += masa[i];
		precioTotal += precio[i];
	}

	seleccionaYEscribeCompra(n, masaMinima, precioTotal, precio, masa, masaRestante);

	return true;

} // resuelve

int main() {

	// Resolvemos
	while (resuelve())
		;

	return 0;

} // main