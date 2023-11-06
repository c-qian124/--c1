#ifndef HUFFMAN_H
#define HUFFMAN_H

#define MAX 100;
#define CHARLEN 50;
struct HuffNode		          //��������������
{
	int weight;			         //Ȩֵ
	int parent, leftchild, rightchild;  //����������Һ���
};
typedef struct HuffNode *HtNode;
typedef struct HuffTreeNode   //�����������
{
	int n;	            //��������Ҷ�ӽ�����
	int root;           //������������
	HtNode  ht;         //ָ�����������ָ��
}*HuffTree;

//�������ܣ� ������ѡ�ļ���Ĭ���ļ�������Ƶ������
//��������� ��
//����ֵ��   freqΪ��Ƶ�����������
int *GetFrequency();

//�������ܣ� �����������
//�������n�� ������
//�������w�� ���Ȩֵ
//����ֵ��   huffman���ĸ�
HuffTree CreateHuffTree(int n, int *w);

#endif