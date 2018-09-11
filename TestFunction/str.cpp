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