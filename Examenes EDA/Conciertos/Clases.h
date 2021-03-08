#pragma once
#include "DiccionarioHash.h"
#include "Diccionario.h"
#include<iostream>
#include <string>

using namespace std;

class Cliente {
public:
	Cliente();
	void esperando(bool espera);
	bool getes();
private:
	bool _esperando;
};

class Concierto {
public:
	void agregaClienteEspera(const string nombreCliente, Cliente &cliente);
	void vende();
	void mostrar();
private:
	DiccionarioHash<string, Cliente> _listaClientesEspera;
};

class Ventas {
public:
	void agregarConcierto(const string nombreConcierto);
	void agregarCliente(const string nombreConcierto, const string nombreCliente);
	void vende(const string nombreConcierto);
	void mostrar();
private:
	Diccionario<string, Cliente> _listaClientes;
	DiccionarioHash<string, Concierto> _listaConciertos;
};