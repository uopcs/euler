#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int getLastDigit(int num)
{
	int k = (int)floor(log10(num))+1;
	int i;
	int sub = 0;
	sub += floor(num / pow(10, 1)) * pow(10, 1);
	return (num)-(sub);
}

int getLetters(int num)
{
	// split int into parts
	int k = (int)floor(log10(num))+1;
	int i;
	int letters = 0;
	int digit = 0;
	int fdigit = 0;
	bool suffix = false;
	for (i = 0; i < k; i++)
	{
		
		// get (i+1)th digit

		digit = getLastDigit((int)floor(num / pow(10, i)));

		
		
		if (i == 0)
		{
			
			// single digit
			switch (digit)
			{
				case 0: // not neccecary, 10 -> ten (no zero included)
					break; // do nothing
				case 1: // one
				case 2: // two
				case 6: // six
					letters += 3;
					break;
				case 4: // four
				case 5: // five
				case 9: // nine
					letters += 4;
					break;
				case 3: // three
				case 7: // seven
				case 8: // eight
					letters += 5;
					break;
			}
		}
		else if (i == 1)
		{
			// 10s
			if (digit == 1)
			{

				// deal with teens
				fdigit = getLastDigit((int)floor(num / pow(10, 0)));
				switch (fdigit)
				{
					case 0: // ten
					case 1: // eleven - one (3)
					case 2: // twelve - two (3)
					case 3: // thirteen - three (3)
					case 5: // fifteen - five (3)
					case 8: // eighteen - eight (3)
						letters += 3;
						break;
					case 4: // fourteen - four (4)
					case 6: // sixteen - six (4)
					case 7: // seventeen - seven (4)
					case 9: // nineteen - nine (4)
						letters += 4;
						break;
				}
			}
			else
			{
				switch (digit)
				{
					case 4: // forty
					case 5: // fifty
					case 6: // sixty
						letters += 5;
						break;
					case 2: // twenty
					case 3: // thirty
					case 8: // eighty
					case 9: // ninety
						letters += 6;
						break;
					case 7: // seventy
						letters += 7;
						break;
				}
			}
		}
		else if (i == 2)
		{
			// 100s
			switch (digit)
			{
				case 1: // one hundred
				case 2: // two hundred
				case 6: // six hundred
					letters += 10;
					break;
				case 4: // four hundred
				case 5: // five hundred
				case 9: // nine hundred
					letters += 11;
					break;
				case 3: // three hundred
				case 7: // seven hundred
				case 8: // eight hundred
					letters += 12;
					break;
			}
			if (digit != 0 && suffix == true)
			{
				letters += 3; // and
			}
		}
		else
		{
			// can only be 1000
			letters += 11;// one thousand
		}
		
		if (digit != 0)
		{
			suffix = true;
		}
	}
	return letters;
}

int main(int argc, char **argv)
{
	// project euler q17
	int i;
	int max = 1000;
	int sum = 0;
	for (i = 1; i <= max; i++)
	{
		sum += getLetters(i);
		//printf("%i -> %i\n", i, getLastDigit(i));
		//printf("%i -> %i\n\n", i, getLetters(i));
	}
	printf("%i", sum);
	return 0;
}
