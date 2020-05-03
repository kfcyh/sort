/*************************************************
*						 *
* Function:SelectSort			         *
* Written by Mr.YeHeng				 *
* 2020/4/28  Huaqiao University			 *
*						 *
*************************************************/

#include "sort.h"
/**********************简单选择排序*********************/
void SelectSort(SqList L)
{
	int j, min;
	for (int i = 1; i < L->length; i++)
	{
		min = i;
		for (j = i + 1; j <= L->length; j++)
		{
			if (L->r[min] > L->r[j])
				min = j;
		}
		if (i != min)
			swap(L, i, min);
	}
}

