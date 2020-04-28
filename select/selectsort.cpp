/*************************************************
*												 *
* Function:SelectSort							 *
* Written by Mr.YeHeng							 *
* 2020/4/28  Huaqiao University					 *
*												 *
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
/*************************测试代码************************/
int main()
{
	SqList L = (SqList)new list;
	int arc[] = { 9,1,5,8,3,7,4,6,2 };
	for (int i = 0; i < 9; i++)
	{
		L->r[i + 1] = arc[i];
		L->length++;
	}
	//L->length = 9;
	SelectSort(L);
	for (int i = 0; i < 9; i++)
	{
		cout << L->r[i + 1] << " ";
	}
	getchar();
}
