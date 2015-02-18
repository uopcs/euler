#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

int buildConcatination(int n, int k)
{
	// <k*1><k*2>..<k*n>
	int* products = malloc(sizeof(int) * n);
	int i;
	for (i = 1; i <= n; i++)
	{
		products[i-1] = i * k;
	}
	// concatinate the array of products
	
	int concat = 0;
	int offset = 0;
	for (i = n-1; i >= 0; i--)
	{
		concat += ceil((products[i] * pow(10, offset)));
		offset += floor(log10((double)products[i]))+1;
		//printf("%i, %i: %i\n", concat, offset, products[i]);
	}
	//printf("%i\n", concat);
	
	return concat;
}

bool mapArr(bool* has)
{
	int i;
	bool map = true;
	for (i = 0; i < 9 ; i++)
	{
		map &= has[i]; // bitwise AND
	}
	return map;
}

int testPandigital(int n)
{
	// if pandigital, return n
	// else return 0
	// array of booleans, if all are true then number is pandigital
	bool* has = malloc(sizeof(bool) * 9);
	memset(has, false, sizeof(bool) * 9); // init as false
	
	// pre-allocate memory for character buffer
	char* n_s = malloc(sizeof(char) * (floor(log10((double)n))+1)); 
	itoa(n, n_s, 10); 
	int i;
	int j;
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			if ((int)(n_s[i] - '0') == (j+1))
			{
				has[j] = true;
			}
		}
	}
	if (mapArr(has))
	{
		//printf("%i\n", n);
		return n;
	}
	return 0;
}

int getMax(int a, int b)
{
	if (a > b)
	{
		return a;
	}
	return b;
}

int main(int argc, char **argv)
{
	// project euler q38
	int max = 0;
	int i;
	int curr;
	// test all pandigitals using set (1, 2, 3, 4, 5) between 1 and 9
	// (1, 2, 3, 4) between 1 and 99
	// (1, 2, 3) between 1 and 999
	// (1, 2) between 1 and 9999
	for (i = 1; i < 10000; i++)
	{
		if (i < 10)
		{
			max = getMax(max, testPandigital(buildConcatination(5, i)));
		}
		if (i < 100)
		{
			max = getMax(max, testPandigital(buildConcatination(4, i)));
		}
		if (i < 1000)
		{
			max = getMax(max, testPandigital(buildConcatination(3, i)));
		}
		max = getMax(max, testPandigital(buildConcatination(2, i)));
	}
	
	printf("%i\n", max);
	
	
	return 0;
}
