#pragma once
#include <string.h>
#include <math.h>
#include <limits.h>

int max(int a, int b);
int min(int a, int b);
void swap(int *a, int *b);
int AbsoluteValue(int n);
bool IsOprator(char *ptr);
bool IsNumber(char *ptr);
int Oprator(int a, int b, char *op);
int Fibonacci(int n);
int ReverseInt(int num);
int NumOfDigit(int num);
bool PalindromeNumber(int ipt_num);
int RomanToInteger(char *ipt_string);
int myAtoi(char* ipt_str);
