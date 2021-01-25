#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#define max 100

void bubble_sert(int a[],int len); /*冒泡排序函数*/

int main(void)
{
	int arr[max];
	int i,len;
	printf("请输入排序长度：");
	scanf("%d", &len);
	/*
	如果不用用户输入排序长度的话就需要自己计算数组长度
	数组长度计算： int len= sizeof(arr) / sizeof(arr[0]);
	这样的话就需要动态申请数组存储空间
	*/

	/*这样由用户确定数组长度，在冒泡排序时传递参数就很方便，并且一定要在主函数中
	将数组长度确定并传递到冒泡排序函数中，否则在冒泡排序函数中传递的就只有
	数组首元素的地址（详见指针中关于数组地址的传递） 无法求得数组长度
	*/
	printf("请输入要排序的数列：");
	for (i = 0; i < len; i++)
	{
		scanf("%d", &arr[i]);
	}
	printf("输入的数列为：");
	for (i = 0; i < len; i++)
	{
		printf("%d	", arr[i]);
	}
	printf("\n");

	bubble_sert(arr,len);

	return 0;
}

void bubble_sert(int a[], int len)
{
	int t,i,j;
	/*确定冒泡排序的趟数
	
	*/
	for ( i = 0; i < len-1; i++) /*这里的len-1表示就是总共排序的次数，由于第一个元素直接就
								 开始排序了，所以要把它减去，就只需要排序len-1 次了*/
	{
		int flag = 1; //用flag为1来代表该趟排序已经有序
		/*冒泡排序的优化算法
		设置一个标志，在已经有序后就不再进行排序，
		否则就继续进行排序，这样可以很好的减少排序的次数
		*/
		for ( j = 0; j < len-1-i; j++) /*要保证j是可以动态变化的，每次都是与当前元素的 后面的元素相比较
								而且比较次数也是随着元素的后移而减少的，所减少的就是前面已经排序过的*/
		{
			if (a[j] >=a[j + 1])
			{
				t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
				flag = 0;//用flag为0来代表该趟排序仍然无序
			}
		}

		if (flag == 1) /*当排序已经是由小到大的顺序时，就可以跳出整个循环，
					   这样就可以很好的避免重复的判断和比较*/
		{
			break;//跳出整个循环
		}
		/*break关键字是用于跳出循环，想for while switch等，但是不可以用于
		if，由于if并不是循环语句，而是条件判断语句，在这里的break
		是用于跳出for循环的*/
		
	}
	for (i = 0; i < len; i++)
	{
		printf("%d	", a[i]);
	}
	printf("\n");
}