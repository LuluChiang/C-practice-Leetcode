/*
	Project for practice
*/
#include <stdio.h>
#include <math.h>
#include <string.h>
//#include "Calculator.h"
//#include "LinkedList.h"
#include "Sort.h"
#include "Array.h"

#define MainExpress "1+2"
#define postfix "123+="
#define Infix "1+2+3"

#define LeetCodeInput ""

int Calculator(char *post);


#define numTestArray 4
int main()
{
	int result = 0, a = 3, b = 6;
	int ar_int[numTestArray] = { 1,1,2,4 };
	char s[2] = { 'a','b' }, p[2] = { 'b','a' };
	int* size = NULL;
	printf("%c  ", *p);
	printf("LeetCode Start:\r\n");
	findAnagrams(s, p, size);
	for (int i = 0; i < 5; i++)
		printf("ar[%d] = %d, \r\n", i, ar_int[i]);

	


	char *ptr = LeetCodeInput;
	result = Calculator(ptr);
	printf("result = %d\r\n", result);

	while (1)
		;
	return 0;
}















char NextOprator(char *str)
{
	str++;
	while (!IsOprator(str))
	{
		str++;
	}
	return *str;

}

int NextOprand(char *str)	//get right one
{
	int opt;
	while (!IsOprator(str))
	{
		str++;
	}
	opt = myAtoi(str);
	return opt;
}

// ex: 123++
int Calculator(char *post) 
{
	unsigned int tempa;
	//unsigned int tempb;
	unsigned int ans;
	char temp[]="";
	char op = ' ', next_op=' ';

	ans = myAtoi(post);	//get first oprand
	while (1)
	{		
		//find next oprator
		while (!IsOprator(post))	
			post++;
		op = NextOprator(post);

		if (op == '+' || op == '-')
		{
			if (NextOprator(post) == '+' || NextOprator(post) == '-')
				ans = Oprator(ans, NextOprand(post), &op);
			else if (NextOprator(post) == '*' || NextOprator(post) == '/')
			{
				//do next * or /
				tempa = NextOprand(post);
				next_op = NextOprator(post);

			}
		}
		else if (op == '*' || op == '/')
		{
			ans = Oprator(ans, NextOprand(post), &op);		
			post = &op;	//post point to op which we just used
		}
	}
	return ans;
}

