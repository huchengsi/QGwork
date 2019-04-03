#include "../head/duLinkedList.h"
#include<stdio.h>
#include<stdlib.h>
/**
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList_DuL(DuLinkedList *L) {
	(*L) = NULL;
	return SUCCESS;
}

/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : destroy a linked list
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
void DestroyList_DuL(DuLinkedList *L) {
	DuLNode *time = *L;
	while (*L)
	{
		time = *L;
		(*L) = time->next;
		free(*L);
	}
}

/**
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q) {
	if (p==NULL)
	{
		return ERROR;
	}
	DuLNode *time1 = p->prior;//需要三个节点互动实现插入
	q->prior = p->prior;
	q->next = p;
	p->prior = q;
	time1->next = q;
}

/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q) {
	if (p == NULL)
	{
		return ERROR;
	}
	DuLNode *time1 = (DuLNode*)malloc(sizeof(DuLNode));
	time1 = p->next;//需要三个节点互动实现插入
	q->next = p->next;
	q->prior = p;
	p->next = q;
	time1->prior = q;
}


/**
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : status
 *  @notice      : None
 */
Status DeleteList_DuL(DuLNode *p, ElemType *e) {
	if (p == NULL||p->next==NULL)
		return ERROR;
	DuLNode *time1 = (DuLNode*)malloc(sizeof(DuLNode));
	 time1 = p;
	 p->next->prior = p->prior;
	 p->prior->next = p->next;
	
	free(time1);
	return SUCCESS;
}
 
/**
 *  @name        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit 
 *	@return		 : Status
 *  @notice      : None
 */
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e)) {
	DuLNode *p = (DuLNode*)malloc(sizeof(DuLNode));
	p = L->next;
	while (L->next != NULL)
	{
		visit(L->data);
		L = L->next;
	}
}

void putdata(ElemType e)
{
	printf("%d->");
}


void creatlist(DuLinkedList *head, DuLNode *tail)
{
	(*head) = (DuLNode*)malloc(sizeof(DuLNode));
	(tail)= (DuLNode*)malloc(sizeof(DuLNode));
	int a;                                 //输入的节点数据域
	(*head)->next=tail;
	(tail)->prior = head;
	tail->next = NULL;
	while (1)
	{
		setvbuf(stdin, NULL, _IONBF, 0);//清空缓存
		printf("请输入存入数据");

		scanf_s("%d", &a);
		InsertAfterList_DuL((*head), creatnode(a));
		printf("继续吗？(Y/N)");
		setvbuf(stdin, NULL, _IONBF, 0);//清空缓存
		int ch = getchar();
		if (ch == 'N' || ch == 'n')
		{
			break;
		}
	}
	return 0;
}
DuLNode* creatnode(ElemType data)//创建一个节点
{
	DuLNode* aimNode = (DuLNode*)malloc(sizeof(DuLNode));//
	aimNode->data = data;
	aimNode->next = NULL;
	aimNode->prior = NULL;
	return aimNode;
}

void DestroyList(DuLinkedList *L)
{

	DuLNode *move = (*L)->next;
	DuLNode *fmove = (*L);
	if (fmove == NULL)
	{
		printf("无法销毁一个空链表\n");
	}
	else {
		while (fmove != NULL)     //判断是否删除干净
		{
			move = fmove->next;
			free(fmove);
			fmove = move;       //到下一个位置继续拆
		}
		(*L)->next = NULL;//置空
		printf("删除成功");
	}
}