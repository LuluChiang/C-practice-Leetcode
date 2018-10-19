#include "str.h"


/*
14. Longest Common Prefix

	Write a function to find the longest common prefix string amongst an array of strings.
	If there is no common prefix, return an empty string "".
*/
char* longestCommonPrefix(char** strs, int strsSize)	//90%
{
	if (strsSize == 0)
		return "";

	int i, j = 0;

	for (i = 1; i < strsSize; i++)
	{
		while (strs[0][j] == strs[i][j])
			j++;
		strs[0][j] = '\0';
		j = 0;
	} 

	return strs[0];
}

/*
171. Excel Sheet Column Number
Given a column title as appear in an Excel sheet, return its corresponding column number.

A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28

Input: "A"		Output: 1
Input: "AB"		Output: 28
Input: "ZY"		Output: 701
*/
int titleToNumber(char* s) 
{
	int sum = 0, power = 0;
	for (int i = strlen(s) - 1; i >= 0; i--, power++)
		sum += (s[i] + 1 - 'A') *pow(26, power);	
	return sum;
}

/*
836. Rectangle Overlap
A rectangle is represented as a list [x1, y1, x2, y2], where (x1, y1) are the coordinates of its bottom-left corner, and (x2, y2) are the coordinates of its top-right corner.
Two rectangles overlap if the area of their intersection is positive.  To be clear, two rectangles that only touch at the corner or edges do not overlap.
Given two (axis-aligned) rectangles, return whether they overlap.

Input: rec1 = [0,0,2,2], rec2 = [1,1,3,3]		Output: true
Input: rec1 = [0,0,1,1], rec2 = [1,0,2,1]		Output: false
*/
bool isRectangleOverlap(int* rec1, int rec1Size, int* rec2, int rec2Size)
{
	return rec1[0]<rec2[2] && rec1[1]<rec2[3] && rec1[2]>rec2[0] && rec1[3]>rec2[1];
}

/*
557. Reverse Words in a String III
Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

Input: "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
Note: In the string, each word is separated by single space and there will not be any extra space in the string.
*/
void swap_char(char* a, char* b)
{
	if (*a == *b)		// otherwise, parameter a, b will be changed simultaneously
		return;
	*a = *a - *b;
	*b = *a + *b;
	*a = *b - *a;
}
char* reverseWords(char* s)
{
	int left = 0, len = strlen(s);
	for (int space = 0; space <= len; space++)
	{
		if (s[space] == ' ' || s[space] == 0x00)
		{
			for (int i = space - 1; i > (space + left) / 2 - 1; i--)
				swap_char(&s[i], &s[left + space - i - 1]);
			left = space + 1;
		}
	}
	return s;
}















