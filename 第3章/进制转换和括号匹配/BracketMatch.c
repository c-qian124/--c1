#include <stdio.h>
#include <stdlib.h>
#include "LinkStack.h"

//括号匹配算法
int BracketMatch( LinkStack top)
{
	int flag = 1;
	char ch,temp;
	Push_link(top,'#');//栈底放#
	printf("请输入要判断的表达式，用#号结束：");
	scanf_s("%c",&ch);
	while (ch!='#')
	{
		if (ch=='(')//左括号，压栈
		{
			Push_link(top, ch);
		}
		else
		{
			if (ch==')')//右括号，出栈
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