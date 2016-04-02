/*
Given 4 strings, write a fucntion to get smallest string that consists all four strings. 
In Case of Multiple strings with smallest length,
Return the string which occurs alphabetically first .

Ex : (acat, tiger, silica, licaria) O/P: "silicariacatiger"
Ex : (def,abc,ghi,jkl)   O/P : “abcdefghijkl” (Alphabetically first )
Ex : (apple,pp,pineapple,nea) O/P: "pineapple";
Ex : (zzzabc,abcdef,yyyzzz,cabyyy) O/P: "cabyyyzzzabcdef" (Order Swapped )

Note : Each string given as input ,should be in the same format in the output string. 
Ie if input string is abcd ,it cannot be modified as bdca in the final string .

The Order of Strings in the Final string ,maynot be in the same order 
given in which they are given
Function Signatue : char * smallestword(char *s1,char *s2,char *s3,char *s4);

Note : You can use String.h functions .

Constraints : 
Length of each String will be less than 100 .

Difficulty : Hard
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
int strlen(char *s)
{
	int i = 0;
	while (s != NULL)
		i++;
	return i;
}
char * sort(char *s)
{
	int i, j;
	for (i = 0; i < strlen(s); i++)
	{
		for (j = i + 1; j < strlen(s); j++)
		{
			if (s[i] > s[j])
			{
				int temp = s[i];
				s[i] = s[j];
				s[j] = temp;
			}
		}
	}
}

char * concat_4strings(char *s1, char *s2, char *s3, char *s4){
	if (s1 == NULL || s2 == NULL || s3 == NULL || s4== NULL)
		return NULL;
	int i,k=0;
	char *res = NULL;
	sort(s1);
	sort(s2);
	sort(s3);
	sort(s4);
	int len = strlen(s1) + strlen(s2) + strlen(s3) + strlen(s4);
	for (i = 0; i < len; i++)
	{
		if (s1[i] < s2[i] && s1[i] < s3[i] && s1[i] < s4[i])
		{
			res[k++] = s1[i];

		}
		else if (s2[i] < s1[i] && s2[i] < s3[i] && s2[i] < s4[i])
		{
			res[k++] = s2[i];

		}
		else if (s3[i] < s1[i] && s3[i] < s2[i] && s3[i] < s4[i])
		{
			res[k++] = s3[i];

		}
		else if (s4[i] < s1[i] && s4[i] < s2[i] && s4[i] < s3[i])
		{
			res[k++] = s4[i];

		}
		else
			res[k++] = s1[i];
	}
	return NULL;
}