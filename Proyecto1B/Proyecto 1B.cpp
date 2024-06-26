﻿//Proyecto 1B
//Estructuras de Datos
//José Calderón Barquero y José Julián Gómez



#include "ListaVotantes.h"
#include "ArbolAVL.h"
#include "BTree.h"
#include "ArbolBB.h"
using namespace std;
double cargaBB = 0, cargaAVL = 0, cargaBtree = 0, cargaLista = 0, listaBB = 0, listaAVL = 0, listaBTree = 0, listaLista = 0, buscaBB = 0, buscaAVL = 0, buscaBtree = 0, buscaLista = 0, liberaBB = 0, liberaAVL = 0, liberaLista = 0;

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
	cout << "Listando" << endl;
	time_t inicio, fin;
	inicio = time(NULL);
	preOrderAVLArchivo(arbolAVL);
	fin = time(NULL);
	cout << "Listado AVL completado" << endl;
	listaAVL = difftime(fin, inicio);
	inicio = time(NULL);
	desplegarArchivo(btree);
	fin = time(NULL);
	cout << "Listado BTree completado" << endl;
	listaBTree = difftime(fin, inicio);
	inicio = time(NULL);
	preOrdenBBArchivo(arbolBB);
	fin = time(NULL);
	cout << "Listado Arbol Binario de Busqueda completado" << endl;
	listaBB = difftime(fin, inicio);
	inicio = time(NULL);
	listarArchivoVotantes(listaVotantes);
	fin = time(NULL);
	cout << "Listado Lista Votantes completado" << endl;
	listaLista = difftime(fin, inicio);
	cout << "Fin del listado" << endl;
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
	string cedStr = to_string(cedBuscar);
	char* cedChar = &cedStr[0];
	inicio = time(NULL);
	BuscarVotante(listaVotantes, cedChar);
	fin = time(NULL);
	buscaLista = difftime(fin, inicio);

}

//Función que libera los arboles y toma el tiempo
void liberarEstructuras(PtrT_Votante listaVotantes, Nodo*& arbolAVL, NodoBB*& arbolBB, NodoBtree*& btree) {
	cout << "Liberando" << endl;
	time_t inicio, fin;
	inicio = time(NULL);
	PodarHojas(arbolBB);
	fin = time(NULL);
	liberaBB = difftime(fin,inicio);
	inicio = time(NULL);
	liberarAVL(arbolAVL);
	fin = time(NULL);
	liberaAVL = difftime(fin, inicio);
	cout << "Liberados" << endl;
	inicio = time(NULL);
	LiberarVotantes(listaVotantes);
	fin = time(NULL);
	liberaLista = difftime(fin, inicio);
	system("pause");
}

//Función de reporte general
void reporte() {
	cout << "\nReporte de tiempos" << endl;
	cout << "Arbol Binario de Busqueda: ";
	cout << "Carga del arbol: " << cargaBB << endl;
	cout << "Listado del arbol: " << listaBB << endl;
	cout << "Busqueda en el arbol: " << buscaBB << endl;
	cout << "Borrado del arbol: " << liberaBB << endl;

	cout << endl;
	cout << "Arbol AVL: ";
	cout << "Carga del arbol: " << cargaAVL << endl;
	cout << "Listado del arbol: " << listaAVL << endl;
	cout << "Busqueda en el arbol: " << buscaAVL << endl;
	cout << "Borrado del arbol: " << liberaAVL << endl;

	cout << endl;
	cout << "Arbol BTree: ";
	cout << "Carga del arbol: " << cargaBtree << endl;
	cout << "Listado del arbol: " << listaBTree << endl;
	cout << "Busqueda en el arbol: " << buscaBtree << endl;

	cout << endl;
	cout << "Lista enlazada: ";
	cout << "Carga de la lista: " << cargaLista << endl;
	cout << "Listado de la lista: " << listaLista << endl;
	cout << "Busqueda en la lista: " << buscaLista << endl;
	cout << "Borrado de la lista: " << liberaLista << endl;
}

void general(PtrT_Votante listaVotantes, Nodo*& arbolAVL, NodoBB*& arbolBB, NodoBtree*& btree) {
	cout << "Modo general iniciado" << endl;
	cargarEstructuras(listaVotantes, arbolAVL, arbolBB, btree);
	listarEstructuras(listaVotantes, arbolAVL, arbolBB, btree);
	buscarEstructuras(listaVotantes, arbolAVL, arbolBB, btree);
	liberarEstructuras(listaVotantes, arbolAVL, arbolBB, btree);
	reporte();
	cout << "Modo general finalizado" << endl;
}

void main() {
	int opcion = 0;
	PtrT_Votante ListaV;
	Nodo* ArbolAVL = NULL;
	NodoBB* ArbolBB = NULL;
	NodoBtree* BTree = NULL;
	inicializarvotantes(ListaV);
	cout << "Por favor espere mientras se carga el Padron" << endl;
	time_t inicio, fin;
	inicio = time(NULL);
	CargarVotantes(ListaV);
	fin = time(NULL);
	cargaLista = difftime(fin, inicio);

	while (opcion != 7) {
		cout << "\nMenu:\n";
		cout << "1. Cargar datos\n";
		cout << "2. Listar datos\n";
		cout << "3. Buscar\n";
		cout << "4. Liberar datos\n";
		cout << "5. Reporte\n";
		cout << "6. Modo general\n";
		cout << "7. Salir\n";
		cout << "Seleccione una opcion: ";
		cin >> opcion;

		switch (opcion) {
		case 1:
			cargarEstructuras(ListaV, ArbolAVL, ArbolBB, BTree);
			break;
		case 2:
			listarEstructuras(ListaV, ArbolAVL, ArbolBB, BTree);
			break;
		case 3:
			buscarEstructuras(ListaV, ArbolAVL, ArbolBB, BTree);
			break;
		case 4:
			liberarEstructuras(ListaV, ArbolAVL, ArbolBB, BTree);
			break;
		case 5:
			reporte();
			break;
		case 6:
			general(ListaV, ArbolAVL, ArbolBB, BTree);
			break;
		case 7:
			cout << "Saliendo del programa...\n";
			break;
		default:
			cout << "Opcion no valida. Intente de nuevo.\n";
		}
	}

	cout << "\nFinalizado" << endl;

	system("pause");


}