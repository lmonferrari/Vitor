#include "stdafx.h"
#include <iostream>

#define TAMANHO 6
#define LINHA 6
#define COLUNA 6
#define COLUNA_EXTENDIDA 7

using namespace std;

//implementação do algoritmo de Gauss
void gauss(float A_aumentada[LINHA][COLUNA_EXTENDIDA], float valores[LINHA]) {

	float auxiliar, soma = 0;
	int n;

	for (int c = 0; c <= COLUNA; c++)
	{
		for (int l = 0; l < LINHA; l++)
		{
			if (l > c)
			{
				auxiliar = -(A_aumentada[l][c] / A_aumentada[c][c]);
				for (int k = 0; k <= COLUNA; k++) {
					A_aumentada[l][k] = auxiliar * A_aumentada[c][k] + A_aumentada[l][k];
				}
			}
		}
	}

	valores[LINHA - 1] = A_aumentada[LINHA - 1][COLUNA_EXTENDIDA - 1] / A_aumentada[LINHA - 1][COLUNA_EXTENDIDA - 2];

	for (int i = LINHA - 1; i >= 1; i--)
	{
		soma = 0;
		for (int j = i + 1; j <= LINHA - 1; j++)
		{
			soma = soma + A_aumentada[i][j] * valores[j];
		}
		valores[i] = (A_aumentada[i][COLUNA_EXTENDIDA - 1] - soma) / A_aumentada[i][i];
	}
	valores[0] = (A_aumentada[0][COLUNA_EXTENDIDA - 1] - soma) / A_aumentada[0][0];
}

void imprime_valores(float valores[LINHA]) {
	
	for (int i = 0; i < LINHA; i++)
	{
		if (valores[i] < 0) {
			cout << "valores de x" << i + 1 << " " << valores[i] << " Compressao" << endl;
		}
		else {
			cout << "valores de x" << i + 1 << "  " << valores[i] << " Tracao" << endl;
		}	
	}
	cout << endl;
}

void imprime_vetor(float vetor[LINHA]) {
	
	for (int i = 0; i < LINHA; i++)
	{
		cout << "Equacao " << i + 1 << ": " << vetor[i] << " " << endl;
	}
}

void imprimi_matriz_aumentada(float A_aumentada[LINHA][COLUNA_EXTENDIDA]) {

	for (int l = 0; l < LINHA; l++) //linha
	{
		for (int c = 0; c < COLUNA_EXTENDIDA; c++) //coluna
		{
			if (A_aumentada[l][c] < 0) {
				cout << "| " << A_aumentada[l][c] << " ";
			}
			else {
				cout << "|  " << A_aumentada[l][c] << " ";
			}
		}
		cout << endl;
	}
}

void imprimi_matriz(float A_coeficientes[LINHA][COLUNA]) {

	for (int l = 0; l < LINHA; l++) //linha
	{
		for (int c = 0; c < COLUNA; c++) //coluna
		{
			if (A_coeficientes[l][c] < 0) {
				cout << "| " << A_coeficientes[l][c] << " ";
			}
			else {
				cout << "|  " << A_coeficientes[l][c] << " ";
			}
		}
		cout << endl;
	}
}

void cria_matriz_aumentada(float A_coeficientes[LINHA][COLUNA], float A_resultados[LINHA], float A_aumentada[LINHA][COLUNA_EXTENDIDA]) {

	for (int l = 0; l < LINHA; l++)
	{
		A_aumentada[l][COLUNA_EXTENDIDA - 1] = A_resultados[l];
		for (int c = 0; c < COLUNA; c++)
		{
			A_aumentada[l][c] = A_coeficientes[l][c];
		}
	}
}

int main(void)
{
	cout.precision(4);
	cout << fixed; 

	cout << "#####################################\n";
	cout << "#                                   #\n";
	cout << "# TRABALHO FEITO POR VITOR MONTEIRO # \n#    Objetivo: Calculo de trelica   #\n";
	cout << "#                                   #\n";
	cout << "#####################################\n\n";

	float P1, P2 = 0; // pesos - valores dados pelo usuário
	float *PP1, *PP2; // ponteiros para os pesos
	float valores[TAMANHO]; // cb cd de db be ba
	char pause;

	cout << "[+] De o valor para Peso 1." << endl;
	cin >> P1;
	cout << "[+] De o valor para Peso 2." << endl;
	cin >> P2;
	
	// utilizando ponteiros
	PP1 = &P1;
	PP2 = &P2;

	cout << "\n[+]Pesos selecionados " << "\n   [-]P1: " << *PP1 << "\n   [-]P2: " << *PP2 << endl;
	cout << "\n[+]Endereco de memoria do Pesos selecionados " << "\n   [-]P1: " << PP1 << "\n   [-]P2: " << PP2 << endl;
	cin >> pause;

	float A_coeficientes[LINHA][COLUNA] =
	{
		0.5000, 0.0000, 0.0000, 0.0000, 0.0000, 0.0000 ,
		-0.86602540378, -1.0000, 0.0000, 0.0000, 0.0000, 0.0000,
		0.0000, 1.0000, -1.0000, 0.0000, 0.0000, 0.00000,
		0.0000, 0.0000, 0.0000, 1.0000, 0.0000, 0.0000,
		0.0000, 0.0000, 0.0000, -0.86602540378,-0.86602540378, 0.0000,
		1.0000, 0.0000, 0.0000, 0.5000, -0.5000, -1.0000
	};
	float A_resultados[LINHA] =
	{
		P2, 0, 0, P1, 0, 0,
	};
	float A_aumentada[LINHA][COLUNA_EXTENDIDA];

	cout << "\n[+]Matriz de coeficientes" << endl << endl;
	imprimi_matriz(A_coeficientes);
	cin >> pause;
	
	cout << "\n[+]Vetor de resultados" << endl << endl;
	imprime_vetor(A_resultados);
	cin >> pause;
	
	cout << "\n[+]Criando matriz aumentada para usar metodo de Gauss\n\n";
	cria_matriz_aumentada(A_coeficientes, A_resultados, A_aumentada);
	imprimi_matriz_aumentada(A_aumentada);
	cin >> pause;
	
	cout << "\n[+]Matriz apos Algoritmo de Gauss\n" << endl;
	gauss(A_aumentada, valores);
	imprimi_matriz_aumentada(A_aumentada);
	cin >> pause;
	
	cout << "\n[+]Imprimindo valores dos nos da trelica: \n" << endl;
	imprime_valores(valores);
	cin >> pause;

	return 0;
}

