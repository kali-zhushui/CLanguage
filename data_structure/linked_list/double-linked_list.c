/*
测试双向链表
*/
#include<stdio.h>
#include<stdlib.h>
struct student
{
	int value;
	struct student *next;
	struct student *preview;
};
#define stu  struct student

stu *init_list()
{
	stu *head=malloc(sizeof(stu));
	head->next=NULL;
	head->preview=NULL;
	return head;
}
int tail_insert(int num,stu *mylist)
{
	stu *p = mylist;
	stu *newnode = malloc(sizeof(stu));
	newnode->value=num;
	if(p->next==NULL)
	{
		p->next=newnode;
		newnode->preview=p;
		newnode->next=NULL;
	}
	else
	{
		while(p->next!=NULL)
			p=p->next;
		p->next=newnode;
		newnode->preview=p;
		newnode->next=NULL;
	}
	return 0;
}
int quiery(stu *mylist)
{
	stu *p = mylist;
	while(p->next!=NULL)
	{
		p=p->next;
		printf("%4d",p->value);
	}
}
int mid_insert(int num1,int num2,stu *mylist)
{
	stu *p = mylist;
	stu *newnode=malloc(sizeof(stu));
	newnode->value=num2;
	if(p->next==NULL)
	{
		p->next=newnode;
		newnode->preview=p;
		newnode->next=NULL;
		printf("The list is empty now,\nI will add a node for you.\n");
	}
	else
	{
		while(p->next!=NULL)
		{
			p=p->next;
			if(p->value==num1)
			{
				//p->next->preview=newnode;
				newnode->next=p->next;
				newnode->preview=p;
				p->next=newnode;
				newnode->next->preview=newnode;
			}
			else
				continue;
				printf("I'm here!\n");
		}
		if(p->next==NULL && p->value!=num1)
			printf("Invalid node!!\n");
	}
	return 0;
}
int modify_list(int num1,int num2,stu *mylist)
{
	stu *p=mylist;
	if(p->next==NULL)
	{
		printf("The list is empty now,are you kidding!\n");
	}
	else
	{
		while(p->next!=NULL)
		{
			p=p->next;
			if(p->value==num1)
			{
				p->value=num2;
			}
			else
				continue;
		}
		if(p->next==NULL && p->value!=num1)
			printf("Invalid node!!\n");
	}
	return 0;
}
int del_list(int num1,stu *mylist)
{
	stu *p=mylist;
		while(p->next!=NULL)
		{
			if(p->next->next==NULL && p->next->value==num1)
			{
				free(p->next->next);
				p->next=NULL;
				break;
			}
			else if(p->next->value==num1)
			{
				p->next=p->next->next;
				free(p->next->preview);
				p->next->preview=p;
				p=p->preview;
			}
				p=p->next;
		}
	return 0;
}
void main()
{
	stu *mylist=init_list();
	tail_insert(12,mylist);
	tail_insert(13,mylist);
	tail_insert(15,mylist);
	tail_insert(10,mylist);
	tail_insert(16,mylist);
	tail_insert(16,mylist);
	del_list(16,mylist);
	quiery(mylist);
	free(mylist);
}