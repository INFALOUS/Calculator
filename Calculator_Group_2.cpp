#include<iostream>
#include<string>
#include<vector>
#include<conio.h>
#include<Windows.h>

using namespace std;

string     Vvod;
vector<int> PervoeChislo;
vector<int> VtoroeChislo;
vector<int> Resultat;

void Fill();
void Summa();
void PokazRezultata();
int Perevod(char simbol);
int checkString();

int main() {
	setlocale(LC_ALL, "Russian");

	do {
		cout << "Введите первое число, операнд и второе число (1+1)" << endl;
		getline(cin, Vvod);
		if (checkString()) {
			system("cls");
			cout << "Выражение некорректно, введите верное" << endl;
			system("pause");
		}
		system("cls");
	} while (checkString());

	Fill();
	Summa();
	PokazRezultata();

	system("pause");
	return 0;
}

int checkString() {
	int counter = 0;

	for (int i = 0; i < Vvod.length(); i++) {
		if (Vvod[i] != '+' && Vvod[i] != '-' && Vvod[i] != '*' && Vvod[i] != '/' && Vvod[i] != '^' && Vvod[i] != ' ') {
			if (Perevod(Vvod[i]) == 10)
				counter++;
		}
	}
	if (counter > 0)
		return true;
	else
		return false;
}

void Fill() {
	int flag = 0;

	for (int i = 0; i < Vvod.length(); i++) {
		if (Vvod[i] != '+' && Vvod[i] != '-' && Vvod[i] != '*' && Vvod[i] != '/' && Vvod[i] != '^' && Vvod[i] != ' ') {
			if (flag == 0)
				PervoeChislo.push_back(Perevod(Vvod[i]));
			else
				VtoroeChislo.push_back(Perevod(Vvod[i]));
		}
		if (Vvod[i] == '+' || Vvod[i] == '-' || Vvod[i] == '*' || Vvod[i] == '/' || Vvod[i] == '^')
			flag++;
	}
}

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

void Summa() {
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

void PokazRezultata() {
	for (int i = 0; i < Resultat.size(); i++)
		cout << Resultat[i];
}

