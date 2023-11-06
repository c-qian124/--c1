//写出主程序,对队列的所有基本操作进行测试
//要求输入一个序列入队，然后再输出队列的内容
#include<stdio.h>
#include<stdlib.h>
#include "LinkQueue.h"
void main()
{
	LinkQueue lqueue = SetNullQueue_Link(); //创建空队列
	int data;
	printf("请输入进队的元素，以0结束：");
	scanf_s("%d,", &data);
	while (data)
	{
		EnQueue_link(lqueue, data); //进队
		scanf_s("%d,", &data);
	}
	printf("出队元素的顺序是：");
	while (!IsNullQueue_Link(lqueue))
	{
		printf("%d ", FrontQueue_link(lqueue)); //输出队头元素
		DeQueue_link(lqueue);   //出队
	}
	printf("\n");
}