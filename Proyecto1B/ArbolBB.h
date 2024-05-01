#pragma once

#include "iostream"
#include <stdio.h>


struct NodoBB
{
	int llave;
	char codElec[7];
	char nombre[31];
	char sexo;
	char fecha[9];
	char numjun[6];
	char pApellido[27];
	char sApellido[27];
	NodoBB* HijoIzquierdo;
	NodoBB* HijoDerecho;
};


bool Insertar(NodoBB*& Raiz, int cualllave, char codElec[], char nombre[], char sexo, char fecha[], char numjun[], char pApellido[], char sApellido[])
{
	if (Raiz == NULL)
	{
		Raiz = new(NodoBB);
		Raiz->llave = cualllave;
		for (int nom = 0; nom < 6; nom++) {
			Raiz->codElec[nom] = codElec[nom];
		}
		Raiz->codElec[6] = '\0';
		for (int nom = 0; nom < 8; nom++) {
			Raiz->fecha[nom] = fecha[nom];
		}
		Raiz->fecha[8] = '\0';
		Raiz->sexo = sexo;
		for (int nom = 0; nom < 30; nom++) {
			Raiz->nombre[nom] = nombre[nom];
		}
		Raiz->nombre[30] = '\0';
		for (int nom = 0; nom < 5; nom++) {
			Raiz->numjun[nom] = numjun[nom];
		}
		Raiz->numjun[5] = '\0';
		for (int nom = 0; nom < 26; nom++) {
			Raiz->pApellido[nom] = pApellido[nom];
		}
		Raiz->pApellido[26] = '\0';
		for (int nom = 0; nom < 26; nom++) {
			Raiz->sApellido[nom] = sApellido[nom];
		}
		Raiz->sApellido[26] = '\0';
		Raiz->HijoIzquierdo = NULL;
		Raiz->HijoDerecho = NULL;
		return true;
	}
	else
	{
		if (cualllave == Raiz->llave) return false;
		else
			if (cualllave < Raiz->llave) return Insertar(Raiz->HijoIzquierdo, cualllave, codElec, nombre, sexo, fecha, numjun, pApellido, sApellido);
			else return Insertar(Raiz->HijoDerecho, cualllave, codElec, nombre, sexo, fecha, numjun, pApellido, sApellido);
	}
}



void PodarHojas(NodoBB*& Raiz)
{
	if (Raiz != NULL)
	{
		PodarHojas(Raiz->HijoIzquierdo);
		PodarHojas(Raiz->HijoDerecho);
		printf("Borro : %i \n", Raiz->llave);
		delete(Raiz); Raiz = NULL;
	}
}

NodoBB* Buscar(NodoBB* Raiz, int cualllave)
{
	if (Raiz == NULL)
	{
		return NULL;
	}
	else
	{
		if (cualllave == Raiz->llave) return Raiz;
		else
			if (cualllave < Raiz->llave) return Buscar(Raiz->HijoIzquierdo, cualllave);
			else return Buscar(Raiz->HijoDerecho, cualllave);
	}
}

void preOrdenBBArchivoAux(NodoBB* raiz, ofstream& archivo) {
	if (raiz != NULL)
	{
		archivo << raiz->llave << "	 |	 ";
		archivo << raiz->nombre;
		archivo << raiz->pApellido << endl;
		preOrdenBBArchivoAux(raiz->HijoIzquierdo, archivo);
		preOrdenBBArchivoAux(raiz->HijoDerecho, archivo);
	}
}

void preOrdenBBArchivo(NodoBB* raiz) {
	ofstream archivo;
	archivo.open("Listado BB.txt");
	if (raiz != NULL)
	{
		archivo << raiz->llave << "	 |	 ";
		archivo << raiz->nombre;
		archivo << raiz->pApellido << endl;
		preOrdenBBArchivoAux(raiz->HijoIzquierdo, archivo);
		preOrdenBBArchivoAux(raiz->HijoDerecho, archivo);
	}
}

void PreOrdenRID(NodoBB* Raiz)
{
	if (Raiz != NULL)
	{
		printf("%i  ", Raiz->llave);
		cout << Raiz->nombre << endl;
		PreOrdenRID(Raiz->HijoIzquierdo);
		PreOrdenRID(Raiz->HijoDerecho);
	}
}

void EnOrdenIRD(NodoBB* Raiz)
{
	if (Raiz != NULL)
	{
		EnOrdenIRD(Raiz->HijoIzquierdo);
		printf("%i  ", Raiz->llave);
		cout << Raiz->nombre << endl;
		EnOrdenIRD(Raiz->HijoDerecho);
	}
}
void PosOrdenIDR(NodoBB* Raiz)
{
	if (Raiz != NULL)
	{
		PosOrdenIDR(Raiz->HijoIzquierdo);
		PosOrdenIDR(Raiz->HijoDerecho);
		printf("%i  ", Raiz->llave);
		cout << Raiz->nombre << endl;
	}
}

/*A.	Una función para "contar" los elementos que tiene un árbol binario(Puede usar recorridos)
B.	Una función para comparar 2 árboles: devuelve true si son idénticos o false en caso contrario (Puede usar recorridos)
C.	Una función que "clone" un árbol en otro (Puede usar recorridos)


int contarElementos(NodoBB* Raiz) {
	int resultado = 0;
	if (Raiz != NULL)
	{
		return contarElementos(Raiz->HijoIzquierdo) + contarElementos(Raiz->HijoDerecho) + 1;
	}
	return 0;
}

bool compararArboles(NodoBB* Raiz1, NodoBB* Raiz2) {
	int resultado = false;
	if (Raiz1 != NULL)
	{
		if (Raiz2 != NULL) {
			if (Raiz1->llave == Raiz2->llave) {
				return compararArboles(Raiz1->HijoIzquierdo, Raiz2->HijoIzquierdo) && compararArboles(Raiz1->HijoDerecho, Raiz2->HijoDerecho);
			}

		}
		return false;
	}
	if (Raiz2 == NULL) {
		return true;
	}
}

void clonarArbol(NodoBB* Raiz1, NodoBB*& Raiz2) {
	if (Raiz1 != NULL)
	{
		Insertar(Raiz2, Raiz1->llave);
		clonarArbol(Raiz1->HijoIzquierdo, Raiz2);
		clonarArbol(Raiz1->HijoDerecho, Raiz2);
	}
}
*/