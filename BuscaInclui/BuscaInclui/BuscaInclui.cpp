//Crie uma função consulta para verificar se o nome digitado já existe na matriz.Caso já exista, retornar
//0 (zero); senão, retornar –1.Essa função será usada em duas situações no programa.Ao digitar nome e
//telefone para incluir, verificar se o nome já existe.Se sim, mostrar mensagem e não incluir na matriz.
//Voltar a ler nome / telefone em seguida.

#include "stdafx.h"
#include <iostream>

using namespace std;

#define LINHA  10
#define COLUNA  2

int consulta(string matriz[LINHA][COLUNA],string pesquisa) {
	int auxiliar = 0;
	
	for (int l = 0; l < LINHA; l++)
	{
		if (pesquisa == matriz[l][auxiliar]) {
			cout << "Existe\n";
			return 0;
		}
		auxiliar++;
	}
	cout << "Nao Existe\n";
	return -1;
}

int main()
{
	// Matriz com alguns valores
	string matriz[LINHA][COLUNA]
	{
		"Vitor", "3355-9599",
		"Joao" , "9955-8999",
		"Joana", "4455-9900"
	};

	char nome[15], telefone[10];

	cout << "Digite o nome : ";
	cin >> nome;
	cout << "Digite o telefone: ";
	cin >> telefone;

	consulta(matriz,nome);
    return 0;
}

