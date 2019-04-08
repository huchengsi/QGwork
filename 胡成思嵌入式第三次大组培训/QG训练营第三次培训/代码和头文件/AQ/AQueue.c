#include"../head/AQueue.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>



/**
 *  @name        : void InitAQueue(AQueue *Q)
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void InitAQueue(AQueue *Q)
{	
	
	Q->length = 0;
	Q->front = 0;
	Q->rear = 0;
}


/**
 *  @name        : void DestoryAQueue(AQueue *Q)
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void DestoryAQueue(AQueue *Q)
{
	free(Q);
}



/**
 *  @name        : Status IsFullAQueue(const AQueue *Q)
 *    @description : 检查队列是否已满
 *    @param         Q 队列指针Q
 *    @return         : 满-TRUE; 未满-FALSE
 *  @notice      : None
 */
Status IsFullAQueue(const AQueue *Q)
{
	if (Q->length == MAXQUEUE)
	{
		printf("是满的\n");
		return TRUE;
	}
	else
		return FALSE;
}

/**
 *  @name        : Status IsEmptyAQueue(const AQueue *Q)
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyAQueue(const AQueue *Q)
{
	if (Q->length == 0)
	{
		printf("是空的\n");
		return TRUE;
	}
	else
		return FALSE;
}



/**
 *  @name        : Status GetHeadAQueue(AQueue *Q, void *e)
 *    @description : 查看队头元素
 *    @param         Q 队列指针Q，存放元素e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadAQueue(AQueue *Q, void *e)//判断类型，输出对应元素
{
	
	if (Q->length == 0)
		return FALSE;
	if (((Mydata*)Q->data[Q->front])->type == 1)
	{
		int a= ((Mydata*)Q->data[Q->front])->INT;
		e = &a;
		printf("%d \n ", ((Mydata*)Q->data[Q->front])->INT);/////
	}
	else if (((Mydata*)Q->data[Q->front])->type == 2)
	{
		char a = ((Mydata*)Q->data[Q->front])->CHAR;
		e = &a;

		printf("%c \n", ((Mydata*)Q->data[Q->front])->CHAR);
	}
	else if (((Mydata*)Q->data[Q->front])->type == 3)
	{
		float a = ((Mydata*)Q->data[Q->front])->FLOAT;
		e = &a;

		printf("%f \n", ((Mydata*)Q->data[Q->front])->FLOAT);
	}
	else if (((Mydata*)Q->data[Q->front])->type == 4)
	{
		double a = ((Mydata*)Q->data[Q->front])->DOULBLE;
		e = &a;

		printf("%lf \n", ((Mydata*)Q->data[Q->front])->DOULBLE);
	}
	else
	{
		return FALSE;
	}

	
	return TRUE;

}



/**
 *  @name        : int LengthAQueue(AQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 队列长度count
 *  @notice      : None
 */
int LengthAQueue(AQueue *Q)
{
	return Q->length;
}



/**
 *  @name        : Status EnAQueue(AQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否满了或为空
 */
Status EnAQueue(AQueue *Q, void *data)
{
	
	if (IsFullAQueue(Q))
		return FALSE;
	Q->length++;
	Q->data[Q->rear] = data;
	
    Q->rear = (Q->rear + 1)%MAXQUEUE;//向后一位,注:满了需要重新到开头
		return TRUE;
	
}



/**
 *  @name        : Status DeAQueue(AQueue *Q)
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeAQueue(AQueue *Q)
{
	if (Q->length == 0)
		return FALSE;
	if (((Mydata*)Q->data[Q->front])->type == 1)
	{
		printf("%d 已经出队\n ", ((Mydata*)Q->data[Q->front])->INT);/////
	}
	else if (((Mydata*)Q->data[Q->front])->type == 2)
	{ 
		printf("%c 已经出队\n", ((Mydata*)Q->data[Q->front])->CHAR);
	}
	else if (((Mydata*)Q->data[Q->front])->type == 3)
	{
		printf("%f 已经出队\n", ((Mydata*)Q->data[Q->front])->FLOAT);
	}
	else if (((Mydata*)Q->data[Q->front])->type == 4)
	{
		printf("%lf 已经出队\n", ((Mydata*)Q->data[Q->front])->DOULBLE);
	}
	else
	{
		return FALSE;
	}

	Q->front = (Q->front + 1) % MAXQUEUE;//真正的出队操作
	return TRUE;
}



/**
 *  @name        : void ClearAQueue(Queue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void ClearAQueue(AQueue *Q)
{
	Q->front = 0;
	Q->rear = 0;
	Q->length = 0;

}



/**
 *  @name        : Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
{
	int i;
	i = Q->front;
	while ((i) != Q->rear)
	{
		foo(Q->data[i]);
		i = (i + 1) % MAXQUEUE;
	}
	printf("end\n");
	return TRUE;


}



/**
 *  @name        : void APrint(void *q)
 *    @description : 操作函数
 *    @param         q 指针q
 *  @notice      : None
 */
void APrint(void *q)//q指向的是一个结构体。判断元素输出即可
{
	if (((Mydata*)q)->type == 1)
	{
		printf("%d -> ", ((Mydata*)q)->INT);/////
	}
	else if (((Mydata*)q)->type == 2)
	{
		printf("%c ->", ((Mydata*)q)->CHAR);
	}
	else if (((Mydata*)q)->type == 3)
	{
		printf("%f ->", ((Mydata*)q)->FLOAT);
	}
	else if (((Mydata*)q)->type == 4)
	{
		printf("%lf ->", ((Mydata*)q)->DOULBLE);
	}
}

