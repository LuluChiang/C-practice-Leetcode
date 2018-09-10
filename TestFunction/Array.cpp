#include <stdlib.h>
#include "Array.h"


int* ReverseArray(int* digits, int digitsSize, int* returnSize)
{
	int *tempArray = (int*)malloc(digitsSize * sizeof(int));
	for (int i = 0; i<digitsSize; i++)
		tempArray[i] = digits[digitsSize - 1 - i];
	*returnSize = digitsSize;
	return tempArray;
}

/**
66. Plus One
Given a non-empty array of digits representing a non-negative integer, plus one to the integer.
The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.
You may assume the integer does not contain any leading zero, except the number 0 itself.

Input: [6,2,3]  Output: [6,2,4]
Input: [9,9,9]  Output: [1,0,0,0]

* Return an array of size *returnSize.
* Note: The returned array must be malloced, assume caller calls free().
*/
int* plusOne(int* digits, int digitsSize, int* returnSize) //still not good, waste time on reverse
{

	int *tempArray;
	bool round = false;
	tempArray = ReverseArray(digits, digitsSize, returnSize);

	for (int i = 0; i<digitsSize; i++)
	{
		if (round == true || i == 0)
			tempArray[i] += 1;
		if (tempArray[i] == 10)
		{
			tempArray[i] = 0;
			round = true;
		}
		else
			round = false;
	}
	if (round == true)   //last rounded
	{
		int *tempArray2 = (int*)realloc(tempArray, sizeof(int) * (digitsSize + 1));
		tempArray[digitsSize] = 1;
		*returnSize += 1;
	}
	tempArray = ReverseArray(tempArray, *returnSize, returnSize);
	return tempArray;
}