#include <iostream>
#include <math.h>

using namespace std;

const double ACC = 0.000001;

double funkcja(double x)
{
	return sin(x);
}

int main()
{
	//Metoda Simpsona
	cout << "### METODA SIMPSONA ###" << endl << endl;

	int P;
	cout << "Podaj ilosc punktow przedzialowych: " << endl;
	cin >> P;
	double xp, xk, s, st, dx, x;

	cout << "Podaj poczatek przedzialu calkowania: " << endl;
	cin >> xp;
	cout << "Podaj koniec przedzialu calkowania: " << endl;
	cin >> xk;
	cout << endl;
	s = 0, st = 0;
	dx = (xk - xp) / P;
	for (int i = 1; i <= P; i++)
	{
		x = xp + i * dx;
		st += funkcja(x - dx / 2);
		if (i < P) s += funkcja(x);
	}
	s = dx / 6 * (funkcja(xp) + funkcja(xk) + 2 * s + 4 * st);

	cout << "Wartosc calki wynosi: " << s << endl << endl;


	//Metoda prostokątów

	//Metoda trapezów (z dokladnoscia do ACC)
	P = 5;
	cout << "### METODA TRAPEZOW ###" << endl << endl;
	xp = 0, xk = 0, s = 0, dx = 0;
	cout << "Podaj poczatek przedzialu: " << endl;
	cin >> xp;
	cout << "Podaj koniec przedzialu: " << endl;
	cin >> xk;
	long c = 0;

	do {
		c = s;
		dx = (xk - xp) / P;
		for (int i = 1; i < P; i++)
		{
			s += funkcja(xp + i * dx);
		}
		s = (s + (funkcja(xp) + funkcja(xk)) / 2) * dx;
		P *= 2;
		if (P> 100000000)
			break;

	} while (abs(s - c) > ACC);

	cout << "Wartosc calki wynosi: " << s << endl << endl;

	//Metoda "trzech osmych"
	cout << "### METODA 3/8 ###" << endl;
	cout << "Podaj ilosc punktow przedzialowych: " << endl;
	int W = 0;
	cin >> W;
	double pp = 0, kp = 0;
	cout << "Podaj poczatek przedzialu: " << endl;
	cin >> pp;
	cout << "Podaj koniec przedzialu: " << endl;
	cin >> kp;

	double h = (kp - pp) / W;

	double suma = funkcja(kp) + funkcja(pp);

	double wynik = 0;

	for (int i = 1; i < W; i++)
	{
		if (i % 3 == 0)
			suma = suma + 2 * funkcja(pp + i * h);
		else
			suma = suma + 3 * funkcja(pp + i * h);
	}

	wynik = (3 * h / 8) * suma;
	cout << "Wartosc calki wynosi: " << wynik << endl;

	return 0;
}