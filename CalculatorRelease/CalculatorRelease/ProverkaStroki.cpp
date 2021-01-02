#include <vector>
#include <string>
#include <iostream>
#include "ProverkaStroki.h"

using namespace std;

int ProverkaStroki(string& Vvod, int& DlinaPervoe) {
	int counter = 0;
	DlinaPervoe = 0;
	for (int i = 0; i < Vvod.length(); i++) {
		if (Vvod[i] == '0' || Vvod[i] == '1' || Vvod[i] == '2' || Vvod[i] == '3' || Vvod[i] == '4' || Vvod[i] == '5' || Vvod[i] == '6' || Vvod[i] == '7' || Vvod[i] == '8' || Vvod[i] == '9') {
			if (counter == 0) DlinaPervoe++;
		}
		else counter++;
	}
	if (counter > 1 || counter == 0)
		return true;
	if (counter == 1) {
		if (Vvod[DlinaPervoe] == '+' || Vvod[DlinaPervoe] == '-' || Vvod[DlinaPervoe] == '*' || Vvod[DlinaPervoe] == '/' || Vvod[DlinaPervoe] == '|' || Vvod[DlinaPervoe] == '!')
			return false;
		else return true;
	}
}