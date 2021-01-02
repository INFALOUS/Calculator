#include <iostream>
#include <string>
#include <vector>
#include "Perevod.h"

using namespace std;

vector <int> Zapolnenie(vector <int>& PervoeChislo, vector <int>& VtoroeChislo, string& Vvod, int& DlinaPervoe) {
	for (int i = 0; i < DlinaPervoe; i++) {
		PervoeChislo.push_back(Perevod(Vvod[i]));
	}
	for (int i = DlinaPervoe + 1; i < Vvod.length(); i++) {
		VtoroeChislo.push_back(Perevod(Vvod[i]));
	}
	return PervoeChislo, VtoroeChislo;
}
