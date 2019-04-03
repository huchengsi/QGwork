#include "../head/linkedList.h"
#include<stdlib.h>
#include<stdio.h>
/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */

Status InitList(LinkedList *L) //创建一个空的头指针
{
	
	(*L) = (LNode*)malloc(sizeof(LNode));     //分配内存空间。
	if (*L == NULL)
	{
		return ERROR;                         //申请失败的返回值
	}            
	else
	{
		(*L)->next = NULL;                       //置空
		return SUCCESS;                         //申请成功的返回值
	}
	}                       
/**
 *  @name        : LNode* creatnode()
 *	@description : create a node
 *	@param		 : ElemType data
 *	@return		 : LNode*
 *  @notice      : None
 */
LNode* creatnode(ElemType data)
{
	LNode* aimNode= (LNode*)malloc(sizeof(LNode));//
	aimNode->data = data;
	aimNode->next = NULL;
	return aimNode;
}
/**
 *  @name        : void creatlist(LNode*L)
 *	@description : create a list
 *	@param		 : none
 *	@return		 : head*
 *  @notice      : None
 */
void creatlist(LinkedList *head)
{
	int a;	
	InitList(head);
	while (1)
	{
		setvbuf(stdin, NULL, _IONBF, 0);//清空缓存
		printf("请输入存入数据");
	
		scanf_s("%d", &a);	
		InsertList((*head), creatnode(a));
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
/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LinkedList *L) 
{

	LNode *move = (*L)->next;
	LNode *fmove = (*L);
	if (fmove == NULL)
	{
		printf("无法销毁一个空链表\n");
	}
	else {
		while (fmove!=NULL)     //判断是否删除干净
		{
			move = fmove->next;
			free(fmove);
			fmove = move;       //到下一个位置继续拆
		}
		(*L)->next = NULL;//置空
		printf("删除成功");
	}
}

/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertList(LNode *p, LNode *q) //把q加到p后面
{
	LNode* newnode = q;
	newnode->next = p->next;//要添加新节点的指向上一个的下一个
	p->next = newnode;	//上一个的下一个改为新节点
}

/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
Status DeleteList(LNode *p, ElemType *e)//删除p后的节点
{
	printf("%p\n", p);
	if (p == NULL || p -> next == NULL)
	{
		printf("123\n");
		return ERROR;
	}
	LNode * t = (p->next)->next;
	free(p->next);
	p->next = t;
	
	return SUCCESS;
}

/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit 
 *	@return		 : None
 *  @notice      : None
 */
void TraverseList(LinkedList L, void (*visit)(ElemType e)) {
	LNode* move=L;
	while (L->next!= NULL&&L->next!=NULL)
	{  
		L = L->next;
		printf("%d\n",L->data);			
	}
	L = move;
}
/**
 *  @name        :  void visit(ElemType e)
 *	@description : print value
 *	@param		 : data
 *	@return		 : None
 *  @notice      : None
 */
void prt(ElemType e)//输出函数
{
	printf("%d\n",e);
}

/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e 
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
Status SearchList(LinkedList L, ElemType e)//!!!!!!!!!!!!!!!!!!!!!!!!!!!
{

	while (L)
	{
		if (L->data == e)
			return SUCCESS;
		L = L->next;
	}
	return ERROR;
}
/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list 
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status ReverseList(LinkedList *L)//反转链表
{
	if (*L == NULL || (*L)->next == NULL)
		return ERROR;
	LNode *NNode = (*L)->next;
	LNode *CurrentNode = NNode->next;
	LNode *head = (LNode*)malloc(sizeof(LNode)); //定义一个暂时的头指针 
	while (CurrentNode)
	{
		NNode->next = CurrentNode->next;
		CurrentNode->next = (*L)->next;
		(*L)->next = CurrentNode;
		CurrentNode = NNode->next;
	}
	head->next = NNode;  //使假的头指针的next指向反转后最后一个节点 
	L = &head; //纠正头指针的指向 
	return SUCCESS;
}


/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status IsLoopList(LinkedList L) 
{
	if (L == NULL)
	{
		printf("链表为空");
		return ERROR;
	}
	LNode*slow = L;
	LNode*fast = L;
	while (fast->next!=NULL)
	{
		if (slow->data == fast->data)
		{
			printf("是\n");
			return SUCCESS;
		}
		fast = fast->next->next;
		slow = slow->next;
	}
	printf("不是\n");
	return 0;
}

/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish 
 */
LNode* ReverseEvenList(LinkedList *L) {
	LNode *CurrentNode, *NextNNode, *NNode;
	CurrentNode = *L;
	while (CurrentNode->next&&CurrentNode->next->next)
	{
		NNode = CurrentNode->next;//只需要每两个替换一次即可
		NextNNode = NNode->next;
		NNode->next = NextNNode->next;
		NextNNode->next = NNode;
		CurrentNode->next = NextNNode;
		CurrentNode = NNode;
	
	}
	return *L;
}

/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : find the middle node in the linked list
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish 
 */
LNode* FindMidNode(LinkedList *L) {
	if (L == NULL)
	{
		printf("链表为空");
		exit(0);
	}
	LNode *slow = *L;
	LNode *fast = (*L);
	
	while (fast->next != NULL )
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}

