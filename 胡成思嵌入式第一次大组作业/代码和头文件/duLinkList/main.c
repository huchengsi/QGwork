
#include "../head/duLinkedList.h"
#include<stdio.h>
#include<stdlib.h>

void  Delete(DuLinkedList *head)
{
	DuLNode*p = (*head)->next;
	int a;
	if (*head == NULL||(*head)->next==NULL)
	{
		printf("������\n");
		return;
	}
	printf("������Ҫɾ���Ķ��������\n");
	scanf_s("%d", &a);
	while (p != NULL && p->data != a)
	{
		p = p->next;
	}
	DeleteList_DuL(p, (*head)->data);
	setvbuf(stdin, NULL, _IONBF, 0);
}
void sert(DuLinkedList *head)//���뵽ͷָ���
{
	int a;
	if ((*head)->next == NULL)
	{
		printf("���ܿ��������\n");
		return 0;
	}

	printf("������ڵ�����");
	scanf_s("%d", &a);
	InsertAfterList_DuL((*head), creatnode(a));
}

void testList(DuLinkedList *h,DuLinkedList *t)
{
	DuLNode *p;

	p = (*h);

	if (p == NULL||(*h)->next==NULL)
		printf("�յ�����\n");
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

		printf("-------------����ѡ��-----------\n");
		printf("1:���ز˵�");
		printf("          2:�˳����� \n");
		printf("3:��������");
		printf("          4:����ڵ� \n");
		printf("5:ɾ���ڵ�");
		printf("          6:��������ڵ� \n");
		printf("7:��������\n");
		printf("--------------------------------\n");
		printf("�����ּ�ѡ��Ҫִ�еĲ���: ");
		scanf_s("%d", &x);
		setvbuf(stdin, NULL, _IONBF, 100);
		printf("\n");

		if (x == 2) exit(1);  //����2���˳�����

		if ('x' < '1' || 'x' > '11')
		{
			printf("�Ƿ�����");
			break;
		}
		switch (x)
		{
		case 1:  break; //����1������switch��䣬������һ��ѭ��
		case 3:  creatlist(head,tail); break;//ok
		case 4:  sert(head); break;//��ͷָ�����ok
		case 5:  Delete(head); break;//ѭ����Ŀ�꣬һ������ָ��
		case 6:  testList(head,tail); break;//ok
		case 7:  DestroyList(head); break;//ok


		default: setvbuf(stdin, NULL, _IONBF, 0); //���������������siwtch��䣬������һ��ѭ��
			printf("�������ֲ���ȷ\n");
			break;
		}
		setvbuf(stdin, NULL, _IONBF, 0);
	}
	while (1);
	return 0;
}
