#include "stdafx.h"
#include "math.h"
#include <iostream>

#define TAMANHO 6
#define LINHA 6
#define COLUNA 6
#define COLUNA_EXTENDIDA 7

using namespace std;

void gauss(double A_aumentada[LINHA][COLUNA_EXTENDIDA], double valores[LINHA]) {

	double auxiliar, soma = 0;
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

void imprime_valores(double valores[LINHA]) {
	for (int i = 0; i < LINHA; i++)
	{
		if (valores[i] < 0) {
			cout << "valores de x" << i + 1 << " " << valores[i] << " Compressao" << endl;
		}
		else {
			cout << "valores de x" << i + 1 << " " << valores[i] << " Tracao" << endl;
		}	
	}
}


void imprime_vetor(double vetor[LINHA]) {
	for (int i = 0; i < LINHA; i++)
	{
		cout << "Equacao " << i + 1 << ": " << vetor[i] << " " << endl;
	}
}

void imprimi_matriz_aumentada(double A_aumentada[LINHA][COLUNA_EXTENDIDA]) {

	for (int l = 0; l < LINHA; l++) //linha
	{
		for (int c = 0; c < COLUNA_EXTENDIDA; c++) //coluna
		{
			cout << A_aumentada[l][c] << " ";
		}
		cout << endl << endl;
	}
}

void imprimi_matriz(double A_coeficientes[LINHA][COLUNA]) {
	cout.precision(4);

	for (int l = 0; l < LINHA; l++) //linha
	{
		for (int c = 0; c < COLUNA; c++) //coluna
		{
			cout << A_coeficientes[l][c] << " ";
		}
		cout << endl << endl;
	}
}

void cria_matriz_aumentada(double A_coeficientes[LINHA][COLUNA], double A_resultados[LINHA], double A_aumentada[LINHA][COLUNA_EXTENDIDA]) {

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
	double P1, P2 = 0; // pesos - valores dados pelo usuário
	double valores[TAMANHO]; // cb cd de db be ba

	cout << "De o valor para Peso 1." << endl;
	cin >> P1;
	cout << "De o valor para Peso 2." << endl;
	cin >> P2;
	cout << "Pesos selecionados - " << "P1: " << P1 << " | P2: " << P2 << endl << endl;

	double A_coeficientes[LINHA][COLUNA] =
	{
		0.5000, 0.0000, 0.0000, 0.0000, 0.0000, 0.0000 ,
		-(sqrt(3))/2, -1.0000, 0.0000, 0.0000, 0.0000, 0.0000,
		0.0000, 1.0000, -1.0000, 0.0000, 0.0000, 0.00000,
		0.0000, 0.0000, 0.0000, 1.0000, 0.0000, 0.0000,
		0.0000, 0.0000, 0.0000, -(sqrt(3))/2,-(sqrt(3))/2, 0.0000,
		1.0000, 0.0000, 0.0000, 0.5000, -0.5000, -1.0000
	};
	double A_resultados[LINHA] =
	{
		P2, 0, 0, P1, 0, 0
	};
	double A_aumentada[LINHA][COLUNA_EXTENDIDA];

	cout << "Matriz de coeficientes" << endl << endl;
	imprimi_matriz(A_coeficientes);
	
	cout << "\n\nVetor de resultados" << endl << endl;
	imprime_vetor(A_resultados);
	
	cout << "\n\nMatriz aumentada para usar metodo de Gauss" << endl << endl;
	cria_matriz_aumentada(A_coeficientes, A_resultados, A_aumentada);
	gauss(A_aumentada, valores);
	
	cout << "\n\nMatriz apos Algoritmo de Gauss\n" << endl;
	imprimi_matriz_aumentada(A_aumentada);
	
	cout << "\n\nImprimindo valores de X: \n" << endl;
	imprime_valores(valores);

	return 0;
}

