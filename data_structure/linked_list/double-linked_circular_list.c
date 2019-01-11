/*
test a double-linked circular list
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

stu *init_list(int tailnum)
{
	stu *head=malloc(sizeof(stu));
	stu *tail=malloc(sizeof(stu));
	head->next=tail;
	head->preview=tail;
	tail->next=head;
	tail->preview=head;
	tail->value = tailnum;
	return head;
}
int tail_insert(int num,stu *mylist)
{
	stu *p = mylist;
	stu *newnode = malloc(sizeof(stu));
	newnode->value=num;
	if(p->next==mylist)
	{
		newnode->next=mylist;
		p->next=newnode;
		newnode->preview=p;
		mylist->preview=newnode;
	}
	else
	{
		while(p->next!=mylist)
			p=p->next;
		p->next=newnode;
		newnode->preview=p;
		newnode->next=mylist;
	}
	return 0;
}
int quiery(stu *mylist)
{
	stu *p = mylist;
	while(p->next!=mylist)
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
		while(p->next!=mylist)
		{
			p=p->next;
			if(p->value==num1)
			{
				//p->next->preview=newnode;
				newnode->next=p->next;
				p->next=newnode;
				newnode->next->preview=newnode;
				newnode->preview=p;
				break;
			}
			else if(p->next==mylist && p->value!=num1)
			{
				printf("Invalid node!!\n");
				break;
			}
		}
	return 0;
}
int modify_list(int num1,int num2,stu *mylist)
{
	stu *p=mylist;
	if(p->next==mylist)
	{
		printf("The list is empty now,are you kidding!\n");
	}
	else
	{
		while(p->next!=mylist)
		{
			p=p->next;
			if(p->value==num1)
			{
				if(p->next==mylist && p->value!=num1)
				{
					printf("Invalid node!!\n");
					break;
				}
				p->value=num2;
			}
			else
				continue;
		}
	}
	return 0;
}
int del_list(int num1,stu *mylist)
{
	stu *p=mylist;
		while(p->next!=mylist)
		{
			if(p->next->next==mylist && p->next->value==num1)
			{
				printf("I'm here!\n");
				free(p->next);
				p->next=mylist;
				mylist->preview=p;
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
int del_list_test(int num1,stu *mylist)
{
	stu *p=mylist;
	stu *tmp;
	int flag = 0;
		while(1)
		{
			if(p->next==mylist && p->value==num1)
			{
				p->preview->next = mylist;
				mylist->preview=p->preview;
				p->preview=NULL;
				p->next=NULL;
				free(p);
				printf("I'm here!\n");
				flag = 1;
				break;
			}
			else if(p->next==mylist)
			{
				if(1==flag)
					printf("Sorry,the node you specified is a mistery!\n");
				break;
			}
			else if(p->value==num1)
			{
				p->preview->next=p->next;
				p->next->preview=p->preview;
				tmp=p->next;
				p->next=NULL;
				p->preview=NULL;
				free(p);
				p=tmp;
				flag = 1;
			}
			if(p->value!=num1)
				p=p->next;
		}
	return 0;
}
void main()
{
	stu *mylist=init_list(34);
	tail_insert(12,mylist);
	tail_insert(13,mylist);
	tail_insert(15,mylist);
	tail_insert(10,mylist);
	tail_insert(16,mylist);
	tail_insert(16,mylist);
	tail_insert(16,mylist);
	tail_insert(16,mylist);
	tail_insert(16,mylist);
	tail_insert(18,mylist);
	del_list_test(16,mylist);
	quiery(mylist);
	free(mylist);
}