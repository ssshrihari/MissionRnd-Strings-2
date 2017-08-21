/*
OVERVIEW: Given two strings, find the words that are common to both the strings.
E.g.: Input: "one two three", "two three five".  Output: "two", "three".

INPUTS: Two strings.

OUTPUT: common words in two given strings, return 2D array of strings.

ERROR CASES: Return NULL for invalid inputs.

NOTES: If there are no common words return NULL.
*/

#include <stdio.h>

#include <malloc.h>
#define SIZE 31
char ** commonWords(char *str1, char *str2) {
	int i = 0, j = 0, space_count = 0, count1 = 0, count2 = 0, count = 0, start = 0 , k = 0, q = 0;
	char refrence_1[100][100];
	long int a[100] = { 0 }, b[100] = { 0 };
	char **output;
	output = (char **)malloc(SIZE*sizeof(char*));
	if (str1 == NULL || str2 == NULL)
	{
		return NULL;
	}
	while (str1[i] == ' ')//Avoiding the spaces in the start of string
		i++;
	a[i] = 1;
	i = 0;
	while (str1[i] != '\0')
	{
		if (str1[i] != ' ')
		{
			if (count == 0)//Starting letter of the string
			{
				start = i;
				count = 1;
			}
			refrence_1[j][k++] = str1[i];//storing each alphabet in a 2-d array
			a[j] = a[j] + (int(str1[i]));//Ascii value sum
		}
		else
		{
			space_count++;
			q = i-1;
			while (q>start &&str1[q] != ' ' )//Making ASCII value Unique
			{
				a[j] = a[j] * int(str1[q]);
				q--;
			}
			count = 0;
			q = 0;
			refrence_1[j][k++] = '\0';
			j++;
			a[j] = 1;
			k = 0;
			
		}
		if (str1[i + 1] == '\0')//Last word of the string
		{
			q = i;
			while (q>start &&str1[q] != ' ')
			{
				a[j] = a[j] * int(str1[q]);
				q--;
			}
			count = 0;
			q = 0;
		}
		i++;
	}
	if (space_count == i)//if string has all spaces
		return NULL;
	space_count = 0;
	refrence_1[j][k++] = '\0';
	count1 = j>0 ? j + 1 : j;//count of words
	j = k = i =q=count=start= 0;
	while (str2[i] == ' ')//Avoiding all the spaces in the beginning of string
		i++;
	b[i] = 1;
	while (str2[i] != '\0')
	{
		if (str2[i] != ' ')
		{
			if (count == 0)//starting character of the word
			{
				start = i;
				count = 1;
			}
			b[j] = b[j] + (int(str2[i]));//ASCII value for the word
		}
		else
		{
			space_count++;
			q = i-1;
			while (q>start && str2[q] != ' ' )//Giving a unique ASCII value for the word
			{
				b[j] = b[j] * int(str2[q]);
				q--;
			}
			count = 0;
			q = 0;
				j++;
			b[j] = 1;
			k = 0;	
		}
		if (str2[i + 1] == '\0')//Last word of the string
		{
			q = i;
			while (q>start &&str1[q] != ' ')
			{
				b[j] = b[j] * int(str2[q]);
				q--;
			}
			count = 0;
			q = 0;
		}
		i++;
	}
	if (space_count == i)//If all spaces are there in second string
		return NULL;
	count2 = j>0 ? j + 1 : j;//count of words
	int z = 0;
	for (i = 0; i < count1; i++){
		for (j = 0; j < count2; j++){
			if (a[i] == b[j]){//matching the unique ASCII value
				output[z] = (char*)malloc(SIZE * sizeof(char));
				output[z++] = refrence_1[i];
			}
		}
	}
	if (z == 0)
		return NULL;
	else
		return output;
}


