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

void fillTriangle(int** t)
{
	FILE *fp;
	
	char filename[] = "H:\\Cdev\\euler\\euler\\triangle.txt";
	fp = fopen(filename, "r");
	char ch;
	char buf[2]; // numbers are always 2 digits
	int idx = 0;
	int row = 0;
	int col = 0;
	while ((ch = getc(fp)) != EOF)
	{
		if (ch == ' ')
		{
			t[row][col++] = atoi(buf);
			idx = 0; // new string
		}
		else if (ch == '\n')
		{
			t[row][col++] = atoi(buf);
			idx = 0; // new string
			col = 0;
			row++;
		}
		else
		{
			buf[idx++] = ch;
		}
	}
}

int main(int argc, char **argv)
{
	// q67
	
	int n = 100; // triangle size
	int** t = malloc(sizeof(int*) * n);
	int i;
	for (i = 0; i < n; i++)
	{
		t[i] = malloc(sizeof(int) * n);
		memset(t[i], 0, sizeof(int) * n);
	}
	
	fillTriangle(t);
	int maxPath = getMaxPath(n, t);
	
	printf("%i\n", maxPath);
	
	
	
	return 0;
}
