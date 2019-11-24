#include <stdio.h>

int main()
{
	//合法的定义
	int a[1] = {0};          //声明时直接指定元素个数
	int b[] = {9,3,4,2};     //初始化时指定元素个数

	//不合法的定义
	b[100] = 4;                
	printf("%d",b[1000]);
	return 0;
}