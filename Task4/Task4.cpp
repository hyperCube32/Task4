#define _USE_MATH_DEFINES
#include <iostream>
#include<cmath>

using namespace std;

double lastPart(double x, int n)
{
	double last;
	last = (pow(-1, n) / (((2 * n) - 1) * pow(x, ((2 * n) - 1))));
	return last;

}

double sumN(double x, int n)
{
	double sum = M_PI_2;
	double last;
	for (int i = 1; i < n+1; ++i)
	{
		last = lastPart(x,i);
		sum += last;
	}
	return sum;
}

int nValue(double E, double x)
{
	double last = x;
	int n;
	for (n = 1; fabs(last) > E; ++n)
	{
		last = lastPart(x, n);
	}
	return n;
}

double sumE(double x, double E)
{
	double last;
	// Инициализация переменной last
	last = x;
	double sum = M_PI_2;
	for (int n = 1; fabs(last) > E; ++n)
	{
		last = lastPart(x,n);
		sum += last;
	}
	return sum;
}

void IO()
{
	cout << "Вычисление значений функции arctg(x)\n\n";
	double x = 0; // Значение аргумента
	double func; // Точное значение функции
	double sum; // Значение частичной суммы
	int n; // Число слагаемых в частичной сумме

	cout << "Задание 1" << endl;
	while (x < 1)
	{
		cout << "Введите значение аргумента болеше 1 > ";
		cin >> x;
		if (x < 1)
		{
			cout << "Введёное число меньше 1" << endl;
		}
	}
	cout << "Задайте число слагаемых > ";
	cin >> n;
	func = atan(x);// Вычисление "точного" значения
	sum = sumN(x, n);
	cout << "Точное значение функции равно " << func << endl;
	cout << "Частичная сумма ряда равна " << sum << endl;
	cout << "Абсолютная погрешность равна " << fabs(func - sum) << endl;
	cout << "Последнее слагаемое равно " << lastPart(x,n) << endl;

	cout << "\nЗадание 2" << endl;
	x = 0;
	while (x < 1)
	{
		cout << "Введите значение аргумента болеше 1 > ";
		cin >> x;
		if (x < 1)
		{
			cout << "Введёное число меньше 1" << endl;
		}
	}
	double E;
	cout << "Задайте точность вычислений > ";
	cin >> E;
	func = atan(x);// Вычисление "точного" значения
	sum = sumE(x, E);
	cout << "Точное значение функции равно " << func << endl;
	cout << "Частичная сумма ряда c заданной точностью равна " << sum << endl;
	cout << "Учтено " << nValue(E, x)-1 << " членов ряда" << endl;
	sum = sumE(x, E / 10);
	cout << "Частичная сумма ряда c точностью, большей в 10 раз, равна " << sum << endl;
	cout << "Учтено " << nValue(E / 10,x)-1 << " членов ряда" << endl;

}

int main()
{
	setlocale(0, "");
	char uslovie = 0;
	cout << "Начать вычисления - y Выйти - n > ";
	cin >> uslovie;
	cout << endl;
	while (uslovie != 'n')
	{
		IO();
		cout << endl;
		cout << "повтоорить вычисление y - да n - нет  > ";
		cin >> uslovie;
		cout << endl;
	}
	return 0;
}

