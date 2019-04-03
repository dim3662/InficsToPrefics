#include "functionsPrefics.h"
#include <iostream>
#include <vector>
#include <string>

size_t Calculator::priority(char operation) {
	switch (operation) {
	case '+': 
		return 1;
	case'-':
		return 2;
	case '*': case '/':
		return 3;
	case '^':
		return 4;
	default:
		return 0;
	}
}

bool Calculator::IsOperands(char elem)
{
	if (elem == 'p' || elem == 'i' || elem == 'e' || elem == '0' || elem == '1' || elem == '2' || elem == '3' || elem == '4' || elem == '5' || elem == '6' || elem == '7' || elem == '8' || elem == '9' || elem == '.') {
		return true;
	}
	else
	return false;
}

bool Calculator::IsOperators(char elem)
{
	if (elem == '+' || elem == '-' || elem == '*' || elem == '/' || elem == '^') {
		return true;
	}
	else
		return false;
}

bool Calculator::IsOperationOneArgument(int& index, string &str, vector<char>& infics)
{
	if (index>=2 && str[index]=='s' && str[index-1]=='o' && str[index-2]=='c') {
		infics.push_back('s');
		infics.push_back('o');
		infics.push_back('c');
		index = index- 3;
		return true;
	}
	else {
		if (index >= 2 && str[index] == 'n' && str[index - 1] == 'i' && str[index - 2] == 's') {
			infics.push_back('n');
			infics.push_back('i');
			infics.push_back('s');
			index = index - 3;
			return true;
		}
		else {
			if (index >= 2 && str[index] == 'g' && str[index - 1] == 't' &&index>=2 && str[index - 2] == 'c') {
				infics.push_back('g');
				infics.push_back('t');
				infics.push_back('c');
				index = index - 3;
				return true;
			}
			
			else {
				if (index >= 1 && str[index] == 'g' && str[index - 1] == 't') {
					;
					infics.push_back('g');
					infics.push_back('t');
					index = index - 2;
					return true;
				}
				else {
					if (index >= 2 && str[index] == 'g' && str[index - 1] == 'o' && str[index - 2] == 'l') {
						infics.push_back('g');
						infics.push_back('o');
						infics.push_back('l');
						index = index - 3;
						return true;
					}
					else {
						if (index >= 1 && str[index] == 'n' && str[index - 1] == 'l') {
							infics.push_back('n');
							infics.push_back('l');
							index = index - 2;
							return true;
						}
						else {
							if (index >= 3 && str[index] == 't' && str[index - 1] == 'r' && str[index - 2] == 'q'&& str[index - 3] == 's') {
								infics.push_back('t');
								infics.push_back('r');
								infics.push_back('q');
								infics.push_back('s');
								index = index - 4;
								return true;
							}
							else {
								return false;
							}
						}
					}
				}
			}
		}
	}
	
}

void Calculator::inficToPrefics( string & str, vector<char>& infics, vector<char>& operators)
{
	int index = str.length() - 1;
	//??????? ?????????? ? ?????????? ?????.....
	while (index >= 0) {
		if (!IsOperands(str[index]) && !IsOperators(str[index]) && str[index] != ')' && str[index] != '(') {
			if (!IsOperationOneArgument(index, str, infics)) index--;
			infics.push_back(' ');
		}
		else {//???? ??? ??????????
			if (IsOperands(str[index]) && str[index] == 'e') {
				infics.push_back(str[index]);
				index = index - 1;
				infics.push_back(' ');
			}
			else {//???? ??? ????? ??
				if (IsOperands(str[index]) && str[index] == 'i'&&str[index - 1] == 'p') {
					infics.push_back(str[index]);
					infics.push_back(str[index - 1]);
					index = index - 2;
					infics.push_back(' ');
				}
				else {
					if (IsOperands(str[index])) {  //???? ????? ?? ??????????? ? ????????? ?????
						while (index >= 0 && IsOperands(str[index])) {
							infics.push_back(str[index]);
							index--;
						}
						infics.push_back(' ');
					}
					else {
						if (str[index] == ')') {//???? ??????????? ????????????? ?????? ?? ??????? ?? ? ????
							operators.push_back(str[index]);
							index--;
						}
						else {
							if (str[index] == '(') {//???? ??????????? ????????????? ?????? ?? ??????? ??? ????????? ?? ????? ?? ????????????? ??????
								while (operators.back() != ')') {
									infics.push_back(operators.back());
									infics.push_back(' ');
									operators.pop_back();
								}
								operators.pop_back();
								index--;
							}
							else {
								if (IsOperators(str[index]) && operators.empty()) {//???? ??? ???? ,?? ???? ????? ?????? ?? ????? ??? ???? ?? ??????????? ? ????
									operators.push_back(str[index]);
									index--;
								}
								else {
									if (IsOperators(str[index]) && !operators.empty()) {//???? ??? ???? ? ????? ?????? ?? ??? ????
										if (priority(str[index]) >= priority(operators.back())) { //???? ??? ????????? ?????? 
											operators.push_back(str[index]);
										}
										else {//???? ??? ????????? ?????? ??? ????? ?????????? ?????????? ? ?????
											while (!operators.empty() && operators.back() != ')') {
												infics.push_back(operators.back());
												infics.push_back(' ');
												operators.pop_back();
											}
											operators.push_back(str[index]);
										}
										index--;
									}
								}
							}
						}
					}
				}
			}
		}
	}

	while (!operators.empty()) { //????? ?????????? ????????? ????????? ??????? ??????? ????? ? ???????????
		infics.push_back(operators.back());
		infics.push_back(' ');
		operators.pop_back();
	}
}

void Calculator::evaluate(string & str, vector<char>& infics, vector<double>& sum, vector<char>& operators)
{
	addNull(str);
	while (!infics.empty()) {
		infics.pop_back();
	}
	inficToPrefics(str, infics, operators);
	//?????????? ???????? ?????????? ?????....
	double doubleNumber = 0;
	string stringNumber = ("");
	int index = 0;
	while (index != infics.size()) {//???? ??? ????? ??????????
		if (IsOperands(infics[index]) && infics[index] == 'e') {
			double e = 2.718281828459045235360287;
			sum.push_back(e);
			index = index + 1;
		}
		else {//???? ??? ????? ??
			if (IsOperands(infics[index]) && infics[index] == 'i'&&infics[index + 1] == 'p') {
				double pi = 3.141592653589793238462643;
				sum.push_back(pi);
				index = index + 2;
			}
			else {
				if (IsOperands(infics[index])) {//???? ??? ?????
					while (IsOperands(infics[index])) {//???? ?? ???????? ?? ????? , ?????? ????? ??????
						stringNumber.push_back(infics[index]);
						index++;
					}
					reverse(stringNumber.begin(), stringNumber.end());
					doubleNumber = atof(stringNumber.c_str());//??????? ?????? ? ????
					sum.push_back(doubleNumber);
					stringNumber = "";
					doubleNumber = 0;
				}
				else {
					if (infics[index] == ' ') {//???? ?????? ?? ??????? ?? ????????? ???????
						index++;
					}
					else {
						if (IsOperators(infics[index])) {//???? ???????? ???????? ?? ??????? ????????? ??? ???????? ? ???????????? ????????? ? ?? ?? ????? ??????????? ????? ???????????
							int i = index;
							int numberOfOperators = 0;
							while (i < infics.size() && IsOperators(infics[i])) {//??????? ?????????? ?????? ?????? ????????
								numberOfOperators++;
								i = i + 2;
							}
							//if (sum.size() == numberOfOperators && infics[index] == '+') {//???? ???????? ????????? ? ? ????? ????? ?????? ????? ?????
							//	double value = sum.back();
							//	value = 0 + value;
							//	sum.pop_back();
							//	sum.push_back(value);
							//	index++;
							//}
							//else {
							if (sum.size() == numberOfOperators && infics[index] == '-') {//???? ???????? ????????? ? ? ????? ????? ?????? ????? ?????
								double value = sum.back();
								value = 0 - value;
								sum.pop_back();
								sum.push_back(value);
								index++;
							}
							else {
								double first;
								double second;
								first = sum.back();
								sum.pop_back();
								second = sum.back();
								sum.pop_back();
								switch (infics[index]) //???????? ?? ??????? ????????
								{
								case'+':
									doubleNumber = first + second;
									sum.push_back(doubleNumber);
									doubleNumber = 0;
									break;
								case'-':
									doubleNumber = first - second;
									sum.push_back(doubleNumber);
									doubleNumber = 0;
									break;
								case'*':
									doubleNumber = first * second;
									sum.push_back(doubleNumber);
									doubleNumber = 0;
									break;
								case'/':
									doubleNumber = first / second;
									sum.push_back(doubleNumber);
									doubleNumber = 0;
									break;
								case'^':
									doubleNumber = pow(first, second);
									sum.push_back(doubleNumber);
									doubleNumber = 0;
									break;
								}
								first = 0;
								second = 0;
								index++;
							}

						}
						else {// ???? ????? ???? ???????? ??? ????? ?????????? ,?? ?? ?????????? ????? ?? ? ????????? ????????
							double doubleForOneArgument = 0;
							if (infics[index] == 's' && infics[index + 1] == 'o' && infics[index + 2] == 'c') {
								doubleForOneArgument = sum.back();
								sum.pop_back();
								doubleNumber = cos(doubleForOneArgument);
								sum.push_back(doubleNumber);
								doubleNumber = 0;
								index += 3;
							}
							else {
								if (infics[index] == 'n' && infics[index + 1] == 'i' && infics[index + 2] == 's') {
									doubleForOneArgument = sum.back();
									sum.pop_back();
									doubleNumber = sin(doubleForOneArgument);
									sum.push_back(doubleNumber);
									doubleNumber = 0;
									index += 3;
								}
								else {
									if (infics[index] == 'g' && infics[index + 1] == 't' && infics[index + 2] == 'c') {
										doubleForOneArgument = sum.back();
										sum.pop_back();
										doubleNumber = 1.0 / tan(doubleForOneArgument);
										sum.push_back(doubleNumber);
										doubleNumber = 0;
										index += 3;
									}

									else {
										if (infics[index] == 'g' && infics[index + 1] == 't') {
											doubleForOneArgument = sum.back();
											sum.pop_back();
											doubleNumber = tan(doubleForOneArgument);
											sum.push_back(doubleNumber);
											doubleNumber = 0;
											index += 2;
										}
										else {
											if (infics[index] == 'g' && infics[index + 1] == 'o' && infics[index + 2] == 'l') {
												doubleForOneArgument = sum.back();
												sum.pop_back();
												doubleNumber = log10(doubleForOneArgument);
												sum.push_back(doubleNumber);
												doubleNumber = 0;
												index += 3;
											}
											else {
												if (infics[index] == 'n' && infics[index + 1] == 'l') {
													doubleForOneArgument = sum.back();
													sum.pop_back();
													doubleNumber = log(doubleForOneArgument);
													sum.push_back(doubleNumber);
													doubleNumber = 0;
													index += 2;
												}
												else {
													if (infics[index] == 't' && infics[index + 1] == 'r' && infics[index + 2] == 'q' && infics[index + 3] == 's') {
														doubleForOneArgument = sum.back();
														sum.pop_back();
														doubleNumber = sqrt(doubleForOneArgument);
														sum.push_back(doubleNumber);
														doubleNumber = 0;
														index += 4;
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}

void Calculator::addNull(string & str)
{
	 int index = 0;
	string hren = "0";
	while (index < str.length()) {
		if (str[index] == '-' && index == 0) {
			str.insert(index, hren);
			index++;
		}
		else {
			if (str[index] == '-' && str[index - 1] == '(') {
				str.insert(index, hren);
				index++;
			}
		}
		index++;
	}
}

void Calculator::validation(string & str)
{
	try {
		int numbers=0;
		for (int i = 0; i < str.size(); i++) {
			if (IsOperands(str[i]))numbers++;
		}
		if (numbers==0) {
			throw out_of_range("Incorrect input.");
		}
	}
	catch (out_of_range &e) {
		cout << "There are not numbers in input" << endl;
		system("PAUSE");
		exit(0);
	}

	try {
		for (int i = str.size()-1; i >= 0; i--) {
			if (str[i] == 'e') {
				if (i == str.size() - 1 && i - 1 >= 0 && IsOperands(str[i - 1])) {
					throw out_of_range("Incorrect input.");
				}
				else {
					if (i == 0 && i + 1 <= str.size() - 1 && IsOperands(str[i + 1])) {
						throw out_of_range("Incorrect input.");
					}
					else {
						if (i - 1 >= 0 && i + 1 <= str.size() - 1 && IsOperands(str[i + 1]) && IsOperands(str[i - 1])) {
							throw out_of_range("Incorrect input.");
						}
					}
				}
			}
			if (str[i] == 'i'&& i>=1 &&str[i - 1] == 'p') {
				if (i == str.size() - 1 && i - 2 >= 0 && IsOperands(str[i - 2])) {
					throw out_of_range("Incorrect input.");
				}
				else {
					if (i == 1 && i + 1 <= str.size() - 1 && IsOperands(str[i + 1])) {
						throw out_of_range("Incorrect input.");
					}
					else {
						if (i - 2 >= 0 && i + 1 <= str.size() - 1 && IsOperands(str[i + 1]) && IsOperands(str[i - 2])) {
							throw out_of_range("Incorrect input.");
						}
					}
				}
			}
		}
	}
	catch (out_of_range &e) {
		cout << "There are constants with operands" << endl;
		system("PAUSE");
		exit(0);
	}
	//???????? ??????????? ?????????? ????????
	int indexChar = 0;
	try {//???????? ?? ??, ??? ?????? ??????? ?? ???? ????????
		int val = 1;
			for (int index = str.size()-1; index >= 0; index--) {
				if (index >= 1 && str[index] == 'i' && str[index - 1] != 'p') {
					val = 0;
					indexChar = index;
					throw out_of_range("Incorrect input.");
				}
				if (index+1<=str.size() &&str[index] == 'p'&& str[index + 1] != 'i') {
					val = 0;
					indexChar = index;
					throw out_of_range("Incorrect input.");
				}
				if (index == 0 && str[index] == 'i') {
					val = 0;
					indexChar = index;
					throw out_of_range("Incorrect input.");
				}
				if (!IsOperands(str[index]) && !IsOperators(str[index])&&str[index]!='('&&str[index] != ')') {
					if (index >= 2 && str[index] == 's' && str[index - 1] == 'o' && str[index - 2] == 'c') {
						val = 1;
						index = index - 3;
					}
					else {
						if (index >= 2 && str[index] == 'n' && str[index - 1] == 'i' && str[index - 2] == 's') {
							val = 1;
							index = index - 3;
						}
						else {
							if (index >= 2 && str[index] == 'g' && str[index - 1] == 't' &&index >= 2 && str[index - 2] == 'c') {
								val = 1;
								index = index - 3;
							}

							else {
								if (index >= 1 && str[index] == 'g' && str[index - 1] == 't') {
									val = 1;
									index = index - 2;
								}
								else {
									if (index >= 2 && str[index] == 'g' && str[index - 1] == 'o' && str[index - 2] == 'l') {
										val = 1;
										index = index - 3;
									}
									else {
										if (index >= 1 && str[index] == 'n' && str[index - 1] == 'l') {
											val = 1;
											index = index - 2;
										}
										else {
											if (index >= 3 && str[index] == 't' && str[index - 1] == 'r' && str[index - 2] == 'q'&& str[index - 3] == 's') {
												val = 1;
												index = index - 4;
											}
											else {
												val=0;
											}
										}
									}
								}
							}
						}
					}
				}
				if (val == 0) {
					indexChar = index;
					throw out_of_range("Incorrect input.");
				}
			}
		
		
	}
	catch (out_of_range &e) {
		cout << "You must wright a correct input, incurrent char simvol in index["<<indexChar<<"]"<< endl;
		system("PAUSE");
		exit(0);
	}

	try {//???????? ?? ??, ??? ?????? ??????? ?? ???? ????????
		if (str=="") {
			throw out_of_range("Incorrect input.");
		}
	}
	catch (out_of_range &e) {
		cout << "You must wright a correct input" << endl;
		system("PAUSE");
		exit(0);
	}

try {//???????? ?? ??, ??? ?????? ??????? ?? ???? ????????
	if (IsOperators(str[0])&&str[0]!='-') {
		throw out_of_range("Incorrect input.");
	}
}
catch (out_of_range &e) {
	cout << "Incorrect input in index [0]" << endl;
	system("PAUSE");
	exit(0);
}

//???????? ?? ?????????? ?????????? ????????????? ? ????????????? ??????
	int open = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(')open++;
	}
	try {
		int open = 0;
		int end = 0;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == '(')open++;
			if (str[i] == ')')end++;
		}
		if (open != end) {
			throw out_of_range("Incorrect input.");
		}
	}
	catch (out_of_range &e) {
		cout << "The number of opening boxes is not equal to the number of closing" << endl;
		system("PAUSE");
		exit(0);
	}

	//???????? ?? ?? ????????? ?????? ?????? ?????? ????????
	int indexInException = 0;
	for (int i = 0; i < str.size() - 1; i++) {
		if (IsOperators(str[i]) && IsOperators(str[i + 1])) {
			indexInException = i;
		}
		try {
			if (IsOperators(str[i]) && IsOperators(str[i + 1])) {
				throw out_of_range("Incorrect input.");
			}
		}
		catch (out_of_range &e) {
			cout << "Several consecutive signs of operators in index[" << indexInException - open << "]" << endl;
			system("PAUSE");
			exit(0);
		}
	}

	// ???????? ?? ??????? ?????? ????????(????? ?? ???? ?? ????
	try {
		int quantity = 0;
		for (int i = 0; i < str.size(); i++) {
			if (IsOperators(str[i]))quantity++;
			}
		for (int index = str.size() - 1; index >= 0; index--) {
			if (!IsOperands(str[index]) && !IsOperators(str[index]) && str[index] != '('&&str[index] != ')') {
				if (index >= 2 && str[index] == 's' && str[index - 1] == 'o' && str[index - 2] == 'c') {
					quantity++;
					index = index - 3;
				}
				else {
					if (index >= 2 && str[index] == 'n' && str[index - 1] == 'i' && str[index - 2] == 's') {
						quantity++;
						index = index - 3;
					}
					else {
						if (index >= 2 && str[index] == 'g' && str[index - 1] == 't' &&index >= 2 && str[index - 2] == 'c') {
							quantity++;
							index = index - 3;
						}

						else {
							if (index >= 1 && str[index] == 'g' && str[index - 1] == 't') {
								quantity++;
								index = index - 2;
							}
							else {
								if (index >= 2 && str[index] == 'g' && str[index - 1] == 'o' && str[index - 2] == 'l') {
									quantity++;
									index = index - 3;
								}
								else {
									if (index >= 1 && str[index] == 'n' && str[index - 1] == 'l') {
										quantity++;
										index = index - 2;
									}
									else {
										if (index >= 3 && str[index] == 't' && str[index - 1] == 'r' && str[index - 2] == 'q'&& str[index - 3] == 's') {
											quantity++;
											index = index - 4;
										}
										else {

										}
									}
								}
							}
						}
					}
				}
			}
		}
		if (quantity == 0) {
			throw out_of_range("Incorrect input.");
		}
	}
	catch (out_of_range &e) {
		cout << "There are no operation signs in the expression" << endl;
		system("PAUSE");
		exit(0);
	}

	//???????? ?? ??????? ???????? ? ??????
	int indexOfSpaces = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == ' ')indexOfSpaces = i;
	}
	try {
		int quantity = 0;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == ' ')quantity++;
		}
		if (quantity != 0) {
			throw out_of_range("Incorrect input.");
		}
	}
	catch (out_of_range &e) {
		cout << "Contains spaces in the expression record in index[" << indexOfSpaces - open << "]" << endl;
		system("PAUSE");
		exit(0);
	}

	//???????? ?? ?? ??? ?????? ???????????? ?? ?? ???? ????????
	try {
		if (IsOperators(str[str.size() - 1])) {
			throw out_of_range("Incorrect input.");
		}
	}
	catch (out_of_range &e) {
		cout << "The record ends in a sign of the operation[" << str.size() - 1 << "]" << endl;
		system("PAUSE");
		exit(0);
	}

	//???????? ?? ??????? ????????? ????????? ? ??????(????? ??? ??? ? ??)
	int indexForChar = 0;
	for (int i = 0; i < str.size(); i++) {
		if (IsOperands(str[i]) || IsOperators(str[i]) || str[i] == '(' || str[i] == ')' || str[i] == 'c' || str[i] == 'o' || str[i] == 's' || str[i] == 't' || str[i] == 'g' || str[i] == 'i' || str[i] == 'l' || str[i] == 'q' || str[i] == 'r' || str[i] == 'n') {

		}
		else {
			indexForChar = i;
		}
	}
	try {
		int quantity = 1;
		for (int i = 0; i < str.size(); i++) {
			if (IsOperands(str[i]) || IsOperators(str[i]) || str[i] == '(' || str[i] == ')' || str[i] == 'c' || str[i] == 'o' || str[i] == 's' || str[i] == 't' || str[i] == 'g' || str[i] == 'i' || str[i] == 'l' || str[i] == 'q' || str[i] == 'r' || str[i] == 'n') {
				quantity = 1;
			}
			else {
				quantity = 0;
			}
			if (quantity == 0) {
				throw out_of_range("Incorrect input.");
			}
		}
	}
	catch (out_of_range &e) {
		cout << "There are char incorrent elements in index[" << indexForChar - open << "]" << endl;
		system("PAUSE");
		exit(0);
	}
}

void Calculator::printValue(vector<double>& sum)
{
	if (sum.size() != 0) {
		cout << sum.back() << endl; //????? ???????? ????????? ????? ? ???????????? ??????
	}
	else cout << "You must use function evaluate before use function printValue" << endl;
}

void Calculator::printPrefics(vector<char>& infics)
{
	for (int i = infics.size() - 1; i >= 0; i--) {
		cout << infics[i];
	}
}

void Calculator::readString(string & read)
{
	str = read;
}

void Calculator::inficToPrefics()
{
	return inficToPrefics(str,infics,operators);
}

string Calculator::readPreficsForm(vector<char>& infics)
{
	if (infics.size() != 0) {
		string str = "";
		for (int i = infics.size() - 1; i >= 0; i--) {
			str.push_back(infics[i]);
		}
		return str;
	}
	else {
		cout << "You must use functoin inficsToPrefics befor use this function" << endl;
		string str = "";
		return str;
	}
}

void Calculator::evaluate()
{
    return evaluate(str,infics,sum,operators);
}

double Calculator::readEvaluate(vector<double>& sum)
{
	if (sum.size() != 0) {
		return sum.back();
	}
	else {
		cout << "You must use function evaluate before use function printValue" << endl;
		return -1;
	}
}

void Calculator::validation()
{
	return validation(str);
}

void Calculator::validationForTests(string & str)
{

	int numbers = 0;
	for (int i = 0; i < str.size(); i++) {
		if (IsOperands(str[i]))numbers++;
	}
	if (numbers == 0) {
		throw out_of_range("Incorrect input.");
	}



	for (int i = str.size() - 1; i >= 0; i--) {
		if (str[i] == 'e') {
			if (i == str.size() - 1 && i - 1 >= 0 && IsOperands(str[i - 1])) {
				throw out_of_range("Incorrect input.");
			}
			else {
				if (i == 0 && i + 1 <= str.size() - 1 && IsOperands(str[i + 1])) {
					throw out_of_range("Incorrect input.");
				}
				else {
					if (i - 1 >= 0 && i + 1 <= str.size() - 1 && IsOperands(str[i + 1]) && IsOperands(str[i - 1])) {
						throw out_of_range("Incorrect input.");
					}
				}
			}
		}
		if (str[i] == 'i'&& i >= 1 && str[i - 1] == 'p') {
			if (i == str.size() - 1 && i - 2 >= 0 && IsOperands(str[i - 2])) {
				throw out_of_range("Incorrect input.");
			}
			else {
				if (i == 1 && i + 1 <= str.size() - 1 && IsOperands(str[i + 1])) {
					throw out_of_range("Incorrect input.");
				}
				else {
					if (i - 2 >= 0 && i + 1 <= str.size() - 1 && IsOperands(str[i + 1]) && IsOperands(str[i - 2])) {
						throw out_of_range("Incorrect input.");
					}
				}
			}
		}
	}

	//???????? ??????????? ?????????? ????????
	int indexChar = 0;

	int val = 1;
	for (int index = str.size() - 1; index >= 0; index--) {
		if (index >= 1 && str[index] == 'i' && str[index - 1] != 'p') {
			val = 0;
			indexChar = index;
			throw out_of_range("Incorrect input.");
		}
		if (index + 1 <= str.size() && str[index] == 'p'&& str[index + 1] != 'i') {
			val = 0;
			indexChar = index;
			throw out_of_range("Incorrect input.");
		}
		if (index == 0 && str[index] == 'i') {
			val = 0;
			indexChar = index;
			throw out_of_range("Incorrect input.");
		}
		if (!IsOperands(str[index]) && !IsOperators(str[index]) && str[index] != '('&&str[index] != ')') {
			if (index >= 2 && str[index] == 's' && str[index - 1] == 'o' && str[index - 2] == 'c') {
				val = 1;
				index = index - 3;
			}
			else {
				if (index >= 2 && str[index] == 'n' && str[index - 1] == 'i' && str[index - 2] == 's') {
					val = 1;
					index = index - 3;
				}
				else {
					if (index >= 2 && str[index] == 'g' && str[index - 1] == 't' &&index >= 2 && str[index - 2] == 'c') {
						val = 1;
						index = index - 3;
					}

					else {
						if (index >= 1 && str[index] == 'g' && str[index - 1] == 't') {
							val = 1;
							index = index - 2;
						}
						else {
							if (index >= 2 && str[index] == 'g' && str[index - 1] == 'o' && str[index - 2] == 'l') {
								val = 1;
								index = index - 3;
							}
							else {
								if (index >= 1 && str[index] == 'n' && str[index - 1] == 'l') {
									val = 1;
									index = index - 2;
								}
								else {
									if (index >= 3 && str[index] == 't' && str[index - 1] == 'r' && str[index - 2] == 'q'&& str[index - 3] == 's') {
										val = 1;
										index = index - 4;
									}
									else {
										val = 0;
									}
								}
							}
						}
					}
				}
			}
		}
		if (val == 0) {
			indexChar = index;
			throw out_of_range("Incorrect input.");
		}
	}



	if (str == "") {
		throw out_of_range("Incorrect input.");
	}



	if (IsOperators(str[0]) && str[0] != '-') {
		throw out_of_range("Incorrect input.");
	}


	//???????? ?? ?????????? ?????????? ????????????? ? ????????????? ??????

	int open = 0;
	int end = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(')open++;
		if (str[i] == ')')end++;
	}
	if (open != end) {
		throw out_of_range("Incorrect input.");
	}


	//???????? ?? ?? ????????? ?????? ?????? ?????? ????????
	int indexInException = 0;
	for (int i = 0; i < str.size() - 1; i++) {
		if (IsOperators(str[i]) && IsOperators(str[i + 1])) {
			indexInException = i;
		}

		if (IsOperators(str[i]) && IsOperators(str[i + 1])) {
			throw out_of_range("Incorrect input.");
		}
	}

	// ???????? ?? ??????? ?????? ????????(????? ?? ???? ?? ????

	int quantity = 0;
	for (int i = 0; i < str.size(); i++) {
		if (IsOperators(str[i]))quantity++;
	}
	for (int index = str.size() - 1; index >= 0; index--) {
		if (!IsOperands(str[index]) && !IsOperators(str[index]) && str[index] != '('&&str[index] != ')') {
			if (index >= 2 && str[index] == 's' && str[index - 1] == 'o' && str[index - 2] == 'c') {
				quantity++;
				index = index - 3;
			}
			else {
				if (index >= 2 && str[index] == 'n' && str[index - 1] == 'i' && str[index - 2] == 's') {
					quantity++;
					index = index - 3;
				}
				else {
					if (index >= 2 && str[index] == 'g' && str[index - 1] == 't' &&index >= 2 && str[index - 2] == 'c') {
						quantity++;
						index = index - 3;
					}

					else {
						if (index >= 1 && str[index] == 'g' && str[index - 1] == 't') {
							quantity++;
							index = index - 2;
						}
						else {
							if (index >= 2 && str[index] == 'g' && str[index - 1] == 'o' && str[index - 2] == 'l') {
								quantity++;
								index = index - 3;
							}
							else {
								if (index >= 1 && str[index] == 'n' && str[index - 1] == 'l') {
									quantity++;
									index = index - 2;
								}
								else {
									if (index >= 3 && str[index] == 't' && str[index - 1] == 'r' && str[index - 2] == 'q'&& str[index - 3] == 's') {
										quantity++;
										index = index - 4;
									}
									else {

									}
								}
							}
						}
					}
				}
			}
		}
	}
	if (quantity == 0) {
		throw out_of_range("Incorrect input.");
	}


	//???????? ?? ??????? ???????? ? ??????
	int indexOfSpaces = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == ' ')indexOfSpaces = i;
	}

	 quantity = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == ' ')quantity++;
	}
	if (quantity != 0) {
		throw out_of_range("Incorrect input.");
	}


	//???????? ?? ?? ??? ?????? ???????????? ?? ?? ???? ????????

	if (IsOperators(str[str.size() - 1])) {
		throw out_of_range("Incorrect input.");
	}


	//???????? ?? ??????? ????????? ????????? ? ??????(????? ??? ??? ? ??)
	int indexForChar = 0;
	for (int i = 0; i < str.size(); i++) {
		if (IsOperands(str[i]) || IsOperators(str[i]) || str[i] == '(' || str[i] == ')' || str[i] == 'c' || str[i] == 'o' || str[i] == 's' || str[i] == 't' || str[i] == 'g' || str[i] == 'i' || str[i] == 'l' || str[i] == 'q' || str[i] == 'r' || str[i] == 'n') {

		}
		else {
			indexForChar = i;
		}
	}

	quantity = 1;
	for (int i = 0; i < str.size(); i++) {
		if (IsOperands(str[i]) || IsOperators(str[i]) || str[i] == '(' || str[i] == ')' || str[i] == 'c' || str[i] == 'o' || str[i] == 's' || str[i] == 't' || str[i] == 'g' || str[i] == 'i' || str[i] == 'l' || str[i] == 'q' || str[i] == 'r' || str[i] == 'n') {
			quantity = 1;
		}
		else {
			quantity = 0;
		}
		if (quantity == 0) {
			throw out_of_range("Incorrect input.");
		}
	}
}

void Calculator::printPrefics()
{
	return printPrefics(infics);
}

void Calculator::printValue()
{
	return printValue(sum);
}


