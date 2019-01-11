#include<stdio.h>
#include<stdlib.h>
struct stack
{
	int num;
	struct stack *next;
	struct stack *top;
};
//栈的初始化
struct stack *stack_init()
{
	struct stack *head=malloc(sizeof(struct stack));
	head->next=NULL;
	head->top=head;
	return head;
}
//压栈,进栈
int push(int num,struct stack *mystack)
{
	struct stack *newnode=malloc(sizeof(struct stack));
	struct stack *p=mystack->top;
	newnode->num=num;
	newnode->top=NULL;
	p->next=newnode;
	mystack->top = newnode;
}
int pop(struct stack *mystack)
{
	int temp;
	//从栈顶开始,依次出栈.
	struct stack *p=mystack;
	temp=mystack->top->num;
	while(p->next!=mystack->top)
	{
		p=p->next;
	}
	free(p->next);
	p->next=NULL;
	mystack->top=p;
	return temp;
}
//查询
int quiery(struct stack * mystack)
{
	struct stack *p = mystack;
	int i =0;
	while(p!=mystack->top)
	{
		p=p->next;
		printf("%d  %d\n",p->num,++i);
	}
}
void main()
{
	//初始化一个栈
	struct stack *mystack=stack_init();
	push(12,mystack);
	push(13,mystack);
	push(14,mystack);
	push(15,mystack);
	push(16,mystack);
	push(17,mystack);
	printf("%d\n",pop(mystack));
	printf("%d\n",pop(mystack));
	printf("%d\n",pop(mystack));
}