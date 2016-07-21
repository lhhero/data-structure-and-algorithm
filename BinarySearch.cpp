/**
 * BinarySearch 二分法查找
 * return  返回-1，表示目标数不存在
 */
int BinarySearch(int nums[],int len,int target)
{
	int low = 0;
	int high = len-1;
	int mid = 0;
	while(low <= high)
	{
		//mid = (low+high)/2;
		mid = low+((high-low)>>1);
		if(nums[mid] == target)
			return mid;
		else if(nums[mid] > target)
			high = mid-1;
		else
			low = mid+1;
	}
	return -1;
}

/**
 * searchInRotatedArray 旋转数组查找，{7,8,9,3,4,5,6}
 * 二分查找变形
 */
int searchInRotatedArray(int nums[], int n, int target) 
{
	int low = 0, high = n-1;
	while(low <= high)
	{
		int mid = low+((high-low)>>1);
		if(nums[mid] == target) 
			return mid;
		if(nums[mid] >= nums[low]) 
		{
			// low ~ mid 是升序的
			if(target >= nums[low] && target < nums[mid])
				high = mid-1;
			else
				low = mid+1;
		}
		else
		{
			// mid ~ high 是升序的
			if(target > nums[mid] && target <= nums[high])
				low = mid+1;
			else
				high = mid-1;
		}
	}
	return -1;
}

/**
 * sqrt()的实现，利用二分的思想
 */

double sqrt3(double x)
{
	double down,up,mid,last;
	down = 0.0;
	up = x;
	mid = (down+up)/2;
	if(x < 0)
		return x;
	while((mid*mid != x) && abs(last-mid) > esp) //esp控制精度
	{
		if(mid*mid < x)
		{
			down = mid;
			last = mid;
			mid = (down+up)/2;
		}
		else
		{
			up = mid;
			last = mid;
			mid = (down+up)/2;
		}
	}
	return mid;
}

/**
 * 牛顿迭代法实现sqrt()
 */
double sqrt(double num)
{
	double val = num;//最终
	double last;//保存上一个计算的值
	do
	{
		last = val;
		val =(val + num/val) / 2;
	}while(abs(val-last) > eps);

	return val;
}

/**
 * pow 
 * @param  base     底数，
 * @param  exponent 指数，没有考虑指数为负数的情况
 * 
 */
double pow(double base,int exponent)
{
	if(exponent < 0)
	{
		base = 1.0/base;
		exponent = -exponent;
	}
	double result = 0.0
	if(exponent == 0)
		result = 1.0;
	if(exponent == 1)
		result = base;
	result = pow(base,exponent>>1);
	result *= result;
	if(exponent & 0x1 == 1)
		result *= base;
	return result;
}
double Power(double base, int exponent) 
{
    	if(exponent < 0)
    	{
            base = 1.0/base;
            exponent = -exponent;
        }
        
        if(exponent == 0)
            return 1;
        if(exponent == 1)
            return base;
        
        double res = base;
        while(exponent > 1)
        {
            res *= res;
            exponent /= 2;
        }
        if(exponent & 0x1 == 1)
            res *= base;
        return res;
    }
