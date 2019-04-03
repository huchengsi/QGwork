#include"../head/linkedList.h"
#include<stdio.h>
#include<stdio.h>
void sert(LinkedList *head)//插入到头指针后
{
	int a;
	if ((*head) ->next==NULL)
	{
		printf("不能空链表插入\n");
		return 0;
	}
	
	printf("请输入节点数据");
	scanf_s("%d", &a);
	InsertList((*head), creatnode(a));
}
void judge(ElemType e)
{
	if (e)
	{
		printf("是");
	}
	else
	{
		printf("not found");
	}
}
void  Delete (LinkedList *head)
{
	
	LNode*p = (*head) ->next;

	int a;
	
	if (*head == NULL)
	{
		printf("空链表\n");
		return ;
	}
	printf("请输入要删除的对象的数据\n");
	scanf_s("%d", &a);
	while (p != NULL&&(p ->next)->data!=a)
	{
		p = p->next;
	}
	DeleteList(p,(*head)->data);
	setvbuf(stdin, NULL, _IONBF, 0);
	

}
void showList(LinkedList *h)
{
	LNode *p;

	p = (*h)->next;
	
	if (p == NULL)
		printf("error\n");
	else
	{
		do
		{
			printf("%d->", p->data);
			p = p->next;
		} while (p != NULL);
		printf("end\n");
	}
}
void look(LinkedList *head)
{
	
	int a;
	printf("请输入要查找的值\n");
	scanf_s("%d",&a);
	if (SearchList((*head), a))
	{
		printf("找到一个符合的节点\n");
	}

}

int main()
{

	const LinkedList head = (LNode*)malloc(sizeof(LNode));
	head->next = NULL;
	int x=1;
	while (1) {
		
		printf("-------------操作选项-----------\n");
		printf("1:返回菜单");
		printf("          2:退出程序 \n");
		printf("3:创建链表");
		printf("          4:插入节点 \n");
		printf("5:删除节点");
		printf("          6:遍历输出节点 \n");
		printf("7:检查链表是否成环");
		printf("  8:查询节是否存在 \n");
		printf("9:反转链表 ");
		printf("         10:偶项反转\n");
		printf("11: 查询中节点");
		printf("      12:销毁链表\n");


		printf("--------------------------------\n");
		printf("按数字键选择要执行的操作: ");
		scanf_s("%d", &x);
		setvbuf(stdin, NULL, _IONBF, 100);
		printf("\n");

		if (x == 2) exit(1);  //输入2，退出程序

		if ('x' < '1' || 'x' > '11')
		{
			printf("非法输入");
			break;
		}
		switch (x)
		{
		case 1:  break; //输入1，跳出switch语句，进入下一次循环
		case 3:  creatlist(head); break;//ok
		case 4:  sert(head); break;//从头指针插入ok
		case 5:  Delete(head); break;//循环的目标，一个整形指针
		case 6:  showList(head); break;//ok
		case 7:  judge(IsLoopList(head)); break;//ok
		case 8:    look(head); break;
		case 9:  ReverseList(head); break;
        case 10:  ReverseEvenList(head); break;//
		case 11:printf("%d\n",FindMidNode(head)->data); break;//ok
		case 12:DestroyList(head);break;//ok


		default: setvbuf(stdin, NULL, _IONBF, 0); //数字输入错误，跳出siwtch语句，进入下一次循环
			printf("输入数字不正确\n");
			break;
		}
		setvbuf(stdin, NULL, _IONBF,0);
	}
	while (1);
	return 0;
}
