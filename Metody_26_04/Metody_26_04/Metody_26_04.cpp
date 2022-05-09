#include <iostream>

using namespace std;

float fh(float x, float y)
{
    return (- y * y);
}

int main()
{
    // metoda Eulera
    float xi = 0.0, yi = 0.0, hi = 0.0, xn2 = 0.0, ni = 0.0;

    cout << "Podaj wartosc poczatkowa x0: ";
    cin >> xi;
    cout << endl << "Podaj wartosc koncowa x0: ";
    cin >> xn2;
    cout << endl << "Podaj wartosc poczatkowa y0: ";
    cin >> yi;
    cout << endl << "Podaj ilosc krokow: ";
    cin >> ni;

    hi = (xn2 - xi) / ni;

    while (xi < xn2)
    {
        yi += hi * fh(xi, yi);
        xi += hi;
        cout << "y = " << yi << "\tx = " << xi << endl;
    }


    // metoda Heuna x e <-1, 1>, x0 = 1, y0 = 2, dy/dx=y^2 

    float x = 0.0, y = 0.0, h = 0.0, xn = 0.0, n = 0.0;

    cout << "Podaj wartosc poczatkowa x0: ";
    cin >> x;
    cout << endl << "Podaj koniec przedzialu x: ";
    cin >> xn;
    cout << endl << "Podaj wartosc poczatkowa y0: ";
    cin >> y;
    cout << endl << "Podaj ilosc krokow: ";
    cin >> n;

    h = (xn - x) / n;

    while (x < xn)
    {
        x += h;
        y += (h / 2) * (fh(x, y) + fh(x + h, y + h * fh(x, y)));
        cout << "y = " << y << "\tx = " << x << endl;
    }

    // metoda Eulera poprawiona
    return 0;
}


