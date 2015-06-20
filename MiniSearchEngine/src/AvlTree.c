/*
 * AvlTree.c
 *
 *  Created on: Oct 26, 2011
 *      Author: icts
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


AvlTree Insert( char *word,char *doc,AvlTree T)
	{
		char *P;
		if(T==NULL)
		{
			T=(struct AvlNode*)malloc(sizeof(struct AvlNode));
			if( T == NULL )
			      {
					printf( "\nOut of space!!!" );
			      }
			strcpy(T->STRING,word);
			P=strchr (T->DOCUMENT_NAME, 0);
			strcpy(P,doc);
			strcat(P," \0");
			T->HEIGHT=0;T->LEFT=T->RIGHT=NULL;
		}
	    else

		{
	    	if(strcmp(word,T->STRING)>0)

			 {
			   T->RIGHT = Insert( word,doc, T->RIGHT );
			   if( Height( T->RIGHT ) - Height( T->LEFT ) == 2 )
			   {
				   if( strcmp(word,T->RIGHT->STRING)>0 )
			            {
				   	   	   T = SingleRotateWithRight( T );
			            }
			       else
			         {
			    	   	   T = DoubleRotateWithRight( T );
			         }
			   }
			 }
		if(strcmp(word,T->STRING)<0)
		{
			T->LEFT = Insert( word, doc,T->LEFT );
			                if( Height( T->LEFT ) - Height( T->RIGHT ) == 2 )
			                {
			                	if(strcmp(word,T->LEFT->STRING)<0  )
			                       {
			                			T = SingleRotateWithLeft( T );
			                       }
			                    else
			                        {
			                    		T = DoubleRotateWithLeft( T );
			                        }
		                     }
		}
		if(strcmp(word,T->STRING)==0)
		{
			if(strstr(T->DOCUMENT_NAME,doc)==NULL)
			{
				P=strchr (T->DOCUMENT_NAME, 0);
				strcpy(P,doc);
				strcat(P," \0");
			}
		}
		}
		  T->HEIGHT = Max( Height( T->LEFT ), Height( T->RIGHT ) ) + 1;

		  return T;
	}

int Height( AvlTree P )
      {
          if( P == NULL )
              return -1;
          else
              return P->HEIGHT;
      }

int Max( int Lhs, int Rhs )
       {
           return Lhs > Rhs ? Lhs : Rhs;
       }

AvlTree SingleRotateWithLeft( AvlTree K2 )
        {
            AvlTree K1;

            K1 = K2->LEFT;
            K2->LEFT = K1->RIGHT;
            K1->RIGHT = K2;

            K2->HEIGHT = Max( Height( K2->LEFT ), Height( K2->RIGHT ) ) + 1;
            K1->HEIGHT = Max( Height( K1->LEFT ), K2->HEIGHT ) + 1;

            return K1;  /* New root */
        }

AvlTree SingleRotateWithRight( AvlTree K1 )
        {
            AvlTree K2;

            K2 = K1->RIGHT;
            K1->RIGHT = K2->LEFT;
            K2->LEFT = K1;

            K1->HEIGHT = Max( Height( K1->LEFT ), Height( K1->RIGHT ) ) + 1;
            K2->HEIGHT = Max( Height( K2->RIGHT ), K1->HEIGHT ) + 1;

            return K2;  /* New root */
        }

AvlTree DoubleRotateWithLeft( AvlTree K3 )
    {
        /* Rotate between K1 and K2 */
        K3->LEFT = SingleRotateWithRight( K3->LEFT );

        /* Rotate between K3 and K2 */
        return SingleRotateWithLeft( K3 );
    }

AvlTree DoubleRotateWithRight( AvlTree K1 )
      {
          /* Rotate between K3 and K2 */
          K1->RIGHT = SingleRotateWithLeft( K1->RIGHT );

          /* Rotate between K1 and K2 */
          return SingleRotateWithRight( K1 );
      }

AvlTree Find(  char* word,AvlTree T )
        {
            if( T == NULL )
                return NULL;
            if( strcmp(word,T->STRING)<0 )
            {
                return Find( word, T->LEFT );
            }
            else
            {
            	if( strcmp(word,T->STRING)>0 )
            	{
            		return Find( word, T->RIGHT );
            	}
            	else
            	{
            		return T;
            	}
            }
        }
