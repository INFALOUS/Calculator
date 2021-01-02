#include<iostream>
#include<string>
#include<cmath>
#include<cstdlib>
#include<vector>
#include<conio.h>
#include<Windows.h>
#include "Delenie.h"
#include "Perevod.h"
#include "PokazRezultata.h"
#include "ProverkaNaBolshe.h"
#include "ProverkaOperand.h"
#include "ProverkaStroki.h"
#include "Summa.h"
#include "Umnozhenie.h"
#include "Vichitanie.h"
#include "Vstuplenie.h"
#include "Zapolnenie.h"


using namespace std;

void Vstuplenie();
vector <int> Zapolnenie(vector <int>& a, vector <int>& b, string& Vvod, int& Dlina_Pervoe);
void Delenie(vector <int>& PervoeChislo, vector <int>& VtoroeChislo, vector <int>& Resultat);
void Summa(vector <int>& PervoeChislo, vector <int>& VtoroeChislo, vector <int>& Resultat);
void Vichitanie(vector <int>& PervoeChislo, vector <int>& VtoroeChislo, vector <int>& Resultat);
void PokazRezultata(vector <int>& PervoeChislo, vector <int>& VtoroeChislo, vector <int>& Resultat);
void Umnozhenie(vector <int>& PervoeChislo, vector <int>& VtoroeChislo, vector <int>& Resultat);
int ProverkaOperand(string& Vvod, int& Operator);

int Perevod(char Simvol);
int ProverkaStroki(string& Vvod, int& DlinaPervoe);
int ProverkaNaBolshe(vector <int>& PervoeChislo, vector <int>& VtoroeChislo);

int main() {
	setlocale(LC_ALL, "Russian");
	vector <int> PervoeChislo;
	vector <int> VtoroeChislo;
	vector <int> Resultat;
	string Vvod;
	int Operator = 0;
	int DlinaPervoe = 0;

	do {
		do {
			Vstuplenie();
			cout << "Введите числа и действие, или ! для выхода." << endl;
			cout << ">>>";
			cin >> Vvod;
			if (ProverkaStroki(Vvod, DlinaPervoe)) {
				system("cls");
				cout << "Ввод неверен, напишите как в примере" << endl;
				cout << ">>>";
				system("pause");
			}
			system("cls");
		} while (ProverkaStroki(Vvod, DlinaPervoe));
		ProverkaOperand(Vvod, Operator);
		switch (Operator) {
		case '+':
			Zapolnenie(PervoeChislo, VtoroeChislo, Vvod, DlinaPervoe);
			Summa(PervoeChislo, VtoroeChislo, Resultat);
			PokazRezultata(PervoeChislo, VtoroeChislo, Resultat);
			break;
		case '-':
			Zapolnenie(PervoeChislo, VtoroeChislo, Vvod, DlinaPervoe);
			Vichitanie(PervoeChislo, VtoroeChislo, Resultat);
			PokazRezultata(PervoeChislo, VtoroeChislo, Resultat);
			break;
		case '*':
			Zapolnenie(PervoeChislo, VtoroeChislo, Vvod, DlinaPervoe);
			Umnozhenie(PervoeChislo, VtoroeChislo, Resultat);
			PokazRezultata(PervoeChislo, VtoroeChislo, Resultat);
			break;
		case '/': break;
		case '|':

			break;
		}
	} while (Operator != '!');

	system("pause");
	return 0;
}
