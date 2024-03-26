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
	int ret= strcmp(((struct employee*)e1)->name, ((struct employee*)e2)->name);//strcmp  ����ֵ��>0,==0,<0
	return ret;
}

/*
strcmp������
str1 = "appple";
str2 = "banana";
strcmp(str1,str2) ����ֵ<0
*/

int compare_int(const void* e1, const void* e2)  //�ȽϺ���e1�󷵻�1����ȷ���0��e2�󷵻�-1
{
	int ret = (*(int*)e1 - *(int*)e2);
	return ret;
}


void Swap(char* buf1,char* buf2,int width)
{
	//���ô����������͵���ʱ����������
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
/*����˵����
base - ��ָ�����ͣ����Խ����κ����͵�ָ�룬�Ա������κ����͵�����
NumOfElement - ������������Ԫ�ظ���
SizeOfOneElement - ������ÿ��Ԫ�صĴ�С
cmp - ����ָ�룬���ܱȽϺ������ú������ڱȽ���������������Ԫ�صĴ�С���������ϵ�����������
	  Ĭ�Ϸ���ֵ����0�����н���
*/
{
	int i = 0;										//ð������һ�˿��Ա�֤ ����һ���ܷ��������
	for (i = 0; i < NumOfElement - 1; i++)
	{
		int flag = 1;								//�����Լ������,��ֹ�ظ�����
		int j = 0;
		for (j = 0; j < NumOfElement - 1 - i; j++)  //���磬��10��Ԫ���±� 0~9��NumOfElement=10
			                                        //��һ�δ�0��8<10-1-0=9���ڶ��δ�0��7<10-1-1=8
		{
			if (cmp((char*)base + j * (SizeOfOneElement), (char*)base + (j+1) * (SizeOfOneElement)))
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
	test1();      //test1() �������������飬test2() ������һ���ṹ��
	//test2();

	return 0;
}