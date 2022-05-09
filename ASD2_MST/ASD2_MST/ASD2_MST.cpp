#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class tree
{
public:
	tree() : id(NULL), name("") {}
	~tree();


public:
	int id;
	string name;
};

class edges
{
public:
	edges() : e1(NULL), e2(NULL), value(NULL) {}
	~edges();

public:
	int e1, e2;
	int value;
};

class algo : public tree, public edges
{
public:
	algo() {}
	~algo() {}

	void Input(const string in);
	void Output();

	tree* tab1 = 0;
	edges* tab2 = 0;

};


void algo::Input(const string in)
{
	ifstream dane(in);

	int vertices;

	dane >> vertices;

	tab1 = new tree[vertices];
	for (int i = 0; i < vertices; i++)
	{
		dane >> id >> name;
		tab1[i].id = id;
		tab1[i].name = name;
	}

	int size;

	dane >> size;

	tab2 = new edges[size];

	for (int i = 0; i < size; i++)
	{
		dane >> e1 >> e2 >> value;
		tab2[i].e1 = e1;
		tab2[i].e2 = e2;
		tab2[i].value = value;
	}

	dane.close();
}

void algo::Output()
{
	for (int i = 0; i < 4; i++)
	{
		cout << tab1[i].id << " " << tab1[i].name << endl;
	}
	cout << "Krawedzie i wartosci:" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << tab2[i].e1 << " " << tab2[i].e2 << " " << tab2[i].value << endl;
	}
}


int main()
{
	algo X;
	X.Input("dane.txt");
	X.Output();
	return 0;
}