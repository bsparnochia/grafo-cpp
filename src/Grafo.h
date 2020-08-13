#ifndef GRAFO_H_
#define GRAFO_H_

#include "Lista.h"

class Vertice;
class Arista;

class Grafo{

	/**
	 * @brief: El Grafo es una estructura de elementos denominados 'vertices'
	 * que se encuentran conectados entre sí mediante Aristas estableciendo asi
	 * un número N de relaciones entre estos
	 */

public:

	/**
	 * @post: Se crea el Grafo vacío sin Vertices ni Aristas
	 */
	Grafo();

	/**
	 * @pre : El Vertice no existe en el Grafo
	 * @post: Se agrega el Vertice al Grafo
	 */
	void agregarVertice( int dato );

	/**
	 * @pre : El Vertice existe en el Grafo
	 * @post: Se elimina el Vertice del Grafo y sus Aristas conectadas
	 */
	void borrarVertice( int dato );

	/**
	 * @pre : La Arista no existe en el Grafo
	 * @post: Agrega la Arista al Grafo
	 */
	void agregarArista( int origen, int destino, int peso );

	/**
	 * @pre : 'origen', 'destino' y 'peso' son valores correspondientes
	 *  a una Arista existente en el Grafo
	 * @post: Se borra la 'Arista' del Grafo
	 */
	void eliminarArista( int origen, int destino, int peso);

	/**
	 * @pre : 'verticeActual' y  'verticeComparado' son Vertices del Grafo
	 * @post: Devuelve la Arista que conecta 'verticeActual' y 'verticeComparado'
	 * si son adyacentes, caso contrario devuelve null
	 */
	Arista* existeArista(int verticeActual,int verticeComparado );

	/**
	 * post: Devuelve el Vertice si existe el 'verticeBuscado' en el Grafo
	 */
	Vertice* existeVertice( int VerticeBuscado);

	~Grafo();

private:
	Lista<Vertice*>* vertices;

};

/* ------- VERTICE ---------- */

class Vertice{

	/**
	 * @brief: El Vertice es un elemento del Grafo
	 * 	que contiene un 'dato' e información sobre los
	 * 	Aristas que conectan éste con sus 'verticesAdyacentes'
	 */

public:

	/**
	 * @pre : El Vertice no existe en el Grafo
	 * @post: Crea un nuevo Vertice con un 'dato', sin ningun
	 * 'verticesAdyacentes' y marcado como no-visitado
	 */
	Vertice( int dato );

	/**
	 * @post: Devuelve el 'dato' del Vertice
	 */
	int getDato() const;

	/**
	 * @post: Devuelve las conexiones del Vertice con sus 'verticesAdyacentes'
	 */
	const Lista<Arista*>* getVerticesAdyacentes() const;

	/**
	 * @post: marca el Vertice como visitado
	 */
	void marcarVisitado();

	/**
	 * @post: marca el Vertice como no-visitado
	 */
	void desmarcarVisitado();

	/**
	 * @post: Elimina el listado de Aristas
	 */
	~Vertice();

private:
	int dato;
	bool visitado;
	Lista<Arista*>* verticesAdyacentes;
};

/* ------- ARISTA ---------- */

class Arista{

	/**
	 * @brief: La arista es una conexión que tiene un 'peso' determinado
	 * y que une dos vertices, 'origen' y 'destino'.
	 */

private:
	Vertice* origen;
	Vertice* destino;
	int peso;

public:

	/**
	 * @pre : Los vertices 'origen' y 'destino' existen en el Grafo
	 * @post: Crea una nueva Arista conectando un vertice 'origen'
	 * con un vertice 'destino' y además indicando un 'peso'
	 */
	Arista( Vertice* nuevoOrigen, Vertice* nuevoDestino, int nuevoPeso);

	/**
	 * @post: obtiene el 'destino' de la Arista
	 */
	Vertice* getDestino() const;

	/**
	 * @post: obtiene el 'origen' de la Arista
	 */
	Vertice* getOrigen() const;

	/**
	 * @post: obtiene el 'peso' de la Arista
	 */
	int getPeso() const;
};

#endif /* GRAFO_H_ */
