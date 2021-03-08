#include "Racional.h"
#include <cmath> 

//Metodos publicos

  //**** COMPLETAR
  //  Deben implementarse los metodos publicos de la clase
  //****
Racional::Racional() {
	_numer = 0;
	_denom = 1;
}

Racional::Racional(int n, int d) {
	if (d == 0)
		throw EDenominadorCero();
	_numer = n;
	_denom = d;
	this->reduce();
}

Racional Racional::suma(const Racional &o) {
	long min = mcm(_denom, o._denom);
	return Racional(_numer * (min / _denom) + o._numer* (min / o._denom), min);
	//return Racional(_numer * o._denom + o._numer * _denom, _denom * o._denom);
	//Esta instruccion hace lo mismo que todo lo anterior pero usa como numero comun la multiplicacion de los denominadores
	//de forma que queda una fraccion grande y reduce al final con la constructora.
}

Racional Racional::operator-(const Racional &o) const {
	long min = mcm(_denom, o._denom);
	return Racional(_numer * (min / _denom) - o._numer* (min / o._denom), min);
	//return Racional(_numer * o._denom - o._numer * _denom, _denom * o._denom);
	//Esta instruccion hace lo mismo que todo lo anterior pero usa como numero comun la multiplicacion de los denominadores
	//de forma que queda una fraccion grande y reduce al final con la constructora.
}

Racional Racional::operator*=(const Racional &o) {
	this->_numer *= o._numer;
	this->_denom *= o._denom;
	this->reduce();
	return *this;
}

Racional Racional::divideYActualiza(const Racional &o) {
	if (o._numer == 0)
		throw EDivisionPorCero();
	this->_numer *= o._denom;
	this->_denom *= o._numer;
	this->reduce();
	return *this;
}
bool Racional::operator==(const Racional &o) const {
	Racional ret1 = Racional(_numer, _denom);
	Racional ret2 = Racional(o._numer, o._denom);
	return ret1._numer == ret2._numer && ret1._denom == ret2._denom;
}

// Funciones amigas
ostream& operator<<(ostream& out, const Racional& f) {
	out << f._numer << "/" << f._denom;
	return out;
}

// Metodos privados
void Racional::reduce() {
	// Se asegura que el denominador siempre sea positivo   
	if (_denom < 0) {
		_numer = -_numer;
		_denom = -_denom;
	}
	// Se divide numerador y denominador por el maximo comun divisor de ambos
	long fsimp = mcd(_numer, _denom);
	_numer /= fsimp;
	_denom /= fsimp;
}

long Racional::mcd(long v1, long v2) {
	// El calculo del maximo comun divisor se hace por el algoritmo de Euclides
	v1 = abs(v1);
	v2 = abs(v2);
	if (v1 < v2) {
		long tmp = v1;
		v1 = v2;
		v2 = tmp;
	}
	while (v2 != 0) {
		long nv2 = v1 % v2;
		v1 = v2;
		v2 = nv2;
	}
	return v1;
}

long Racional::mcm(long v1, long v2) {
	return v1 * v2 / mcd(v1, v2);
}

