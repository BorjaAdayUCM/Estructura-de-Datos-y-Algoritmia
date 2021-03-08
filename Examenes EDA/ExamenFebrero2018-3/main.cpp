#include <iostream>

using namespace std;

void backtraking(int n, int esc, int escAct, int escAnt, int k, int solParcial[]) {
	if (k == n) {
		for (int i = 0; i < n; i++) {
			cout << solParcial[i] << " ";
		}
		cout << '\n';
		return;
	}

	solParcial[k] = esc;
	backtraking(n, esc, escAct + 1, escAnt, k + 1, solParcial);

	if (!(k == 0) && (escAct >= escAnt && n - k >= escAct)) {
		solParcial[k] = esc + 1;
		backtraking(n, esc + 1, 1, escAct, k + 1, solParcial);
	}
	

}

int main() {
	int max, solParcial[30];
	cin >> max;
	while (max != 0) {
		backtraking(max, 1, 0, 0, 0, solParcial);
		cin >> max;
	}
}