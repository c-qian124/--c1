#include <stdio.h>
#include <stdlib.h>
#include "LinkStack.h"

//����ƥ���㷨
int BracketMatch( LinkStack top)
{
	int flag = 1;
	char ch,temp;
	Push_link(top,'#');//ջ�׷�#
	printf("������Ҫ�жϵı��ʽ����#�Ž�����");
	scanf_s("%c",&ch);
	while (ch!='#')
	{
		if (ch=='(')//�����ţ�ѹջ
		{
			Push_link(top, ch);
		}
		else
		{
			if (ch==')')//�����ţ���ջ
			{
				temp=Top_link(top);
				if (temp=='(')
				{
					Pop_link(top);
				}
				else
				{
					flag = 0;break;
				}				
			}
		}
		scanf_s("%c",&ch);
	}//while
	if (!flag || Top_link(top)!='#')
	{
		printf("no\n");
		return 0;
	}
	else
	{
		printf("yes\n");
		return 1;
		
	}
}

//void main()
//{
//	LinkStack mystack = NULL;
//	mystack = SetNullStack_Link();
//	BracketMatch(mystack);
//}