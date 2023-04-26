
//二分查找
int my_binarySearch(int* nums, int numsSize, int target) 
{
	if (numsSize == 0) return -1;
	int mid, left = 0, right = numsSize - 1, res = -1;
	while (left <= right)
	{
		mid = left + (right - left) / 2; //防止溢出
		if (nums[mid]>target)
		{
			//当中间的数大于目标值，去找左边的
			right = mid - 1;
		}
		else if (nums[mid]<target)
		{
			//当中间的数小于目标值，去找右边的
			left = mid + 1;
		}
		else
		{
			res = mid;
			break;
		}
	}
	return res;
}