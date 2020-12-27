#include<iostream>
#include<string>
#include<vector>
#include<conio.h>
#include<Windows.h>


using namespace std;

string Vvod;
vector<int> PervoeChislo;
vector<int> VtoroeChislo;
vector<int> Resultat;

vector <int> Zapolnenie(vector <int>& a, vector <int>& b); 
void Delenie();
void Vstuplenie();
void Summa();
void Vichitanie();
void PokazRezultata();
void Umnozhenie();
int ProverkaOperand();

int Perevod(char Simvol);
int ProverkaStroki();
int ProverkaNaBolshe();



int DlyaDelenia;
int Operator;
int Dlinna_Chislo;

void Vstuplenie() {
	cout << "Приветствую>>>" << endl;
	cout << "Вы можете посчитать:" << endl;
	cout << "1. Сумма двух чисел (+) >>" << endl;
	cout << "2. Разность двух чисел (-) >>" << endl;
	cout << "3. Произведение двух чисел (*) >>" << endl;
	cout << "4. Частное двух чисел (/) (But not really) >>" << endl;
	cout << "5. Побитовое отрицание (|) (Still nope) >>" << endl;
	cout << "0. Выйти (!) >>" << endl;
	cout << "Пример ввода: 12121212*21212121" << endl;
	cout << ">>" << endl;
}

int ProverkaOperand() {
	Operator = 0;
	for (int i = 0; i < Vvod.length(); i++) {
		if (Vvod[i] == '+') return Operator = '+';
		else if (Vvod[i] == '-') return Operator = '-';
		else if (Vvod[i] == '*') return Operator = '*';
		else if (Vvod[i] == '/') return Operator = '/';
		else if (Vvod[i] == '%') return Operator = '%';
		else if (Vvod[i] == '!') return Operator = '!';
	}
}

int main() {
	setlocale(LC_ALL, "Russian");

		do {
			Vstuplenie();
			do {
				cout << "Введите числа и действие, или ! для выхода." << endl;
				cout << ">>>";
				cin >> Vvod;
				if (ProverkaStroki()) {
					system("cls");
					cout << "Ввод неверен, напишите как в примере" << endl;
					cout << ">>>";
					system("pause");
				}
				system("cls");
			} while (ProverkaStroki());
			ProverkaOperand();
			switch (Operator) {
			case '+':
				Zapolnenie(PervoeChislo, VtoroeChislo);
				Summa();
				PokazRezultata();
				break;
			case '-':
				Zapolnenie(PervoeChislo, VtoroeChislo);
				Vichitanie();
				PokazRezultata();
				break;
			case '*':
				Zapolnenie(PervoeChislo, VtoroeChislo);
				Umnozhenie();
				PokazRezultata();
				break;
			case '/': break;
			case '|':

				break;
			}
		} while (Operator != '!');

		system("pause");
		return 0;
}
	


int ProverkaNaBolshe() {
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

int ProverkaStroki() {
	int counter = 0;
	Dlinna_Chislo = 0;
	for (int i = 0; i < Vvod.length(); i++) {
		if (Vvod[i] == '0' || Vvod[i] == '1' || Vvod[i] == '2' || Vvod[i] == '3' || Vvod[i] == '4' || Vvod[i] == '5' || Vvod[i] == '6' || Vvod[i] == '7' || Vvod[i] == '8' || Vvod[i] == '9') {
			if (counter == 0) Dlinna_Chislo++;
		}
		else counter++;
	}
	if (counter > 1 || counter == 0)
		return true;
	if (counter == 1) {
		if (Vvod[Dlinna_Chislo] == '+' || Vvod[Dlinna_Chislo] == '-' || Vvod[Dlinna_Chislo] == '*' || Vvod[Dlinna_Chislo] == '/' || Vvod[Dlinna_Chislo] == '|' || Vvod[Dlinna_Chislo] == '!')
			return false;
		else return true;
	}
}

vector <int> Zapolnenie(vector <int>& PervoeChislo, vector <int>& VtoroeChislo) {
	for (int i = 0; i < Dlinna_Chislo; i++) {
		PervoeChislo.push_back(Perevod(Vvod[i]));
	}
	for (int i = Dlinna_Chislo + 1; i < Vvod.length(); i++) {
		VtoroeChislo.push_back(Perevod(Vvod[i]));
	}
	return PervoeChislo, VtoroeChislo;
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
	int counter = 0;
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


void Vichitanie() {
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

	if (ProverkaNaBolshe()) {
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

void Delenie() {
	
}

void Umnozhenie() {
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

