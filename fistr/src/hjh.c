#include<stdio.h>

int mystrlen(char *tempstring);
void StringCat(char *dest, char *src);
void main()
{
	char mystring1[50],mystring2[50];
	int len;

	printf("\nEnter a string1:");
	gets(mystring1);
	printf("\nEnter a string2:");
	gets(mystring2);
	StringCat(mystring1,mystring2);
	printf("\nResult String:");
	puts(mystring1);
}

int mystrlen(char *tempstring)
{
	int i=0,len=0;
	while(tempstring[i] !='\0')
	{
		len++;
		i++;
	}
	return	len;
}


void StringCat(char *dest, char *src)
{
	int i=0,len;
	len=mystrlen(dest);
	//dest[len]=' ';
	//len++;
	while(src[i] !='\0')
	{
		dest[len]=src[i];
		i++;
		len++;
	}
	dest[len]='\0';
}

