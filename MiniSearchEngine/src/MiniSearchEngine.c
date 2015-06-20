/*
 ============================================================================
 Name        : MiniSearchEngine.c
 Author      : Arun K Bharathan
 Version     :
 Copyright   :
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include"define.h"

struct AvlNode
{
	char STRING[50];
	char DOCUMENT_NAME[50];
    int HEIGHT;
    struct AvlNode *LEFT;
    struct AvlNode *RIGHT;
};
void main()
{	char *P;
	AvlTree T=NULL,root=NULL,T1=NULL,T2=NULL;
	char string1[50]="\0",string2[50]="\0",string3[50]="\0",string4[50]="\0";char eof1,eof2;
	int cnt,cnt1;
	FILE *freed,*docs;
 	freed=fopen("INPUT.TXT","r");
	while(fscanf(freed,"%s",string1) != EOF)
	{
		docs=fopen(string1,"r");
		while(fscanf(docs,"%s",string3) != EOF)
		{
			T=Insert(string3,string1,T);
		}
		fclose(docs);
	}
	fclose(freed);
		printf("Enter your words to search **USE ONLY AND||OR**\n");
		fgets( string1, 50, stdin );

		string1[strlen(string1)-1]='\0';

	 if(strstr(string1," AND ")!=NULL)
	 {

		 P=strstr(string1," AND ");
		 *(P+1)=' ';*(P+2)=' ';*(P+3)=' ';
		for(cnt=0,cnt1=0;cnt<strlen(string1);cnt++,cnt1++)
		{
			string2[cnt]=string1[cnt1];
			if(string2[cnt]==' ')
			{
				string2[cnt]='\0';
				break;
			}
		}
		for(cnt1=0;cnt<=strlen(string1);cnt++)
			{
				if(isalnum(string1[cnt]))
				{
					string3[cnt1]=string1[cnt];
					cnt1++;
				}
				if(string1[cnt]=='\0')
				{
					string3[cnt1]='\0';
				}
			}
		 root=T;
		 T=Find( string3, root);
		 if(T!=NULL)
		 {strcpy(string3,T->DOCUMENT_NAME);}
		   		 T= Find( string2, root);
		 if(T!=NULL)
		 {strcpy(string2,T->DOCUMENT_NAME);}
			for(cnt=0,cnt1=0;cnt<=strlen(string3);cnt++,cnt1++)
				{
					string4[cnt]=string3[cnt1];
					if(string4[cnt]==' ')
					{
						string4[cnt]='\0';
						cnt=-1;
						P=strstr(string2,string4);
						if(P!=NULL)
						{
							printf("%s ",string4);
						}
					}
				}


	 }
	 if(strstr(string1," OR ")!=NULL)
	 {
		 P=strstr(string1," OR ");
		 *(P+1)=' ';*(P+2)=' ';
		for(cnt=0,cnt1=0;cnt<strlen(string1);cnt++,cnt1++)
			{
				string2[cnt]=string1[cnt1];
				if(string2[cnt]==' ')
				{
					string2[cnt]='\0';
					break;
				}
			}
			for(cnt1=0;cnt<=strlen(string1);cnt++)
				{
					if(isalnum(string1[cnt]))
					{
						string3[cnt1]=string1[cnt];cnt1++;
					}
					if(string1[cnt]=='\0')
					{
						string3[cnt1]='\0';
					}
				}

					 T1=Find( string2, T);
					 if(T1!=NULL)
					 {
						 strcpy(string2,T1->DOCUMENT_NAME);
					 }
					 T2= Find( string3, T);

					 if(T2!=NULL)
					 {
						 strcpy(string3,T2->DOCUMENT_NAME);
					 }
					 if((T1==NULL)&&(T2==NULL))
					 {
						 printf("\nNOT FOUND.");
						 exit(5);
					 }
						for(cnt=0,cnt1=0;cnt<=strlen(string3);cnt++,cnt1++)
							{
								string4[cnt]=string3[cnt1];
								if(string4[cnt]==' ')
								{
									string4[cnt]='\0';
									cnt=-1;
									P=strstr(string2,string4);
									if(P==NULL)
									{
										printf("%s ",string4);
									}
								}
							}
						if(T2==NULL)
						{
							printf(" %s ",string2);
						}

	 }

	 T= Find( string1, T);
	 if(T!=NULL)
	 {

		 printf("\n%s",T->DOCUMENT_NAME);
	 }
	 else
	 {
		 printf("\nNOT FOUND.");
	 }
	 printf("\n%s","***");
}
