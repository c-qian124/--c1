#include <stdio.h>
#include <stdlib.h>
#include "SeqQueue.h"
#include "FarmerRiver.h"

int FarmerOnRight(int status)    //判断当前状态下农夫是否在右岸
{
	return (0 != (status & 0x08));
}

int WorfOnRight(int status)     //判断当前状态下狼是否在右岸
{
	return (0 != (status & 0x04));
}

int CabbageOnRight(int status)  //判断当前状态下白菜是否在右岸
{
	return (0 != (status & 0x02));
}

int GoatOnRight(int status)     //判断当前状态下羊是否在右岸
{
	return (0 != (status & 0x01));
}

int IsSafe(int status)     //判断当前状态是否安全
{
	if ((GoatOnRight(status) == CabbageOnRight(status)) && (GoatOnRight(status) != FarmerOnRight(status)))
        return (0);        /* 羊吃白菜*/
	if ((GoatOnRight(status) == WorfOnRight(status)) && (GoatOnRight(status) != FarmerOnRight(status)))
        return (0);        /* 狼吃羊*/
    return (1);            /* 其他状态是安全的*/
}

void FarmerRiver() //农夫过河算法
 {
	int i, movers, nowstatus, newstatus;
    int status[16];  //用于记录已考虑的状态路径
	SeqQueue moveTo;  //用于记录可以安全到达的中间状态
	moveTo = SetNullQueue_seq(20); //创建空队列
	EnQueue_seq(moveTo, 0x00);    //初始状态时所有物品在右岸，初始状态入队
    for (i = 0; i < 16; i++)  //数组status初始化为-1
        status[i] =  - 1;
    status[0] = 0; 
	while (!IsNullQueue_seq(moveTo) && (status[15] == -1)) //队列非空且没有到达结束状态
    {
		nowstatus = FrontQueue_seq(moveTo); //取队头状态为当前状态
		DeQueue_seq(moveTo);
        for (movers = 1; movers <= 8; movers <<= 1)  //遍历三个要移动物品
         //考虑各种物品移动
		if ((0 != (nowstatus & 0x08)) == (0 != (nowstatus &movers)))
        //农夫与移动的物品在同一侧
        {
			newstatus = nowstatus ^ (0x08 | movers); //计算新状态
			//如果新状态是安全的且之前没有出现过
            if (IsSafe(newstatus) && (status[newstatus] ==  - 1))
            {
				status[newstatus] = nowstatus;   //记录新状态
				EnQueue_seq(moveTo, newstatus);  //新状态入队
            }
        }
    }
    // 输出经过的状态路径
    if (status[15] !=  - 1) //到达最终状态
    {
        printf("The reverse path is : \n");
		for (nowstatus = 15; nowstatus >= 0; nowstatus = status[nowstatus])
        {
			printf("The nowstatus is : %d\n", nowstatus);
			if (nowstatus == 0)
                exit(0);
        }
    }
    else
        printf("No solution.\n"); //问题无解
    
 }