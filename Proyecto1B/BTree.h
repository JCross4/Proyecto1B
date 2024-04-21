#pragma once
#include <iostream>
#include <conio.h>

using namespace std;

#define MAX 4
#define MIN 2

struct NodoBtree {
	int val[MAX + 1], count;
	char codElec[MAX + 1][7];
	char nombre[MAX + 1][31];
	char sexo[MAX + 1];
	char fecha[MAX + 1][9];
	char numjun[MAX + 1][6];
	char pApellido[MAX + 1][27];
	char sApellido[MAX + 1][27];
	NodoBtree* link[MAX + 1];
};


//Crear nodo 
NodoBtree* crearnodo(int val, char codElec[], char nombre[], char sexo, char fecha[], char numjun[], char pApellido[], char sApellido[], NodoBtree* hijo, NodoBtree* raiz) {
	NodoBtree* NuevoNodo = new NodoBtree;
	NuevoNodo->val[1] = val;
	for (int nom = 0; nom < 6; nom++) {
		NuevoNodo->codElec[1][nom] = codElec[nom];
	}
	NuevoNodo->codElec[1][6] = '\0';
	for (int nom = 0; nom < 8; nom++) {
		NuevoNodo->fecha[1][nom] = fecha[nom];
	}
	NuevoNodo->fecha[1][8] = '\0';
	for (int nom = 0; nom < 30; nom++) {
		NuevoNodo->nombre[1][nom] = nombre[nom];
	}
	NuevoNodo->nombre[1][30] = '\0';
	NuevoNodo->sexo[1] = sexo;
	for (int nom = 0; nom < 5; nom++) {
		NuevoNodo->numjun[1][nom] = numjun[nom];
	}
	NuevoNodo->numjun[1][5] = '\0';
	for (int nom = 0; nom < 26; nom++) {
		NuevoNodo->pApellido[1][nom] = pApellido[nom];
	}
	NuevoNodo->pApellido[1][26] = '\0';
	for (int nom = 0; nom < 26; nom++) {
		NuevoNodo->sApellido[1][nom] = sApellido[nom];
	}
	NuevoNodo->sApellido[1][26] = '\0';
	NuevoNodo->count = 1;
	NuevoNodo->link[0] = raiz;
	NuevoNodo->link[1] = hijo;
	return NuevoNodo;
}

//coloca el nodo en la posicion adecuada, de acuerdo a su valor
void Colocarnodo(int val, char codelec[], char nombre[], char sexo, char fecha[], char numjun[], char pApellido[], char sApellido[], int pos, NodoBtree* node, NodoBtree* hijo) {
	int j = node->count;
	while (j > pos) {
		node->val[j + 1] = node->val[j];
		for (int nom = 0; nom < 6; nom++) {
			node->codElec[j+1][nom] = node->codElec[j][nom];
		}
		node->codElec[j+1][6] = '\0';
		for (int nom = 0; nom < 8; nom++) {
			node->fecha[j+1][nom] = node->fecha[j][nom];
		}
		node->fecha[j + 1][8] = '\0';
		for (int nom = 0; nom < 30; nom++) {
			node->nombre[j + 1][nom] = node->nombre[j][nom];
		}
		node->nombre[j + 1][30] = '\0';
		node->sexo[j + 1] = node->sexo[j];
		for (int nom = 0; nom < 5; nom++) {
			node->numjun[j + 1][nom] = node->numjun[j][nom];
		}
		node->numjun[j + 1][5] = '\0';
		for (int nom = 0; nom < 26; nom++) {
			node->pApellido[j + 1][nom] = node->pApellido[j][nom];
		}
		node->pApellido[j + 1][26] = '\0';
		for (int nom = 0; nom < 26; nom++) {
			node->sApellido[j + 1][nom] = node->sApellido[j][nom];
		}
		node->sApellido[j + 1][26] = '\0';
		node->link[j + 1] = node->link[j];
		j--;
	}
	node->val[j + 1] = val;
	for (int nom = 0; nom < 6; nom++) {
		node->codElec[j + 1][nom] = codelec[nom];
	}
	node->codElec[j + 1][6] = '\0';
	for (int nom = 0; nom < 8; nom++) {
		node->fecha[j + 1][nom] = fecha[nom];
	}
	node->fecha[j + 1][8] = '\0';
	for (int nom = 0; nom < 30; nom++) {
		node->nombre[j + 1][nom] = nombre[nom];
	}
	node->nombre[j + 1][30] = '\0';
	node->sexo[j + 1] = sexo;
	for (int nom = 0; nom < 5; nom++) {
		node->numjun[j + 1][nom] = numjun[nom];
	}
	node->numjun[j + 1][5] = '\0';
	for (int nom = 0; nom < 26; nom++) {
		node->pApellido[j + 1][nom] = pApellido[nom];
	}
	node->pApellido[j + 1][26] = '\0';
	for (int nom = 0; nom < 26; nom++) {
		node->sApellido[j + 1][nom] = sApellido[nom];
	}
	node->sApellido[j + 1][26] = '\0';
	node->link[j + 1] = hijo;
	node->count++;
}


void PartirNodo(int val, char codelec[], char nombre[], char sexo, char fecha[], char numjun[], char pApellido[], char sApellido[], int* pval, int pos, NodoBtree* node, NodoBtree* hijo, NodoBtree** NuevoNodo) {
	int median, j;

	if (pos > MIN)
		median = MIN + 1;
	else
		median = MIN;

	*NuevoNodo = new NodoBtree;
	j = median + 1;
	while (j <= MAX) {
		(*NuevoNodo)->val[j - median] = node->val[j];
		for (int nom = 0; nom < 6; nom++) {
			(*NuevoNodo)->codElec[j - median][nom] = node->codElec[j][nom];
		}
		(*NuevoNodo)->codElec[j - median][6] = '\0';
		for (int nom = 0; nom < 8; nom++) {
			(*NuevoNodo)->fecha[j - median][nom] = node->fecha[j][nom];
		}
		(*NuevoNodo)->fecha[j - median][8] = '\0';
		for (int nom = 0; nom < 30; nom++) {
			(*NuevoNodo)->nombre[j - median][nom] = node->nombre[j][nom];
		}
		(*NuevoNodo)->nombre[j - median][30] = '\0';
		(*NuevoNodo)->sexo[j - median] = node->sexo[j];
		for (int nom = 0; nom < 5; nom++) {
			(*NuevoNodo)->numjun[j - median][nom] = node->numjun[j][nom];
		}
		(*NuevoNodo)->numjun[j - median][5] = '\0';
		for (int nom = 0; nom < 26; nom++) {
			(*NuevoNodo)->pApellido[j - median][nom] = node->pApellido[j][nom];
		}
		(*NuevoNodo)->pApellido[j - median][26] = '\0';
		for (int nom = 0; nom < 26; nom++) {
			(*NuevoNodo)->sApellido[j - median][nom] = node->sApellido[j][nom];
		}
		(*NuevoNodo)->sApellido[j - median][26] = '\0';
		(*NuevoNodo)->link[j - median] = node->link[j];
		j++;
	}
	node->count = median;
	(*NuevoNodo)->count = MAX - median;

	if (pos <= MIN) {
		Colocarnodo(val, codelec, nombre, sexo, fecha, numjun, pApellido, sApellido, pos, node, hijo);
	}
	else {
		Colocarnodo(val, codelec, nombre, sexo, fecha, numjun, pApellido, sApellido, pos - median, *NuevoNodo, hijo);
	}
	*pval = node->val[node->count];
	(*NuevoNodo)->link[0] = node->link[node->count];
	node->count--;
}

//colocar valor
int SetValorNodo(int val, char codelec[], char nombre[], char sexo, char fecha[], char numjun[], char pApellido[], char sApellido[], int* pval, char icodelec[], char inombre[], char isexo, char ifecha[], char inumjun[], char ipApellido[], char isApellido[], NodoBtree* node, NodoBtree** hijo) {

	int pos;
	if (!node) {
		*pval = val;
		for (int nom = 0; nom < 6; nom++) {
			icodelec[nom] = codelec[nom];
		}
		icodelec[6] = '\0';
		for (int nom = 0; nom < 8; nom++) {
			ifecha[nom] = fecha[nom];
		}
		ifecha[8] = '\0';
		for (int nom = 0; nom < 30; nom++) {
			inombre[nom] = nombre[nom];
		}
		inombre[30] = '\0';
		isexo = sexo;
		for (int nom = 0; nom < 5; nom++) {
			inumjun[nom] = numjun[nom];
		}
		inumjun[5] = '\0';
		for (int nom = 0; nom < 26; nom++) {
			ipApellido[nom] = ipApellido[nom];
		}
		ipApellido[26] = '\0';
		for (int nom = 0; nom < 26; nom++) {
			isApellido[nom] = isApellido[nom];
		}
		isApellido[26] = '\0';
		*hijo = NULL;
		return 1;
	}

	if (val < node->val[1]) {
		pos = 0;
	}
	else {
		for (pos = node->count;
			(val < node->val[pos] && pos > 1); pos--);
		if (val == node->val[pos]) {
			cout << "No está permitido nodos duplicados\n";
			return 0;
		}
	}
	if (SetValorNodo(val, codelec, nombre, sexo, fecha, numjun, pApellido, sApellido, pval, icodelec, inombre, isexo, ifecha, inumjun, ipApellido, isApellido, node->link[pos], hijo)) {
		if (node->count < MAX) {
			Colocarnodo(*pval, icodelec, inombre, isexo, ifecha, inumjun, ipApellido, isApellido, pos, node, *hijo);
		}
		else {
			PartirNodo(*pval, icodelec, inombre, isexo, ifecha, inumjun, ipApellido, isApellido, pval, pos, node, *hijo, hijo);
			return 1;
		}
	}
	return 0;
}

//inserta valores en el btree
void insertarBTree(int val, char codelec[], char nombre[], char sexo, char fecha[], char numjun[], char pApellido[], char sApellido[], NodoBtree* & raiz) {
	int flag, ival;
	char icodelec[7], inombre[31], ifecha[9], inumjun[6], ipApellido[27], isApellido[27];
	char isexo = NULL;
	NodoBtree* hijo;

	flag = SetValorNodo(val, codelec, nombre, sexo, fecha, numjun, pApellido, sApellido, &ival, icodelec, inombre, isexo, ifecha, inumjun, ipApellido, isApellido, raiz, &hijo);
	if (flag)
		raiz = crearnodo(ival, icodelec, inombre, isexo, ifecha, inumjun, ipApellido, isApellido, hijo, raiz);
}

//copia el sucesor del nodo que será borrado
void copySuccessor(NodoBtree* minodo, int pos) {
	NodoBtree* dummy;
	dummy = minodo->link[pos];

	for (; dummy->link[0] != NULL;)
		dummy = dummy->link[0];
	minodo->val[pos] = dummy->val[1];
	for (int nom = 0; nom < 6; nom++) {
		minodo->codElec[pos][nom] = dummy->codElec[1][nom];
	}
	minodo->codElec[pos][6] = '\0';
	for (int nom = 0; nom < 8; nom++) {
		minodo->fecha[pos][nom] = dummy->fecha[1][nom];
	}
	minodo->fecha[pos][8] = '\0';
	for (int nom = 0; nom < 30; nom++) {
		minodo->nombre[pos][nom] = dummy->nombre[1][nom];
	}
	minodo->nombre[pos][30] = '\0';
	minodo->sexo[pos] = dummy->sexo[1];
	for (int nom = 0; nom < 5; nom++) {
		minodo->numjun[pos][nom] = dummy->numjun[1][nom];
	}
	minodo->numjun[pos][5] = '\0';
	for (int nom = 0; nom < 26; nom++) {
		minodo->pApellido[pos][nom] = dummy->pApellido[1][nom];
	}
	minodo->pApellido[pos][26] = '\0';
	for (int nom = 0; nom < 26; nom++) {
		minodo->sApellido[pos][nom] = dummy->sApellido[1][nom];
	}
	minodo->sApellido[pos][26] = '\0';
}

//remueve un valor de un nodo y reacomoda el arbol
void removeVal(NodoBtree* minodo, int pos) {
	int i = pos + 1;
	while (i <= minodo->count) {
		minodo->val[i - 1] = minodo->val[i];
		for (int nom = 0; nom < 6; nom++) {
			minodo->codElec[i - 1][nom] = minodo->codElec[i][nom];
		}
		minodo->codElec[i - 1][6] = '\0';
		for (int nom = 0; nom < 8; nom++) {
			minodo->fecha[i - 1][nom] = minodo->fecha[i][nom];
		}
		minodo->fecha[i - 1][8] = '\0';
		for (int nom = 0; nom < 30; nom++) {
			minodo->nombre[i - 1][nom] = minodo->nombre[i][nom];
		}
		minodo->nombre[i - 1][30] = '\0';
		minodo->sexo[i - 1] = minodo->sexo[i];
		for (int nom = 0; nom < 5; nom++) {
			minodo->numjun[i - 1][nom] = minodo->numjun[i][nom];
		}
		minodo->numjun[i - 1][5] = '\0';
		for (int nom = 0; nom < 26; nom++) {
			minodo->pApellido[i - 1][nom] = minodo->pApellido[i][nom];
		}
		minodo->pApellido[i - 1][26] = '\0';
		for (int nom = 0; nom < 26; nom++) {
			minodo->sApellido[i - 1][nom] = minodo->sApellido[i][nom];
		}
		minodo->sApellido[i - 1][26] = '\0';
		minodo->link[i - 1] = minodo->link[i];
		i++;
	}
	minodo->count--;
}

//shift a la derecha
void doRightShift(NodoBtree* minodo, int pos) {
	NodoBtree* x = minodo->link[pos];
	int j = x->count;

	while (j > 0) {
		x->val[j + 1] = x->val[j];
		for (int nom = 0; nom < 6; nom++) {
			x->codElec[j + 1][nom] = x->codElec[j][nom];
		}
		x->codElec[j + 1][6] = '\0';
		for (int nom = 0; nom < 8; nom++) {
			x->fecha[j + 1][nom] = x->fecha[j][nom];
		}
		x->fecha[j + 1][8] = '\0';
		for (int nom = 0; nom < 30; nom++) {
			x->nombre[j + 1][nom] = x->nombre[j][nom];
		}
		x->nombre[j + 1][30] = '\0';
		x->sexo[j + 1] = x->sexo[j];
		for (int nom = 0; nom < 5; nom++) {
			x->numjun[j + 1][nom] = x->numjun[j][nom];
		}
		x->numjun[j + 1][5] = '\0';
		for (int nom = 0; nom < 26; nom++) {
			x->pApellido[j + 1][nom] = x->pApellido[j][nom];
		}
		x->pApellido[j + 1][26] = '\0';
		for (int nom = 0; nom < 26; nom++) {
			x->sApellido[j + 1][nom] = x->sApellido[j][nom];
		}
		x->sApellido[j + 1][26] = '\0';
		x->link[j + 1] = x->link[j];
	}
	x->val[1] = minodo->val[pos];
	for (int nom = 0; nom < 6; nom++) {
		x->codElec[1][nom] = minodo->codElec[pos][nom];
	}
	x->codElec[1][6] = '\0';
	for (int nom = 0; nom < 8; nom++) {
		x->fecha[1][nom] = minodo->fecha[pos][nom];
	}
	x->fecha[1][8] = '\0';
	for (int nom = 0; nom < 30; nom++) {
		x->nombre[1][nom] = minodo->nombre[pos][nom];
	}
	x->nombre[1][30] = '\0';
	x->sexo[1] = x->sexo[pos];
	for (int nom = 0; nom < 5; nom++) {
		x->numjun[1][nom] = minodo->numjun[pos][nom];
	}
	x->numjun[1][5] = '\0';
	for (int nom = 0; nom < 26; nom++) {
		x->pApellido[1][nom] = minodo->pApellido[pos][nom];
	}
	x->pApellido[1][26] = '\0';
	for (int nom = 0; nom < 26; nom++) {
		x->sApellido[1][nom] = minodo->sApellido[pos][nom];
	}
	x->sApellido[1][26] = '\0';
	x->link[1] = x->link[0];
	x->count++;

	x = minodo->link[pos - 1];
	minodo->val[pos] = x->val[x->count];
	for (int nom = 0; nom < 6; nom++) {
		minodo->codElec[pos][nom] = x->codElec[x->count][nom];
	}
	minodo->codElec[pos][6] = '\0';
	for (int nom = 0; nom < 8; nom++) {
		minodo->fecha[pos][nom] = x->fecha[x->count][nom];
	}
	minodo->fecha[pos][8] = '\0';
	for (int nom = 0; nom < 30; nom++) {
		minodo->nombre[pos][nom] = x->nombre[x->count][nom];
	}
	minodo->nombre[pos][30] = '\0';
	minodo->sexo[pos] = x->sexo[x->count];
	for (int nom = 0; nom < 5; nom++) {
		minodo->numjun[pos][nom] = x->numjun[x->count][nom];
	}
	minodo->numjun[pos][5] = '\0';
	for (int nom = 0; nom < 26; nom++) {
		minodo->pApellido[pos][nom] = x->pApellido[x->count][nom];
	}
	minodo->pApellido[pos][26] = '\0';
	for (int nom = 0; nom < 26; nom++) {
		minodo->sApellido[pos][nom] = x->sApellido[x->count][nom];
	}
	minodo->sApellido[pos][26] = '\0';
	minodo->link[pos] = x->link[x->count];
	x->count--;
	return;
}

//shift a la izquierda
void doLeftShift(NodoBtree* minodo, int pos) {
	int j = 1;
	NodoBtree* x = minodo->link[pos - 1];

	x->count++;
	x->val[x->count] = minodo->val[pos];
	for (int nom = 0; nom < 6; nom++) {
		x->codElec[x->count][nom] = minodo->codElec[pos][nom];
	}
	x->codElec[x->count][6] = '\0';
	for (int nom = 0; nom < 8; nom++) {
		x->fecha[x->count][nom] = minodo->fecha[pos][nom];
	}
	x->fecha[x->count][8] = '\0';
	for (int nom = 0; nom < 30; nom++) {
		x->nombre[x->count][nom] = minodo->nombre[pos][nom];
	}
	x->nombre[x->count][30] = '\0';
	x->sexo[x->count] = minodo->sexo[pos];
	for (int nom = 0; nom < 5; nom++) {
		x->numjun[x->count][nom] = minodo->numjun[pos][nom];
	}
	x->numjun[x->count][5] = '\0';
	for (int nom = 0; nom < 26; nom++) {
		x->pApellido[x->count][nom] = minodo->pApellido[pos][nom];
	}
	x->pApellido[x->count][26] = '\0';
	for (int nom = 0; nom < 26; nom++) {
		x->sApellido[x->count][nom] = minodo->sApellido[pos][nom];
	}
	x->sApellido[pos][26] = '\0';
	x->link[x->count] = minodo->link[pos]->link[0];

	x = minodo->link[pos];
	minodo->val[pos] = x->val[1];
	for (int nom = 0; nom < 6; nom++) {
		minodo->codElec[pos][nom] = x->codElec[1][nom];
	}
	minodo->codElec[pos][6] = '\0';
	for (int nom = 0; nom < 8; nom++) {
		minodo->fecha[pos][nom] = x->fecha[1][nom];
	}
	minodo->fecha[pos][8] = '\0';
	for (int nom = 0; nom < 30; nom++) {
		minodo->nombre[pos][nom] = x->nombre[1][nom];
	}
	minodo->nombre[pos][30] = '\0';
	minodo->sexo[pos] = x->sexo[1];
	for (int nom = 0; nom < 5; nom++) {
		minodo->numjun[pos][nom] = x->numjun[1][nom];
	}
	minodo->numjun[pos][5] = '\0';
	for (int nom = 0; nom < 26; nom++) {
		minodo->pApellido[pos][nom] = x->pApellido[1][nom];
	}
	minodo->pApellido[pos][26] = '\0';
	for (int nom = 0; nom < 26; nom++) {
		minodo->sApellido[pos][nom] = x->sApellido[1][nom];
	}
	minodo->sApellido[pos][26] = '\0';
	x->link[0] = x->link[1];
	x->count--;

	while (j <= x->count) {
		x->val[j] = x->val[j + 1];
		for (int nom = 0; nom < 6; nom++) {
			x->codElec[j][nom] = x->codElec[j+1][nom];
		}
		x->codElec[j][6] = '\0';
		for (int nom = 0; nom < 8; nom++) {
			x->fecha[j][nom] = x->fecha[j + 1][nom];
		}
		x->fecha[j][8] = '\0';
		for (int nom = 0; nom < 30; nom++) {
			x->nombre[j][nom] = x->nombre[j + 1][nom];
		}
		x->nombre[j][30] = '\0';
		x->sexo[j] = x->sexo[j];
		for (int nom = 0; nom < 5; nom++) {
			x->numjun[j][nom] = x->numjun[j + 1][nom];
		}
		x->numjun[j][5] = '\0';
		for (int nom = 0; nom < 26; nom++) {
			x->pApellido[j][nom] = x->pApellido[j + 1][nom];
		}
		x->pApellido[j][26] = '\0';
		for (int nom = 0; nom < 26; nom++) {
			x->sApellido[j][nom] = x->sApellido[j + 1][nom];
		}
		x->sApellido[j][26] = '\0';
		x->link[j] = x->link[j + 1];
		j++;
	}
	return;
}

//Fusionar nodos
void UnirNodos(NodoBtree* minodo, int pos) {
	int j = 1;
	NodoBtree* x1 = minodo->link[pos], * x2 = minodo->link[pos - 1];

	x2->count++;
	x2->val[x2->count] = minodo->val[pos];
	for (int nom = 0; nom < 6; nom++) {
		x2->codElec[x2->count][nom] = minodo->codElec[pos][nom];
	}
	x2->codElec[x2->count][6] = '\0';
	for (int nom = 0; nom < 8; nom++) {
		x2->fecha[x2->count][nom] = minodo->fecha[pos][nom];
	}
	x2->fecha[x2->count][8] = '\0';
	for (int nom = 0; nom < 30; nom++) {
		x2->nombre[x2->count][nom] = minodo->nombre[pos][nom];
	}
	x2->nombre[x2->count][30] = '\0';
	x2->sexo[x2->count] = minodo->sexo[pos];
	for (int nom = 0; nom < 5; nom++) {
		x2->numjun[x2->count][nom] = minodo->numjun[pos][nom];
	}
	x2->numjun[x2->count][5] = '\0';
	for (int nom = 0; nom < 26; nom++) {
		x2->pApellido[x2->count][nom] = minodo->pApellido[pos][nom];
	}
	x2->pApellido[x2->count][26] = '\0';
	for (int nom = 0; nom < 26; nom++) {
		x2->sApellido[x2->count][nom] = minodo->sApellido[pos][nom];
	}
	x2->sApellido[pos][26] = '\0';
	x2->link[x2->count] = minodo->link[0];

	while (j <= x1->count) {
		x2->count++;
		x2->val[x2->count] = x1->val[j];
		for (int nom = 0; nom < 6; nom++) {
			x2->codElec[x2->count][nom] = x1->codElec[j][nom];
		}
		x2->codElec[x2->count][6] = '\0';
		for (int nom = 0; nom < 8; nom++) {
			x2->fecha[x2->count][nom] = x1->fecha[j][nom];
		}
		x2->fecha[x2->count][8] = '\0';
		for (int nom = 0; nom < 30; nom++) {
			x2->nombre[x2->count][nom] = x1->nombre[j][nom];
		}
		x2->nombre[x2->count][30] = '\0';
		x2->sexo[x2->count] = x1->sexo[j];
		for (int nom = 0; nom < 5; nom++) {
			x2->numjun[x2->count][nom] = x1->numjun[j][nom];
		}
		x2->numjun[x2->count][5] = '\0';
		for (int nom = 0; nom < 26; nom++) {
			x2->pApellido[x2->count][nom] = x1->pApellido[j][nom];
		}
		x2->pApellido[x2->count][26] = '\0';
		for (int nom = 0; nom < 26; nom++) {
			x2->sApellido[x2->count][nom] = x1->sApellido[j][nom];
		}
		x2->sApellido[pos][26] = '\0';
		x2->link[x2->count] = x1->link[j];
		j++;
	}

	j = pos;
	while (j < minodo->count) {
		minodo->val[j] = minodo->val[j + 1];
		for (int nom = 0; nom < 6; nom++) {
			minodo->codElec[j][nom] = minodo->codElec[j+1][nom];
		}
		minodo->codElec[j][6] = '\0';
		for (int nom = 0; nom < 8; nom++) {
			minodo->fecha[j][nom] = minodo->fecha[j + 1][nom];
		}
		minodo->fecha[j][8] = '\0';
		for (int nom = 0; nom < 30; nom++) {
			minodo->nombre[j][nom] = minodo->nombre[j + 1][nom];
		}
		minodo->nombre[j][30] = '\0';
		minodo->sexo[j] = minodo->sexo[j + 1];
		for (int nom = 0; nom < 5; nom++) {
			minodo->numjun[j][nom] = minodo->numjun[j + 1][nom];
		}
		minodo->numjun[j][5] = '\0';
		for (int nom = 0; nom < 26; nom++) {
			minodo->pApellido[j][nom] = minodo->pApellido[j + 1][nom];
		}
		minodo->pApellido[j][26] = '\0';
		for (int nom = 0; nom < 26; nom++) {
			minodo->sApellido[j][nom] = minodo->sApellido[j + 1][nom];
		}
		minodo->sApellido[j][26] = '\0';
		minodo->link[j] = minodo->link[j + 1];
		j++;
	}
	minodo->count--;
	free(x1);
}

//Ajusta el nodo dado
void AjustarNodo(NodoBtree* minodo, int pos) {
	if (!pos) {
		if (minodo->link[1]->count > MIN) {
			doLeftShift(minodo, 1);
		}
		else {
			UnirNodos(minodo, 1);
		}
	}
	else {
		if (minodo->count != pos) {
			if (minodo->link[pos - 1]->count > MIN) {
				doRightShift(minodo, pos);
			}
			else {
				if (minodo->link[pos + 1]->count > MIN) {
					doLeftShift(minodo, pos + 1);
				}
				else {
					UnirNodos(minodo, pos);
				}
			}
		}
		else {
			if (minodo->link[pos - 1]->count > MIN)
				doRightShift(minodo, pos);
			else
				UnirNodos(minodo, pos);
		}
	}
}

//borrar un valor del nodo
int BorrarDeNodo(int val, NodoBtree* minodo) {
	int pos, flag = 0;
	if (minodo) {
		if (val < minodo->val[1]) {
			pos = 0;
			flag = 0;
		}
		else {
			for (pos = minodo->count;
				(val < minodo->val[pos] && pos > 1); pos--);
			if (val == minodo->val[pos]) {
				flag = 1;
			}
			else {
				flag = 0;
			}
		}
		if (flag) {
			if (minodo->link[pos - 1]) {
				copySuccessor(minodo, pos);
				flag = BorrarDeNodo(minodo->val[pos], minodo->link[pos]);
				if (flag == 0) {
					cout << "No existe en el B-Tree\n";
				}
			}
			else {
				removeVal(minodo, pos);
			}
		}
		else {
			flag = BorrarDeNodo(val, minodo->link[pos]);
		}
		if (minodo->link[pos]) {
			if (minodo->link[pos]->count < MIN)
				AjustarNodo(minodo, pos);
		}
	}
	return flag;
}

/* delete val from B-tree */
void borrado(int val, NodoBtree* minodo, NodoBtree* raiz) {
	NodoBtree* tmp;
	if (!BorrarDeNodo(val, minodo)) {
		cout << "No existe ese valor en el B-Tree\n";
		system("pause");
		return;
	}
	else {
		if (minodo->count == 0) {
			tmp = minodo;
			minodo = minodo->link[0];
			free(tmp);
		}
	}
	raiz = minodo;
	cout << "Borrado" << endl;
	system("pause");
	return;
}

/* search val in B-Tree */
bool busqueda(int val, int* pos, NodoBtree* minodo) {
	bool result;
	if (!minodo) {
		return false;
	}

	if (val < minodo->val[1]) {
		*pos = 0;
	}
	else {
		for (*pos = minodo->count;
			(val < minodo->val[*pos] && *pos > 1); (*pos)--);
		if (val == minodo->val[*pos]) {
			cout << "Se ha encontrado el Nodo\n";
			cout << minodo->val[*pos] << endl;
			cout << minodo->nombre[*pos] << endl;
			system("pause");
			return true;
		}
	}
	result = busqueda(val, pos, minodo->link[*pos]);
	if (!result){
		cout << "No se ha encontrado el Nodo\n";
	system("pause");
}
	return result;
}

// B-Tree desplegar
void desplegar(NodoBtree* minodo) {
	int i;
	if (minodo) {
		for (i = 0; i < minodo->count; i++) {
			desplegar(minodo->link[i]);
			cout << minodo->val[i + 1] << ' ';
			cout << minodo->nombre[i + 1] << endl;
		}
		desplegar(minodo->link[i]);
	}
}