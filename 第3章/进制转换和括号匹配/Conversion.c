#include <stdio.h>
#include <stdlib.h>
#include "LinkStack.h"
void Conversion(LinkStack ps, int n) //ʵ��8���Ƶ�ת��
{
	int temp;
	while (n)
	{
		Push_link(ps, n % 8);
		n /= 8;
	}
	printf("ת��Ϊ�˽��ƺ�Ľ����");
	while (!IsNullStack_link(ps))
	{
		temp = Top_link(ps);
		printf("%d", temp);
		Pop_link(ps);
	}
}	/* End of Conversion( ) */

void Hexconversion(LinkStack ps, int n) //ʵ��16���Ƶ�ת��
{
	int temp;
	while (n)
	{
		int temp = n % 16;
		switch (temp)
		{
		case 10:temp = 'A'; break;
		case 11:temp = 'B'; break;
		case 12:temp = 'C'; break;
		case 13:temp = 'D'; break;
		case 14:temp = 'E'; break;
		case 15:temp = 'F'; break;
		}
		Push_link(ps, temp);
		n = n / 16;
	}
	printf("ת��Ϊʮ�����ƺ�Ľ����");
	while (!IsNullStack_link(ps))
	{
		temp = Top_link(ps);
		if (temp<10) printf("%d", temp);
		else printf("%c", temp);
		Pop_link(ps);
	}
}	/* End of Hex Conversion( ) */

void main()
{
	LinkStack mystack = NULL;
	int n, m;
	mystack = SetNullStack_Link();
	printf("��������Ҫת���˽��Ƶ�ʮ��������");
	scanf_s("%d", &n);
	Conversion(mystack, n);
	printf("\n");
	printf("��������Ҫת���˽��Ƶ�ʮ����������");
	scanf_s("%d", &m);
	Hexconversion(mystack, m);
	printf("\n");
}