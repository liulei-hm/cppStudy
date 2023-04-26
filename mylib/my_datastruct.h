#pragma once

#include <cstddef>

typedef struct linkStack {
	int data;
	struct linkStack *next;
}linkStack;

char *my_strcat(char *dest, const char* src);
char *my_strcpy(char *dest, const char* src);
int  my_strcmp(const char *str1, const char* str2);
char *my_strstr(const char *str1, const char *str2);
size_t my_strlen(const char *s);


void *my_memcpy(void *dest, const void *src, size_t num);
void *my_memmove(void *dest, const void *src, size_t n);

void my_quicksort(int *a, int low, int high);
void my_boblesort(int *a, int len);
linkStack *linkStack_push(linkStack *stack, int val);
linkStack *linkStack_pop(linkStack *stack, linkStack * val);

int my_binarySearch(int* nums, int numsSize, int target);