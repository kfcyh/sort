/************************************************************************************
*						    				    *
* Function: struct of Sqlist and function of swap for kinds of algorithm for sort   *
* Written by Mr.YeHeng				   				    *
* 2020/4/28  Huaqiao University		            			            *
*						    				    *
************************************************************************************/

#pragma once
#include <stdlib.h>
#include <iostream>
using namespace std;
#define MAXSIZE 10

typedef struct list {
	int r[MAXSIZE + 1];
	int length;
	list():length(0){}
}*SqList;

inline void swap(SqList L, int i, int j)
{
	int temp = L->r[i];
	L->r[i] = L->r[j];
	L->r[j] = temp;
}

