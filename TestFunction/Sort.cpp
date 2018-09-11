#include "Sort.h"


/*
Selection Sort
*/
void SelectionSort(int num, int *ar)
{
	int index_min;
	for (int i = 0; i < num; i++)
	{
		index_min = i;
		for (int j = i + 1; j < num; j++)
		{
			if (ar[j] < ar[index_min])
				index_min = j;
		}
		if(i != index_min)
			swap(&ar[index_min], &ar[i]);
	}
}

/*
Bubble Sort
*/
void BubbleSort(int num, int* ar)
{
	bool swap_flag = false;
	for (int i = 0; i < num; i++)
	{
		swap_flag = false;
		for (int j = 0; j < num - i - 1 ; j++)
			if (ar[j] > ar[j + 1])
			{
				swap(&ar[j], &ar[j + 1]);
				swap_flag = true;
			}
		if (!swap_flag) //done early
			return;
	}
}
/*
Insertion Sort
*/
void InsertionSort(int num, int* ar)
{

}
