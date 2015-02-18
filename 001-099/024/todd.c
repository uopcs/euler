#include <stdio.h>
#include <math.h>

unsigned long long fact(unsigned long long n)
{
	unsigned long long i;
	unsigned long long f = 1;
	for (i = 1; i <= n; i++)
	{
		f *= i;
	}
	return f;
}

unsigned long long joinIntInt(unsigned long long a, unsigned long long b, unsigned long long n) // this works given that a is always one digit unsigned long long
{
	unsigned long long k = (n-1);
	//printf("%i + %i: %i -> %f\n", a, b, n, ceil(((pow(10, k))*a) + b));
	return ceil(((pow(10, k))*a) + b);
}

unsigned long long* removeElem(int* arr, int idx, int n) 
{
	int i;
	int j = 0;
	int* arr2 = malloc(sizeof(int) * (n-1));
	for (i = 0; i < n; i++)
	{
		if (arr[i] != idx)
		{
			arr2[j] = arr[i];
			j++;
		}
	}
	return arr2;
}

unsigned long long* getPermutations(int n, int* arr)
{
	int i;
	int j;
	int idx = 0;
	unsigned long long* perms;
	unsigned long long* c = malloc(sizeof(unsigned long long) * fact(n));
	if (n > 2) // divide
	{
		
		for (i = 0; i < n; i++)
		{
			// remove element i from array
			// recurse w/ shortened arrays
			perms = getPermutations(n-1, removeElem(arr, arr[i], n));
			//printf("%i: %i\n", i, n);
			// iterate through shortened arrays, appending i to the front of each
			for (j = 0; j < fact(n-1); j++)
			{
				c[idx] = joinIntInt(arr[i], perms[j], n);
				//printf("%i\n", c[idx]);
				idx++;
			}
			
		}
		// return c
		return c;
	}
	else // conquer
	{
		// arr[0], arr[1]
		// arr[1], arr[0]
		c[0] = joinIntInt(arr[0], arr[1], 2);
		c[1] = joinIntInt(arr[1], arr[0], 2);
		return c;
	}
}



unsigned long long main(unsigned long long argc, char **argv)
{
	// project euler q24
	int len = 10;
	int* digits = malloc(len * sizeof(unsigned long long));
	int i;
	for (i = 0; i < len; i++)
	{
		printf("%i", i);
		digits[i] = i;
	}
	printf("\n\n");
	
	// get array of permutations
	unsigned long long* permutations = getPermutations(len, digits);
	printf("%I64d\n", permutations[999999]);
		
	// this overflows
	
	return 0;
}
