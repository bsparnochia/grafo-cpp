
#include <iostream>
#include "Grafo.h"

using namespace std;

int main(){

	try{
		/* Creación del Grafo */
		Grafo* mapa = new Grafo();
		int A = 2;
		int B = 3;
		int C = 5;

		/* Inserción de vértices */
		mapa->agregarVertice(A);
		mapa->agregarVertice(B);

		/* mostrar vértices del Grafo por pantalla */
		mapa->mostrarVertices();

		/* conexión de vértices */
		mapa->agregarArista(A, B);
		mapa->agregarArista(B, A);

		/* Existencias de vertices */
		if ( mapa->existeVertice(A) ){
			cout<<"\nEl vertice " << A << " existe en el grafo" <<endl;
		}
		if ( !mapa->existeVertice(C) ){
			cout<<"El vertice " << C << " no existe en el grafo" <<endl;
		}

		/* Existencias de Aristas*/
		if ( mapa->existeArista(A, B) ){
			cout<<"Existe la arista entre A Y B" <<endl;
		}
		if ( !mapa->existeArista(C, B) ){
			cout<<"No existe la arista entre C Y B"<<endl;
		}

		mapa->mostrarAristasDelVertice(A);

		mapa->borrarArista(A, B);
		mapa->borrarArista(B, A);

		mapa->mostrarAristasDelVertice(A);

		delete mapa;

	}catch( std::string& error ){
		cout<<error<<endl;
	}
	return 0;
}
