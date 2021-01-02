#include <iostream>
#include <vector>
#include "ProverkaNaBolshe.h"

using namespace std;

int ProverkaNaBolshe(vector <int>& PervoeChislo, vector <int>& VtoroeChislo) {
	if (PervoeChislo.size() > VtoroeChislo.size())
		return 1;
	else if (VtoroeChislo.size() > PervoeChislo.size())
		return 0;

	for (int i = 0; i < PervoeChislo.size(); i++) {
		if (PervoeChislo[i] > VtoroeChislo[i])
			return 1;
		else if (VtoroeChislo[i] > PervoeChislo[i])
			return 0;
	}
}