#include"../head/linkedList.h"
#include<stdio.h>
#include<stdio.h>
void sert(LinkedList *head)//���뵽ͷָ���
{
	int a;
	if ((*head) ->next==NULL)
	{
		printf("���ܿ��������\n");
		return 0;
	}
	
	printf("������ڵ�����");
	scanf_s("%d", &a);
	InsertList((*head), creatnode(a));
}
void judge(ElemType e)
{
	if (e)
	{
		printf("��");
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
		printf("������\n");
		return ;
	}
	printf("������Ҫɾ���Ķ��������\n");
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
	printf("������Ҫ���ҵ�ֵ\n");
	scanf_s("%d",&a);
	if (SearchList((*head), a))
	{
		printf("�ҵ�һ�����ϵĽڵ�\n");
	}

}

int main()
{

	const LinkedList head = (LNode*)malloc(sizeof(LNode));
	head->next = NULL;
	int x=1;
	while (1) {
		
		printf("-------------����ѡ��-----------\n");
		printf("1:���ز˵�");
		printf("          2:�˳����� \n");
		printf("3:��������");
		printf("          4:����ڵ� \n");
		printf("5:ɾ���ڵ�");
		printf("          6:��������ڵ� \n");
		printf("7:��������Ƿ�ɻ�");
		printf("  8:��ѯ���Ƿ���� \n");
		printf("9:��ת���� ");
		printf("         10:ż�ת\n");
		printf("11: ��ѯ�нڵ�");
		printf("      12:��������\n");


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
		case 3:  creatlist(head); break;//ok
		case 4:  sert(head); break;//��ͷָ�����ok
		case 5:  Delete(head); break;//ѭ����Ŀ�꣬һ������ָ��
		case 6:  showList(head); break;//ok
		case 7:  judge(IsLoopList(head)); break;//ok
		case 8:    look(head); break;
		case 9:  ReverseList(head); break;
        case 10:  ReverseEvenList(head); break;//
		case 11:printf("%d\n",FindMidNode(head)->data); break;//ok
		case 12:DestroyList(head);break;//ok


		default: setvbuf(stdin, NULL, _IONBF, 0); //���������������siwtch��䣬������һ��ѭ��
			printf("�������ֲ���ȷ\n");
			break;
		}
		setvbuf(stdin, NULL, _IONBF,0);
	}
	while (1);
	return 0;
}
