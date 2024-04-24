#pragma once
#include<stdio.h>
#include<stdlib.h>


struct Nodo
{
	int llave;
	char codElec[7];
	char nombre[31];
	char sexo;
	char fecha[9];
	char numjun[6];
	char pApellido[27];
	char sApellido[27];

	struct Nodo* izq;
	struct Nodo* derecha;
	int altura;
};

//obtiene el maximo de dos numeros
//int max(int a, int b);

//obtiene la altura del arbol
int altura(struct Nodo* N)
{
	if (N == NULL)
		return 0;
	return N->altura;
}

struct Nodo* nuevoNodo(int llave1, char codElec[], char nombre[], char sexo, char fecha[], char numjun[], char pApellido[], char sApellido[])
{
	struct Nodo* Nodo = (struct Nodo*)
		malloc(sizeof(struct Nodo));
	Nodo->llave = llave1;
	for (int nom = 0; nom < 6; nom++) {
		Nodo->codElec[nom] = codElec[nom];
	}
	Nodo->codElec[6] = '\0';
	for (int nom = 0; nom < 8; nom++) {
		Nodo->fecha[nom] = fecha[nom];
	}
	Nodo->fecha[8] = '\0';
	Nodo->sexo = sexo;
	for (int nom = 0; nom < 30; nom++) {
		Nodo->nombre[nom] = nombre[nom];
	}
	Nodo->nombre[30] = '\0';
	for (int nom = 0; nom < 5; nom++) {
		Nodo->numjun[nom] = numjun[nom];
	}
	Nodo->numjun[5] = '\0';
	for (int nom = 0; nom < 26; nom++) {
		Nodo->pApellido[nom] = pApellido[nom];
	}
	Nodo->pApellido[26] = '\0';
	for (int nom = 0; nom < 26; nom++) {
		Nodo->sApellido[nom] = sApellido[nom];
	}
	Nodo->sApellido[26] = '\0';
	Nodo->izq = NULL;
	Nodo->derecha = NULL;
	Nodo->altura = 1;  //nuevonodo es agregado como hoja
	return(Nodo);
}


struct Nodo* RotarDerecha(struct Nodo* y)
{
	struct Nodo* x = y->izq;
	struct Nodo* T2 = x->derecha;

	// hace rotacion
	x->derecha = y;
	y->izq = T2;

	// actualiza alturas
	y->altura = max(altura(y->izq), altura(y->derecha)) + 1;
	x->altura = max(altura(x->izq), altura(x->derecha)) + 1;

	// retorna nueva raiz
	return x;
}


struct Nodo* RotarIzquierda(struct Nodo* x)
{
	struct Nodo* y = x->derecha;
	struct Nodo* T2 = y->izq;

	// hace rotacion
	y->izq = x;
	x->derecha = T2;

	//  actualiza alturas
	x->altura = max(altura(x->izq), altura(x->derecha)) + 1;
	y->altura = max(altura(y->izq), altura(y->derecha)) + 1;

	// retorna nueva raiz
	return y;
}

// obtiene balance
int obtenerbalance(struct Nodo* N)
{
	if (N == NULL)
		return 0;
	return altura(N->izq) - altura(N->derecha);
}


struct Nodo* insertarAVL(struct Nodo* & Nodo, int llave, char codElec[], char nombre[], char sexo, char fecha[], char numjun[], char pApellido[], char sApellido[])
{
	/* 1. Insercion normal */
	if (Nodo == NULL)
		return(nuevoNodo(llave, codElec, nombre, sexo, fecha, numjun, pApellido, sApellido));

	if (llave < Nodo->llave)
		Nodo->izq = insertarAVL(Nodo->izq, llave, codElec, nombre, sexo, fecha, numjun, pApellido, sApellido);
	else if (llave > Nodo->llave)
		Nodo->derecha = insertarAVL(Nodo->derecha, llave, codElec, nombre, sexo, fecha, numjun, pApellido, sApellido);
	else // no se permiten llaves iguales
		return Nodo;

	/* 2. actualiza altura */
	Nodo->altura = 1 + max(altura(Nodo->izq),
		altura(Nodo->derecha));

	/* 3. verifica si el arbol se desbalancea */
	int balance = obtenerbalance(Nodo);

	// 4 casos para un arbol desbalanceado

	// izq izq 
	if (balance > 1 && llave < Nodo->izq->llave)
		return RotarDerecha(Nodo);

	// derecha derecha 
	if (balance < -1 && llave > Nodo->derecha->llave)
		return RotarIzquierda(Nodo);

	// izq derecha 
	if (balance > 1 && llave > Nodo->izq->llave)
	{
		Nodo->izq = RotarIzquierda(Nodo->izq);
		return RotarDerecha(Nodo);
	}

	// derecha izq 
	if (balance < -1 && llave < Nodo->derecha->llave)
	{
		Nodo->derecha = RotarDerecha(Nodo->derecha);
		return RotarIzquierda(Nodo);
	}


	return Nodo;
}

//recorido
void preOrder(struct Nodo* root)
{
	if (root != NULL)
	{
		printf("%d ", root->llave);
		cout << root->nombre << endl;
		preOrder(root->izq);
		preOrder(root->derecha);
	}
}

Nodo* buscarAVL(struct Nodo* root, int buscar)
{
	if (root == NULL)
		return NULL;
	if (buscar < root->llave)
		return buscarAVL(root->izq, buscar);
	else if (buscar > root->llave)
		return buscarAVL(root->derecha, buscar);
	else 
		return root;
}

void liberarAVL(struct Nodo* rpot) {

}