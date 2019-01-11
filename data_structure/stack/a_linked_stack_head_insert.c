#include<stdio.h>
#include<stdlib.h>
//用单链表模拟一个栈
struct stack
{
	int value;
	struct stack *next;
} *mystack;
#define stack  struct stack
//初始化
stack *stack_init()
{
	stack *head = malloc(sizeof(stack));
	head->next=NULL;
	return head;
}
//插入数据
int insert(int num)
{
	stack *p = mystack;
	stack *newnode = malloc(sizeof(stack));
	newnode->value=num;
	newnode->next=NULL;
	if(p->next!=NULL)
	{
		newnode->next=p->next;
		p->next = newnode;
	}
	else
	{
		p->next=newnode;
	}
	return 0;
}
//判断长度,不计算头结点.
int len()
{
	int length=0;
	stack *p = mystack;
	while(p->next!=NULL)
	{
		p=p->next;
		++length;
	}
	return length;
}

//弹栈
int pop()
{
	stack *p = mystack;
	stack *tmp;
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
	stack *p = mystack;
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
	firstnum=mystack->next->value;
	return firstnum;
}
int main(int argc,char** argv)
{
	mystack = stack_init();
	quiery(mystack);
	insert(12);
	insert(13);
	insert(14);
	insert(15);
	insert(16);
	insert(17);
	insert(18);
	printf("%d\n",pop());
	quiery(mystack);
	printf("%d",fnum());
	free(mystack);
	return 0;
}