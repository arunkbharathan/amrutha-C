/*
 ============================================================================
 Name        : linklis.c
 Author      : Arun
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
struct test
{
int data;
struct test* point;
};
typedef struct test alien;
void create(void);
struct test* poi;
struct test* ptr;
struct test* thala;
struct test* prev;
struct test* local;
int incre=0;
int find(int);
void flush();
void insert(int,int);

int main(void) {
	int temp,cnt,inter,opt;
		int fresher;
		char ttt;
		system("clear");
		printf("Enter no of structure locations:");
		scanf("%d",&temp);
		thala=(struct test*)malloc(sizeof(alien));

		thala->point=NULL;
		poi=thala;
		for(cnt=0;cnt<temp;cnt++)
		{
			create();

		}
		ptr=thala->point;
		for(cnt=0;cnt<temp;cnt++)
		{
		  printf("enter the element \n");
		  scanf("%d",&fresher);
		  ptr->data=fresher;
		  ptr=ptr->point;

		}
		ptr=thala->point;

		while(ptr)
		{ printf("\n%d",(int)ptr);
			printf("\t%d\n",ptr->data);
			ptr=ptr->point;
		}
		printf("\nPress any Key");
		scanf("\n%c",&ttt);
		system("clear");
		while(1)
		{

			printf("\n******WELCOME TO LINKED LIST******\n");
			printf("ENTER YOUR OPTION\n");
			printf("1.DELETE 2.FIND 3.INSERT 4.DISPLAY LIST 5.EXIT\n");
			scanf("%d",&opt);
			switch(opt)
			{
				case 1:
					printf("\nEnter the element to Delete:\n");
					scanf("%d",&temp);
					ptr=thala;
		 			flush(temp);
		 			break;
		 		case 2:
		 			printf("\nEnter the element to Find:\n");
					scanf("%d",&temp);
					ptr=thala;

					if(find(temp))
					{
		    				printf("\nFound\n");
					}
					else
					{
		 				 printf("\nNot Found\n");
					}
					break;
				case 3:
					printf("\nEnter the Element to Insert:\n");
					scanf("%d",&inter);
					printf("\nEnter before which Element to Insert:\n");
					scanf("%d",&temp);
					ptr=thala;
		 			insert(inter,temp);
		 			break;
		 		case 4:
		 			ptr=thala->point;
					while(ptr)
					{
						printf("\n%d",(int)ptr);
						printf("\t%d\n",ptr->data);
						ptr=ptr->point;
					}
		 			break;
				case 5:
					exit(5);
				default:
					printf("\nENTER THE CORRECT OPTION\n");
					break;
			}

		}
	return EXIT_SUCCESS;
}

void create()
{
	poi->point=(struct test*)malloc(sizeof(alien));
	poi=poi->point;
	poi->point=NULL;

}

int find(int val)
{


	while(ptr->point!=NULL)
	{

		if(val==ptr->point->data)
		{
			return 1;
		}
		ptr=ptr->point;
	}
    return 0;
}

void flush(int temp)
{
  if(find(temp))
  {    //   printf("ptr\t%d",(int)ptr);
	  prev=ptr->point->point;	//ptr=delete cheyyannulla elementinte munnthe elementinte address
	  free(ptr->point);    //delete cheyannulla elementinte location freeaakki
	  ptr->point=prev;  //delete cheythathinu shesham koottiyinnakkunnu

  }
  else
	{
	  printf("\nNot Found");
	}
  }


  void insert(int inter,int temp)
  {
  	if(find(temp))
  	{
  		local=ptr->point;
  		ptr->point=(struct test*)malloc(sizeof(alien));
  		ptr->point->data=inter;
  		ptr->point->point=local;
  	}
  	else
  	{
  		printf("\n number not found");
  	}
  }

