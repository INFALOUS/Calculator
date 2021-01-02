#include <iostream>
#include <vector>
#include "Summa.h"

using namespace std;

void Summa(vector<int>& PervoeChislo, vector<int>& VtoroeChislo, vector<int>& Resultat) {
	int flag = 0;

	if (PervoeChislo.size() > VtoroeChislo.size()) {
		for (int i = PervoeChislo.size() - VtoroeChislo.size(); i > 0; i--) {
			VtoroeChislo.insert(VtoroeChislo.begin(), 0);
		}

	}
	else if (VtoroeChislo.size() > PervoeChislo.size()) {
		for (int i = VtoroeChislo.size() - PervoeChislo.size(); i > 0; i--) {
			PervoeChislo.insert(PervoeChislo.begin(), 0);
		}
	}

	for (int i = PervoeChislo.size() - 1; i >= 0; i--) {

		Resultat.insert(Resultat.begin(), (PervoeChislo[i] + VtoroeChislo[i] + flag) % 10);

		if (i == 0 && PervoeChislo[i] + VtoroeChislo[i] + flag > 9)
			Resultat.insert(Resultat.begin(), 1);

		if ((PervoeChislo[i] + VtoroeChislo[i] + flag) > 9)
			flag = 1;
		else
			flag = 0;
	}
}
