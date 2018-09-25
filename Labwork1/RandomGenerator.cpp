#define _USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <cmath>
#include "RandomGenerator.h"

using namespace std;

void RandomGenerator::Frequency(double Storage[100], int VariantOfDivision)
{
	if (VariantOfDivision == 1)
	{
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < 100; j++)
				if (Storage[j] >= double(i) / 10 && Storage[j] <= double(i + 1) / 10)
					Division[i]++;
	}
	else if (VariantOfDivision == 2)
	{
		double LeftBorder = -3, RightBorder = -2.4;
		int CurrentStoragePosition = 0;

		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 100; j++)
				if (Storage[j] >= LeftBorder && Storage[j] <= RightBorder)
					Division[CurrentStoragePosition]++;
		}

		LeftBorder += 0.6;
		RightBorder += 0.6;
		CurrentStoragePosition++;
	}
	else if (VariantOfDivision == 3)
	{
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < 100; j++)
				if (Storage[j] >= i * 10 && Storage[j] <= (i + 1) * 10)
					Division[i]++;
	}

}

void RandomGenerator::Statistics(double Storage[100], int VariantOfDivision)
{
	Frequency(Storage, VariantOfDivision);

	if (VariantOfDivision == 1)
	{
		for (int i = 0; i < 10; i++)
			cout << "[" << double(i) / 10 << "," << double(i + 1) / 10 << "]" << "  " << Division[i] / 100 << endl;

	}
	else if (VariantOfDivision == 2)
	{
		double LeftBorder = -3, RightBorder = -2.4;

		for (int i = 0; i < 10; i++)
		{
			cout << "[" << LeftBorder << "," << RightBorder  << "]" << "  " << Division[i] / 100 << endl;
			LeftBorder += 0.6;
			RightBorder += 0.6;
		}
	}
	else if (VariantOfDivision == 3)
	{
		for (int i = 0; i < 10; i++)
			cout << "[" << i * 10 << "," << (i + 1) * 10 << "]" << "  " << Division[i] / 100 << endl;
	}

}

void RandomGenerator::StaticticsForLinearMethod()
{
	LinearCongruentialMethod();
	Statistics(FirstStorage, 1);
}

void RandomGenerator::StaticticsForQuadraticMethod()
{
	QuadraticCongruentialMethod();
	Statistics(SecondStorage, 1);
}

void RandomGenerator::LinearCongruentialMethod()
{
	int A = 163, C = 569, M = 983;
	Xn = 2;

	for (int i = 0; i < 100; i++)
	{
		Xn = (int)(A * Xn + C) % M;
		FirstStorage[i] = double(Xn) / M;
	}
}

void RandomGenerator::QuadraticCongruentialMethod()
{
	int A = 163, C = 569, M = 983;
	Xn = 2;
	int D = 17;

	for (int i = 0; i < 100; i++)
	{
		Xn = (int)(D*Xn*Xn + A * Xn + C) % M;
		SecondStorage[i] = double(Xn) / M;
	}
}

void RandomGenerator::FibonacciNumbers()
{
	int M = 983;
	int Previous = 0;
	Xn = 2;

	for (int i = 0; i < 100; i++)
	{
		Previous = Xn;
		Xn = (int)(Xn + Previous) % M;
		FrequncyStorage[i] = double(Xn) / M;
	}

	Statistics(FrequncyStorage, 1);
}

void RandomGenerator::InverseCongruentialSequence()
{
	int A = 163, C = 569, M = 983;
	Xn = 2;

	for (int i = 0; i < 100; i++)
	{
		Xn = (int)(A * (1 / Xn) + C) % M;
		FrequncyStorage[i] = double(Xn) / M;
	}

	Statistics(FrequncyStorage, 1);
}

void RandomGenerator::MergeMethod()
{
	LinearCongruentialMethod();
	QuadraticCongruentialMethod();
	Xn = 2;

	for (int i = 0; i < 100; i++)
	{
		Xn = abs(FirstStorage[i] - SecondStorage[i]);
		FrequncyStorage[i] = Xn;
	}

	Statistics(FrequncyStorage, 1);
}

void RandomGenerator::ThreeSigmaRule()
{
	LinearCongruentialMethod();
	Xn = 0;
	double Sum = 0, RandomNumber;

	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			RandomNumber = FirstStorage[1 + rand() % 100];
			Sum += RandomNumber;
		}

		Xn = (Sum - 6);
		FrequncyStorage[i] = Xn;
		Sum = 0;
	}

	Statistics(FrequncyStorage, 2);
}

void RandomGenerator::PolarCoordinateMethod()
{
	QuadraticCongruentialMethod();

	for (int i = 0; i < 50; i++)
		PolarFirstIteration(i);

	Statistics(FrequncyStorage, 2);
}

void RandomGenerator::PolarFirstIteration(int i)
{
	x = SecondStorage[1 + rand() % 100] * 2 - 1;
	y = SecondStorage[1 + rand() % 100] * 2 - 1;
	PolarSecondIteration(x, y, i);
}

void RandomGenerator::PolarSecondIteration(double x, double y, int i)
{
	{
		double Sum = x * x + y * y;

		if (Sum >= 1)
			PolarFirstIteration(i);
		else
		{
			x = x * pow((-2 * log(Sum) / Sum), 0.5);
			y = y * pow((-2 * log(Sum) / Sum), 0.5);

			FrequncyStorage[i] = x; 
			FrequncyStorage[100 - i] = y;
		}
	}
}

void RandomGenerator::MethodOfIntegralRelations()
{
	LinearCongruentialMethod();
	Xn = 0;

	for (int i = 0; i < 100; i++)
		FrequncyStorage[i] = Iteration8(FirstStorage[0 + rand() % 100], FirstStorage[0 + rand() % 100]);

	Statistics(FrequncyStorage, 2);
}

double RandomGenerator::Iteration8(double x, double y)
{
	bool check;
	Xn = pow(8 - M_E, 0.5)*((x - 0.5) / y);
	check = pow(Xn, 2) <= -4 * log(y);

	if (check)
		return Xn;
	else
		Xn = Iteration8(FirstStorage[0 + rand() % 100], FirstStorage[0 + rand() % 100]);
}

void RandomGenerator::LogarithmMethod()
{
	LinearCongruentialMethod();
	Xn = 0;

	for (int i = 0; i < 100; i++)
	{
		Xn = -127 * log(FirstStorage[0 + rand() % 100]);
		FrequncyStorage[i] = Xn;
	}

	Statistics(FrequncyStorage, 3);
}

void RandomGenerator::ArensMethod()
{
	Xn = 0;

	for (int i = 0; i < 100; i++)
		FrequncyStorage[i] = ArensFirstIteration();

	Statistics(FrequncyStorage, 3);
}

double RandomGenerator::ArensFirstIteration()
{
	Xn = FirstStorage[0 + rand() % 100];
	SecondAdditionalValue = tan(M_PI * Xn);
	Xn = SecondAdditionalValue * pow(2 * FirstAdditionalValue - 1, 0.5) + FirstAdditionalValue - 1;
	return ArensSecondIteration(Xn);
}

double RandomGenerator::ArensSecondIteration(double x)
{
	if (x <= 0)
		ArensFirstIteration();

	Candidate = FirstStorage[1 + rand() % 100];

	if (Candidate > (1 + SecondAdditionalValue * SecondAdditionalValue)*exp((FirstAdditionalValue - 1)*log((pow(x / FirstAdditionalValue - 1, 0.5))) - pow(2 * FirstAdditionalValue - 1, 0.5)*SecondAdditionalValue))
		ArensFirstIteration();
	else
		return x;
}