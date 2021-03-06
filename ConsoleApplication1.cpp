// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <exception>
using namespace std;

bool inputCheck(int value, int lower, int upper);
bool halfCheck(char half);
int tillMidnight(int hours, int minutes, char half);
void colorOutput(string message, int color);

int main()
{
	setlocale(LC_ALL, "Russian");

	int hours, minutes;
	char half;

	cout << "Введите время (ч м):" << endl;
	cin >> hours >> minutes;
	if ( !inputCheck(hours, 0, 12))   return 0;
	if ( !inputCheck(minutes, 0, 60)) return 0;

	cout << "Введите половину суток:" << endl;
	cin >> half;
	if ( !halfCheck(half)) return 0;

	int tm = tillMidnight(hours, minutes, half);

	colorOutput("До полуночи ", 3);
	colorOutput(" осталось ", 7);
	colorOutput(std::to_string(tm/60), 4);
	colorOutput(" часов ", 7);
	colorOutput(std::to_string(tm%60), 4);
	colorOutput(" минут", 7);

	cin.get();
	cin.get();

    return 0;
}

bool inputCheck(int value, int lower, int upper) {
	
	if (value < lower || value > upper) {
		cout << "Значение должно быть больше " << lower << " и меньше " << upper << endl;
		cin.get(); 
		cin.get();
		return false;
	}
	return true;
}

bool halfCheck(char half) {
	
	if (!(half == 'a' || half == 'p')) {
		cout << "Значение должно быть а или p";
		cin.get();
		cin.get();
		return false;
	}
	return true;
}

int tillMidnight(int hours, int minutes, char half) {
	
	int timeInMinutes = hours * 60 + minutes;
	
	if (half == 'p') {
		timeInMinutes += 12 * 60;
	}

	return 24 * 60 - timeInMinutes;
}

void colorOutput(string message, int color) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
	cout << message;
}