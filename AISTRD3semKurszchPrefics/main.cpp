#include <iostream>
#include <string>
#include <cmath>
#include <stdio.h>
#include <vector>
#include "functionsPrefics.h"

using namespace std;



int main() {
	Calculator prefics;
	string str= "";
	cout << "Hello, Welcom in my programm." << endl;
	cout << "Function of one argumetn must be in skobkah." << endl;
	cout << "You must write a expression." << endl;
	cout << "Expression: ";
	cin >> str;
	prefics.readString(str);
	//cout << str << endl;
	//проверка коректности введенного значения
	prefics.validation();
	//перевод иинфиксной в префиксную форму.....
	prefics.inficToPrefics();
	//печатаем префиксную форму 
	cout << "Prefics form:";
	prefics.printPrefics();
	cout << endl;
	//нахождение значение префиксной формы....
	cout << "Evaluate: ";
	prefics.evaluate();
	//печатаем значение выражения
	prefics.printValue();
	cout << endl;
	system("PAUSE");
}