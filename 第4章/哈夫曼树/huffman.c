#include<stdio.h>
#include<stdlib.h>
#include"huffman.h"

int *GetFrequency() //读入自选文件或默认文件进行字频分析。
{
	int i;
	int LEN = CHARLEN
	FILE *fp = NULL;
	int *freq = (int *)malloc(sizeof(int)*LEN);
	/*	----- 初始化fre数组 -----*/
	for (i = 0; i < LEN; i++)
		freq[i] = 0;
	fp = fopen(".\\file.txt", "r");
	if (fp == NULL)
	{
		printf("\n\t\t找不到文件\"\n");
		exit(0);
	}
	/*	----- 对文件进行字频分析 ,在这里只是小写字母-----*/
	for (char ch; 0 < fscanf_s(fp, "%c", &ch);)
	{
		printf("%c ", ch);
		if (ch >= 0x61) freq[ch - 0x61]++;
	}
	printf("\n");
	fclose(fp);
	return freq;
}
//	构造哈夫曼树
HuffTree CreateHuffTree(int n, int *w){
	HuffTree pht;
	int i, j, x1, x2, min1, min2;
	pht = (HuffTree)malloc(sizeof(struct HuffTreeNode));
	if (pht == NULL){
		printf("Out of space!!\n");
		return pht;
	}
	//为哈夫曼树申请2*N-1个空间
	pht->ht = (HtNode)malloc(sizeof(struct HuffNode)*(2 * n - 1));

	if (pht->ht == NULL){
		printf("Out of space!!\n");
		return pht;
	}
	//初始化哈夫曼树
	for (i = 0; i < 2 * n - 1; i++){
		pht->ht[i].leftchild = -1;	//初始化叶结点左孩子
		pht->ht[i].rightchild = -1;	//初始化叶结点右孩子
		pht->ht[i].parent = -1;	//初始化叶结点的父亲
		if (i < n)
			pht->ht[i].weight = w[i];
		else
			pht->ht[i].weight = -1;
	}
	for (i = 0; i < n - 1; i++){
		min1 = MAX;			//m1代表极小值
		min2 = MAX;			//m2代表次小值
		x1 = -1;			//极小值下标
		x2 = -1;			//次小值下标
		//找到极小值下标x1并把极小值赋值给m1
		for (j = 0; j < n + i; j++)
		if (pht->ht[j].weight < min1&&pht->ht[j].parent == -1){
			min2 = min1;
			x2 = x1;
			min1 = pht->ht[j].weight;
			x1 = j;
		}
		//找到次小值下标x2并把次小值赋值给min2
		else if (pht->ht[j].weight < min2&&pht->ht[j].parent == -1){
			min2 = pht->ht[j].weight;
			x2 = j;
		}
		//构建x1，x2的父结点
		pht->ht[x1].parent = n + i;	//x1父结点下标
		pht->ht[x2].parent = n + i;	//x2父结点下标
		pht->ht[n + i].weight = min1 + min2;//父结点的权值为极小值加次小值
		pht->ht[n + i].leftchild = x1;	//父结点的左孩子为x1
		pht->ht[n + i].rightchild = x2;	//父结点的右孩子的x2
	}
	pht->root = 2 * n - 2;//哈夫曼树根结点位置
	pht->n = n;
	return pht;
}