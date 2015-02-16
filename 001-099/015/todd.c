#include <stdio.h>



int main(int argc, char **argv)
{
	// project euler q15
	int x = 20;
	int l = x+1;
	unsigned long long lattice[l][l];
	memset(lattice, 0, sizeof(unsigned long long) * l * l); // initilizes array as 0
	int i;
	int j;
	// start in bottom right corner
	// initialize bottom and right sides as 1, lattice[l-1][l-1] = 0
	for (i = 0; i < l; i++)
	{
		lattice[l-1][i] = 1;
		lattice[i][l-1] = 1;
	}
	lattice[l-1][l-1] = 0;
	// can now start filling in the lattice
	// lattice[x][y] = lattice[x][y+1] + lattice[x+1][y]
	while (1)
	{
		for (i = 0; i < l-1; i++)
		{
			for (j = 0; j < l-1; j++)
			{
				if (lattice[i][j] == 0 && lattice[i+1][j] != 0 && lattice[i][j+1] != 0)
				{
					lattice[i][j] = lattice[i][j+1] + lattice[i+1][j];
					printf("lattice[%i][%i]: %llu\n", i, j, lattice[i][j]);
					continue;
				}
			}
		}
		if (lattice[0][0] != 0)
		{
			printf("%llu\n", lattice[0][0]);
			break;
		}
	}
	return 0;
}
