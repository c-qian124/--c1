//写出主程序,对队列的所有基本操作进行测试
//要求输入一个序列入队，然后再输出队列的内容
#include<stdio.h>
#include<stdlib.h>
#include "SeqQueue.h"
void main()
{
		
	SeqQueue squeue = SetNullQueue_seq(5); //创建空队列
	int data;
	printf("请输入进队的元素，以0结束：");
	scanf_s("%d,", &data);
	while (data)
	{
		EnQueue_seq(squeue, data);      //进队
		scanf_s("%d,", &data);
	}
	printf("出队元素的顺序是：");
	while (!IsNullQueue_seq(squeue))
	{
		printf("%d ", FrontQueue_seq(squeue)); //输出队头元素
		DeQueue_seq(squeue);   //出队
	}
	printf("\n");
}