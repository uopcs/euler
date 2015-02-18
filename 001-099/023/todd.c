#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool checkAbundant(int n)
{
	int i;
	int sum = 0;
	// loop over to find factors of n
	for (i = 1; i <= (int)sqrt(n); i++)
	{
		if ((double)n/i == n/i)
		{  
			// sum all factors
			sum += i;  // if n = 12 and i = 2, this would be sum += 2
			if (i != 1 && i != n/i)
				sum += (n/i); // and this would be sum += 6
		}
	}
	//printf("%i - %i\n", n, sum);
	// if sum = n, return true
	if (sum > n)
		return true;
	// else return false
	return false;
}

bool checkIfSumOfTwoAbundant(int n)
{
	// iterate from i to n/2
	int i;
	int j;
	for (i = 1; i <= n/2; i++)
	{
		// test if i is abundant
		if (checkAbundant(i))
		{
			// for abundant i, test (n - i) - j
			j = n - i;
			// if i and j are abundant return true
			if (checkAbundant(j))
			{
				return true;
			}
		}
	}
	return false;
	
	// if loop expires, return false
}

int main(int argc, char **argv)
{
	// project euler q23
	
	int sum = 0;
	int i;

	// iterate through numbers 1 to 28123
	
	for (i = 1; i <= 28123; i++)
	{
		// check if a number can be written as the sum of two abundant numbers
		// if so, add it to sum
		if (!checkIfSumOfTwoAbundant(i))
		{
			//printf("%i\n", sum);
			sum += i;
		}
		
	}
	// print sum
	printf("\n%i\n", sum);
	
	
	return 0;
}
