/*
 - Function of math problem

*/
#include "Calculator.h"



int max(int a, int b)
{
	return a > b ? a : b;
}
int min(int a, int b)
{
	return a > b ? b : a;
}

void swap(int *a, int *b)
{
	if (*a == *b)		// otherwise, parameter a, b will be changed simultaneously
		return;
	*a = *a-*b; 
	*b = *a+*b; 
	*a = *b-*a;
}
int AbsoluteValue(int n)	//not sure
{
	return n > 0 ? n : n * (-1);
}

bool IsNumber(char *ptr)
{
	if ('0' <= *ptr && *ptr <= '9')
		return true;
	return false;
}
bool IsOprator(char *ptr)
{
	if (*ptr == '+' || *ptr == '-' || *ptr == '*' || *ptr == '/')
		return true;
	return false;
}
int Oprator(int a, int b, char *op)
{
	if (*op == '+')
		return a + b;
	else if (*op == '-')
		return a - b;
	else if (*op == '*')
		return a * b;
	else if (*op == '/')
		return a / b;
	else
		return 0;
}

int Fibonacci(int n)
{
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else
		return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int NumOfDigit(int num)
{
	int opt = 0;
	while (num != 0)
	{
		num /= 10;
		opt++;
	}
	return opt;
}


/*
7. Reverse Integer
	Given a 32-bit signed integer, reverse digits of an integer.
	123 => 321

	Assume we are dealing with an environment which could only store integers 
	within the 32-bit signed integer range: [−231,  231 − 1]. 

	For the purpose of this problem, 
	assume that your function returns 0 when the reversed integer overflows.
*/
int ReverseInt(int num)
{
	/* 1. recursive (no checking range)*/
	if (num / 10 == 0)
		return num;
	else
		return (num % 10) * pow(10, NumOfDigit(num) - 1) + ReverseInt(num / 10);

	/* 2. iteration 
	long int opt = 0;
	while (num != 0)
	{
		opt = opt * 10 + num % 10;
        if( opt < INT_MIN || opt > INT_MAX)
            return 0;
		ipt/=10;
	}
	return opt;
	*/
}

/*
9. Palindrome Number
	123 no, 1221 yes

	Follow up:
	Coud you solve it without converting the integer to a string?
*/
bool PalindromeNumber(int ipt_num)
{
	if (ipt_num == ReverseInt(ipt_num) && ipt_num > 0)
		return true;

	return false;
}

/*
13. Roman to Integer
Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000

I can be placed before V (5) and X (10) to make 4 and 9.
X can be placed before L (50) and C (100) to make 40 and 90.
C can be placed before D (500) and M (1000) to make 400 and 900.

Input: "LVIII"		Output: 58
Input: "MCMXCIV"	Output: 1994
*/
int RomanToInteger(char *ipt_string)	//stupid 
{
	int opt = 0, len_string = strlen(ipt_string);
	char *end_string = ipt_string + strlen(ipt_string);

	while (ipt_string != end_string)
	{
		if (*ipt_string == 'I')
		{
			if (*(ipt_string + 1) == 'V')
			{
				opt += 4;
				ipt_string += 2;
			}
			else if (*(ipt_string + 1) == 'X')
			{
				opt += 9;
				ipt_string += 2;
			}
			else
			{
				opt += 1;
				ipt_string += 1;
			}
		}
		else if (*ipt_string == 'V')
		{
			opt += 5;
			ipt_string += 1;
		}
		else if (*ipt_string == 'X')
		{
			if (*(ipt_string + 1) == 'L')
			{
				opt += 40;
				ipt_string += 2;
			}
			else if (*(ipt_string + 1) == 'C')
			{
				opt += 90;
				ipt_string += 2;
			}
			else
			{
				opt += 10;
				ipt_string += 1;
			}
		}
		else if (*ipt_string == 'L')
		{
			opt += 50;
			ipt_string += 1;
		}
		else if (*ipt_string == 'C')
		{
			if (*(ipt_string + 1) == 'D')
			{
				opt += 400;
				ipt_string += 2;
			}
			else if (*(ipt_string + 1) == 'M')
			{
				opt += 900;
				ipt_string += 2;
			}
			else
			{
				opt += 100;
				ipt_string += 1;
			}
		}
		else if (*ipt_string == 'D')
		{
			opt += 500;
			ipt_string += 1;
		}
		else if (*ipt_string == 'M')
		{
			opt += 1000;
			ipt_string += 1;
		}
	}
	return opt;
}


/*
8. String to Integer (atoi)
Implement atoi which converts a string to an integer.

The function first discards as many whitespace characters as necessary 
until the first non-whitespace character is found. Then, starting from this character, 
takes an optional initial plus or minus sign followed by as many numerical digits as possible, 
and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, 
which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, 
or if no such sequence exists because either str is empty or it contains only whitespace characters, 
no conversion is performed.

If no valid conversion could be performed, a zero value is returned.

Note:
Only the space character ' ' is considered as whitespace character.
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. If the numerical value is out of the range of representable values, INT_MAX (231 − 1) or INT_MIN (−231) is returned.
*/
int myAtoi(char* ipt_str) 
{ 
	long long opt = 0, len_string = strlen(ipt_str);
	char *end_string = ipt_str + strlen(ipt_str);
	bool negative = false;
	while (ipt_str != end_string)
	{
		if (*ipt_str == ' ')
			;
		else if (IsNumber(ipt_str))
		{
			opt = 10 * opt + *ipt_str - '0';
			if (opt >= INT_MAX || opt <= INT_MIN || !IsNumber(ipt_str + 1))
				goto EXIT;
		}
		else //not num, not ' '
		{
			if ((*ipt_str == '-') && IsNumber(ipt_str + 1))
				negative = true;
			else if ((*ipt_str == '+') && IsNumber(ipt_str + 1))
				;
			else
				goto EXIT;
		}
		ipt_str++;
	}
	opt = 0;
EXIT:
	if (negative)
		opt *= -1;

	if (opt >= INT_MAX)
		return INT_MAX;
	else if (opt <= INT_MIN)
		return INT_MIN;
	return opt;
}


/*
70. Climbing Stairs
You are climbing a stair case. It takes n steps to reach to the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
Note: Given n will be a positive integer.

Input: 2		Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps

Input: 3		Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
*/
int climbStairs(int n)
{
	/*	Time Limit Exceeded		=>  or using "Fibonacci Formula"
	if (n <= 2)
		return n;
	else
		return climbStairs(n - 1) + climbStairs(n - 2);
	*/
	if (n <= 2)
		return n;
	int pre1 = 1, pre2 = 2, curr;
	for (int i = 3; i <= n; i++)
	{
		curr = pre1 + pre2;
		pre1 = pre2;
		pre2 = curr;
	}
	return curr;
}

/*
198. House Robber
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

Input: [1,2,3,1]		Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.

Input: [2,7,9,3,1]		Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.
*/
int rob(int* nums, int numsSize)	//try again
{	
	/*		Time Limit Exceeded
	if (numsSize == 0)
		return 0;
	else if (numsSize == 1)
		return nums[0];
	else if (numsSize == 2)
		return max(nums[0], nums[1]);
	else
		return max(nums[numsSize - 1] + rob(nums, numsSize - 2), nums[numsSize - 2] + rob(nums, numsSize - 3));
	*/

	int pre=0, curr=1, rlt=0;	
	for (int i = 1; i < numsSize; i++)
	{		
		curr = nums[i];
		rlt = max(pre, curr);
	}

	return 0;
}

/*
461. Hamming Distance
The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
Given two integers x and y, calculate the Hamming distance.
Note:
0 ≤ x, y < 231.

Input: x = 1, y = 4
Output: 2
Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
      ↑   ↑
The above arrows point to positions where the corresponding bits are different.
*/
int hammingDistance(int x, int y)
{
	int rlt = 0, xor = x^y;
	while (xor != 0)
	{
		if (xor & 0x01 == 0x01)
			rlt++;
		xor = xor >> 1;
	}
	/* Nice solution for bit counting
	while (xor) 
	{
		++rlt;
		xor &= xor - 1;
	}
	*/
	return rlt;
}




