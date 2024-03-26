#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct employee
{
	char name[10];
	int age;
};

int compBYname(const void* e1, const void* e2)
{
	int ret= strcmp(((struct employee*)e1)->name, ((struct employee*)e2)->name);//strcmp  返回值：>0,==0,<0
	return ret;
}

/*
strcmp函数：
str1 = "appple";
str2 = "banana";
strcmp(str1,str2) 返回值<0
*/

int compare_int(const void* e1, const void* e2)  //比较函数e1大返回1，相等返回0，e2大返回-1
{
	int ret = (*(int*)e1 - *(int*)e2);
	return ret;
}


void Swap(char* buf1,char* buf2,int width)
{
	//不用创建具体类型的临时变量，交换
	int i = 0;
	for (i = 0; i < width; i++)
	{
		char temp = *buf1;
		*buf1 = *buf2;
		*buf2 = temp;
		buf1++;
		buf2++;
	}
}

void bubble_sort(void* base, int NumOfElement, int SizeOfOneElement, int (*cmp)(const void* e1
	, const void* e2))
/*参数说明：
base - 空指针类型，可以接收任何类型的指针，以便排序任何类型的数据
NumOfElement - 所排序的数组的元素个数
SizeOfOneElement - 数组中每个元素的大小
cmp - 函数指针，接受比较函数，该函数用于比较数组中两个相邻元素的大小（或排序关系），自行设计
	  默认返回值大于0，进行交换
*/
{
	int i = 0;										//冒泡排序一趟可以保证 最大的一定能放在最后面
	for (i = 0; i < NumOfElement - 1; i++)
	{
		int flag = 1;								//假设以及排序好,防止重复运算
		int j = 0;
		for (j = 0; j < NumOfElement - 1 - i; j++)  //例如，共10个元素下标 0~9，NumOfElement=10
			                                        //第一次从0到8<10-1-0=9，第二次从0到7<10-1-1=8
		{
			if ((cmp((char*)base + j * (SizeOfOneElement), (char*)base + (j+1) * (SizeOfOneElement)))>0)
			{
				Swap((char*)base + j * (SizeOfOneElement), (char*)base + (j+1) * (SizeOfOneElement),
					SizeOfOneElement);
				flag = 0;
			}
		}
		if (flag == 1)
			break;
	}
}

void test1()
{
	int arr1[] = { 9,8,7,6,5,4,3,2,1,0};
	int sz = sizeof(arr1) / sizeof(arr1[0]);

	bubble_sort(arr1, sz, sizeof(arr1[0]), compare_int);
}


void test2()
{
	struct employee e[] = { {"bill",20},{"zion",31},{"alen",28} };
	int num = sizeof(e) / sizeof(e[0]);

	bubble_sort(e, num, sizeof(e[0]), compBYname);
	int i = 0;
	for (i = 0; i < num; i++)
	{
		printf("%s\n", e[i].name);
	}
}


int main()
{
	test1();      //test1() 是排序整型数组，test2() 是排序一个结构体
	//test2();

	return 0;
}
