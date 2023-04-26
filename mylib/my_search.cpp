
//���ֲ���
int my_binarySearch(int* nums, int numsSize, int target) 
{
	if (numsSize == 0) return -1;
	int mid, left = 0, right = numsSize - 1, res = -1;
	while (left <= right)
	{
		mid = left + (right - left) / 2; //��ֹ���
		if (nums[mid]>target)
		{
			//���м��������Ŀ��ֵ��ȥ����ߵ�
			right = mid - 1;
		}
		else if (nums[mid]<target)
		{
			//���м����С��Ŀ��ֵ��ȥ���ұߵ�
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