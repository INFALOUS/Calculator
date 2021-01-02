#include <vector>
#include <iostream>
#include "Perevod.h"

using namespace std;

int Perevod(char Simvol) {
	if (Simvol == '0')
		return 0;
	else if (Simvol == '1')
		return 1;
	else if (Simvol == '2')
		return 2;
	else if (Simvol == '3')
		return 3;
	else if (Simvol == '4')
		return 4;
	else if (Simvol == '5')
		return 5;
	else if (Simvol == '6')
		return 6;
	else if (Simvol == '7')
		return 7;
	else if (Simvol == '8')
		return 8;
	else if (Simvol == '9')
		return 9;
	else
		return 10;
}