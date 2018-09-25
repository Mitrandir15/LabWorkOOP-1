#define _USE_MATH_DEFINES
#include <iostream>
#include <Windows.h>
#include "RandomGenerator.h"

using namespace std;

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int choice = 0;
	cout << "Оберіть номер методу для генерування псевдовипадкових чисел" << endl;
	cin >> choice;
	RandomGenerator random;
	switch (choice)
	{
	case 1: random.StaticticsForLinearMethod(); break;
	case 2: random.StaticticsForQuadraticMethod(); break;
	case 3: random.FibonacciNumbers(); break;
	case 4: random.InverseCongruentialSequence(); break;
	case 5: random.MergeMethod(); break;
	case 6: random.ThreeSigmaRule(); break;
	case 7: random.PolarCoordinateMethod(); break;
	case 8: random.MethodOfIntegralRelations(); break;
	case 9: random.LogarithmMethod(); break;
	case 10: random.ArensMethod(); break;
	default: cout << "Ви ввели неіснуюючий номер!" << endl;
		break;
	}
	system("pause");
}