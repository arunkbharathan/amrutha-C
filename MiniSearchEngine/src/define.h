/*
 * define.h
 *
 *  Created on: Oct 26, 2011
 *      Author: icts
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#ifndef DEFINE_H_
#define DEFINE_H_
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
#endif /* DEFINE_H_ */
