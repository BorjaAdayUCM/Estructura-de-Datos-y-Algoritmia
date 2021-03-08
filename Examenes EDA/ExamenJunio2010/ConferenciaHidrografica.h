#pragma once
#include "DiccionarioHash.h"
#include <iostream>
#include <string>
#include "Pantano.h"
#include "Rio.h"

using namespace std;

class ConferenciaHidrografica {
public:
	ConferenciaHidrografica();
	void insertar_rio(const string& rio);
	const Rio& busca_rio(const string& rio) const;
	Rio& busca_rio(const string& rio);
	void insertar_pantano(const string& rio, const string& pantano, const float cmax, const float vol);
	void embalsar(const string& rio, const string& pantano, const float vol);
	float embalsado_pantano(const string& rio, const string& pantano) const;
	float embalsado_cuenca(const string& rio) const;
	void transvasar(const string& rio_origen, const string& pantano_origen, const string& rio_destino, const string& pantano_destino, float vol);
	void mostrar();
private:
	DiccionarioHash<string, Rio> _rios;
};

ConferenciaHidrografica::ConferenciaHidrografica() {}

void ConferenciaHidrografica::insertar_rio(const string& rio) {
	if (_rios.contiene(rio)) throw ERioDuplicado();
	_rios.inserta(rio, Rio());
}

const Rio& ConferenciaHidrografica::busca_rio(const string& rio) const {
	DiccionarioHash<string, Rio>::ConstIterator irio = _rios.cbusca(rio);
	if (irio == _rios.cend()) throw ERioNoExiste();
	return irio.valor();
}

Rio& ConferenciaHidrografica::busca_rio(const string & rio) {
	DiccionarioHash<string, Rio>::Iterator irio = _rios.busca(rio);
	if (irio == _rios.end()) throw ERioNoExiste();
	return irio.valor();
}

void ConferenciaHidrografica::insertar_pantano(const string & rio, const string & pantano, const float cmax, const float vol) {
	busca_rio(rio).insertar_pantano(pantano, cmax, vol);
}

void ConferenciaHidrografica::embalsar(const string & rio, const string & pantano, const float vol) {
	busca_rio(rio).busca_pantano(pantano).pon_vol(vol);
}

float ConferenciaHidrografica::embalsado_pantano(const string & rio, const string & pantano) const {
	return busca_rio(rio).busca_pantano(pantano).vol();
}

float ConferenciaHidrografica::embalsado_cuenca(const string & rio) const {
	return busca_rio(rio).embalsado_pantanos();
}

void ConferenciaHidrografica::transvasar(const string& rio_origen, const string& pantano_origen, const string& rio_destino, const string& pantano_destino, float vol) {
	Pantano& pOrigen = (vol >= 0 ? busca_rio(rio_origen).busca_pantano(pantano_origen): busca_rio(rio_destino).busca_pantano(pantano_destino));
	Pantano& pDestino = (vol >= 0 ? busca_rio(rio_destino).busca_pantano(pantano_destino) : busca_rio(rio_origen).busca_pantano(pantano_origen));
	float volOrigen = (vol >= 0 ? busca_rio(rio_origen).busca_pantano(pantano_origen).vol() : busca_rio(rio_destino).busca_pantano(pantano_destino).vol());
	float volDestino = (vol >= 0 ? busca_rio(rio_destino).busca_pantano(pantano_destino).vol() : busca_rio(rio_origen).busca_pantano(pantano_origen).vol());
	float maxOrigen = (vol >= 0 ? busca_rio(rio_origen).busca_pantano(pantano_origen).cmax() : busca_rio(rio_destino).busca_pantano(pantano_destino).cmax());
	float maxDestino = (vol >= 0 ? busca_rio(rio_destino).busca_pantano(pantano_destino).cmax() : busca_rio(rio_origen).busca_pantano(pantano_origen).cmax());
	float volumen = (vol >= 0 ? vol : -vol);
	//Si tengo suficiente
	if (volOrigen >= volumen) {
		//Si cabe el agua
		if (volumen + volDestino <= maxDestino) {
			pOrigen.pon_vol(volOrigen - volumen);
			pDestino.pon_vol(volDestino + volumen);
		}
		//Si no cabe
		else {
			pOrigen.pon_vol(volOrigen - (maxDestino - volDestino));
			pDestino.pon_vol(maxDestino);
		}
	}
	//Si no tengo suficiente
	else {
		//Si cabe el agua
		if (volOrigen + volDestino <= maxDestino) {
			pOrigen.pon_vol(0);
			pDestino.pon_vol(volOrigen + volDestino);
		}
		//Si no cabe
		else {
			pOrigen.pon_vol(volOrigen - (maxDestino - volDestino));
			pDestino.pon_vol(maxDestino);
		}
	}
}

void ConferenciaHidrografica::mostrar() {
	DiccionarioHash<string, Rio>::ConstIterator irio = _rios.cbegin();
	DiccionarioHash<string, Rio>::ConstIterator erio = _rios.cend();
	while (irio != erio) {
		cout << irio.clave() << endl; irio.valor().mostrar();
		irio.next();
	}
}





