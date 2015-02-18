#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int simplifyFraction(int n, int d)
{
	// get lowest common denominator
	int i;
	while (1)
	{
		for (i = sqrt(n); i > 0; i--)
		{
			if (n/i == (double)n/i && d/i == (double)d/i)
			{
				n = n/i;
				d = d/i;
				//printf("\n%i/%i\n", n, d);
				continue;
			}
		}
		break;
	}
	return d;
}

int getLastDigit(int n)
{
	return n - floor(n / 10) * 10;
}

int getFirstDigit(int n)
{
	// always two decimal figures
	return floor(n / 10);
}

bool naiveSimplify(int n, int d)
{
	//printf("%i, %i -> %i, %i: %i, %i\n", n, d, getFirstDigit(n), getLastDigit(n), getFirstDigit(d), getLastDigit(d));
	
	// possible simplifications
	int n0 = getFirstDigit(n);
	int n1 = getLastDigit(n);
	int d0 = getFirstDigit(d);
	int d1 = getLastDigit(d);
	
	double f0 = (double)n/d; // value of fraction n/d
	double f1 = 0;
	double f2 = 0;
	double f3 = 0;
	double f4 = 0;
	
	// test if we can cancel things out
	if (d1 != 0)
	{
		if (n0 == d0)
		{
			f1 = (double)n1/d1;
		}
		if (n1 == d0)
		{
			f2 = (double)n0/d1;
		}
	}
	if (n0 == d1)
	{
		f3 = (double)n1/d0;
	}
	if (n1 == d1)
	{
		f4 = (double)n0/d0;
	}
	
	if (f0 == f1 || f0 == f2 || f0 == f3 || f0 == f4)
	{
		//printf("%i/%i = %f -> %f, %f, %f, %f\n", n, d, f0, f1, f2, f3, f4);
		return true;
	}
	
	
	return false;
}

int main(int argc, char **argv)
{
	// project euler q33

	// iterate through every fraction 
	int i;
	int j;
	int prod_n = 1;
	int prod_d = 1;
	for (i = 11; i < 100; i++) // denominator
	{
		for (j = 10; j < i; j++) // numerator
		{
			if (!((i % 10 == 0) && (j % 10 == 0))) // skip trivial examples
			{
				if (! ((getFirstDigit(i) == getLastDigit(i)) && (getFirstDigit(j) == getLastDigit(j))) )
				{
					if ((getFirstDigit(i) == getFirstDigit(j)) || (getFirstDigit(i) == getLastDigit(j)) ||
						(getLastDigit(i) == getFirstDigit(j)) || (getLastDigit(i) == getLastDigit(j)))
					{
						if (naiveSimplify(j, i))
						{
							//printf("%i/%i\n", j, i);
							prod_n *= j;
							prod_d *= i;
							//printf("%d/%d\n", prod_n, prod_d);
						}
					}
				}
			}
		}
	}
	printf("%i\n", simplifyFraction(prod_n, prod_d));
}
