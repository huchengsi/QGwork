#include<stdio.h>
#include<stdlib.h>
#include"../head/LQueue.h"


 /*  @name        : void InitLQueue(LQueue *Q)
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void InitLQueue(LQueue *Q)
{
	Q->front = (Node*)malloc(sizeof(Node));
	Q->rear = (Node*)malloc(sizeof(Node));
	if (!Q->front)
	{
		return FALSE;
	}
	Q->length = 0;
	Q->front = NULL;
	Q->rear = NULL;
}
/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue *Q)
{
	while (Q->front)
	{
		Q->rear = Q->front->next;
		free(Q->front);
		Q->front = Q->rear;
	}
	return TRUE;


}
/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue *Q)
{
	if (Q->length == 0)
		return TRUE;
	else
		return FALSE;
}
/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : 查看队头元素
 *    @param         Q e 队列指针Q,返回数据指针e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadLQueue(LQueue *Q, void *e)
{

	if (Q->length == 0)
		return FALSE;
	if (Q->front->type == 1)
	{
		printf("%d \n", *((int*)(Q->front->data)));
		e = (int*)Q->front->data;
	}
	else if (Q->front->type == 2)
	{
		printf("%c \n", *(char*)Q->front->data);/////
		e = (char*)Q->front->data;
	}
	else if (Q->front->type == 3)
	{
		printf("%f \n", *(float*)Q->front->data);/////
		e = (float*)Q->front->data;
	}
	else if (Q->front->type == 4)
	{
		printf("%lf \n", *(double*)Q->front->data);/////
		e = (double*)Q->front->data;
	}
}
/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q)
{
	int a=Q->length;
	return a;
}
/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否为空
 */
Status EnLQueue(LQueue *Q, void *data)
{
	
	Node *Lnode = (Node*)malloc(sizeof(Node));
	if (Lnode == NULL)
		return FALSE;
	Lnode->data = data;
	Lnode->next = NULL;//开始这里会出现值覆盖问题
	if (Q->front == NULL)
	{
		Q->front = Lnode;
		Q->rear = Lnode;
		Q->length++;
		return TRUE;
	}
	Q->rear->next = Lnode;
	Q->rear = Lnode;
	Q->length++;
	/*if (Q->front->type == 1)
	{
		Lnode->data = (int*)data;
	}
	else if (Q->front->type == 2)
	{
		Lnode->data = (char*)data;
	}
	else if (Q->front->type == 3)
	{
		Lnode->data = (float*)data;
	}
	else if (Q->front->type == 4)
	{
		Lnode->data = (double*)data;
	}*/

}
/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q)
{

	if (Q->length == 0)
		return FALSE;
	if (Q->front->type == 1)
	{
		printf("%d 已经出队\n ", *((int*)(Q->front->data)));
		Q->length--;/////
	}
	else if (Q->front->type == 2)
	{
		printf("%c 已经出队\n ", *(char*)Q->front->data);/////
		Q->length--;
	}
	else if (Q->front->type == 3)
	{
		printf("%f 已经出队\n ", *(float*)Q->front->data);/////
		Q->length--;
	}
	else if (Q->front->type == 4)
	{
		printf("%lf 已经出队\n ", *(double*)Q->front->data);/////
		Q->length--;
	}
	Node *p = Q->front;
	Q->front = Q->front->next;
	free(p->data);
	free(p);//真正的出队操作
	return TRUE;
	


}
/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q)
{
	Node *p;
	Node *q;
	p = Q->front;
	while (Q->length--)
	{
		q = p;
		p = p->next;
		free(q);
	}
	Q->front = NULL;
	Q->rear = NULL;
	return TRUE;
}
/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
{
	if (Q->front == NULL)
		return 0;
	Node *q = Q->front;
	int a = Q->length;
	while (a--)
	{
		foo((void*)q);
		if (q->next==NULL)
		{
			break;
		}
		q = q->next;
	}
	printf("end\n");
	return TRUE;
}
/**
 *  @name        : void LPrint(void *q)
 *    @description : 操作函数
 *    @param         q 指针q
 
 *  @notice      : None
 */
void LPrint(void *q)
{
	if (((Node*)q)->type == 1)
	{
		printf("%d->", *((int*)(((Node*)q)->data)));
	}
	else if (((Node*)q)->type == 2)
	{
		printf("%c->", *(char*)((Node*)q)->data);/////
	}
	else if (((Node*)q)->type == 3)
	{
		printf("%f->", *(float*)((Node*)q)->data);/////
	}
	else if (((Node*)q)->type== 4)
	{
		printf("%lf->", *(double*)((Node*)q)->data);/////
	}
}
