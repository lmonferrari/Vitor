#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

//prototipos
void gauss(float A_equacoes[6][7], float valores[6]);
void imprimi_matriz(float A_equacoes[6][7]);
void imprime_valores(float valores[6], string forca[6]);

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

	float A_equacoes[6][7] =
	{
		0.5000, 0.0000, 0.0000, 0.0000, 0.0000, 0.0000 , P2,
		-0.86602540378, -1.0000, 0.0000, 0.0000, 0.0000, 0.0000, 0,
		0.0000, 1.0000, -1.0000, 0.0000, 0.0000, 0.00000, 0,
		0.0000, 0.0000, 0.0000, 1.0000, 0.0000, 0.0000, P1,
		0.0000, 0.0000, 0.0000, -0.86602540378,-0.86602540378, 0.0000, 0,
		1.0000, 0.0000, 0.0000, 0.5000, -0.5000, -1.0000, 0
	};

	cout << "\n[+]Matriz antes Algoritmo de Gauss\n" << endl;
	imprimi_matriz(A_equacoes);
	cin >> pause;

	cout << "\n[+]Matriz apos Algoritmo de Gauss\n" << endl;
	gauss(A_equacoes, valores);
	imprimi_matriz(A_equacoes);
	cin >> pause;

	cout << "\n[+]Imprimindo valores dos nos da trelica: \n" << endl;
	imprime_valores(valores, forca);
	cin >> pause;

	return 0;
}

//implementação do algoritmo de Gauss
void gauss(float A_equacoes[6][7], float valores[6]) {

	float auxiliar, soma = 0;
	int n;

	for (int c = 0; c <= 6; c++)
	{
		for (int l = 0; l < 6; l++)
		{
			if (l > c)
			{
				auxiliar = -(A_equacoes[l][c] / A_equacoes[c][c]);
				for (int k = 0; k <= 6; k++) {
					A_equacoes[l][k] = auxiliar * A_equacoes[c][k] + A_equacoes[l][k];
				}
			}
		}
	}

	valores[6 - 1] = A_equacoes[5][6] / A_equacoes[5][5];

	for (int i = 6 - 1; i >= 1; i--)
	{
		soma = 0;
		for (int j = i + 1; j <= 6 - 1; j++)
		{
			soma = soma + A_equacoes[i][j] * valores[j];
		}
		valores[i] = (A_equacoes[i][6] - soma) / A_equacoes[i][i];
	}
	valores[0] = (A_equacoes[0][6] - soma) / A_equacoes[0][0];
}

void imprime_valores(float valores[6], string forca[6]) {

	for (int i = 0; i < 6; i++)
	{
		if (valores[i] < 0) {
			cout << forca[i] << " " << -valores[i] << " Compressao" << endl;
		}
		else {
			cout << forca[i] << " " << valores[i] << " Tracao" << endl;
		}
	}
	cout << endl;
}

void imprimi_matriz(float A_equacoes[6][7]) {

	for (int l = 0; l < 6; l++) //linha
	{
		for (int c = 0; c < 7; c++) //coluna
		{
			if (A_equacoes[l][c] < 0) {
				cout << "| " << A_equacoes[l][c] << " ";
			}
			else {
				cout << "|  " << A_equacoes[l][c] << " ";
			}
		}
		cout << endl;
	}
}