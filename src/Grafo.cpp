#include "Grafo.h"

/* ---- GRAFO ---- */

Grafo::Grafo(){
	this->vertices = new Lista<Vertice*>;
}

Grafo::~Grafo(){
	delete this->vertices;
}

/* ---- VERTICE ---- */


Vertice::Vertice( int nuevoDato){
	this->dato = nuevoDato;
	this->visitado = false;
	this->verticesAdyacentes = new Lista<Arista*>;
}

int Vertice::getDato() const {
	return dato;
}

const Lista<Arista*>* Vertice::getVerticesAdyacentes() const {
	return verticesAdyacentes;
}

void Vertice::marcarVisitado(){
	this->visitado = true;
}

void Vertice::desmarcarVisitado(){
	this->visitado = false;
}

Vertice::~Vertice(){
	delete this->verticesAdyacentes;
}

/* ---- ARISTA  ---- */


Arista::Arista (Vertice* nuevoOrigen, Vertice* nuevoDestino, int nuevoPeso){

	this->origen = nuevoOrigen;
	this->destino = nuevoDestino;
	this->peso = nuevoPeso;
}

Vertice* Arista::getDestino() const {
	return destino;
}

Vertice* Arista::getOrigen() const {
	return origen;
}

int Arista::getPeso() const {
	return peso;
}
