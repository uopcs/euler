#include <stdio.h>
#include <stdbool.h>

int getScore(char name[], int length, int num)
{
	int i;
	int score = 0;
	for (i = 0; i < length; i++)
	{
		score += (int)name[i] - 64;
	}
	return score * num;
}

int main(int argc, char **argv)
{
	// setup file pointers
	FILE *fp;
	int sum = 0; // sum of scores
	
	char filename[] = "H:\\Cdev\\MEMS\\names_s.txt";
	fp = fopen(filename, "r");
	char ch;
	char name[256];
	bool readingName = false;
	int idx = 0;
	int num = 1;
	while ((ch = getc(fp)) != EOF)
	{
		if (ch == '"' && !readingName)
		{
			readingName = true;
			idx = 0;
		}
		else if (ch == '"' && readingName)
		{
			readingName = false;
			sum += getScore(name, idx, num++);
		}
		else if (readingName)
		{
			name[idx] = ch;
			idx++;
		}
	}
	printf("%i", sum);
	return 0;
}
