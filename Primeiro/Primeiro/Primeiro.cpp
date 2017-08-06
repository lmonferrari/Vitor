#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

//prototipos
void gauss(float A_aumentada[6][7], float valores[6]);
void imprime_valores(float valores[6],string forca[6]);
void imprime_vetor(float vetor[6]);
void imprimi_matriz_aumentada(float A_aumentada[6][7]);
void imprimi_matriz(float A_coeficientes[6][6]);
void cria_matriz_aumentada(float A_coeficientes[6][6], float A_resultados[6], float A_aumentada[6][7]);

int main(void)
{
	//limitando as casas decimais
	cout.precision(4);
	cout << fixed;

	cout << "#####################################\n";
	cout << "#                                   #\n";
	cout << "# TRABALHO FEITO POR VITOR MONTEIRO # \n#    Objetivo: Calculo de trelica   #\n";
	cout << "#                                   #\n";
	cout << "#####################################\n\n";

	float P1, P2 = 0; // pesos - valores dados pelo usuário
	float *PP1, *PP2; // ponteiros para os pesos
	float valores[6]; // cb cd de db be ba
	string forca[6] = {
		"Fbc","Fcd","Fde","Fdb","Fbe","Fba"
	};
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

	float A_coeficientes[6][6] =
	{
		0.5000, 0.0000, 0.0000, 0.0000, 0.0000, 0.0000 ,
		-0.86602540378, -1.0000, 0.0000, 0.0000, 0.0000, 0.0000,
		0.0000, 1.0000, -1.0000, 0.0000, 0.0000, 0.00000,
		0.0000, 0.0000, 0.0000, 1.0000, 0.0000, 0.0000,
		0.0000, 0.0000, 0.0000, -0.86602540378,-0.86602540378, 0.0000,
		1.0000, 0.0000, 0.0000, 0.5000, -0.5000, -1.0000
	};
	float A_resultados[6] =
	{
		P2, 0, 0, P1, 0, 0,
	};
	float A_aumentada[6][7];

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
	imprime_valores(valores,forca);
	cin >> pause;

	return 0;
}

//implementação do algoritmo de Gauss
void gauss(float A_aumentada[6][7], float valores[6]) {

	float auxiliar, soma = 0;
	int n;

	for (int c = 0; c <= 6; c++)
	{
		for (int l = 0; l < 6; l++)
		{
			if (l > c)
			{
				auxiliar = -(A_aumentada[l][c] / A_aumentada[c][c]);
				for (int k = 0; k <= 6; k++) {
					A_aumentada[l][k] = auxiliar * A_aumentada[c][k] + A_aumentada[l][k];
				}
			}
		}
	}

	valores[6 - 1] = A_aumentada[5][6] / A_aumentada[5][5];

	for (int i = 6 - 1; i >= 1; i--)
	{
		soma = 0;
		for (int j = i + 1; j <= 6 - 1; j++)
		{
			soma = soma + A_aumentada[i][j] * valores[j];
		}
		valores[i] = (A_aumentada[i][6] - soma) / A_aumentada[i][i];
	}
	valores[0] = (A_aumentada[0][6] - soma) / A_aumentada[0][0];
}

void imprime_valores(float valores[6],string forca[6]) {

	for (int i = 0; i < 6; i++)
	{
		if (valores[i] < 0) {
			cout << forca[i] << " " << valores[i] << " Compressao" << endl;
		}
		else {
			cout << forca[i] << "  " << valores[i] << " Tracao" << endl;
		}
	}
	cout << endl;
}

void imprime_vetor(float vetor[6]) {

	for (int i = 0; i < 6; i++)
	{
		cout << "Equacao " << i + 1 << ": " << vetor[i] << " " << endl;
	}
}

void imprimi_matriz_aumentada(float A_aumentada[6][7]) {

	for (int l = 0; l < 6; l++) //linha
	{
		for (int c = 0; c < 7; c++) //coluna
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

void imprimi_matriz(float A_coeficientes[6][6]) {

	for (int l = 0; l < 6; l++) //linha
	{
		for (int c = 0; c < 6; c++) //coluna
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

void cria_matriz_aumentada(float A_coeficientes[6][6], float A_resultados[6], float A_aumentada[6][7]) {

	for (int l = 0; l < 6; l++)
	{
		A_aumentada[l][6] = A_resultados[l];
		for (int c = 0; c < 6; c++)
		{
			A_aumentada[l][c] = A_coeficientes[l][c];
		}
	}
}