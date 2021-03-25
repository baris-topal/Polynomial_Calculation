
#include <iostream>
#include <string>
using namespace std;

void yaz(int kat[], int kuv[], int boyut) {
	string poli;

	for (int i = 0; i < boyut; i++) {
		if (kat[i] == 0) {}
		else if (kuv[i] == 0 && kat[i] != 0) {
			poli = poli + " " + to_string(kat[i]) + " +";
		}
		else {
			poli = poli + " " + to_string(kat[i]) + "x^" + to_string(kuv[i]) + " +";
		}
	}
	poli.pop_back();

	cout << poli << endl;
}
void topla(int p1_kat[], int p1_ust[], int p1_boyut) {
	int p2_boyut, * p2_kat, * p2_ust, * temp_kat, * temp_ust;
	cout << "Toplanacak polinomun eleman sayisini giriniz: ";
	cin >> p2_boyut;
	p2_kat = new int[p2_boyut];
	p2_ust = new int[p2_boyut];
	for (int i = 0; i < p2_boyut; i++) {
		cout << i + 1 << ". elemanin katsayisi: ";
		cin >> p2_kat[i];
		cout << i + 1 << ". elemanin kuvveti: ";
		cin >> p2_ust[i];
	}
	cout << "Polinom: ";
	yaz(p2_kat, p2_ust, p2_boyut);
	int temp_boyut = p1_boyut + p2_boyut;
	temp_kat = new int[temp_boyut];
	temp_ust = new int[temp_boyut];


	for (int i = 0; i < temp_boyut; i++) {
		if (i < p1_boyut) {
			temp_kat[i] = p1_kat[i];
			temp_ust[i] = p1_ust[i];
		}
		else {
			temp_kat[i] = p2_kat[i - p1_boyut];
			temp_ust[i] = p2_ust[i - p1_boyut];
		}

	}


	int son = temp_boyut, temp;
	for (int i = 0; i < son; i++)
	{
		for (int j = i + 1; j < son; j++)
		{
			if (temp_ust[i] == temp_ust[j]) {
				temp_kat[i] += temp_kat[j];
				temp = temp_kat[j];
				temp_kat[j] = temp_kat[son - 1];
				temp_kat[son - 1] = temp;

				temp = temp_ust[j];
				temp_ust[j] = temp_ust[son - 1];
				temp_ust[son - 1] = temp;
				son--;
			}
		}
		for (int k = 0; k < i; k++) {
			if (temp_ust[i] == temp_ust[k]) {
				temp_kat[k] += temp_kat[i];
				temp = temp_kat[i];
				temp_kat[i] = temp_kat[son - 1];
				temp_kat[son - 1] = temp;

				temp = temp_ust[i];
				temp_ust[i] = temp_ust[son - 1];
				temp_ust[son - 1] = temp;
				i--;
				son--;
			}
		}
	}
	cout << "Polinom Toplamasi: ";
	yaz(temp_kat, temp_ust, son);
}

void cikar(int p1_kat[], int p1_ust[], int p1_boyut) {
	int p2_boyut, * p2_kat, * p2_ust, * temp_kat, * temp_ust;
	cout << "Cikarilacak polinomun eleman sayisini giriniz: ";
	cin >> p2_boyut;
	p2_kat = new int[p2_boyut];
	p2_ust = new int[p2_boyut];
	for (int i = 0; i < p2_boyut; i++) {
		cout << i + 1 << ". elemanin katsayisi: ";
		cin >> p2_kat[i];
		cout << i + 1 << ". elemanin kuvveti: ";
		cin >> p2_ust[i];
	}
	cout << "Polinom: ";
	yaz(p2_kat, p2_ust, p2_boyut);
	int temp_boyut = p1_boyut + p2_boyut;
	temp_kat = new int[temp_boyut];
	temp_ust = new int[temp_boyut];


	for (int i = 0; i < temp_boyut; i++) {
		if (i < p1_boyut) {
			temp_kat[i] = p1_kat[i];
			temp_ust[i] = p1_ust[i];
		}
		else {
			temp_kat[i] = p2_kat[i - p1_boyut];
			temp_ust[i] = p2_ust[i - p1_boyut];
		}

	}


	int son = temp_boyut, temp;
	for (int i = 0; i < son; i++)
	{
		for (int j = i + 1; j < son; j++)
		{
			if (temp_ust[i] == temp_ust[j]) {
				temp_kat[i] -= temp_kat[j];
				temp = temp_kat[j];
				temp_kat[j] = temp_kat[son - 1];
				temp_kat[son - 1] = temp;

				temp = temp_ust[j];
				temp_ust[j] = temp_ust[son - 1];
				temp_ust[son - 1] = temp;
				son--;
			}
		}
		for (int k = 0; k < i; k++) {
			if (temp_ust[i] == temp_ust[k]) {
				temp_kat[k] -= temp_kat[i];
				temp = temp_kat[i];
				temp_kat[i] = temp_kat[son - 1];
				temp_kat[son - 1] = temp;

				temp = temp_ust[i];
				temp_ust[i] = temp_ust[son - 1];
				temp_ust[son - 1] = temp;
				i--;
				son--;
			}
		}
	}
	cout << "Polinom Cikarmasi: ";
	yaz(temp_kat, temp_ust, son);
}

int main()
{
	int* p1_kat, * p1_ust, p1_boyut;
	cout << "Polinomun eleman sayisini giriniz: ";
	cin >> p1_boyut;

	p1_kat = new int[p1_boyut];
	p1_ust = new int[p1_boyut];
	int sayac = 0;
	while (sayac < p1_boyut) {
		cout << sayac + 1 << ". elemanin katsayisi: ";
		cin >> p1_kat[sayac];
		cout << sayac + 1 << ". elemanin kuvveti: ";
		cin >> p1_ust[sayac];
		sayac++;
	}
	cout << "Polinom: ";
	yaz(p1_kat, p1_ust, p1_boyut);

	topla(p1_kat, p1_ust, p1_boyut);

	cikar(p1_kat, p1_ust, p1_boyut);

}
