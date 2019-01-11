#include<stdio.h>
#include<stdlib.h>
//用单向链表模拟一个队列
struct queue
{
	int value;
	struct queue *next;
} *myqueue;
#define queue  struct queue
//初始化
queue *queue_init()
{
	queue *head = malloc(sizeof(queue));
	head->next=NULL;
	return head;
}
//插入数据
int insert(int num1)
{
	queue *p = myqueue;
	queue *newnode = malloc(sizeof(queue));
	newnode->value = num1;
	newnode->next = NULL;
	//找到尾部
	while(p->next!=NULL)
	{
		p=p->next;
	}
	p->next = newnode;
	//将新的节点插入尾部
}
//判断长度,不计算头结点.
int len()
{
	int length=0;
	queue *p = myqueue;
	while(p->next!=NULL)
	{
		p=p->next;
		++length;
	}
	return length;
}

//弹栈
int outqueue()
{
	queue *p = myqueue;
	queue *tmp;
	int popvalue;
	if(p->next == NULL)
		return -1;
	else
	{
		tmp = p->next;
		p->next=p->next->next;
		tmp->next=NULL;
		popvalue = tmp->value;
		free(tmp);
	}
	
	return popvalue;
}
//查询
int quiery()
{
	queue *p = myqueue;
	int i =0;
	while(p->next!=NULL)
	{
		p=p->next;
		printf("%d  %d\n",p->value,++i);
	}
}
int fnum()
{
	int firstnum;
	firstnum=myqueue->next->value;
	return firstnum;
}
int main(int argc,char** argv)
{
	myqueue = queue_init();
	quiery(myqueue);
	quiery(myqueue);
	free(myqueue);
	return 0;
}