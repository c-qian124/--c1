#ifndef HUFFMAN_H
#define HUFFMAN_H

#define MAX 100;
#define CHARLEN 50;
struct HuffNode		          //定义哈夫曼树结点
{
	int weight;			         //权值
	int parent, leftchild, rightchild;  //父结点与左右孩子
};
typedef struct HuffNode *HtNode;
typedef struct HuffTreeNode   //定义哈夫曼树
{
	int n;	            //哈夫曼树叶子结点个数
	int root;           //哈夫曼树树根
	HtNode  ht;         //指向哈夫曼树的指针
}*HuffTree;

//函数功能： 读入自选文件或默认文件进行字频分析。
//输入参数： 无
//返回值：   freq为字频分析结果数组
int *GetFrequency();

//函数功能： 构造哈夫曼树
//输入参数n： 结点个数
//输入参数w： 结点权值
//返回值：   huffman树的根
HuffTree CreateHuffTree(int n, int *w);

#endif