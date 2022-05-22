#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

class Zbior
{
	int* rodzic;
	int* rank;
public:
	Zbior(int n);
	int szukaj(int i);
	void zlacz(int x, int y);
};

Zbior::Zbior(int n)
{
	rodzic = new int[n];
	rank = new int[n];

	for (int i = 0; i < n; i++)
	{
		rodzic[i] = -1;
		rank[i] = 1;
	}
}

int Zbior::szukaj(int i)
{
	if (rodzic[i] == -1)
		return i;

	return rodzic[i] = szukaj(rodzic[i]);
}

void Zbior::zlacz(int x, int y)
{
	int s1 = szukaj(x);
	int s2 = szukaj(y);

	if (s1 != s2)
	{
		if (rank[s1] < rank[s2])
		{
			rodzic[s1] = s2;
			rank[s2] += rank[s1];
		}
		else
		{
			rodzic[s2] = s1;
			rank[s1] += rank[s2];
		}
	}
}

class Graf
{
	vector<vector<int> > listaKraw;
	int V;
public:
	Graf(int V);
	void dodajKraw(int x, int y, int value);
	void MST();
};

Graf::Graf(int V)
{
	this->V = V;
}

void Graf::dodajKraw(int x, int y, int value)
{
	listaKraw.push_back({ value, x, y });
}

void Graf::MST()
{
	sort(listaKraw.begin(), listaKraw.end());

	int id = 0;
	string name;
	int size = 0;
	cin >> size;
	string* t = new string[size];
	for (int i = 0; i < size; i++)
	{
		cin >> id >> name;
		t[id - 1] = name;
	}

	Zbior s(V);
	int suma = 0;
	for (auto& krawedz : listaKraw)
	{
		int value = krawedz[0];
		int x = krawedz[1];
		int y = krawedz[2];

		if (s.szukaj(x-1) != s.szukaj(y-1))
		{
			s.zlacz(x-1, y-1);
			suma += value;
			cout << t[x-1] << " " << t[y-1] << " " << value << endl;
		}
	}
	cout << "Suma wag wybranych krawedzi: " << suma << endl;
}

int main()
{
	int ver_size;
	int e_size;
	cin >> ver_size;
	Graf g(ver_size);

	int skip1 = 0;						//
	string skip2;					    // TE LINIE TYLKO PRZEWIJAJA
	for (int i = 0; i < ver_size; i++)	// PLIK W ODPOWIEDNIE MIEJSCE DO ODCZYTU
		cin >> skip1 >> skip2;			//

	int a = 0, b = 0, value = 0;

	cin >> e_size;
	for (int i = 0; i < e_size; i++)
	{
		cin >> a >> b >> value;
		g.dodajKraw(a, b, value);
	}

	g.MST();
	return 0;
}