#include <iostream>
#include <vector>
#include  "Umnozhenie.h"

using namespace std;

void Umnozhenie(vector<int>& PervoeChislo, vector<int>& VtoroeChislo, vector<int>& Resultat) {
	int flag = 0;
	int counter = 0;

	vector <int> Tecushiy;
	vector <int> PerviyNositel;
	vector <int> VtoroiNositel = { 0 };

	while (VtoroeChislo.empty() == false) {

		int def = 0;
		for (int i = PervoeChislo.size() - 1; i >= 0; i--) {
			Tecushiy.insert(Tecushiy.begin(), (PervoeChislo[i] * VtoroeChislo.back() + def) % 10);

			if (i == 0 && PervoeChislo[i] * VtoroeChislo.back() + def > 9)
				Tecushiy.insert(Tecushiy.begin(), (PervoeChislo[i] * VtoroeChislo.back() + def) / 10);

			if ((PervoeChislo[i] * VtoroeChislo.back() + def) > 9)
				def = (PervoeChislo[i] * VtoroeChislo.back() + def) / 10;
			else
				def = 0;
		}
		if (counter > 0)
			for (int i = counter; i >= 1; i--) {
				Tecushiy.push_back(0);
			}
		int j = Tecushiy.size() - VtoroiNositel.size();
		int k = Tecushiy.size() - PerviyNositel.size();

		if (PerviyNositel.empty()) {
			for (int i = abs(j); i > 0; i--) {
				VtoroiNositel.insert(VtoroiNositel.begin(), 0);
			}
		}
		else
			for (int i = abs(k); i > 0; i--) {
				PerviyNositel.insert(PerviyNositel.begin(), 0);
			}

		if (PerviyNositel.empty()) {
			for (int i = VtoroiNositel.size() - 1; i >= 0; i--) {
				PerviyNositel.insert(PerviyNositel.begin(), (VtoroiNositel[i] + Tecushiy[i] + flag) % 10);

				if (i == 0 && VtoroiNositel[i] + Tecushiy[i] + flag > 9)
					PerviyNositel.insert(PerviyNositel.begin(), 1);

				if ((VtoroiNositel[i] + Tecushiy[i] + flag) > 9)
					flag = 1;
				else
					flag = 0;
			}
			VtoroiNositel.clear();
		}
		else if (VtoroiNositel.empty()) {
			for (int i = PerviyNositel.size() - 1; i >= 0; i--) {
				VtoroiNositel.insert(VtoroiNositel.begin(), (PerviyNositel[i] + Tecushiy[i] + flag) % 10);

				if (i == 0 && PerviyNositel[i] + Tecushiy[i] + flag > 9)
					VtoroiNositel.insert(VtoroiNositel.begin(), 1);

				if ((PerviyNositel[i] + Tecushiy[i] + flag) > 9)
					flag = 1;
				else
					flag = 0;
			}
			PerviyNositel.clear();
		}

		counter++;
		Tecushiy.clear();
		VtoroeChislo.pop_back();
	}

	if (PerviyNositel.empty()) Resultat.swap(VtoroiNositel); else Resultat.swap(PerviyNositel);
	PerviyNositel.clear();
	VtoroiNositel.clear();
	Tecushiy.clear();
}