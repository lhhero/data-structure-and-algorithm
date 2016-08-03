/**
 * 冒泡排序
 * 时间复杂度：最坏（O(n^2)）,平均（O(n^2)）,最好（O(n)）
 * 稳定
*/
void bubble(int* array,int len)
{
	bool flag = true;
	for(int i = 0; i < len-1 && flag; ++i)
	{
		flag = false;
		for(int j = len-1; j > i; j--)
		{
			if(array[j] < array[j-1])
			{
				swap(array[j],array[j-1]);
				flag = true;
			}
		}
	}
}

/**简单选择排序
 *  * 时间复杂度：最坏（O(n^2)）,平均（O(n^2)）,最好（O(n^2)）
 * 元素间的比较次数与序列初始状态无关，始终是n(n-1)/2次
 * 不稳定
*/
void selectSort(int* array,int len)
{
	for(int i = 0; i < len-1; i++)
	{
		int min = i;
		for(int j = i+1; j < len; j++)
		{
			if(array[min] > array[j])
				min = j;
		}
		if(min != i)
			swap(array[min],array[i]);
	}
}

/**
 * 直接插入排序
 * 时间复杂度：最坏（O(n^2)）,平均（O(n^2)）,最好（O(n)）[有序]
 * 初始序列基本有序的情况下，最优的是插入排序
 * 稳定
*/
void insertSort(int* array,int len)
{
	int i,j;
	for(i = 1; i < len; ++i)
	{
		if(array[i] < array[i-1])
		{
			int tmp = array[i];
			for(j = i-1; (j >= 0) && (array[j] > tmp); j--)
				array[j+1] = array[j];
			array[j+1] = tmp;
		}
	}
}
/**希尔排序
 *不稳定
*/
void shell_sort(int array[] , int length)  
{  
    int i , j , temp;  
    int d = length/2;       // 设置希尔排序的初始增量 
    while(d >= 1)  
    {  
        for(i = d ; i < length ; ++i)  
        {  
            temp = array[i];  
            j = i - d;       // 步长为d的前面一个位置  
            while(j >= 0 && array[j] > temp)        // 从后往前进行插入排序  
            {  
                array[j + d] = array[j];  
                j -= d;  
            }  
            array[j + d] = temp;     // 找到了插入位置  
        }  
        d /= 2;  
    }  
}  


int partition(int *arr , int low , int high)
{
  int pivot = arr[low];
  while(low < high)
  {
    while(low < high && arr[high] >= pivot)
      --high;
    arr[low] = arr[high];
    while(low < high && arr[low] <= pivot)
      ++low;
    arr[high] = arr[low];
  }
  arr[low] = pivo;
  return low;
}

/**快速排序 递归
 * 时间复杂度：最坏（O(n^2)[基本有序]）,平均（O(nlogn)）,最好（O(nlogn))
 * 不稳定
 */
 
void qsort(int *arr , int low , int high)
{
  if(low < high)
  {
    int pivot = partition(arr , low , high);
    qsort(arr , low , pivot-1);
    qsort(arr , pivot+1 , high);
  }
}

void Merge(int array[] , int low , int mid , int high)
{
	int i , j , k;
	int *temp = (int *)malloc((high - low + 1)*sizeof(int));
	i = low , j = mid + 1 , k = 0;
	while(i <= mid && j <= high)
	{
		if(array[i] < array[j])        // 进行排序存入动态分配的数组中
			temp[k++] = array[i++];
		else
			temp[k++] = array[j++];
	}
	while(i <= mid)                    // 如果前一半中还有未处理完的数据，按顺序移入动态分配的数组内
		temp[k++] = array[i++];
	while(j <= high)                   // 如果前一半中还有未处理完的数据，按顺序移入动态分配的数组内
		temp[k++] = array[j++];
	for(i = low , j = 0; i<= high ; ++i)
		array[i] = temp[j++];
	free(temp);
}
/**归并排序
*时间复杂度：最坏（O(nlogn)）,平均（O(nlogn)）,最好（O(nlogn))
*稳定
*/
void Msort(int array[] , int low , int high)
{
	int mid;
	if(low < high)
	{
		mid = (low + high)>>1;
		Msort(array , low , mid);
		Msort(array , mid + 1 , high);
		Merge(array , low , mid , high);
	}
}

/**堆排序
 * 时间复杂度：最坏（O(nlogn)）,平均（O(nlogn)）,最好（O(nlogn))，对初始序列的排序顺序不敏感
 * 不稳定
 */
void HeapAdjust(int array[] , int s , int m)   // 对堆进行调整，使下标从s到m的无序序列成为一个大顶堆  
{
	int j , temp = array[s];
	for(j = 2*s; j <= m ; j *= 2)
	{
		if(j < m && array[j] < array[j + 1])   // 如果结点的左孩子小于右孩子增加j的值
			++j;              // 用于记录较大的结点的下标
		if(temp >= array[j])  // 如果父结点大于等于两个孩子,则满足大顶堆的定义，跳出循环
			break;
		array[s] = array[j];    // 否则用较大的结点替换父结点
		s = j;          // 记录下替换父结点的结点下标  
	}
	array[s] = temp;        // 把原来的父结点移动到替换父结点的结点位置  
}

void HeapSort(int array[] , int len)
{
	int i;
	for(i = len / 2; i >= 0 ; --i)    // 建立大顶堆
		HeapAdjust(array , i , len-1);
	for(i = len - 1 ; i > 0 ; --i)
	{
		swap(array[0] , array[i] );       // 第个元素和最后一个元素进行交换  
		HeapAdjust(array , 0 , i-1);      // 建立大顶堆  
	}
}
