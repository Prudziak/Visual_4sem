#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// visualgo.net/en/hashtable - program do projektowania sobie takiej tabeli 

class Hashtable
{
public:
	Hashtable() : key(NULL), chain(""), baseIndex(NULL) {}
	~Hashtable();
	
	void Input(const string fName);

	friend ostream& operator<<(ostream& s, Hashtable& K);

private:
	long key;
	string chain;
	long baseIndex;
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


void Hashtable::Input(const string fName)
{
	ifstream dane(fName);
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
		while (dane.is_open())
		{
			while (!dane.eof())
			{
				dane >> akcja;
				//cout << akcja << endl;
				if (akcja == "size")
				{
					dane >> size;
					tab = new Hashtable[size];
				}
				if (akcja == "add")
				{
					dane >> key >> chain;
					long indeks = key % size;
					//cout << "Key i chain: " << key << " " << chain << endl;
					if (tab[indeks].key == NULL && tab[indeks].chain == "")
					{
						tab[indeks].key = key;
						tab[indeks].chain = chain;
						baseIndex = indeks;
						cout << "Indeks: " << indeks << ", Base index: " << baseIndex << endl;
						//cout << "Indeks: " << indeks << endl;
					}
					else
					{
						if (indeks + 1 < size)
						{
							tab[indeks+1].key = key;
							tab[indeks+1].chain = chain;
							baseIndex = indeks;
							cout << "Indeks: " << indeks << ", Base index: " << baseIndex << endl;
						}
					}
				}
				if (akcja == "delete")
				{
					dane >> key;
					long indeks = key % size;
					tab[indeks].key = NULL;
					tab[indeks].chain = "";
					tab[indeks].baseIndex = NULL;

					int x = indeks + 1;
					if (x == size)
						x = 0;

					while (x != indeks)
					{
						long distance = x - (x - tab[x].baseIndex);
						if (distance < 0)
							distance = size + distance;


					}
				}
				if (akcja == "print")
				{
					for (int i = 0; i < size; i++)
					{
						if (tab[i].key != NULL)
						{
							cout << i << " " << tab[i];
						}
					}
					cout << endl;
				}
				if (akcja == "stop")
				{
					delete[] tab;
					testy += 1;
				}
			}
		}
	}
}

int main()
{
	Hashtable X;
	X.Input("hashtable.txt");
	return 0;
}

