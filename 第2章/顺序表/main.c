

#include<stdio.h>
#include<stdlib.h>
#include "SeqList.h"
void main()
{
	SeqList seqlist;
	int max, len, i, x;
	printf("输入顺序表的最大值(<100)=");
	scanf_s("%d", &max);
	seqlist = SetNullList_Seq(max);//创建空的顺序表
	if (seqlist != NULL)
	{
		printf("输入顺序表的长度=");
		scanf_s("%d", &len);
	}
	printf("输入顺序表的元素：");
	for (i = 0; i<len; i++)
	{
		scanf_s("%d", &x);
		InsertPre_seq(seqlist, i, x); //通过插入建立顺序表
	}
	printf("顺序表是否为空，1为空，0为非空：%d\n", IsNullList_seq(seqlist));
	printf("当前顺序表的元素是：");
	print(seqlist);               //输出顺序表
	scanf("%d", &key);
	temp = binsearch_recursion(zrx_alist, key, 0, zrx_alist->n - 1, pos);
	printf("%d\n", temp);
	//if (binsearch(zrx_alist, key, &pos)==-1)
	//{
	//	InsertPre_seq(zrx_alist, pos, key);
	//	printf("The list is after insert %d key:\n",key);
	//	//print(zrx_alist);
	//}
	//print(zrx_alist);
	
	DelIndex_seq(seqlist, 3);   //删除下标为3的元素
	printf("删除下标为3的元素后的顺序表:");
	print(seqlist);                   //输出顺序表
	InsertPre_seq(seqlist, 2, 99);  //在下标2位置之前插入99
	printf("在下标2位置之前插入99后的顺序表:");
	print(seqlist);                    //输出顺序表
	printf("查找值为99的元素下标:");
	printf("%d\n", Locate_seq(seqlist, 99)); //查找值为99的元素下标
	
	DestoryList_Seq(seqlist);	//销毁顺序表
}
