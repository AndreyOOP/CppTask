// Task3.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <iostream>
#include <string>
#include <exception>
using namespace std;


int main()
{
	setlocale(LC_ALL, "Russian");

	int n, tempN;

	cout << "Введите целое число (999 < х < 2 000 000 000):" << endl;
	cin >> n;
	tempN = n;

	int arr[10];

	for (int i = 0; i < 10; i++)
		arr[i] = -1;

	int len = 0;

	while (n > 0)
	{
		arr[len++] = n % 10;
		n /= 10;
	}

	int lastTwo  = arr[0] + arr[1];
	int firstTwo = arr[len-1] + arr[len-2];
	int sum = 0;

	for (int j = 0; j < len; j++) {
		sum += arr[j];
		//cout << arr[j] << " ";
	}

	cout << endl;
	cout << "Сумма первых двух цифр: " << firstTwo << endl;
	cout << "Сумма последних двух цифр: " << lastTwo << endl;
	cout << "Сумма всех цифр: " << sum << endl;

	if (firstTwo == lastTwo) {
		cout << "a) Сумма первых двух цифр числа " << tempN << " равна сумме двух последних" << endl;
	}else if (firstTwo > lastTwo) {
		cout << "a) Сумма первых двух цифр числа " << tempN << " больше суммы двух последних" << endl;
	}else {
		cout << "a) Сумма первых двух цифр числа " << tempN << " меньше суммы двух последних" << endl;
	}

	if (sum % 9 == 0) {
		cout << "б) Сумма всех цифр числа " << tempN << " кратна 9" << endl;
	}
	else {
		cout << "б) Сумма всех цифр числа " << tempN << " не кратна 9" << endl;
	}

	cin.get();
	cin.get();

    return 0;
}

