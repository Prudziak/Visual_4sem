#include <iostream>
#include <fstream>

using namespace std;

void heapSort(const string fname);

int heapAlgo(int tabela, int testCases, int size);
int max(int tabela, int size);

int main()
{
	heapSort("Plik.txt");
	return 0;
}

void heapSort(const string fname)
{
	ifstream dane(fname);
	int testCases;
	dane >> testCases;
	int size = 0;
	for (int i = 0; i < testCases; i++)
	{
		cout << "Case " << i << endl;
		dane >> size;
		int* tabela = new int[size];
		for (int j = 0; j < size; j++)
		{
			dane >> tabela[j];
			cout << tabela[j] << " ";
		}
		cout << endl;
		delete[] tabela;
	}

}

int max(int* tabela, int size)
{
	int max = tabela[0];
	for (int i = 0; i < size; i++)
	{
		if (tabela[i] > max)
			max = tabela[i];
	}
	return max;
}

int heapAlgo(int* tabela, int testCases, int size)
{
	for (int i = size; i > 0; i--)
	{
		tabela[size] = max(tabela, size);
		int largest = size;
		int left = 2 * size + 1;
		int right = 2 * size + 2;

		if (left < size && tabela[left] > tabela[largest])
			largest = left;

		if (right < size && tabela[right] > tabela[largest])
			largest = right;

		if (largest != size)
		{
			swap(tabela[size], tabela[largest]);
			heapAlgo
		}
	}
}
