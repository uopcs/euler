#include <stdio.h>
#include <stdbool.h>

bool isTriangle(int n)
{
	int i = 1;
	while (((0.5) * (i * (i+1))) <= n)
	{
		if (((0.5) * (i * (i+1))) == n)
		{
			return true;
		}
		i++;
	}
	return false;
}

int getScore(char word[], int length)
{
	int i;
	int score = 0;
	for (i = 0; i < length; i++)
	{
		score += (int)word[i] - 64;
	}
	return score;
}

int main(int argc, char **argv)
{
	// euler q42
	
	// setup file pointers
	FILE *fp;
	int sum = 0; // sum of scores

	
	char filename[] = "H:\\Cdev\\MEMS\\words.txt";
	fp = fopen(filename, "r");
	char ch;
	char word[256];
	bool readingName = false;
	int idx = 0;
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
			if (isTriangle(getScore(word, idx)))
			{
				sum++;
			}
		}
		else if (readingName)
		{
			word[idx++] = ch;
		}
	}
	printf("%i\n", sum);
	return 0;
}
