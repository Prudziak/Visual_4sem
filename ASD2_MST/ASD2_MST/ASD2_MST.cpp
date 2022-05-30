#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

class Zbior
{
<<<<<<< HEAD
	int min = INT_MAX, min_indeks = NULL;

	for (int i = 0; i < ver_size; i++)
		if (odwiedzone[i] == false && klucz[i] < min)
			min = klucz[i], min_indeks = i;

	return min_indeks;
=======
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
>>>>>>> 710429b7ef2dc3f8684b34b72fc273f5e2b75429
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

<<<<<<< HEAD
	map<int, string> vertices;
	int ver_size = 0;
	dane >> ver_size;
	int id = 0;
	string nazwa;
	for (int i = 0; i < ver_size; i++)
	{
		dane >> id >> nazwa;
		vertices[id] = nazwa;
	}	 

	//for (auto i = vertices.begin(); i != vertices.end(); ++i)
		//cout << i->first << " " << i->second << endl;


	//przechowywanie krawedzi i wag w macierzy sasiedztwa

	int edge_size = 0;
	dane >> edge_size;
=======
>>>>>>> 710429b7ef2dc3f8684b34b72fc273f5e2b75429
	int a = 0, b = 0, value = 0;

	cin >> e_size;
	for (int i = 0; i < e_size; i++)
	{
<<<<<<< HEAD
		dane >> a >> b >> value;
		wmax = (a > wmax) ? a : wmax;
		wmax = (b > wmax) ? b : wmax;
		wagi[a-1][b-1] = value;
	}


	int* MST = new int[ver_size];
	int* klucz = new int[ver_size];
	bool* odwiedzone = new bool[ver_size];


	for (int i = 0; i < ver_size; i++)
	{
		klucz[i] = INT_MAX;
		odwiedzone[i] = false;
	}

	klucz[0] = 0;
	MST[0] = -1;

	for (int i = 0; i < ver_size - 1; i++)
	{
		int x = min_wartosc(klucz, odwiedzone, ver_size);

		odwiedzone[x] = true;
		MST[0] = x;

		for (int j = 1; j <= ver_size; j++)
			if (wagi[x][j] && odwiedzone[j] == false && wagi[x][j] < klucz[j])
			{
				if (MST[j - 1] == MST[j])
					MST[j] = x + 1;
				else 
					MST[j] = x;
				klucz[j] = wagi[x][j];
			}
	}
	

	//for (int x = 0; x < ver_size; x++)
		//cout << MST[x] << endl;

	for (int i = 1; i < ver_size; ++i)
	{	
		cout << vertices[MST[i+1]] << " " << vertices[i+1] << " " << wagi[MST[i]][i] << endl;
	}
	dane.close();
=======
		cin >> a >> b >> value;
		g.dodajKraw(a, b, value);
	}

	g.MST();
>>>>>>> 710429b7ef2dc3f8684b34b72fc273f5e2b75429
	return 0;
}