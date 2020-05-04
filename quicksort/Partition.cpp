#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
using namespace std;

 inline void insertsort(vector<int>& L,int start,int end)
{

	for (int i = start+1; i <= end ; ++i)
	{
		int tmp = std::move(L[i]);
		int j=0;
	
		for (j = i; j>0 && (L[j - 1] > tmp); --j)
		{
			L[j] = std::move(L[j - 1]);
		}
		L[j] = std::move(tmp);
	}
}

inline void swap(vector<int>& L, int i, int j)
{
	int temp = L[i];
	L[i] = L[j];
	L[j] = temp;
}


/**********************计算枢纽元*********************/
inline const int& Partition(vector<int>& L, int low, int high)
{
	/*取头、尾和中间值中的中值*/
	int m = (high + low) / 2;
	if (L[m] < L[low])
		swap(L, low, m);
	if (L[high] < L[low])
		swap(L, low, high);
	if (L[high] < L[m])
		swap(L, high, m);
	/**************************/
	swap(L, m, high - 1); //将枢纽元置于high-1处
	return L[high - 1]; //返回枢纽元
}

/*************************快速排序************************/
void QuickSort(vector<int>& L, int low, int high)
{
	if (low + 10 <= high) 
	{
		const int pivot = Partition(L, low, high); //计算本次枢纽元
		int i = low, j = high - 1; //取需要划分元素段的头尾游标
		while (1)
		{
			while (L[++i] < pivot) {}	//i指向大于枢纽元的元素
			while (L[--j] > pivot) {}	//j指向小于枢纽元的元素
			if (i < j)
				swap(L, i, j);		//如果i在j左边交换两元素
			else
				break;					//如果i在j右边退出
		}
		swap(L, i, high - 1);			//恢复枢纽元
		QuickSort(L, low, i - 1);		//将小于枢纽元的部分排序
		QuickSort(L, i + 1, high);		//将大于枢纽元的部分排序
	}
	else //若长度小于10则使用插入排序
	{
		insertsort(L,low,high);
	}

}

/***********外部接口**********/
void QuickSort(vector<int>& L)
{
	QuickSort(L, 0, L.size() - 1);
}




