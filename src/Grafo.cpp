#include "Grafo.h"
#include <string>
#include <sstream>
#include <iostream>

/* ---- GRAFO ---- */

Grafo::Grafo(){
	this->vertices = new Lista<Vertice*>;
}

Grafo::~Grafo(){
	this->vertices->iniciarCursor();
	while ( this->vertices->avanzarCursor()){
		Vertice* verticeActual = this->vertices->obtenerCursor();
		delete verticeActual;
	}
	delete this->vertices;
}

void Grafo::agregarVertice(int datoNuevo){

	if ( this->existeVertice(datoNuevo) ){
		throw std::string ("El Vertice existe en el Grafo!");
	}
	Vertice* nuevoVertice = new Vertice(datoNuevo);
	this->vertices->agregar(nuevoVertice);
}

void Grafo::agregarArista( int origen, int destino, int peso){

	Vertice* verticeOrigen = this->existeVertice(origen);
	Vertice* verticeDestino = this->existeVertice(destino);

	if ( !verticeOrigen ){
		throw std::string("El vertice origen no existe");
	}
	else if ( !verticeDestino ){
		throw std::string("El vertice destino no existe");
	}
	else if ( this->existeArista(origen, destino, peso) ){
		throw std::string("El arista ya existe!");
	}

	Arista* nuevoArista = new Arista( verticeOrigen, verticeDestino, peso);
	verticeOrigen->getVerticesAdyacentes()->agregar(nuevoArista);
}

void Grafo::agregarArista( int origen, int destino){

	Vertice* verticeOrigen = this->existeVertice(origen);
	Vertice* verticeDestino = this->existeVertice(destino);

	if ( !verticeOrigen ){
		throw std::string("El vertice origen no existe");
	}
	else if ( !verticeDestino ){
		throw std::string("El vertice destino no existe");
	}
	else if ( this->existeArista(origen, destino) ){
		throw std::string("El arista ya existe!");
	}

	Arista* nuevoArista = new Arista( verticeOrigen, verticeDestino);
	verticeOrigen->getVerticesAdyacentes()->agregar(nuevoArista);
}

void Grafo::borrarVertice(int datoOrigen){

	Vertice* verticeOrigen = this->existeVertice(datoOrigen);

	if ( !verticeOrigen ){
		throw std::string("El vertice que desea borrar no existe!");
	}

	Lista<Arista*>* aristas = verticeOrigen->getVerticesAdyacentes();
	aristas->iniciarCursor();
	while (aristas->avanzarCursor()){
		Arista* aristaActual = aristas->obtenerCursor();
		int datoDestinoActual = aristaActual->getDestino()->getDato();
		/* Borra, si es que existe, el arista inverso
		 * DESTINO --> ORIGEN
		 */
		borrarArista(datoDestinoActual, datoOrigen);
	}

	/* borra los aristas salientes del vertice */
	delete verticeOrigen->getVerticesAdyacentes();

	/* borra el vertice */
	delete verticeOrigen;
}

void Grafo::borrarArista( int datoOrigen, int datoDestino){

	Vertice* verticeOrigen = this->existeVertice(datoOrigen);

	if ( !verticeOrigen ){
		std::stringstream ss;
		ss << "El vertice "<<datoOrigen<<" de la arista no existe!";
		std::string mensaje = ss.str();
		throw std::string(mensaje);
	}

	Lista<Arista*>* aristasDelOrigen = verticeOrigen->getVerticesAdyacentes();
	int posicionArista = 0;
	bool encontrada = false;
	aristasDelOrigen->iniciarCursor();
	while (!encontrada && aristasDelOrigen->avanzarCursor()){
		posicionArista++;
		Arista* aristaActual = aristasDelOrigen->obtenerCursor();
		if (aristaActual->esLaMisma(datoOrigen, datoDestino)){
			encontrada = true;
			delete aristaActual;
		}
	}

	if (encontrada){
		aristasDelOrigen->remover(posicionArista);
	}
}

Vertice* Grafo::existeVertice(int verticeBuscado){

	Vertice* buscado = nullptr;
	bool encontrado = false;

	this->vertices->iniciarCursor();
	while ( !encontrado && this->vertices->avanzarCursor() ){
		Vertice* actual = this->vertices->obtenerCursor();

		if ( actual->getDato() == verticeBuscado ){
			encontrado = true;
			buscado = actual;
		}
	}

	return buscado;
}

Arista* Grafo::existeArista(int origen,int destino){
	Arista* aristaBuscada = nullptr;
	bool busquedaFinalizada = false;

	this->vertices->iniciarCursor();
	while ( !busquedaFinalizada && this->vertices->avanzarCursor() ){
		Vertice* verticeOrigen = this->vertices->obtenerCursor();
		int datoOrigen = verticeOrigen->getDato();
		if ( datoOrigen == origen ){
			Lista<Arista*>* conexiones = verticeOrigen->getVerticesAdyacentes();
			aristaBuscada = buscarConexionDestino(conexiones, destino);
			busquedaFinalizada = true;
		}
	}

	return aristaBuscada;
}

Arista* Grafo::existeArista(int origen, int destino, int peso ){

	Arista* aristaBuscada = nullptr;
	bool busquedaFinalizada = false;

	this->vertices->iniciarCursor();
	while ( !busquedaFinalizada && this->vertices->avanzarCursor() ){
		Vertice* verticeOrigen = this->vertices->obtenerCursor();
		int datoOrigen = verticeOrigen->getDato();
		if ( datoOrigen == origen ){
			Lista<Arista*>* conexiones = verticeOrigen->getVerticesAdyacentes();
			aristaBuscada = buscarConexionDestino(conexiones, destino, peso);
			busquedaFinalizada = true;
		}
	}

	return aristaBuscada;
}

void Grafo::mostrarVertices(){

	std::cout << "Vertices del Grafo:  ";
	this->vertices->iniciarCursor();
	while (this->vertices->avanzarCursor()){
		int datoVertice = this->vertices->obtenerCursor()->getDato();
		std::cout << "(" << datoVertice << ")  ";
	}
}

void Grafo::mostrarAristasDelVertice(int datoVertice){

	Vertice* verticeBuscado = this->existeVertice(datoVertice);

	if (!verticeBuscado){
		throw std::string("El vertice que desea ver sus aristas no existe!");
	}

	Lista<Arista*>* aristas = verticeBuscado->getVerticesAdyacentes();
	if (aristas->estaVacia()){
		std::cout<< "El vertice " << datoVertice << " no tiene aristas" <<std::endl;
	}
	aristas->iniciarCursor();
	while (aristas->avanzarCursor()){
		Arista* aristaActual = aristas->obtenerCursor();
		std::cout<< "(" << aristaActual->getOrigen()->getDato() << ") "
				 << "-->"
				 << "(" << aristaActual->getDestino()->getDato() << ")"
				 <<std::endl;
	}
}


/* ---- PRIVADO -GRAFO-  ------------------ */

Arista* Grafo::buscarConexionDestino( Lista<Arista*>* conexiones, int destino, int peso){

	Arista* aristaBuscada = nullptr;
	bool destinoEncontrado = false;

	conexiones->iniciarCursor();
	while ( !destinoEncontrado && conexiones->avanzarCursor() ){
		Arista* aristaActual = conexiones->obtenerCursor();
		int datoDestino = aristaActual->getDestino()->getDato();
		int pesoActual = aristaActual->getPeso();

		if ( (datoDestino == destino) && (pesoActual == peso) ){
			aristaBuscada = aristaActual;
			destinoEncontrado = true;
		}
	}
	return aristaBuscada;
}

Arista* Grafo::buscarConexionDestino( Lista<Arista*>* conexiones, int destino ){

	Arista* aristaBuscada = nullptr;
	bool destinoEncontrado = false;

	conexiones->iniciarCursor();
	while ( !destinoEncontrado && conexiones->avanzarCursor() ){
		Arista* aristaActual = conexiones->obtenerCursor();
		int datoDestino = aristaActual->getDestino()->getDato();

		if ( (datoDestino == destino) ){
			aristaBuscada = aristaActual;
			destinoEncontrado = true;
		}
	}
	return aristaBuscada;
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

Lista<Arista*>* Vertice::getVerticesAdyacentes() const {
	return verticesAdyacentes;
}

bool Vertice::tieneAristas(){
	return !(this->getVerticesAdyacentes()->estaVacia());
}

void Vertice::marcarVisitado(){
	this->visitado = true;
}

void Vertice::desmarcarVisitado(){
	this->visitado = false;
}

Vertice::~Vertice(){
	Lista<Arista*>* aristasSalientes = this->getVerticesAdyacentes();
	aristasSalientes->iniciarCursor();
	while (aristasSalientes->avanzarCursor()){
		Arista* aristaActual = aristasSalientes->obtenerCursor();
		delete aristaActual;
	}
	delete this->verticesAdyacentes;
}

/* ---- ARISTA  ---- */


Arista::Arista (Vertice* nuevoOrigen, Vertice* nuevoDestino, int nuevoPeso){

	this->origen = nuevoOrigen;
	this->destino = nuevoDestino;
	this->peso = nuevoPeso;
}

Arista::Arista( Vertice* nuevoOrigen, Vertice* nuevoDestino){
	this->origen = nuevoOrigen;
	this->destino = nuevoDestino;
	this->peso = 1;
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

bool Arista::esLaMisma( int otroOrigen, int otroDestino ){
	return (otroOrigen == this->origen->getDato()) &&
			(otroDestino == this->destino->getDato());
}
