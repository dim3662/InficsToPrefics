#pragma once
#include <string>
#include <vector>
using namespace std;

class Calculator {
private:
	double readEvaluate(vector<double>& sum);
	string readPreficsForm(vector<char>& infics);
	void validationForTests(string  &str);//проверка коректности введенной строки
	std::vector<double> sum;
	std::vector<char> infics;
	string str;
	std::vector<char> operators;
	//все что до этого используется для тестов
	size_t priority(char operation);
	bool IsOperands(char elem);
	bool IsOperators(char elem);
	bool IsOperationOneArgument(int& index, string  &str, vector<char>& infics);
	void addNull(string  &str);
	void inficToPrefics(string  &str, vector<char>& infics, vector<char>& operators);
	void evaluate(string  &str, vector<char>& infics, vector<double>& sum, vector<char>& operators);
	void validation(string  &str);
	void printValue(vector<double>& sum);
	void printPrefics(vector<char>& infics);
public:
	Calculator( string str="") {
		this->str = str;
	}
	~Calculator(){
	str.clear();
	sum.clear();
	infics.clear();
	operators.clear();
	}
	void readString(string &read);
	void inficToPrefics();//перевод инфиксной в префиксную
	void evaluate();// подсчет префиксной формы записи
	void validation();//проверка коректности введенной строки
	void printPrefics();//вывод в консоль перфиксной формы записи
	void printValue(); //вывод в консолько значение выражения
};