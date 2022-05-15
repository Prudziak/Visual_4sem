#include <iostream>
#include <fstream>
#include <map>

using namespace std;

int min_wartosc(int klucz[], bool odwiedzone[], int ver_size)
{
	int min = INT_MAX;
	int min_indeks = 0;

	for (int i = 0; i < ver_size; i++)
	{
		if (odwiedzone[i] == false && klucz[i] < min)
			min = klucz[i], min_indeks = i;
	}

	return min_indeks;
}


int main()
{
	ifstream dane("dane.txt");

	// przechowywanie id i nazw wierzcholkow

	map<int, string> vertices;
	int ver_size = 0;
	dane >> ver_size;
	int id;
	string nazwa;
	for (int i = 0; i < ver_size; i++)
	{
		dane >> id >> nazwa;
		vertices[id] = nazwa;
	}


	//przechowywanie krawedzi i wag w macierzy sasiedztwa

	int edge_size = 0;
	dane >> edge_size;
	int a = 0, b = 0, value = 0;

	int max_n = 100;

	int** wagi = new int*[max_n];
	for (int i = 0; i < max_n; i++)
		wagi[i] = new int[max_n];

	for (int i = 0; i < max_n; i++)
		for (int j = 0; j < max_n; j++)
			wagi[i][j] = 0;

	int wmax = 0;
	for (int i = 0; i < edge_size; i++)
	{
		dane >> a >> b >> value;
		wmax = (a > wmax) ? a : wmax;
		wmax = (b > wmax) ? b : wmax;
		wagi[a - 1][b - 1] = value;
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

		for (int j = 0; j < ver_size; j++)
			if (wagi[x][j] && odwiedzone[j] == false && wagi[x][j] < klucz[j])
			{
				MST[j] = x;
				klucz[j] = wagi[x][j];
			}
	}

	for (int i = 1; i < ver_size; i++)
	{
		cout << vertices[MST[i]] << " " << vertices[i] << " " << wagi[i][MST[i]] << endl;
	}
	int x = 0;
	cin >> x;
	return 0;
}