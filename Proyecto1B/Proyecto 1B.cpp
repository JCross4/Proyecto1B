#include "ListaVotantes.h"
#include "ArbolAVL.h"
#include "BTree.h"
using namespace std;


void main() {
	bool realizado = false;
	bool ciclo = true;
	int opcion = 0;
	PtrT_Votante ListaV;
	inicializarvotantes(ListaV);
	cout << "Por favor espere mientras se carga el Padron" << endl;
	CargarVotantes(ListaV);
	char buscado[] = "107490737";
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
	LiberarVotantes(ListaV);

	cout << "Finalizado" << endl;

	system("pause");


}