#include <iostream>
#include <time.h>
#include <math.h>
#include <iomanip>

using namespace std;

double f(double x)
{
	return sin(x);
}

int main()
{

	cout << setprecision(10);

	//METODA MONTE CARLO
	cout << "### METODA MONTE CARLO ###\n";
	double xp, xk, n, dx, s;
	cout << "Podaj poczatek przedzialu: " << endl;
	cin >> xp;
	cout << "Podaj koniec przedzialu: " << endl;
	cin >> xk;
	cout << "Podaj liczbe punktow przedzialowych (najlepiej minimum 10000): " << endl;
	cin >> n;

	srand(time(NULL));
	s = 0;
	dx = xk - xp;

	double max = 1.0 * RAND_MAX;

	for (int i = 1; i <= n; i++)
	{
		s += f(xp + ((double)rand() / max * dx));
	}
	s = dx * s / n;

	cout << "Wartosc calki wynosi: " << s << endl << endl;

	//MERODA GAUSSA-LEGENDRE'A
	cout << "### METODA GAUSSA-LEGENDRE'A ###\n";
	double a, b;
	cout << "Podaj poczatek przedzialu: " << endl;
	cin >> a;
	cout << "Podaj koniec przedzialu: " << endl;
	cin >> b;
	int size = 4;

	static double w4[] = { 0.3478548451, 0.6521451549,
	0.6521451549, 0.3478548451 };

	static double x4[] = { -0.8611363116, -0.3399810436,
	0.3399810436, 0.8611363116 };

	static double w5[] = { 0.2369268851, 0.4786286705, 0.5688888889,
	0.4786286705, 0.2369268851 };

	static double x5[] = { -0.9061798459, -0.5384693101, 0.0,
	0.5384693101, 0.9061798459 };

	double h, hr, s4 = 0, s5 = 0;
	h = (b - a) / 2;
	hr = (b+a)/2;

	for (int i = 0; i < 4; i++)
	{
		s4 += w4[i] * f(h * x4[i] + hr);
	}
	s4 *= h;
	cout << "Dla w4 oraz x4\n";
	cout << "Wartos calki wynosi: " << s4 << endl;

	for (int i = 0; i < 5; i++)
	{
		s5 += w5[i] * f(h * x5[i] + hr);
	}
	s5 *= h;

	cout << "Dla w5 oraz x5\n";
	cout << "Wartosc calki wynosi: " << s5 << endl;


	return 0;
}