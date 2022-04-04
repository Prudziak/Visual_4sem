#include <iostream>
#include <fstream>

using namespace std;

void heapify(int* tabela, int size, int i);
void heapSort(int* tabela, int size);
void view(int* tabela, int size);

//========================================

int main()
{
	
	ifstream dane("Plik.txt");
	int testCases;
	dane >> testCases;
	cout << "Przypadki testowe: " << testCases << endl;
	int size = 0;
	for (int i = 0; i < testCases; i++)
	{
		dane >> size;
		cout << "Case " << i + 1 << " , size: " << size << endl;
		int* tabela = new int[size];
		for (int j = 0; j < size; j++)
		{
			dane >> tabela[j];
			cout << tabela[j] << " ";
		}
		cout << endl << endl;

		heapSort(tabela, size);

		cout << "Finalnie: ";
		for (int i = 0; i < size; i++)
		{
			cout << tabela[i] << " ";
		}
		cout << endl << endl;
		delete[] tabela;
	}
	return 0;
}

//========================================

void heapify(int* tabela, int size, int i)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < size && tabela[left] > tabela[largest])
		largest = left;

	if (right < size && tabela[right] > tabela[largest])
		largest = right;

	if (largest != i)
	{
		swap(tabela[i], tabela[largest]);
		heapify(tabela, size, largest);
	}
}

void heapSort(int* tabela, int size)
{
	for (int i = size / 2 - 1; i >= 0; i--)
	{
		heapify(tabela, size, i);
	}

	for (int i = size - 1; i > 0; i--)
	{
		view(tabela, i+1);
		swap(tabela[0], tabela[i]);
		heapify(tabela, i, 0);
	}
}

void view(int* tabela, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << tabela[i] << " ";
	}
	cout << endl;
}
