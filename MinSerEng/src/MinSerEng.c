/*
 ============================================================================
 Name        : MiniSearchEngine.c
 Author      : Arun K Bharathan
 Version     :
 Copyright   :
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include"includes.h"

struct AvlNode
{
	char WORD[50];
	char DOCUMENT_NAME[50];
    int HEIGHT;
    struct AvlNode *LEFT;
    struct AvlNode *RIGHT;
};
void main()
{	char *P;
	AvlTree T=NULL,root=NULL,T1=NULL,T2=NULL;
	char TmpSTR1[50]="\0",TmpSTR2[50]="\0",TmpSTR3[50]="\0",TmpSTR4[50]="\0";
	int cnt,cnt1;
	FILE *freed,*docs;
 	freed=fopen("INPUT.TXT","r");
	while(fscanf(freed,"%s",TmpSTR1) != EOF)
	{
		docs=fopen(TmpSTR1,"r");
		while(fscanf(docs,"%s",TmpSTR3) != EOF)
		{
			T=Insert(TmpSTR3,TmpSTR1,T);
		}
		fclose(docs);
	}
	fclose(freed);
		printf("Enter your words to search **USE ONLY AND||OR**\n");
		fgets( TmpSTR1, 50, stdin );

		TmpSTR1[strlen(TmpSTR1)-1]='\0';

	 if(strstr(TmpSTR1," AND ")!=NULL)
	 {

		 P=strstr(TmpSTR1," AND ");
		 *(P+1)=' ';*(P+2)=' ';*(P+3)=' ';
		for(cnt=0,cnt1=0;cnt<strlen(TmpSTR1);cnt++,cnt1++)
		{
			TmpSTR2[cnt]=TmpSTR1[cnt1];
			if(TmpSTR2[cnt]==' ')
			{
				TmpSTR2[cnt]='\0';
				break;
			}
		}
		for(cnt1=0;cnt<=strlen(TmpSTR1);cnt++)
			{
				if(isalnum(TmpSTR1[cnt]))
				{
					TmpSTR3[cnt1]=TmpSTR1[cnt];
					cnt1++;
				}
				if(TmpSTR1[cnt]=='\0')
				{
					TmpSTR3[cnt1]='\0';
				}
			}
		 root=T;
		 T=Find( TmpSTR3, root);
		 if(T!=NULL)
		 {strcpy(TmpSTR3,T->DOCUMENT_NAME);}
		   		 T= Find( TmpSTR2, root);
		 if(T!=NULL)
		 {strcpy(TmpSTR2,T->DOCUMENT_NAME);}
			for(cnt=0,cnt1=0;cnt<=strlen(TmpSTR3);cnt++,cnt1++)
				{
					TmpSTR4[cnt]=TmpSTR3[cnt1];
					if(TmpSTR4[cnt]==' ')
					{
						TmpSTR4[cnt]='\0';
						cnt=-1;
						P=strstr(TmpSTR2,TmpSTR4);
						if(P!=NULL)
						{
							printf("%s ",TmpSTR4);
						}
					}
				}


	 }
	 if(strstr(TmpSTR1," OR ")!=NULL)
	 {
		 P=strstr(TmpSTR1," OR ");
		 *(P+1)=' ';*(P+2)=' ';
		for(cnt=0,cnt1=0;cnt<strlen(TmpSTR1);cnt++,cnt1++)
			{
				TmpSTR2[cnt]=TmpSTR1[cnt1];
				if(TmpSTR2[cnt]==' ')
				{
					TmpSTR2[cnt]='\0';
					break;
				}
			}
			for(cnt1=0;cnt<=strlen(TmpSTR1);cnt++)
				{
					if(isalnum(TmpSTR1[cnt]))
					{
						TmpSTR3[cnt1]=TmpSTR1[cnt];cnt1++;
					}
					if(TmpSTR1[cnt]=='\0')
					{
						TmpSTR3[cnt1]='\0';
					}
				}

					 T1=Find( TmpSTR2, T);
					 if(T1!=NULL)
					 {
						 strcpy(TmpSTR2,T1->DOCUMENT_NAME);
					 }
					 T2= Find( TmpSTR3, T);

					 if(T2!=NULL)
					 {
						 strcpy(TmpSTR3,T2->DOCUMENT_NAME);
					 }
					 if((T1==NULL)&&(T2==NULL))
					 {
						 printf("\nNOT FOUND.");
						 exit(5);
					 }
						for(cnt=0,cnt1=0;cnt<=strlen(TmpSTR3);cnt++,cnt1++)
							{
								TmpSTR4[cnt]=TmpSTR3[cnt1];
								if(TmpSTR4[cnt]==' ')
								{
									TmpSTR4[cnt]='\0';
									cnt=-1;
									P=strstr(TmpSTR2,TmpSTR4);
									if(P==NULL)
									{
										printf("%s ",TmpSTR4);
									}
								}
							}
						if(T2==NULL)
						{
							printf(" %s ",TmpSTR2);
						}

	 }

	 T= Find( TmpSTR1, T);
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
