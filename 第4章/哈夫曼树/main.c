#include<stdio.h>
#include<stdlib.h>
#include"huffman.h"
void main(){
	int *text;
	int num = 6, i = 0;		//num为哈夫曼树叶子节点个数
	HuffTree pht;           //定义哈夫曼树	
	printf("从文件读入的结点信息：\n");
	/*scanf_s("%d\n", &num);
	for (i = 0; i < num; i++)
	scanf_s("%d", &text[i]);
	printf("\n");*/
	text = GetFrequency();
	printf("构建哈夫曼数前，遍历哈夫曼表数组初态:\n");
	printf("weight   leftchild     rightchild    parent\n");
	for (i = 0; i < num; i++){
		printf("%2d       -1            -1           -1\n", text[i]);
	}
	printf("\n");
	pht = CreateHuffTree(num, text);//构建哈夫曼树
	//输出哈夫曼树
	printf("构建哈夫曼数后，遍历哈夫曼表数组终态:\n");
	printf("ww     leftchild       rightchild     parent\n");
	for (i = 0; i < num * 2 - 1; i++){
		printf("%2d      %2d	       %2d           %2d\n",
			pht->ht[i].weight, pht->ht[i].leftchild, pht->ht[i].rightchild, pht->ht[i].parent);
	}
}