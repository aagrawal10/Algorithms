#include <iostream>
#include <cstdlib>

using namespace std;

#define MAX_SIZE 1000

void swap(int array[], int index1, int index2)
{
	int temp = array[index1];
	array[index1] = array[index2];
	array[index2] = temp;
}

int Partition (int array[], int lowerIndex, int upperIndex)
{
	int pivot = array[upperIndex];
	int j = lowerIndex;
	for (int i = lowerIndex ; i <= upperIndex ; i++)
	{
		if (array[i] > pivot) continue;
		swap(array, j++, i);
	}

	return j - 1;
}

void QuickSort (int array[], int lowerIndex, int upperIndex)
{
	// Base condition
	if (lowerIndex >= upperIndex) return;

	int pivotIndex = Partition (array, lowerIndex, upperIndex);
	QuickSort (array, lowerIndex, pivotIndex - 1);
	QuickSort (array, pivotIndex + 1, upperIndex);
}

void PrintArray(int array[], int lowerIndex, int upperIndex)
{
	cout << "Printing Array now" << endl;
	for (int i = lowerIndex ; i <= upperIndex ; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl << "Printing Array complete" << endl;
}

int main ()
{
	int array[MAX_SIZE];
	int n;

	cout << "Enter array length : ";
	cin >> n;
	cout << "Enter array elements one after another" << endl;
	for (int i = 0 ; i < n ; i++)
	{
		cin >> array[i];
	}

	PrintArray(array, 0, n - 1);
	QuickSort(array, 0, n - 1);
	PrintArray(array, 0, n - 1);

	return 0;
}
