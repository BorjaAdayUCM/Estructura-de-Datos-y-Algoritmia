#include <iostream>
#include "Clases.h"

Cliente::Cliente() {
	_esperando = false;
}

void Cliente::esperando(bool espera) {
	_esperando = espera;
}

bool Cliente::getes() {
	return _esperando;
}
void Concierto::agregaClienteEspera(const string nombreCliente, Cliente &cliente){
	_listaClientesEspera.inserta(nombreCliente, cliente);
	cliente.esperando(true);
}

void Concierto::vende() {
	if (_listaClientesEspera.esVacio()) throw EAccesoNoValido();
	DiccionarioHash<string, Cliente>::Iterator it = _listaClientesEspera.begin();
	_listaClientesEspera.borra(it.clave());
	it.valor().esperando(false);
}

void Concierto::mostrar() {
	DiccionarioHash<string, Cliente>::Iterator it = _listaClientesEspera.begin();
	DiccionarioHash<string, Cliente>::Iterator ite = _listaClientesEspera.end();
	while (it != ite) {
		cout << it.clave() << " " <<  it.valor().getes() << endl;
		it.next();
	}
}

void Ventas::agregarConcierto(const string nombreConcierto) {
	DiccionarioHash<string, Concierto>::ConstIterator it = _listaConciertos.cbusca(nombreConcierto);
	if (it != _listaConciertos.cend()) throw EAccesoNoValido();
	_listaConciertos.inserta(nombreConcierto, Concierto());
}

void Ventas::agregarCliente(const string nombreConcierto, const string nombreCliente) {
	DiccionarioHash<string, Concierto>::ConstIterator iti = _listaConciertos.cbusca(nombreConcierto);
	if (iti == _listaConciertos.cend()) throw EAccesoNoValido();
	Diccionario<string, Cliente>::Iterator it = _listaClientes.busca(nombreCliente);
	Cliente cliente;
	if(it != _listaClientes.end()) cliente = it.valor();
	if (it == _listaClientes.end()) {
		cliente = Cliente();
		_listaClientes.inserta(nombreCliente, cliente);
	}
	_listaConciertos.busca(nombreConcierto).valor().agregaClienteEspera(nombreCliente, cliente);
}

void Ventas::vende(const string nombreConcierto) {
	_listaConciertos.busca(nombreConcierto).valor().vende();
}

void Ventas::mostrar(){
	DiccionarioHash<string, Concierto>::Iterator iti = _listaConciertos.begin();
	while (iti != this->_listaConciertos.end()) {
		cout << iti.clave() << " -> " << endl;
		iti.valor().mostrar();
		iti.next();
	}
	Diccionario<string, Cliente>::Iterator it = _listaClientes.begin();
	while (it != this->_listaClientes.end()) {
		cout << it.clave() << "->" << it.valor().getes() << endl;
		it.next();
	}
		
}