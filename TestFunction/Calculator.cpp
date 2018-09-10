/*
 - Function of math problem

*/


#include <string.h>
#include <math.h>
#include <limits.h>
#include "Calculator.h"


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