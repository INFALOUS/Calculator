#include <iostream>
#include <vector>
#include "Vichitanie.h"
#include "ProverkaNaBolshe.h"

using namespace std;

void Vichitanie(vector<int>& PervoeChislo, vector<int>& VtoroeChislo, vector<int>& Resultat) {
	int flag = 0;
	auto begin = Resultat.cbegin();

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

	if (ProverkaNaBolshe(PervoeChislo, VtoroeChislo)) {
		for (int i = PervoeChislo.size() - 1; i >= 0; i--) {
			if (PervoeChislo[i] < VtoroeChislo[i]) {
				Resultat.insert(Resultat.begin(), (PervoeChislo[i] + 10) - VtoroeChislo[i]);
				int Schet = i;
				while (Schet > 0) {
					if (PervoeChislo[Schet - 1] > 0) {
						PervoeChislo[Schet - 1] = PervoeChislo[Schet - 1] - 1;
						flag++;
						if (flag == 2)
							PervoeChislo[Schet - 1] += 1;
						break;
					}
					else {
						PervoeChislo[Schet - 1] = -1;
						Schet--;
					}
				}
			}
			else {
				Resultat.insert(Resultat.begin(), PervoeChislo[i] - VtoroeChislo[i]);
			}
			if (PervoeChislo[i] < 0 && i == 0) {
				Resultat[i] = 0;
			}
		}
		for (int i = 0; i < Resultat.size(); i++) {
			if (Resultat[i] < 0) {
				Resultat[i] = 0;
			}
		}
	}
	else {
		for (int i = PervoeChislo.size() - 1; i >= 0; i--) {
			if (VtoroeChislo[i] < PervoeChislo[i]) {
				Resultat.insert(Resultat.begin(), (VtoroeChislo[i] + 10) - PervoeChislo[i]);
				int Schet = i;
				while (Schet > 0) {
					if (VtoroeChislo[Schet - 1] != 0) {
						VtoroeChislo[Schet - 1] = VtoroeChislo[Schet - 1] - 1;
						flag++;
						if (flag == 2)
							VtoroeChislo[Schet - 1] += 1;
						break;
					}
					else {
						VtoroeChislo[Schet - 1] = -1;
						Schet--;
					}
				}
			}
			else {
				Resultat.insert(Resultat.begin(), VtoroeChislo[i] - PervoeChislo[i]);
			}
			if (VtoroeChislo[i] < 0 && i == 0) {
				Resultat[i] = 0;
			}
		}
		cout << "-";
	}
}