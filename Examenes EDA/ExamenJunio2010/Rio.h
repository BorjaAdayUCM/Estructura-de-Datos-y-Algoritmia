#pragma once
#include "DiccionarioHash.h"
#include <iostream>
#include "Pantano.h"
#include <string>


using namespace std;

class Rio {
public:
	Rio();
	float embalsado_pantano(const string& pantano) const;
	float embalsado_pantanos() const;
	const Pantano& busca_pantano(const string& pantano) const;
	Pantano& busca_pantano(const string& pantano);
	void insertar_pantano(const string& pantano, const float cmax, const float vol);
	void mostrar() const;
private:
	DiccionarioHash<string, Pantano> _pantanos;
};

Rio::Rio() {}

float Rio::embalsado_pantano(const string& pantano) const {
	return busca_pantano(pantano).vol();
}

float Rio::embalsado_pantanos() const {
	DiccionarioHash<string, Pantano>::ConstIterator ipantanos = _pantanos.cbegin();
	DiccionarioHash<string, Pantano>::ConstIterator epantanos = _pantanos.cend();
	float embalsadoPantanos = 0;
	while (ipantanos != epantanos) {
		embalsadoPantanos += ipantanos.valor().vol();
		ipantanos.next();
	}
	return embalsadoPantanos;
}

const Pantano& Rio::busca_pantano(const string& pantano) const {
	DiccionarioHash<string, Pantano>::ConstIterator ipantano = _pantanos.cbusca(pantano);
	if (ipantano == _pantanos.cend()) throw EPantanoNoExiste();
	return ipantano.valor();
}

Pantano& Rio::busca_pantano(const string & pantano) {
	DiccionarioHash<string, Pantano>::Iterator ipantano = _pantanos.busca(pantano);
	if (ipantano == _pantanos.end()) throw EPantanoNoExiste();
	return ipantano.valor();
}

void Rio::insertar_pantano(const string & pantano, const float cmax, const float vol) {
	if (_pantanos.contiene(pantano)) throw EPantanoDuplicado();
	_pantanos.inserta(pantano, Pantano(cmax, vol));
}

void Rio::mostrar() const {
	DiccionarioHash<string, Pantano>::ConstIterator ipantanos = _pantanos.cbegin();
	DiccionarioHash<string, Pantano>::ConstIterator epantanos = _pantanos.cend();
	while (ipantanos != epantanos) {
		cout << "     " << ipantanos.clave() << " "; ipantanos.valor().mostrar();
		ipantanos.next();
	}
}

class ERioDuplicado {};
class ERioNoExiste {};
