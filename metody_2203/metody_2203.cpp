#include <iostream>
#include <math.h>

using namespace std;

const double EPS0 = 0.0000000001;
const double EPSX = 0.0000000001;

double funkcja(double x)
{
    return pow(x, 4) - 9 * pow(x, 3) - 15;
}

int main()
{
    // metoda falsi 
    double a, b, x0, x1, fa, fb, f0;

    cout << "### METODA FALSI ###" << endl;

    cout << "Podaj zakres poszukiwanego pierwiastka: " << endl;
    cout << "a = "; cin >> a;
    cout << "b = "; cin >> b;

    fa = funkcja(a); fb = funkcja(b); x1 = a; x0 = b;

    int licznik = 0;

    if (fa * fb > 0)
        cout << "Funkcja nie spelnia zalozen!" << endl;
    else
    {
        while (fabs(x1 - x0) > EPSX)
        {
            x1 = x0;
            x0 = a - fa * (b - a) / (fb - fa);
            f0 = funkcja(x0);
            if (fabs(f0) < EPS0) break;
            if (fa * f0 < 0)
            {
                b = x0; fb = f0;
            }
            else
            {
                a = x0; fa = f0;
            }
            licznik++;
        }   
        cout << "Miejsce zerowe wynosi x0 = " << x0 << " po " << licznik << " sprawdzeniach." << endl << endl;
    }
    // metoda siecznych

    cout << "### METODA SIECZNYCH ###" << endl;

    x0 = 0; x1 = 0; f0 = 0; licznik = 0;
    double x2, f1, f2;
    int i;

    cout << "Podaj wstepne wartosci x1 oraz x2" << endl;
    cout << "x1 = "; cin >> x1;
    cout << "x2 = "; cin >> x2;

    f1 = funkcja(x1); f2 = funkcja(x2); i = 64;
    while (i && fabs(x1 - x2) > EPSX)
    {
        if (fabs(f1 - f2) < EPS0)
        {
            cout << "Zle punkty startowe." << endl;
            i = 0;
            break;
        }
        x0 = x1 - f1 * (x1 - x2) / (f1 - f2);
        f0 = funkcja(x0);
        if (fabs(f0) < EPS0) break;
        x2 = x1; f2 = f1;
        x1 = x0; f1 = f0;
        if (!(--i)) cout << "Przekroczony limit obiegow!" << endl;
        licznik++;
    }
    if (i) cout << "Miejsce zerowe x0 = " << x0 << " po " << licznik << " sprawdzeniach." << endl;

    // metoda Mullera
    double x31, x32, x3, f3;
    double dx01, dx02, dx12, dy02, dy12, h12;
    double a0, a1, a2, d;
    int n = 64;
    licznik = 0;
    f0 = 0; f1 = 0; f2 = 0;

    bool result = false;

    cout << "Podaj punkty startowe (x1, x2, x3):" << endl;
    cin >> x1, x2, x3;

    f0 = funkcja(x0);
    f1 = funkcja(x1);
    f2 = funkcja(x2);

    while (true)
    {
        if (!--n)
        {
            cout << "Przekroczono dozwolona liczbe obiegow!" << endl;
            break;
        }
        dx01 = x0 - x1;
        dx02 = x0 - x2;
        dx12 = x1 - x2;
        dy02 = f0 - f2;
        dy12 = f1 - f2;
        h12 = dy12 / dx12;

        a2 = (dy02 / dx02 - h12) / dx01;
        a1 = h12 - a2 * (x1 + x2);
        a0 = f2 - x2 * (a2 * x2 + a1);

        d = a1 * a1 - 4 * a2 * a0;

        if (d < 0)
        {
            cout << "Zle dobrane punkty startowe, brak pierwiastka rzeczywistego." << endl;
            break;
        }
        d = sqrt(d);
        x31 = (-a1 - d) / 2 / a2;
        x32 = (-a1 + d) / 2 / a2;

        if ((fabs(f3) < EPSX) || (fabs(x3 - x2) < EPS0))
        {
            result = true;
            break;
        }
        x0 = x1; f0 = f1;
        x1 = x2; f1 = f2;
        x2 = x3; f2 = f3;
        licznik++;
    }

    if (!result) cout << "Zakonczono z bledem." << endl << endl;

    cout << "Pierwiastek funkcji wynosi: " << x3 << " po " << licznik << " obiegach." << endl;

    return 0;
}


