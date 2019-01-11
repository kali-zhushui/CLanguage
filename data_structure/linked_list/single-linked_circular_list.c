#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct student
{
	int num;
	struct student *next;
};
int insert_list(int num1,struct student *mylist);
int delete_list(int num1,struct student *mylist);
int len(struct student *mylist);
int modify_list(int num1,int num2,struct student *mylist);
int quiery(struct student *mylist);
int mid_insert(int num1,int num2,struct student *mylist);
//单链表的初始化
struct student *init_list()
{
	struct student *head = malloc(sizeof(struct student));
	struct student *tail = malloc(sizeof(struct student));
	head->next = tail;
	tail->next = head;
	tail->num = 0;
	return head;
}
//往链表中插入一个新的节点
int insert_list(int num1,struct student *mylist)
{
	struct student *head = mylist;
	struct student *p = mylist;
	int length = len(mylist);
	if(p->next->num == 0)
	{
		p->next->num=num1;
	}
	else
	{
		struct student *newnode = malloc(sizeof(struct student));
		newnode->num = num1;
		newnode->next = head;
		//找到尾部
		while(p->next!=head)
		{
			p=p->next;
		}
		newnode->next=head;
		p->next = newnode;
		//将新的节点插入尾部

	}
}
//删除单向链表的指定节点
int delete_list(int num1,struct student *mylist)
{
	struct student *p = mylist;
	struct student *head = mylist;
	struct student *tmp = head;
	if(len(mylist)>0)
	{
		while(p->next!=head)
		{
			if(p->next->num==num1)
			{
				if(p->next==head && p->num!=num1)
				{
					printf("Nothing found!\n");
				}
				tmp = p->next;
				p->next=p->next->next;
				free(tmp);
				continue;
			}
			else
			{
				p = p->next;
			}
		}
	}
	else
	{
		printf("The list is empty!");
		return -1;
	}
}
//计算单向循环链表的长度
int len(struct student *mylist)
{
	struct student *head = mylist;
	int length=0;
	struct student *p=mylist;
	while(p->next!=head)
	{
		++length;
		p = p->next;
	}
	return length;
}
//更改单向循环链表一个节点的num值
int modify_list(int num1,int num2,struct student *mylist)
{
	struct student *head = mylist;
	struct student *p = mylist;
	while(p->next!=head)
	{
		if(p->num==num1)
		{
			p->num = num2;
			p = p->next;
			continue;
		}
		else
		{
			p = p->next;
		}
	}
	return 0;
}
int quiery(struct student *mylist)
{
	struct student *head = mylist;
	struct student *p = mylist;
	int i = 0;
	while(p->next!=head)
	{
		++i;
		p = p->next;
		printf("%d: %d\n",i,p->num);
	}
}
//中间插入一个链表节点
int mid_insert(int num1,int num2,struct student *mylist)
{
	struct student *head = mylist;
	struct student *p = mylist;
	struct student *tmp = NULL;
	struct student *newnode = malloc(sizeof(struct student));
	while(p->num!=num1 && p->next !=head)
	{
		p = p->next;
	}
	if(p->next==head && p->num!=num1)
		printf("Invalid node!\n");
//	tmp = p->next;
//	p->next = newnode;
	newnode->next=p->next;
	p->next=newnode;
	newnode->num = num2;
	return 0;
}
//使链表执行删除操作时能够删除重复元素
//倒序
int reverse_list(struct student *mylist)
{
	struct student *head = mylist;
	struct student *p = mylist;
	int length = len(mylist);
	struct student *a[length];
	struct student *tmp = malloc(sizeof(struct student));
	int i = 0,j;
	while(p->next!=head)
	{
		p=p->next;
		a[i]=p;
		i++;
	}
	for(i = 0,j=length-1;i<(length)/2;i++,j--)
	{
		tmp->num = a[i]->num;
		a[i]->num = a[j]->num;
		a[j]->num = tmp->num;
	}
	free(tmp);
}

int remove_list_test(int num1,struct student *mylist)
{
	struct student *head = mylist;
	struct student *p = mylist;
	struct student *q = mylist->next;
	struct student *tmp;
	while(p->next!=head)
	{
		if(q->num!=num1)
		{
			p=p->next;
			q=p->next;
		}
		else
		{
			break;
		}
	}
	p->next=q->next;
	q->next=NULL;
	free(q);
	
}
int remove_list(int num1,struct student *mylist)
{
	struct student *head = mylist;
	struct student *p = mylist->next;
	struct student *q = mylist;
	struct student *tmp;
	while(p!=head)
	{
		if(p->num==num1)
		{
			break;
		}
		p=p->next;
		q=q->next;
	}
	q->next=p->next;
	p->next=NULL;
	free(p);
}
void main()
{
	struct student *myhead = init_list();
	insert_list(12,myhead);
	insert_list(13,myhead);
	insert_list(14,myhead);
	insert_list(15,myhead);
	insert_list(18,myhead);
	insert_list(19,myhead);
	quiery(myhead);
	reverse_list(myhead);
	quiery(myhead);
}