#include "ListaVotantes.h"
#include "ArbolAVL.h"
#include "BTree.h"
#include "ArbolBB.h"
using namespace std;
double cargaBB, cargaAVL, cargaBtree;

void cargarEstructuras(PtrT_Votante listaVotantes, Nodo* & arbolAVL, NodoBB* & arbolBB, NodoBtree* & btree) {
	PtrT_Votante votante = listaVotantes;
	time_t inicio, fin;
	inicio = time(NULL);
	while (votante) {
		int cedula = atoi(votante->cedula);
		if (cedula < 102020582)
			Insertar(arbolBB, cedula, votante->codelec, votante->nombre, votante->sexo, votante->fecha, votante->numjun, votante->papellido, votante->sapellido);
		//cout << "1111" << endl;
		votante = votante->PtrSiguiente;
	}
	fin = time(NULL);
	cargaBB = difftime(fin, inicio);
	votante = listaVotantes;
	inicio = time(NULL);
	while (votante) {
		int cedula = atoi(votante->cedula);
		arbolAVL = insertarAVL(arbolAVL, cedula, votante->codelec, votante->nombre, votante->sexo, votante->fecha, votante->numjun, votante->papellido, votante->sapellido);
		votante = votante->PtrSiguiente;
	}
	fin = time(NULL);
	cargaAVL = difftime(fin, inicio);
	votante = listaVotantes;
	inicio = time(NULL);
	while (votante) {
		int cedula = atoi(votante->cedula);
		insertarBTree(cedula, votante->codelec, votante->nombre, votante->sexo, votante->fecha, votante->numjun, votante->papellido, votante->sapellido, btree);
		votante = votante->PtrSiguiente;
	}
	fin = time(NULL);
	cargaBtree = difftime(fin, inicio);
	
}

void listarEstructuras(PtrT_Votante listaVotantes, Nodo*& arbolAVL, NodoBB*& arbolBB, NodoBtree*& btree) {

}



void main() {
	bool realizado = false;
	bool ciclo = true;
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
	//preOrder(ArbolAVL);
	//desplegar(BTree);

	/*char buscado[] = "107490737";
	PtrT_Votante Encontrado = NULL;
	Encontrado = BuscarVotante(ListaV, buscado);
	if (Encontrado != NULL) {
		cout << endl << "Encontre' al Votante!! " << endl << endl;

		cout << "Cédula: " << Encontrado->cedula << endl;
		cout << "Nombre: " << Encontrado->nombre << endl;
		cout << "Primer Apellido: " << Encontrado->papellido << endl;
		cout << "Segundo Apellido: " << Encontrado->sapellido << endl;
		cout << "Sexo: " << Encontrado->sexo << endl;
		cout << "Fecha: " << Encontrado->fecha << endl;
		cout << "Código Electoral:  " << Encontrado->codelec << endl;
		cout << "Número Junta: " << Encontrado->numjun << endl;
	}
	else
		cout << " No se encontro al votante !!! " << endl;
	*/

	/*cout << "Introduzca una cedula a buscar: " << endl;
	int cedBuscar;
	cin >> cedBuscar;

	int pos = 3;
	NodoBB* buscado = Buscar(ArbolBB, cedBuscar);
	Nodo* buscadoAVL = buscarAVL(ArbolAVL, cedBuscar);
	busqueda(cedBuscar, &pos, BTree);
	*/

	/*cout << "Tiempo de carga de arbol binario: ";
	cout << cargaBB << endl;
	cout << "Tiempo de carga de arbol AVL ";
	cout<<cargaAVL << endl;
	cout << "Tiempo de carga de arbol BTree ";
	cout<<cargaBtree << endl;
	*/
	LiberarVotantes(ListaV);

	cout << "Finalizado" << endl;

	system("pause");


}