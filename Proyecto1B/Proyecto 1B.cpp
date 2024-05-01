#include "ListaVotantes.h"
#include "ArbolAVL.h"
#include "BTree.h"
#include "ArbolBB.h"
using namespace std;
double cargaBB = 0, cargaAVL = 0, cargaBtree = 0, listaBB = 0, listaAVL = 0, listaBTree = 0, buscaBB = 0, buscaAVL = 0, buscaBtree = 0;

//Función para cargar los arboles AVL, BB y BTree a partir de la lista
void cargarEstructuras(PtrT_Votante listaVotantes, Nodo* & arbolAVL, NodoBB* & arbolBB, NodoBtree* & btree) {
	PtrT_Votante votante = listaVotantes;
	time_t inicio, fin;
	inicio = time(NULL);
	while (votante) {
		int cedula = atoi(votante->cedula);
			Insertar(arbolBB, cedula, votante->codelec, votante->nombre, votante->sexo, votante->fecha, votante->numjun, votante->papellido, votante->sapellido);
		votante = votante->PtrSiguiente;
	}
	fin = time(NULL);
	cargaBB = difftime(fin, inicio);
	cout << "Se tardaron " << cargaBB << " segundos en cargar el arbol Binario de Busqueda" << endl;
	system("pause");
	votante = listaVotantes;
	inicio = time(NULL);
	while (votante) {
		int cedula = atoi(votante->cedula);
		arbolAVL = insertarAVL(arbolAVL, cedula, votante->codelec, votante->nombre, votante->sexo, votante->fecha, votante->numjun, votante->papellido, votante->sapellido);
		votante = votante->PtrSiguiente;
	}
	fin = time(NULL);
	cargaAVL = difftime(fin, inicio);
	cout << "Se tardaron " << cargaAVL << " segundos en cargar el arbol AVL" << endl;
	system("pause");
	votante = listaVotantes;
	inicio = time(NULL);
	while (votante) {
		int cedula = atoi(votante->cedula);
		insertarBTree(cedula, votante->codelec, votante->nombre, votante->sexo, votante->fecha, votante->numjun, votante->papellido, votante->sapellido, btree);
		votante = votante->PtrSiguiente;
	}
	fin = time(NULL);
	cargaBtree = difftime(fin, inicio);
	cout << "Se tardaron " << cargaBtree << " segundos en cargar el arbol BTree" << endl;
	system("pause");
}

//Función que lista los elementos de cada arbol y toma el tiempo
void listarEstructuras(PtrT_Votante listaVotantes, Nodo*& arbolAVL, NodoBB*& arbolBB, NodoBtree*& btree) {
	time_t inicio, fin;
	inicio = time(NULL);
	//preOrder(ArbolAVL);
	fin = time(NULL);
	listaAVL = difftime(fin, inicio);
	system("pause");
	inicio = time(NULL);
	//desplegar(BTree);
	fin = time(NULL);
	listaBTree = difftime(fin, inicio);
	system("pause");
	inicio = time(NULL);
	//PreOrdenRID(arbolBB);
	fin = time(NULL);
	listaBB = difftime(fin, inicio);
	system("pause");
}

//Función que busca un elemento en cada arbol y toma el tiempo
void buscarEstructuras(PtrT_Votante listaVotantes, Nodo*& arbolAVL, NodoBB*& arbolBB, NodoBtree*& btree) {
	time_t inicio, fin;
	cout << "Introduzca una cedula a buscar: " << endl;
		int cedBuscar;
	cin >> cedBuscar;

	int pos = 3;
	inicio = time(NULL);
	NodoBB* buscado = Buscar(arbolBB, cedBuscar);
	fin = time(NULL);
	buscaBB = difftime(fin, inicio);
	inicio = time(NULL);
	Nodo* buscadoAVL = buscarAVL(arbolAVL, cedBuscar);
	fin = time(NULL);
	buscaAVL = difftime(fin, inicio);
	inicio = time(NULL);
	busqueda(cedBuscar, &pos, btree);
	fin = time(NULL);
	buscaBtree = difftime(fin, inicio);
}

//Función que libera los arboles y toma el tiempo
void liberarEstructuras(PtrT_Votante listaVotantes, Nodo*& arbolAVL, NodoBB*& arbolBB, NodoBtree*& btree) {
	time_t inicio, fin;

	LiberarVotantes(listaVotantes);
	//#TODO
}

//Función de reporte general
void reporte() {
	cout << "Reporte de tiempos" << endl;
	cout << "Arbol Binario de Busqueda: ";
	cout << "Carga del arbol: " << cargaBB << endl;
	cout << "Listado del arbol: " << listaBB << endl;
	cout << "Busqueda en el arbol: " << buscaBB << endl;

	cout << endl;
	cout << "Arbol AVL: ";
	cout << "Carga del arbol: " << cargaAVL << endl;
	cout << "Listado del arbol: " << listaAVL << endl;
	cout << "Busqueda en el arbol: " << buscaAVL << endl;

	cout << endl;
	cout << "Arbol BTree: ";
	cout << "Carga del arbol: " << cargaBtree << endl;
	cout << "Listado del arbol: " << listaBTree << endl;
	cout << "Busqueda en el arbol: " << buscaBtree << endl;
}


void main() {
	int opcion = 0;
	PtrT_Votante ListaV;
	Nodo* ArbolAVL = NULL;
	NodoBB* ArbolBB = NULL;
	NodoBtree* BTree = NULL;
	inicializarvotantes(ListaV);
	cout << "Por favor espere mientras se carga el Padron" << endl;
	CargarVotantes(ListaV);
	cargarEstructuras(ListaV, ArbolAVL, ArbolBB, BTree);
	cout << "Se cargaron estructuras" << endl;
	
	LiberarVotantes(ListaV);

	cout << "Finalizado" << endl;

	system("pause");


}