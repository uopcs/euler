#include <stdio.h>

int getMax(int a, int b)
{
	if (a > b)
	{
		return a;
	}
	return b;
}

int getMaxPath(int n, int** t)
{
	int k = n-1; // current size
	
	if ( n == 1)
	{
		return t[0][0];
	}
	
	int** nt = malloc(sizeof(int*) * k);
	int i;
	for (i = 0; i < k; i++)
	{
		nt[i] = malloc(sizeof(int) * k);
		memset(nt[i], 0, sizeof(int) * k);
	}
	
	// build triangle with smaller complexity
	int j;
	
	for (i = 0; i < k-1; i++)
	{
		for (j = 0; j <= i; j++)
		{
			//printf("%i: %i\n", i, j); // row, col
			nt[i][j] = t[i][j];
		}
	}
	
	// now work out the final layer
	// nt[k-1][i] = max(t[k][i]+t[k-1][i], t[k][i+1]+t[k][i]);
	
	for (i = 0; i < k; i++)
	{
		nt[k-1][i] = getMax(t[k][i]+t[k-1][i], t[k][i+1]+t[k-1][i]);
		//printf("%i ", nt[k-1][i]);
	}
	//printf("\n");
	
	
	
	return getMaxPath(k, nt);
}

void fillTriangle(int n, int** t)
{
	// filthy
	int data[120] = {75,
					95, 64, 
					17, 47, 82,
					18, 35, 87, 10, 
					20, 4, 82, 47, 65, 
					19, 1, 23, 75, 3, 34, 
					88, 2, 77, 73, 7, 63, 67, 
					99, 65, 4, 28, 6, 16, 70, 92, 
					41, 41, 26, 56, 83, 40, 80, 70, 33, 
					41, 48, 72, 33, 47, 32, 37, 16, 94, 29, 
					53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14, 
					70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57, 
					91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48, 
					63, 66, 4, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31, 
					4, 62, 98, 27, 23, 9, 70, 98, 73, 93, 38, 53, 60, 4, 23};
					
	int i;
	int row = 0;
	int col = 0;
	for (i = 0; i < 120; i++)
	{
		//printf("%i, %i\n", row, col);
		t[row][col] = data[i];
		col++;
		if (col > row)
		{
			col = 0;
			row++;
		}
	}
}

int main(int argc, char **argv)
{
	// dynamic programming approach to problem 18
	// complexity : O(n^2)
	// as opposed to the factorial complexity brute force approach
	
	int n = 15; // triangle size
	int** t = malloc(sizeof(int*) * n);
	int i;
	for (i = 0; i < n; i++)
	{
		t[i] = malloc(sizeof(int) * n);
		memset(t[i], 0, sizeof(int) * n);
	}
	
	fillTriangle(n, t);
	int maxPath = getMaxPath(n, t);
	
	printf("%i\n", maxPath);
	
	
	
	return 0;
}
