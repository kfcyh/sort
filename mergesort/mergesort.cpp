void Merge(vector<int>& numbers, int start, int mid, int end) 
{
	int* temp = new int[end - start + 1];	//第一步，申请空间，大小为两个排序序列之和
	int fistSectionIndex = start;			//第二步，设定两个待排序列的起始位置的索引
	int secondSectionIndex = mid + 1;
	int tempIndex = 0;	//所申请空间的索引

	while (fistSectionIndex <= mid && secondSectionIndex <= end) //直到两个序列中有一个到达终止位置
	{	
		if (numbers[fistSectionIndex] <= numbers[secondSectionIndex])
			temp[tempIndex++] = numbers[fistSectionIndex++];
		else
			temp[tempIndex++] = numbers[secondSectionIndex++];
	}

	while (fistSectionIndex <= mid)
		temp[tempIndex++] = numbers[fistSectionIndex++];

	while (secondSectionIndex <= end)
		temp[tempIndex++] = numbers[secondSectionIndex++];

	for (int j = 0; j < tempIndex; ++j)		//将合并且排序好的元素，复制到原来的数组中，释放临时数组空间
		numbers[start + j] = temp[j];

	delete[] temp;
}


void MergeSort(vector<int>& numbers, int start, int end) 
{
	if (numbers.empty() || start >= end)
		return;

	int mid = (start + end) / 2;

	MergeSort(numbers, start, mid);		//递归排序numbers[start,mid](首先从上往下递归分解到最底层元素个数为1的情况)
	MergeSort(numbers, mid + 1, end);	//递归排序numbers[mid + 1,end](首先从上往下递归分解到最底层元素个数为1的情况)

	Merge(numbers, start, mid, end);	//然后递归的从下往上合并排序
}

/*二路归并排序（迭代实现）*/
void MergeSort1(vector<int>& nums, int start, int end)
{
	int n = nums.size();
	if (start < end) 
	{
		//step为组内元素个数，step/2为左子区间元素个数
		for (int step = 2; step / 2 <n; step *= 2) 
		{
			//每step个元素一组，组内前step/2和后step/2个元素进行合并
			for (int i = 0; i < n; i += step) 
			{
				int mid = i + step / 2 - 1;				//左子区间元素个数为step/2
				if (mid + 1<n)							//右子区间存在元素个数则合并
														//左子区间为[i,mid]，右子区间为[mid+1, min(i+step-1, n-1)]
					Merge(nums, i, mid, min(i + step - 1, n - 1));
			}
		}
	}
}

void MergeSort(vector<int>& numbers)
{
	MergeSort(numbers, 0, numbers.size() - 1);
  //MergeSort1(numbers, 0, numbers.size() - 1);
}
