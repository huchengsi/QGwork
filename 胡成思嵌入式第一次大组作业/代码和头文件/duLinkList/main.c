
#include "../head/duLinkedList.h"
#include<stdio.h>
#include<stdlib.h>

void  Delete(DuLinkedList *head)
{
	DuLNode*p = (*head)->next;
	int a;
	if (*head == NULL||(*head)->next==NULL)
	{
		printf("空链表\n");
		return;
	}
	printf("请输入要删除的对象的数据\n");
	scanf_s("%d", &a);
	while (p != NULL && p->data != a)
	{
		p = p->next;
	}
	DeleteList_DuL(p, (*head)->data);
	setvbuf(stdin, NULL, _IONBF, 0);
}
void sert(DuLinkedList *head)//插入到头指针后
{
	int a;
	if ((*head)->next == NULL)
	{
		printf("不能空链表插入\n");
		return 0;
	}

	printf("请输入节点数据");
	scanf_s("%d", &a);
	InsertAfterList_DuL((*head), creatnode(a));
}

void testList(DuLinkedList *h,DuLinkedList *t)
{
	DuLNode *p;

	p = (*h);

	if (p == NULL||(*h)->next==NULL)
		printf("空的链表\n");
	else
	{

		//TraverseList_DuL(p, putdata);
		do
		{
			p = p->next;
			printf("%d->", p->data);
			//p = p->next;
		} while (p->next->next!=NULL);
		printf("end\n");
	}
}
void testList2(DuLinkedList *h, DuLinkedList *t)
{
	DuLNode *p;

	p = (*h);

	if (p == NULL)
		printf("error\n");
	else
	{

		//TraverseList_DuL(p, putdata);
		do
		{
			p = p->next;
			printf("%d->", p->data);
			//p = p->next;
		} while (p->next != t);
		printf("end\n");
	}
}
int main()
{

	const DuLinkedList head = (DuLNode*)malloc(sizeof(DuLNode));
	DuLNode *tail = (DuLNode*)malloc(sizeof(DuLNode));
	tail->prior = NULL;
	tail->next = NULL;
	InitList_DuL(head);
	int x = 1;
	while (1) {

		printf("-------------操作选项-----------\n");
		printf("1:返回菜单");
		printf("          2:退出程序 \n");
		printf("3:创建链表");
		printf("          4:插入节点 \n");
		printf("5:删除节点");
		printf("          6:遍历输出节点 \n");
		printf("7:销毁链表\n");
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
		case 3:  creatlist(head,tail); break;//ok
		case 4:  sert(head); break;//从头指针插入ok
		case 5:  Delete(head); break;//循环的目标，一个整形指针
		case 6:  testList(head,tail); break;//ok
		case 7:  DestroyList(head); break;//ok


		default: setvbuf(stdin, NULL, _IONBF, 0); //数字输入错误，跳出siwtch语句，进入下一次循环
			printf("输入数字不正确\n");
			break;
		}
		setvbuf(stdin, NULL, _IONBF, 0);
	}
	while (1);
	return 0;
}
