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
	 * @pre : La Arista con la información 'origen', 'destino' y 'peso'
	 * 			no existe en el Grafo
	 * @post: Agrega la Arista al Grafo
	 */
	void agregarArista( int origen, int destino, int peso );

	/**
	 * @pre : La Arista con la información 'origen' y 'destino'
	 * 			no existe en el Grafo
	 * @post: Agrega la Arista al Grafo
	 */
	void agregarArista( int origen, int destino);


	/**
	 * @pre : 'origen', 'destino' y 'peso' son valores correspondientes
	 *  a una Arista existente en el Grafo
	 * @post: Se borra la 'Arista' del Grafo
	 */
	void borrarArista( int origen, int destino, int peso);

	/**
	 * @pre : 'origen', 'destino' son valores correspondientes
	 *  a una Arista existente en el Grafo
	 * @post: Se borra la 'Arista' del Grafo
	 */
	void borrarArista( int origen, int destino);

	/**
	 * @post: Devuelve la Arista que conecta 'origen' y 'destino'
	 * y que tiene el 'peso' indicado si son adyacentes, caso contrario devuelve null
	 */
	Arista* existeArista(int origen,int destino, int peso );

	/**
	 * @post: Devuelve la Arista que conecta 'verticeActual' y 'verticeComparado'
	 * si son adyacentes, caso contrario devuelve null
	 */
	Arista* existeArista(int origen,int destino);

	/**
	 * @post: Devuelve el Vertice si existe el 'verticeBuscado' en el Grafo
	 */
	Vertice* existeVertice(int VerticeBuscado);

	/**
	 * @post: muestra los Vertices que contiene el Grafo
	 */
	void mostrarVertices();

	/**
	 * @post: muestra por pantalla los Aristas salientes del 'vertice'
	 */
	void mostrarAristasDelVertice(int vertice);

	/**
	 * post: libera los recursos del Grafo
	 */
	~Grafo();

private:

	/**
	 * @post: Devuelve un Arista que contiene el 'destino' y 'peso' indicado por
	 * parámetro. En caso de no encontrar una Arista que cumpla esta condición
	 * retornará null
	 */
	Arista* buscarConexionDestino( Lista<Arista*>* conexiones, int destino, int peso);

	/**
	 * @post: Devuelve un Arista que contiene el 'destino' indicado por
	 * parámetro. En caso de no encontrar una Arista que cumpla esta condición
	 * retornará null
	 */
	Arista* buscarConexionDestino( Lista<Arista*>* conexiones, int destino );


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
	Lista<Arista*>* getVerticesAdyacentes() const;

	/**
	 * @post: Devuelve si el 'vertice' tiene Aristas
	 * 		  salientes hacia otros Vertices
	 */
	bool tieneAristas();

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
	 * @pre : Los vertices 'origen' y 'destino' existen en el Grafo pero
	 * 		 no una Arista formulada con su 'origen', 'destino' y 'peso'
	 * @post: Crea una nueva Arista conectando un vertice 'origen'
	 * con un vertice 'destino' y además indicando un 'peso'
	 */
	Arista( Vertice* nuevoOrigen, Vertice* nuevoDestino, int nuevoPeso);

	/**
	 * @pre : Los vertices 'origen' y 'destino' existen en el Grafo
	 * 		 pero no una Arista con estos datos
	 * @post: Crea una nueva Arista conectando un vertice 'origen'
	 * con un vertice 'destino' y además indicando un 'peso'
	 */
	Arista( Vertice* nuevoOrigen, Vertice* nuevoDestino);

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

	/**
	 * @post: retonarna verdadero si el 'otroOrigen' y el 'otroDestino' son iguales
	 * 			al 'origen' y 'destino' de la Arista
	 */
	bool esLaMisma( int otroOrigen, int otroDestino );
};

#endif /* GRAFO_H_ */
