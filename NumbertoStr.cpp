/*
OVERVIEW: Given a float number ,Convert it into a string

INPUTS: A Float,Final string ,How many digits after decimal has to be displayed .
Its zero for integers.


OUTPUT: No need to output anything ,Modify the str in function parameter such that it
now holds the string format of the float number specified

Example : number_to_str(345,str,0);
Should copy "345\0" in the str;
number_to_str(345.342,str,2);
Should copy "345.34" in the str;

NOTES: Don't create new string.

*/

#include <stdio.h>



void number_to_str(float number, char *str, int afterdecimal)
{
	int integral, temp_num, k = 0, l = 0, pos = 0;
	char temp;
	float precision;


	integral = (int)number;//integer value
	precision = number - integral;//precision value
	if (number < 0)//if the number is neagtive
	{
		str[pos] = '-';
		pos++;
		integral = integral - (2 * integral);
	}
	while (integral > 0)//extracting each digit an converting into a string
	{
		temp_num = integral % 10;
		str[pos] = '0' + temp_num;
		integral = integral / 10;
		pos++;
	}
	//for negative numbers we have a negative sign which also must be included
	if (str[0] == '-')
	{
		k = 1;
		l = pos - 1;
	}
	else//if no negative sign
	{
		k = 0;
		l = pos - 1;
	}
	while (k < l)//we make the reversed number into the original string number
	{
		temp = str[k];
		str[k] = str[l];
		str[l] = temp;
		k++;
		l--;
	}
	if (str[0] == '-')//if we have a negative sign in the beginnning
		precision = -precision;
	if (precision>0)//for the numbers after the decimal point
	{
		str[pos++] = '.';
		while (afterdecimal>0)
		{
			precision = precision * 10;
			integral = (int)precision;
			temp_num = integral % 10;
			str[pos] = '0' + temp_num;
			pos++;
			afterdecimal--;
		}
	}
}


