/*
 * includes.h
 *
 *  Created on: Nov 3, 2011
 *      Author: arun
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#ifndef INCLUDES_H_
#define INCLUDES_H_
typedef  struct AvlNode *AvlTree;
struct AvlNode node;
AvlTree Insert( char*,char*,AvlTree);
AvlTree Find( char*, AvlTree);
int Height( AvlTree );
int Max( int, int );
AvlTree SingleRotateWithLeft( AvlTree );
AvlTree SingleRotateWithRight( AvlTree);
AvlTree DoubleRotateWithLeft( AvlTree );
AvlTree DoubleRotateWithRight( AvlTree);


#endif /* INCLUDES_H_ */
