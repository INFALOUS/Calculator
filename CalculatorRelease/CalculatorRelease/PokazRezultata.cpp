#include <iostream>
#include <vector>
#include "PokazRezultata.h"

using namespace std;

void PokazRezultata(vector<int>& PervoeChislo, vector<int>& VtoroeChislo, vector<int>& Resultat) {
	int counter = 0;
	cout << "Result is:" << endl;
	for (int i = 0; i < Resultat.size(); i++) {
		if (Resultat[i] == 0) counter++; else break;
	}
	if (Resultat.size() >= 1 & counter > 0) Resultat.erase(Resultat.begin(), Resultat.begin() + counter - 1);
	for (int i = 0; i < Resultat.size(); i++) {
		cout << Resultat[i];
	}
	cout << "" << endl;
	cout << ">>>" << endl;
	PervoeChislo.clear();
	VtoroeChislo.clear();
	Resultat.clear();
}