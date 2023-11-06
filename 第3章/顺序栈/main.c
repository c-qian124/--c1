//写出主程序,对栈的所有基本算法进行测试
//要求输入一个序列，通过栈实现序列反转
#include <stdlib.h>
#include <stdio.h>
#include "SeqStack.h"
void main()
{
	SeqStack p = SetNullStack_Seq(5); //创建一个空栈
	int data;
	printf("请输入进栈的元素，以0结束：");
	scanf_s("%d,", &data);
	while (data)
	{
		Push_seq(p, data);      //进栈
		scanf_s("%d,", &data);
	}
	printf("出栈元素的顺序是：");
	while (!IsNullStack_seq(p))      //是否空栈
	{
		printf("%d ", Top_seq(p)); //取栈顶元素
		Pop_seq(p);                //出栈
	}
	printf("\n");
}