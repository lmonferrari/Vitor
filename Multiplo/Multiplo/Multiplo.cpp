#include "stdafx.h"
#include <iostream>

using namespace std;

int calcula(int n1, int n2) {
	if (n1 % n2 == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

int main()
{
	int n1, n2;
	int resultado;

	cout << "Digite um numero: ";
	cin >> n1;

	cout << "\nDigite outro numero: ";
	cin >> n2;

	resultado = calcula(n1, n2);

	cout << n1 << " eh multiplo de " << n2 << " ?" << endl;

	if (!resultado)
	{
		cout << "Nao eh mutiplo" << endl;
	}
	else
	{
		cout << "Eh multiplo" << endl;
	}

	return 0;
}

