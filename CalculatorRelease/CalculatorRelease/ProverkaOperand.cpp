#include <vector>
#include <string>
#include <iostream>
#include "ProverkaOperand.h"

using namespace std;

int ProverkaOperand(string& Vvod, int& Operator) {
	Operator = 0;
	for (int i = 0; i < Vvod.length(); i++) {
		if (Vvod[i] == '+') return Operator = '+';
		else if (Vvod[i] == '-') return Operator = '-';
		else if (Vvod[i] == '*') return Operator = '*';
		else if (Vvod[i] == '/') return Operator = '/';
		else if (Vvod[i] == '%') return Operator = '%';
		else if (Vvod[i] == '!') return Operator = '!';
	}
}