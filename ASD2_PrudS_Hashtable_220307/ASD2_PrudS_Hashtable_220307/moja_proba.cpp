#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// visualgo.net/en/hashtable - program do projektowania sobie takiej tabeli 

class Hashtable
{
public:
	Hashtable() : key(NULL), chain(""), odleglosc(NULL) {}
	~Hashtable();
	
	void Input(const string fIn, const string fOut);

	friend ostream& operator<<(ostream& s, Hashtable& K);

public:
	long key;
	string chain;
	long odleglosc;
};

ostream& operator<<(ostream& s, Hashtable& K)
{
	if (K.key != NULL)
		return s << K.key << " " << K.chain << endl;
	else
		return s<<"" << endl;
}

Hashtable::~Hashtable()
{
}


void Hashtable::Input(const string fIn, const string fOut)
{
	ifstream dane(fIn);
	ofstream zapis(fOut);
	int cases;
	long size;
	string akcja;
	dane >> cases;
	cout << "Cases: " << cases << endl;
	dane >> akcja >> size; // tworzenie wstepnej tablicy 

	//cout << akcja << " " << size << endl; //test

	Hashtable* tab = new Hashtable[size];

	int testy = 0;
	while (testy < cases)
	{
		while (!dane.eof())
		{
			dane >> akcja;
			if (akcja == "size")
			{
				dane >> size;
				tab = new Hashtable[size];
			}
			if (akcja == "add")
			{
				dane >> key >> chain;
				long indeks = key % size;
				int k = 0;
				while (tab[indeks].key != NULL)
				{
					if (indeks == size - 1)
						indeks = -1;
					indeks += 1;
					k += 1;
				}
				tab[indeks].key = key;
				tab[indeks].chain = chain;
				tab[indeks].odleglosc = k;
			}
			if (akcja == "delete")
			{
				dane >> key;
				long indeks = key % size;
				while (tab[indeks].key != key)
				{
					if (indeks == size - 1)
						indeks = -1;
					indeks++;
				}
				tab[indeks].key = NULL;
				tab[indeks].chain = "";
				tab[indeks].odleglosc = NULL;

				long x = indeks + 1;
				if (x == size)
					x = 0;

				while (x != indeks)
				{
					if (tab[x].key != NULL)
					{	
						long distance = x - tab[x].odleglosc;
						if (distance < 0)
							distance = size + distance;
						if (tab[distance].key == NULL && tab[x].odleglosc != 0)
						{
							tab[distance].key = tab[x].key;
							tab[distance].chain = tab[x].chain;
							tab[distance].odleglosc = 0;
							tab[x].key = NULL;
							tab[x].chain = "";
							tab[x].odleglosc = NULL;
						}
					}
					if (x == size - 1)
						x = -1;
					x++;
				}
				x = indeks + 1;
				while (x != indeks)
				{
					if (x == size)
						x = 0;
					if (tab[x].key != NULL && tab[x].odleglosc != 0)
					{
						int d2 = x - tab[x].odleglosc;
						if (d2 < 0)
							d2 = size + d2;
						if (d2 == size)
							d2 = 0;
						int d3 = x - 1;
						if (d3 < 0)
							d3 = size - 1;
						int q = d3;
						int z = 0;
						while (q != d2)
						{
							if (q == -1)
								q = size - 1;
							if (tab[q].key == NULL)
							{
								if (tab[x].key != NULL)
								{
									tab[q].odleglosc = tab[x].odleglosc - (z + 1);
									tab[q].key = tab[x].key;
									tab[q].chain = tab[x].chain;
									tab[x].key = NULL;
									tab[x].chain = "";
									tab[x].odleglosc = NULL;
								}
							}
							z++;
							q--;
						}
					}
					x++;
				}
			}
			if (akcja == "print")
			{
				for (int i = 0; i < size; i++)
				{
					if (tab[i].key != NULL)
					{
						zapis << i << " " << tab[i];
					}
				}
				zapis << endl;
			}
			if (akcja == "stop")
			{
				testy += 1;
			}
		}
	}
		for (int i = 0; i < size; i++)
		{
			tab[i].key = NULL;
			tab[i].chain = "";
			tab[i].odleglosc = NULL;
		}
	dane.close();
	zapis.close();
	delete[] tab;
}

int main()
{
	Hashtable X;
	X.Input("hashtable.txt", "output.txt");
	return 0;
}

