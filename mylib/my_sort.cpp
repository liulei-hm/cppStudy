#include "all.h"

//912. �������� - ���ۣ�Leetcode��
//https://leetcode.cn/problems/sort-an-array/

/****************************�����㷨**************************/
int my_compare(const void*a, const void*b)
{
	return *(int*)a - *(int*)b;
}

void my_qsort(void *base, size_t nitems, size_t size)
{
	qsort(base,nitems, size, my_compare);
}

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
/****************************��������**************************/
void my_quicksort(int *a, int low, int high)
{
	int pivot, i = low, j = high;
	if (low<high)
	{
		pivot = a[low];
		while (i<j)
		{
			while (i < j&&a[j] >= pivot) 
			{ --j; }
			if (i<j) { a[i] = a[j]; i++; }
			while (i < j&&a[i] < pivot) 
			{ ++i; }
			if (i<j) { a[j] = a[i]; --j; }
		}
		a[i] = pivot;
		my_quicksort(a, low, i - 1);
		my_quicksort(a, i + 1, high);
	}
}


/****************************ð������**************************/
void my_boblesort(int *a,int len)
{
	int flag = 0;
	for (int i = len - 1; i >= 1; --i) 
	{
		flag = 0;
		for (int j = 1; j <= i; j++) 
		{
			if (a[j - 1]>a[j])
			{
				int temp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = temp;
				flag = 1;
			}
		}
		if (flag == 0)
		{
			return;
		}			
	}
}


/****************************ѡ������**************************/
void my_selectionsort(int arr[], int len)
{
	int i, j;
	for (i = 0; i < len - 1; i++)
	{
		int min = i;
		for (j = i + 1; j < len; j++)     //���Lδ�����Ԫ��
		{
			if (arr[j] < arr[min])    //�ҵ�Ŀǰ��Сֵ
			{
				min = j;    //�o���Сֵ
			}
			swap(&arr[min], &arr[i]);    //�����Q
		}
	}
}

/****************************�鲢����**************************/
//https://blog.csdn.net/weixin_45031801/article/details/127034720
void merge(int* a, int low, int mid, int hight)  //�ϲ�����
{
    int* b = new int[hight - low + 1];  //�� new ����һ����������
    int i = low, j = mid + 1, k = 0;    // kΪ b �����С��
    while (i <= mid && j <= hight)
    {
        if (a[i] <= a[j])
        {
            b[k++] = a[i++];  //����С�������� b ��������
        }
        else
        {
            b[k++] = a[j++];
        }
    }
    while (i <= mid)  // j ���н�������ʣ��� i ���в����� b ������
    {
        b[k++] = a[i++];
    }
    while (j <= hight)// i ���н�������ʣ��� j ���в����� b ������
    {
        b[k++] = a[j++];
    }
    k = 0;  //��С��Ϊ 0 ��ʼ����
    for (int i = low; i <= hight; i++)  //�� b �����ֵ���ݸ����� a
    {
        a[i] = b[k++];
    }
    delete[]b;     // ������������󣬽���Ŀռ�����ͷţ����٣�
}
void mergesort(int* a, int low, int hight) //�鲢����
{
    if (low < hight)
    {
        int mid = (low + hight) / 2;
        mergesort(a, low, mid);          //�� a[low,mid]��������
        mergesort(a, mid + 1, hight);    //�� a[mid+1,hight]��������
        merge(a, low, mid, hight);       //���кϲ�����
    }
}

/****************************���Ժ���**************************/
void test_sort()
{
    int a[10] = { 876,675,896,101,301,401,980,431,451,777 };
    my_boblesort(a, 10);
    for (int i = 0; i < 10; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}
TEST(SortTest, LessSortTest) {
    int arr[5] = {1,8,7,4,5};
    int dest[5] = {1, 4, 5,7,8};
    my_quicksort(arr, 0, sizeof(arr)/sizeof(int)-1);
    EXPECT_EQ(memcmp(dest, arr, sizeof(arr)), 0);
}
TEST(quickSortTest, LessSortTest) {
    int arr[5] = {1,8,7,4,5};
    int dest[5] = {1, 4, 5,7,8};
    mergesort(arr, 0, sizeof(arr)/sizeof(int)-1);
    EXPECT_EQ(memcmp(dest, arr, sizeof(arr)), 0);
}
int main()
{
//    int n, a[100];
//    cout << "�����������е�Ԫ�ظ��� n Ϊ��" << endl;
//    cin >> n;
//    cout << "���������������е�Ԫ�أ�" << endl;
//    for (int i = 0; i < n; i++)
//    {
//        cin >> a[i];
//    }
    int arr[] = { 2,1,3,5,6,8,7,4,10,5,3,21,1,2,2,2,8 };
    //my_quicksort(arr,0,sizeof(arr)/sizeof(int));
    mergesort(arr, 0, sizeof(arr)/sizeof(int)-1);
    cout << "mergesort:" << endl;
    for (int i = 0; i < sizeof(arr)/sizeof(int); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}