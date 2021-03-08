#pragma once

using namespace std;

class Pantano {
public:
	Pantano(float cmax, float vol);
	float cmax() const;
	float vol() const;
	void pon_vol(float vol);
	void mostrar() const;
private:
	float _cmax;
	float _vol;
};

Pantano::Pantano(float cmax = 0, float vol = 0) {
	_cmax = cmax;
	if (vol > cmax) _vol = cmax;
	else _vol = vol;
}

float Pantano::cmax() const { return _cmax; }

float Pantano::vol() const { return _vol; }

void Pantano::pon_vol(float vol) {
	if (vol > _cmax) _vol = _cmax;
	else _vol = vol;
}

void Pantano::mostrar() const {
	cout << " " << _vol << " " << _cmax << endl;
}

class EPantanoNoExiste {};
class EPantanoDuplicado {};