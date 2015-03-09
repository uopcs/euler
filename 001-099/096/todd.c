#include <stdio.h>
#include <stdbool.h>
#include <conio.h>
#include <time.h>


void parse(int**** p)
{
	FILE *fp;
	
	int i = -1; // puzzle id
	int j = 0; // section id
	int k = 0; // section i
	int l = 0; // section j
	
	char filename[] = "H:\\Cdev\\sudoku\\sodoku\\puzzles.txt";
	fp = fopen(filename, "r");
	char ch;
	char* buf = malloc(sizeof(char)); // current char
	
	int line = 0;
	while ((ch = getc(fp)) != EOF)
	{
		if ((line % 10) != 0)
		{
			// parse
			//printf("%c", ch);
			buf[0] = ch;
			if (j < 9)
			{
				//printf("%i, %i, %i, %i\n", i, j, k, l);
				p[i][j][k][l++] = atoi(buf);
				if (l == 3)
				{
					l = 0;
					j++;
				}
			}
		}
		
		
		
		if (ch == '\n')
		{
			if ((line % 10) == 0)
			{
				//printf("\n\n");
				i++;
				j = 0;
				k = 0;
				l = 0;
			}
			else if (j % 3 == 0)
			{
				l = 0;
				j -= 3;
				k++;
				if (k == 3)
				{
					k = 0;
					j += 3;
				}
			}
			if (j == 9)
			{
				j = 0;
			}
			
			line++;
		}
	}
}

void removeData(int* poss, int* data)
{
	// both 9 long
	int i;
	for (i = 0; i < 9; i++)
	{
		if (data[i] != 0)
		{
			// data is not a blank
			// the cell in question cannot be data
			poss[data[i]-1] = 0; // set as not possible
		}
	}
}

int getPossibilityCount(int* poss)
{
	int count = 0;
	int i;
	for (i = 0; i < 9; i++)
	{
		if (poss[i] != 0)
		{
			count++;
		}
	}
	return count;
	
}

void getSection(int*** puzzle, int* section, int i)
{
	int j;
	int k;
	int idx = 0;
	for (j = 0; j < 3; j++)
	{
		for (k = 0; k < 3; k++)
		{
			//printf("%i, ", puzzle[i][j][k]);
			section[idx++] = puzzle[i][j][k];
		}
	}
	//printf("\n");
}

void getRow(int*** puzzle, int* row, int i, int j)
{
	int idx = 0;
	int sr = i - (i % 3); // get the 'section row'
	int offset;
	int k;
	for (offset = 0; offset < 3; offset++)
	{
		for (k = 0; k < 3; k++)
		{
			//printf("%i, ", puzzle[sr+offset][j][k]);
			row[idx++] = puzzle[sr+offset][j][k];
		}
	}
	//printf("\n");
	
}

void getColumn(int*** puzzle, int* col, int i, int k)
{
	int idx = 0;
	int sc = i % 3;
	int offset;
	int j;
	// sections will be: sc, sc+3, sc+6
	for (offset = 0; offset < 7; offset += 3)
	{
		for (j = 0; j < 3; j++)
		{
			//printf("%i, ", puzzle[sc+offset][j][k]);
			col[idx++] = puzzle[sc+offset][j][k];
		}
	}
	//printf("\n");
}

void printBoard(int *** puzzle)
{
	system("cls");
	int i = 0;
	int j = 0;
	int k = 0;
	int num;
	printf("|-----------|\n|");
	while (i < 9)
	{
		num = puzzle[i][j][k++];
		if (num != 0)
		{
			printf("%i", num);
		}
		else
		{
			printf(" ");
		}
		
		if (k == 3)
		{
			printf("|");
			k = 0;
			i++;
			if (i % 3 == 0)
			{
				i -= 3;
				printf("\n|");
				k = 0;
				j++;
				if (j == 3)
				{
					printf("-----------|\n");
					j = 0;
					i += 3;
					k = 0;
					if (i != 9)
					{
						printf("|");
					}
				}
			}
		}
	}
}

int getSolution(int* poss)
{
	int i;
	for (i = 0; i < 9; i++)
	{
		if (poss[i] != 0){
			poss[i] = 0; // to 0
			return i+1;
		}
	}
	return 0;
}



void cpyPuzzle(int*** a, int*** b)
{
	int i; int j; int k;
	for (i = 0; i < 9; i++)
	{
		
		for (j = 0; j < 3; j++)
		{
			for (k = 0; k < 3; k++)
			{
				
				//printf("%i %i %i %i", b[i][j][k], i, j, k);
				b[i][j][k] = a[i][j][k];
			}
		}
	}
}

void cpyArr(int* a, int* b)
{
	int i;
	for (i = 0; i < 9; i++)
	{
		b[i] = a[i];
	}
}

bool testTried(int** t, int i, int j, int k)
{
	int l;
	for (l = 0; l < 81;l ++)
	{
		if (i == t[l][0] && j == t[l][1] && k == t[l][2])
		{
			return true;
		}
	}
	return false; // this cell has not been tried
}

int solvePuzzle(int*** puzzle, int** tried, int idx)
{
	int i; // section id
	int j; // section i
	int k; // section j
	
	int l; // used when recursing
	int* possible = malloc(sizeof(int) * 9);
	
	int* section = malloc(sizeof(int) * 9); // square section
	int* col = malloc(sizeof(int) * 9); // column
	int* row = malloc(sizeof(int) * 9); // row
	
	int* best = malloc(sizeof(int) * 3); // contains the i j and k of easiest to guess cell
	int* bestPoss = malloc(sizeof(int) * 9);
	int bestN;
	
	int nPos = 0;
	
	bool update;
	bool complete = false;
	
	
	
	
	int*** tmp = malloc(sizeof(int**) * 9); // used when 'guessing'
	
	for (i = 0; i < 9; i++)
	{
		tmp[i] = malloc(sizeof(int*) * 3);
		for (j = 0; j < 3; j++)
		{
			tmp[i][j] = malloc(sizeof(int) * 3);
			memset(tmp[i][j], 0, sizeof(int) * 3);
		}
	}
	int sum = 0;
	
	
	
	
	// algorithm is recursive
	
	
	while (complete == false)
	{
		update = false;
		complete = true;
		bestN = 9;
		memset(best, 0, sizeof(int) * 3);
		
		
		
		//
		// run a 'sweep'
		printBoard(puzzle);
		for (i = 0; i < 9; i++)
		{
			// for all sections
			
			for (j = 0; j < 3; j++)
			{
				for (k = 0; k < 3; k++)
				{
					if (puzzle[i][j][k] == 0)
					{
						//printf("%i ", puzzle[i][j][k]);
						memset(possible, 1, sizeof(int) * 9); // 1 = possible, 0 not possible (note the value wont acutually be 1)
						// get column
						getColumn(puzzle, col, i, k);
						// get row
						getRow(puzzle, row, i, j);
						// get section
						getSection(puzzle, section, i);
						
						// test if one possiblility
						removeData(possible, col);
						removeData(possible, row);
						removeData(possible, section);
						
						// if one possibility, update = true, puzzle[i][j][k] = possibility
						
						nPos = getPossibilityCount(possible);
						
						if (!testTried(tried, i, j, k))
						{
							if(testTried(tried, i, j, k))
							{
								printf("vhgvh");
							}
							if (nPos < bestN)
							{
								//printf("%d\n", nPos < bestN);
								bestN = nPos;
								best[0] = i;
								best[1] = j;
								best[2] = k;
								cpyArr(possible, bestPoss);
							}
						}
						
						if (nPos == 1)
						{
							puzzle[i][j][k] = getSolution(possible);
							update = true;
						}
						else if (nPos == 0)
						{
							// dun fucked up
							return 0;
						}
						else
						{
							complete = false;
						}
						// cant update then set complete to false
					}
					
					
					
				}
				//printf("\n");
			}
			//printf("\n\n");
		}
		
		
		if (!update)
		{
			// we need to guess
			//printf("guess cell [%i][%i][%i]: %i possilibities\n\n", best[0], best[1], best[2], bestN);
			
			if (best[0] == 0 && best[1] == 0 && best[2] == 0)
			{
				return 0;
			}
			
			tried[idx][0] = best[0];
			tried[idx][1] = best[1];
			tried[idx++][2] = best[2];
			// copy puzzle bestN times
			// fill in the blank with possibilities
			// recurse this function with the new ones?
			// how do i know if i fucked up?
			for (l = 0; l < bestN; l++)
			{
				cpyPuzzle(puzzle, tmp);
				tmp[best[0]][best[1]][best[2]] = getSolution(bestPoss);
				sum = solvePuzzle(tmp, tried, idx);
				if (sum != 0)
				{
					//printf("SOLVED\n");
					return sum;
					
				}
				else
				{
					continue;
				}
			}
			return 0;
			
			if (idx == 81)
			{
				printf("FAILED\n");
				return -1;
			}
			
			
			
		}
	}
	
	printBoard(puzzle);
	// puzzle is solved
	// get sum
	
	sum = 0;
	sum += puzzle[0][0][2];
	sum += puzzle[0][0][1] * 10;
	sum += puzzle[0][0][0] * 100;
	
	//printf("%i \n", sum);
	if (sum != 0 && sum != -1)
	{
		printf("SOLVED\n");
		return sum;
	}
	else
	{
		printf("FAILED\n");
	}
}

int solve(int**** p, int n)
{
	// solves all puzzles
	int i;
	int sum = 0;
	
	int j;
	
	int** tried = malloc(sizeof(int*) * 81);
	for (i = 0; i < 81; i++)
	{
		tried[i] = malloc(sizeof(int) * 3);
		memset(tried[i], 0, sizeof(int) * 3);
	}
	
	
	
	for (i = 0; i < n; i++)
	{
		
		//reset
		for (j = 0; j < 81; j++)
		{
			memset(tried[j], 0, sizeof(int) * 3);
		}
		
		printf("problem %i: ", i+1);
		sum += solvePuzzle(p[i], tried, 0);
		//printf("problem: %i, sum: %i\n", i+1, sum);
		
	}
	
	printf("%i", sum);
}



int main(int argc, char **argv)
{
	int n = 50; // number of puzzles
	// initialize array of puzzles
	int**** puzzles = malloc(sizeof(int***) * n); // 50 9x3x3 grids
	int i; int j; int k;
	for (i = 0; i < n; i++)
	{
		puzzles[i] = malloc(sizeof(int**) * 9);
		for (j = 0; j < 9; j++)
		{
			puzzles[i][j] = malloc(sizeof(int*) * 3);
			for (k = 0; k < 3; k++)
			{
				puzzles[i][j][k] = malloc(sizeof(int) * 3);
				memset(puzzles[i][j][k], 0, sizeof(int) * 3);
			}
		}
	}
	
	parse(puzzles);
	solve(puzzles, n);
	
	
	
	
	
	

	return 0;
}
