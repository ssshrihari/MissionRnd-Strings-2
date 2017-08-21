/*
OVERVIEW: Given a string, reverse all the words not the string.

E.g.: Input: "i like coding". Output: "coding like i"

INPUTS: A string.

OUTPUT: Modify the string according to the logic.

NOTES: Don't create new string.
*/
#include <Stdio.h>
#include <string.h>

void str_words_in_rev(char *input, int len){
	int i = 0, j = 0, k = 0, start = 0, end = 0, count = 0, spacec = 0;
	char temp;
	j = len - 1;

	//reversing the entire string
	for (i = 0; i < j; i++, j--)
	{
		temp = input[i];
		input[i] = input[j];
		input[j] = temp;
	}
	//reversing each word in the string
	temp = 0;
	for (i = 0; i < len; i++)
	{
		//setting the parameters for a word in the string
		if (input[i] != ' ')
		{
			if (count == 0)
			{
				start = i;
				count = 1;
			}
			k++;
			end = k;
			spacec = 0;

		}
		//if multiple spacces occur in the input in the starting,ending or in between words
		if ((input[i] == ' ' &&  spacec == 1) || count == 0)
		{
			k++;
		}
		//reversing the words
		if ((input[i] == ' ' || i == len - 1) && count == 1)
		{
			end = end - 1;
			for (j = start; j < end; j++, end--)
			{

				temp = input[j];
				input[j] = input[end];
				input[end] = temp;
			}

			count = 0;
			k++;
			spacec = 1;

		}

	}




}