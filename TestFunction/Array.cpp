
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

Input: [1,4,3,2]
Output: 4
Explanation: n is 2, and the maximum sum of pairs is 4 = min(1, 2) + min(3, 4).
Note:
n is a positive integer, which is in the range of [1, 10000].
All the integers in the array will be in the range of [-10000, 10000].
*/
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
int maxSubArray(int* nums, int numsSize)	//try again
{
	int max = nums[0];	
	int* func = (int*)malloc(sizeof(int)*numsSize);	//func(i): maxSubArray of nums[0] ~ nums[i]
	func[0] = nums[0];

	for (int i = 1; i < numsSize; i++)
	{
		if (func[i - 1] > 0)	//we know func[i-1] is worth to add in max
			func[i] = func[i - 1] + nums[i];	
		else
			func[i] = nums[i];
		max = max > func[i] ? max : func[i];
	}
	return max;
}

/*
215. Kth Largest Element in an Array
Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

Input: [3,2,1,5,6,4] and k = 2
Output: 5

Input: [3,2,3,1,2,4,5,5,6] and k = 4
Output: 4
Note:
You may assume k is always valid, 1 <= k <= array's length.
*/
int findKthLargest(int* nums, int numsSize, int k) 
{
	BubbleSort(numsSize, nums);
	return nums[numsSize - k];
}

/*
728. Self Dividing Numbers
A self-dividing number is a number that is divisible by every digit it contains.
For example, 128 is a self-dividing number because 128 % 1 == 0, 128 % 2 == 0, and 128 % 8 == 0.
Also, a self-dividing number is not allowed to contain the digit zero.
Given a lower and upper number bound, output a list of every possible self dividing number, including the bounds if possible.

Input:
left = 1, right = 22
Output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22]
Note:
The boundaries of each input argument are 1 <= left <= right <= 10000.
*/
bool selfDividing(int target)
{
	int digit, temp = target;
	while (temp != 0)
	{
		digit = temp % 10;
		if (digit == 0 || target%digit != 0)
			return false;
		temp = temp / 10;
	}
	return true;
}
int* selfDividingNumbers(int left, int right, int* returnSize)
{
	int cnt = 0;
	int* rtnArray = (int*)malloc(sizeof(int));
	for (; left <= right; left++)
	{
		if (selfDividing(left))
		{
			cnt++;
			rtnArray = (int*)realloc(rtnArray, sizeof(int) * cnt);
			rtnArray[cnt - 1] = left;
		}
	}
	*returnSize = cnt;
	return rtnArray;
}

/*
628. Maximum Product of Three Numbers
Given an integer array, find three numbers whose product is maximum and output the maximum product.

Input: [1,2,3]			Output: 6
Input: [1,2,3,4]		Output: 24
*/
int maximumProduct(int* nums, int numsSize) 
{
	BubbleSort(numsSize, nums);
	int a = nums[numsSize - 1] * nums[numsSize - 2] * nums[numsSize - 3];
	int b= nums[0] * nums[1] * nums[numsSize - 1];
	return a > b ? a : b;
}

/*
136. Single Number
Given a non-empty array of integers, every element appears twice except for one. Find that single one.
Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Input: [2,2,1]			Output: 1
Input: [4,1,2,1,2]		Output: 4
*/
int singleNumber(int* nums, int numsSize)
{
	int xor = 0;
	for (int i = 0; i < numsSize; i++)
		xor ^= nums[i];
	return xor;
}

/*
283. Move Zeroes
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Input: [0,1,0,3,12]		Output: [1,3,12,0,0]
Note:
You must do this in-place without making a copy of the array.
Minimize the total number of operations.
*/
void moveZeroes(int* nums, int numsSize) //try again
{
	for (int i = 0, leftmostzero = 0; i < numsSize; i++)
		if (nums[i] != 0)
		{
			swap(&nums[i], &nums[leftmostzero]);
			leftmostzero++;
		}
}

/*
448. Find All Numbers Disappeared in an Array
Given an array of integers where 1 <= a[i] <= n (n = size of array), some elements appear twice and others appear once.
Find all the elements of [1, n] inclusive that do not appear in this array.
Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

Input:[4,3,2,7,8,2,3,1]		Output:[5,6]
*/
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) 
{
	int* rtnAr = (int*)malloc(sizeof(int) * (numsSize + 1));
	//int rtnAr[5];
	memset(rtnAr, 0x00, sizeof(int) * (numsSize + 1));
	for (int i = 0; i < numsSize; i++)
	{
		rtnAr[nums[i]] = 1;
	}
	int count = 0;
	for (int i = 1; i <= numsSize; i++)
	{
		if (rtnAr[i] == 0)
			rtnAr[count++] = i;
	}
	*returnSize = count;
	return rtnAr;
}

/*
121. Best Time to Buy and Sell Stock
Say you have an array for which the ith element is the price of a given stock on day i.
If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.
Note that you cannot sell a stock before you buy one.

Input: [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Not 7-1 = 6, as selling price needs to be larger than buying price.

Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
*/
int maxProfit(int* prices, int pricesSize)
{
	int low_point = prices[0], max = 0;
	for (int i = 1; i < pricesSize; i++)
	{
		if (prices[i] < low_point)
			low_point = prices[i];
		if (prices[i] - low_point > max)
			max = prices[i] - low_point;
	}
	return max;
}
/*
35. Search Insert Position
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
You may assume no duplicates in the array.

Input: [1,3,5,6], 5		Output: 2
Input: [1,3,5,6], 2		Output: 1
Input: [1,3,5,6], 7		Output: 4
Input: [1,3,5,6], 0		Output: 0
*/
int searchInsert(int* nums, int numsSize, int target) 
{
	for (int i = 0; i < numsSize; i++)
		if (nums[i] >= target)
			return i;
	return numsSize;
}
/*
438. Find All Anagrams in a String
Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.
Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.
The order of output does not matter.

Input:s: "cbaebabacd" p: "abc"
Output:[0, 6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".

Input:s: "abab" p: "ab"
Output:[0, 1, 2]
Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
*/
//bool IsAnagrams(char* s, int* alpha_p, int len)
//{
//	int alphabet[26] = { 0 };
//	for (int i = 0; i < len; i++)
//		alphabet[s[i] - 'a']++;
//	for (int i = 0; i < 26; i++)
//		if (alphabet[i] != alpha_p[i])
//			return false;
//	return true;
//}
//int* findAnagrams(char* s, char* p, int* returnSize)
//{
//	*returnSize = 0;
//	if (*s == NULL || *p == NULL || strlen(p)>strlen(s))
//		return NULL;
//	int alphabet_sub[26] = { 0 }, cnt = 0;
//	for (int i = 0; i < strlen(p); i++)
//		alphabet_sub[p[i] - 'a']++;
//	printf("%c", *p);
//
//	int* rtn_array = (int*)malloc(sizeof(int) * 0);
//	for (int i = 0; i <= strlen(s) - strlen(p); i++)
//	{
//		if (IsAnagrams(&s[i], alphabet_sub, strlen(p)))
//		{
//			rtn_array = (int*)realloc(rtn_array, sizeof(int)*++cnt);
//			rtn_array[cnt - 1] = i;
//		}
//	}
//	*returnSize = cnt;
//	return rtn_array;
//}

