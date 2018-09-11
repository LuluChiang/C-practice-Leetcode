
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

/*
561. Array Partition I
Given an array of 2n integers, your task is to group these integers into n pairs of integer, say (a1, b1), (a2, b2), ..., (an, bn) which makes sum of min(ai, bi) for all i from 1 to n as large as possible.

Example 1:
Input: [1,4,3,2]

Output: 4
Explanation: n is 2, and the maximum sum of pairs is 4 = min(1, 2) + min(3, 4).
Note:
n is a positive integer, which is in the range of [1, 10000].
All the integers in the array will be in the range of [-10000, 10000].*/
int arrayPairSum(int* nums, int numsSize) 
{
	int sum = 0;
	BubbleSort(numsSize, nums);
	for (int i = 0; i < numsSize; i = i + 2)
		sum += nums[i];
	return sum;
}

/*
169. Majority Element
Given an array of size n, find the majority element. The majority element is the element that appears more than n/2 times.
You may assume that the array is non-empty and the majority element always exist in the array.


Input: [3,2,3]
Output: 3

Input: [2,2,1,1,1,2,2]
Output: 2
*/
int majorityElement(int* nums, int numsSize) 
{
	BubbleSort(numsSize, nums);
	return nums[numsSize/2];
}

/*
53. Maximum Subarray
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Follow up:
If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
*/
int maxSubArray(int* nums, int numsSize)
{

}
