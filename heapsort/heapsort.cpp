#include "sort.h"

void percDown(SqList L, int index, int size)
{
	if (index >= size)
		return;
	L->r[0] = L->r[index];
	for (int i = index * 2; i <= size; i *= 2)
	{
		if (i + 1 <= size)
			if (L->r[i + 1] > L->r[i])
				i++;
		if (L->r[0] >= L->r[i])
			break;
		L->r[index] = L->r[i];
		index = i;
	}
	L->r[index] = L->r[0];
}

void heapSort(SqList L)
{
	if (!L)
		return;
	for (int i = L->length / 2; i > 0; i--)
		percDown(L, i, L->length);

	for (int j = L->length; j > 1; j--)
	{
		swap(L, j, 1);
		percDown(L, 1, j - 1);
	}
}
