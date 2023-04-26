#include <stdio.h>
#include <assert.h>

//�ο���ַ https://zhuanlan.zhihu.com/p/70873246

/*
�������ã�ģ��ʵ��memcpy����,�Ӵ洢��src����n���ַ����洢��dst��
*/
void *my_memcpy(void *dest, const void *src, size_t num)
{
	void *ret = dest;
	size_t i = 0;
	assert(dest!=NULL);
	assert(src != NULL);

	for (int i = 0; i < num; i++)
	{
		//��Ϊvoid*����ֱ�ӽ����ã�������Ҫǿת��char*�ٽ�����
		//�˴���void* ʵ���˷��ͱ��
		*(char *)dest = *(char *)src;
		dest = (char *)dest + 1;
		src = (char *)src + 1;
	}
	return ret;
}

/*
�������ã��൱�ڿ����ڴ��ص��� memcpy ������
�Ӵ洢�� src ���� n ���ַ����洢�� dst��
�ж�Դ��ַ��Ŀ�ĵ�ַ�Ĵ�С��
�ž��������ǴӸߵ�ַ��ʼ�������ǵ͵�ַ��ʼ������
*/
void *my_memmove(void *dest, const void *src, size_t n) {
	assert(dest != NULL);
	assert(src != NULL);
	char *s_dest;
	char *s_src;
	s_dest = (char *)dest;
	s_src = (char *)src;
	if ((s_src < s_dest) && (s_src + n > s_dest)) {
		//��Դ��ַ��Ŀ�ĵ�ַС��������n��Ŀ�ĵ�ַ��ʱ
		//�Ӹߵ�ַ��͵�ַ����
		s_dest = s_dest + n - 1;
		s_src = s_src + n - 1;
		while (n--) {
			*s_dest-- = *s_src--;
		}
	}
	else
	{
		//����ַ������ʱ������һ��memcpy���Ʒ���
		while (n--) {
			*s_dest++ = *s_src++;
		}
		return dest;
	}
}