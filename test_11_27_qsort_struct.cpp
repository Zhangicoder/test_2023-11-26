//qsort进行排序，自制函数实现qsort功能进行排序
//整型数列排序，结构体数列排序
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>	
#include<string.h>
//用于qsort函数回调
int cmp_int(const void* e1, const void* e2)
{
	return (*(int*)e1 - *(int*)e2);
}

void Swap(char* buf1, char* buf2, int width)
{
	int i = 0;
	for (i = 0; i < width; i++)
	{
		char tmp = *buf1;
		*buf1 = *buf2;
		*buf2 = tmp;
		buf1++;
		buf2++;
	}
}
//自制拥有qsort功能的函数
void bubble_sort(void* base, int sz, int width, int(*cmp)(const void* e1, const void* e2))
{
	int i = 0;
	for (i = 0; i < sz-1; i++)
	{
		int flag = 1;
		int j = 0;
		for (j = 0; j < sz-1-i; j++)
		{
			if (cmp((char*)base + j * width, (char*)base + (j + 1) * width))
			{
				Swap((char*)base+j*width,(char*)base+(j+1)*width,width);
			}
		}
	}
}
//用于test2
struct Stu
{
	char name[20];
	int age;
};
//用于test2
int cmp_stu_by_name(const void* e1, const void* e2)
{
	return strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->name);
}
//用于test2
int cmp_stu_by_age(const void* e1, const void* e2)
{
	return((struct Stu*)e1)->age - ((struct Stu*)e2)->age;
}
//使用qsort进行排序
void test1()
{
	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	qsort(arr, sz, sizeof(arr[0]), cmp_int);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void test2()
{
	//测试使用qsort来排序结构数据
	struct Stu s[] = { {"zhangsan",15},{"lisi",30},{"wangwu",25} };
	int sz = sizeof(s) / sizeof(s[0]);
	qsort(s, sz, sizeof(s[0]), cmp_stu_by_name);
}
//使用自制函数排序
void test3()
{
	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	bubble_sort(arr, sz, sizeof(arr[0]), cmp_int);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void test4()
{
	//测试使用自制qsort函数来排序结构数据
	struct Stu s[] = { {"zhangsan",15},{"lisi",30},{"wangwu",25} };
	int sz = sizeof(s) / sizeof(s[0]);
	bubble_sort(s, sz, sizeof(s[0]), cmp_stu_by_name);
}
int main()
{
	test1();
	//test2();
	test3();
	//test4();
	return 0;
}