#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// visualgo.net/en/hashtable - program do projektowania sobie takiej tabeli 

class Hashtable
{
public:
	long klucz;
	string chain;
	Hashtable(int a, string b) : klucz(a), chain(b)
	{
	}

	friend ostream& operator<<(ostream& s, Hashtable& K);
};


ostream& operator<<(ostream& s, Hashtable& K)
{
	return s << K.klucz << ", " << K.chain << endl;
}


int main()
{
	string linia;
	ifstream plik;
	plik.open("hashtable.txt");
	if (plik.good() == true)
	{
		while (!plik.eof())
		{
			getline(plik, linia);
			cout << linia << endl;
		}
		plik.close();
	}

	Hashtable X(123, "Amiga");

	cout << X;

	int test = 0;

	

	return 0;
}

