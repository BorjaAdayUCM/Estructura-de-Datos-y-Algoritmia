#include <iostream>
using namespace std;

const int MAX_BARRAS = 30;

int energia[MAX_BARRAS];
int n;

int vueltaAtras(int n, int target, int energiaAcumulada, int k, bool solParcial[]) {
	if (k == n) {
		if (energiaAcumulada == target) return 1;
		return 0;
	}
	int select = 0, noSelect = 0;
	if (energiaAcumulada < target) {
		solParcial[k] = true;
		select = vueltaAtras(n, target, energiaAcumulada + energia[k], k + 1, solParcial);
	}

	solParcial[k] = false;
	noSelect = vueltaAtras(n, target, energiaAcumulada, k + 1, solParcial);
	return select + noSelect;
}

int cuantas(int n, int target) {
	bool solParcial[MAX_BARRAS];
	for (int i = 0; i < MAX_BARRAS; i++) solParcial[i] = false;
	return vueltaAtras(n, target, 0, 0, solParcial);
}

bool resuelve() {

	int target;
	cin >> n >> target;

	if ((n == 0) && (target == 0))
		return false;

	for (int i = 0; i < n; i++) {
		cin >> energia[i];
	}
	cout << cuantas(n, target) << '\n';

	return true;

} // resuelve

int main() {

	// Resolvemos
	while (resuelve())
		;

	return 0;

} // main