#include <iostream>

using namespace std;

double f(double x, double y)
{
    return (-y * y);
}

int main()
{
    //--------------------RZAD 4 RUNGEGO-KUTTY----------------//

    double x0 = 0.0, xk = 0.0, y0 = 0.0, krok = 0.0;
    cout << "Podaj poczatek przedzialu: " << endl;
    cin >> x0;
    cout << "Podaj koniec przedzialu: " << endl;
    cin >> xk;
    cout << "Podaj wartosc y0: " << endl;
    cin >> y0;
    cout << "Podaj krok(np. 20): " << endl;
    cin >> krok;

    double _x0 = x0;
    double h = (xk - x0) / krok;

    for (x0 = x0; x0 <= xk - h; x0 += h)
    {
        double k1 = h * f(x0, y0);
        double k2 = h * f(x0 + (0.5 * h), y0 + (0.5 * k1));
        double k3 = h * f(x0 + (0.5 * h), y0 + (0.5 * k2));
        double k4 = h * f(x0 + h, y0 + k3);

        y0 += ((k1 + (2.0 * k2) + (2.0 * k3) + k4) / 6.0);

        cout << "x=" << x0+h << " y=" << y0 << endl;
        cout << "k1=" << k1 << " k2=" << k2 << " k3=" << k3 << " k4=" << k4 << endl;
        cout << "y0=" << y0 << endl << endl;
    } 

    cout << "Wartosc y = " << y0 << endl;

    //-------------------------RZAD 5---------------------------------//
    x0 = _x0;

    for (x0 = x0; x0 <= xk - h; x0 += h)
    {
        double k1 = h * f(x0, y0);
        double k2 = h * f(x0 + (0.25 * h), y0 + (0.25 * k1));
        double k3 = h * f(x0 + (3./8.) * h, y0 + (3./32.) * k1 + (9./32.) * k2);
        double k4 = h * f(x0 + (12./13.) * h, y0 + (1932./2197.) * k1 - (7200./2197.) * k2 + (7296./2197.) * k3);
        double k5 = h * f(x0 + h, y0 + (439./216.) * k1 - 8. * k2 + (3680./513.)* k3 - ()

        y0 += ((k1 + (2.0 * k2) + (2.0 * k3) + k4) / 6.0);

        cout << "x=" << x0 + h << " y=" << y0 << endl;
        cout << "k1=" << k1 << " k2=" << k2 << " k3=" << k3 << " k4=" << k4 << endl;
        cout << "y0=" << y0 << endl << endl;
    }
    
    return 0;
}

