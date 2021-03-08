#include <iostream>

using namespace std;

bool analiza(int v[], int n) {
	int i = 1, tamPelAnt = 0, tamPelAct = 1;
	bool creciente = true;
	while (i < n && creciente)
	{
		if (v[i] == v[i - 1]) tamPelAct++;
		else if (v[i] > v[i - 1])
		{
			if (tamPelAct < tamPelAnt) creciente = false;
			tamPelAnt = tamPelAct;
			tamPelAct = 1;
		}
		else creciente = false;
		if (i == n - 1 && tamPelAct < tamPelAnt) creciente = false;
		i++;
	}
	return creciente;
}

int main() {
	int n, v[1000];
	cin >> n;
	while(n != 0) {
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		if (analiza(v, n)) cout << "SI\n";
		else cout << "NO\n";
		cin >> n;
	}
}