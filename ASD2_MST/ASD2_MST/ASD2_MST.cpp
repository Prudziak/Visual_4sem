#include <iostream>
#include <fstream>

using namespace std;

class vertices
{
public:
	int id;
	string name;
protected:
	vertices() {};
	~vertices() {};
	void Input1(const char* fname);
};

void vertices::Input1(const char* fname)
{
	ifstream dane(fname);
	int s1;
	dane >> s1;
	vertices* tab1 = new vertices[s1];
	for (int i = 0; i < s1; i++)
	{
		dane >> tab1->id >> tab1->name;
	}
}

class edges
{
public:
	int e1, e2, value;
protected:
	edges() {}
	~edges() {}
	void Input2(const char* fname);
	edges sort();
};

void edges::Input2(const char* fname)
{
	ifstream dane(fname);
	int s2;
	dane >> s2;
	edges* tab2 = new edges[s2];
	for (int i = 0; i < s2; i++)
	{
		dane >> tab2->e1 >> tab2->e2 >> tab2->value;
	}
	dane.close();
}

int main()
{
	cout << "Hello world" << endl;
	return 0;
}