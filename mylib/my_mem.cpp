#include <stdio.h>
#include <assert.h>

//参考网址 https://zhuanlan.zhihu.com/p/70873246

/*
函数作用：模拟实现memcpy函数,从存储区src复制n个字符到存储区dst。
*/
void *my_memcpy(void *dest, const void *src, size_t num)
{
	void *ret = dest;
	size_t i = 0;
	assert(dest!=NULL);
	assert(src != NULL);

	for (int i = 0; i < num; i++)
	{
		//因为void*不能直接解引用，所以需要强转成char*再解引用
		//此处的void* 实现了泛型编程
		*(char *)dest = *(char *)src;
		dest = (char *)dest + 1;
		src = (char *)src + 1;
	}
	return ret;
}

/*
函数作用：相当于考虑内存重叠的 memcpy 函数，
从存储区 src 复制 n 个字符到存储区 dst。
判断源地址和目的地址的大小，
才决定到底是从高地址开始拷贝还是低地址开始拷贝。
*/
void *my_memmove(void *dest, const void *src, size_t n) {
	assert(dest != NULL);
	assert(src != NULL);
	char *s_dest;
	char *s_src;
	s_dest = (char *)dest;
	s_src = (char *)src;
	if ((s_src < s_dest) && (s_src + n > s_dest)) {
		//当源地址比目的地址小，但加上n比目的地址大时
		//从高地址向低地址复制
		s_dest = s_dest + n - 1;
		s_src = s_src + n - 1;
		while (n--) {
			*s_dest-- = *s_src--;
		}
	}
	else
	{
		//当地址不覆盖时，采用一般memcpy复制方法
		while (n--) {
			*s_dest++ = *s_src++;
		}
		return dest;
	}
}