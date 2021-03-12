// RSA.cpp

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <time.h>
using namespace std;

void klucze_RSA();
int odwr_mod(int a, int n);
void czekaj(void);
int nwd(int a, int b);
int pot_mod(int a, int w, int n);
void kodowanie_RSA();

int main()
{
	int w;

	srand((unsigned)time(NULL));

	do
	{
		cout << "Szyfrowanie danych RSA\n"
			"-----------------------------\n"
			"\n\n"
			"MENU\n"
			"====\n"
			"[ 0 ] - Koniec pracy programu\n"
			"[ 1 ] - Generowanie kluczy RSA\n"
			"[ 2 ] - Kodowanie RSA\n\n";
			
		cin >> w;
		cout << "\n\n\n";
		switch (w)
		{
		case 1: klucze_RSA(); break;
		case 2: kodowanie_RSA(); break;
		}
		cout << "\n\n\n";
	} while (w != 0);

	return 0;
}
void czekaj(void) {

	char c[1];

	cout << "\nZapisz dane\n\n";
	cin.getline(c, 1);
	cin.getline(c, 1);
	for (int i = 1; i < 500; i++)
	{
		cout << endl;
	}
}
int nwd(int a, int b)
{
	int t;
	while (b != 0)
	{
		t = b;
		b = a % b;
		a = t;
	};
	return a;
}
int odwr_mod(int a, int n) {

	int a0, n0, p0, p1, q, r, t;

	p0 = 0; p1 = 1; a0 = a; n0 = n;
	q = n0 / a0;
	r = n0 % a0;
	while (r > 0)
	{
		t = p0 - q * p1;
		if (t >= 0)
			t = t % n;
		else
			t = n - ((-t) % n);
		p0 = p1; p1 = t;
		n0 = a0; a0 = r;
		q = n0 / a0;
		r = n0 % a0;
	}
	return p1;
}
void klucze_RSA() {
	const int tp[10] = { 11,13,17,19,23,29,31,37,41,43 };
	int p, q, phi, n, e, d;

	cout << "Generowanie kluczy RSA\n"
		"----------------------\n\n";

	do
	{
		p = tp[rand() % 10];
		q = tp[rand() % 10];
	} while (p == q);

	phi = (p - 1) * (q - 1);
	n = p * q;

	

	for (e = 3; nwd(e, phi) != 1; e += 2);
	d = odwr_mod(e, phi);

	

	cout << "KLUCZ PUBLICZNY\n"
		"wykladnik e = " << e
		<< "\n    modul n = " << n
		<< "\n\nKLUCZ PRYWATNY\n"
		"wykladnik d = " << d << endl;
	czekaj();
}
int pot_mod(int a, int w, int n) {

	int pot, wyn, q;

	pot = a; wyn = 1;
	for (q = w; q > 0; q /= 2)
	{
		if (q % 2) wyn = (wyn * pot) % n;
		pot = (pot * pot) % n; 
	}
	return wyn;
}
void kodowanie_RSA() {

	int e, n, t;

	cout << "Kodowanie danych RSA\n"
		"--------------------\n\n"
		"Podaj wykladnik = "; cin >> e;
	cout << "    Podaj modul = "; cin >> n;
	cout << "----------------------------------\n\n"
		"Podaj kod RSA   = "; cin >> t;
	cout << "\nWynik kodowania = " << pot_mod(t, e, n) << endl;

	czekaj();
}