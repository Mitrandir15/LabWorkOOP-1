#pragma once

class RandomGenerator
{

public:
	
	void LinearCongruentialMethod();
	void QuadraticCongruentialMethod();
	void FibonacciNumbers();
	void InverseCongruentialSequence();
	void MergeMethod();
	void ThreeSigmaRule();
	void PolarCoordinateMethod();
	void MethodOfIntegralRelations();
	void LogarithmMethod();
	void ArensMethod();

	void BarChartForLinearMethod();
	void BarChartForQuadraticMethod();
	void BarChart(double Storage[100], int VariantOfDivision);
	void Frequency(double Storage[100], int VariantOfDivision);

private:

	double Division[10] = {};

	double FirstStorage[100] = {};
	double SecondStorage[100] = {};
	double FrequncyStorage[100] = {};

	double x = 0, y = 0;
	double Xn;

	//допоміжні змінні до 10-ого методу
	double FirstAdditionalValue = 5;
	double SecondAdditionalValue = 0;
	double Candidate = 0;

	//допоміжні функції до методу полярних координат
	void PolarFirstIteration(int i);
	void PolarSecondIteration(double FirstValue, double SecondValue, int i);

	//допоміжна функція до 8-ого методу
	double Iteration8(double FirstValue, double SecondValue);

	//допоміжні функції до 10-ого методу
	double ArensFirstIteration();
	double ArensSecondIteration(double x);
};
