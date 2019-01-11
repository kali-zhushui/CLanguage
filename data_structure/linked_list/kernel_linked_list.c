#include<stdlib.h>
#include<stdio.h>
#include"kernel_list.h"

struct list
{
	int value;
	struct list_head point;
} *pos,*mylist;
struct list *list_init()
{
	struct list *head=malloc(sizeof(struct list));
	INIT_LIST_HEAD(&head->point);
	return head;
}
struct list *insert_list(int num)
{
	struct list *newnode = malloc(sizeof(struct list));
	list_add_tail(&newnode->point,&mylist->point);
	newnode->value=num;
	return newnode;
}
struct list *makeanode(int num)
{
	struct list *newnode = malloc(sizeof(struct list));
	newnode->value=num;
	return newnode;
}
int quiery()
{
	
	list_for_each_entry(pos,&mylist->point,point)
	{
		printf("%d\n",pos->value);
	}
	return 0;
}

int del_list(int num)
{
	int flag = 0;
	struct list_head *tmp;
	list_for_each_entry(pos,&mylist->point,point)
	{
		if(pos->value==num)
		{
			tmp = pos->point.next;
			list_del(&pos->point);
			pos->point.next = tmp;
			flag = 1;
		}
	}
	if(flag == 0)
	{
		printf("Invalid input!\n");
	}
}
//use the function list_for_each_entry th delete a value-specified node
int main()
{
	mylist = list_init();
	insert_list(12);
	insert_list(12);
	insert_list(13);
	insert_list(14);
	insert_list(14);
	del_list(12);
	quiery();
	free(mylist);
	return 0;
}
/* struct kernellist
{
	int num;
	struct list_head mypoint;
};
struct kernellist *init_list()
{
	struct kernellist *head=malloc(sizeof(struct kernellist));
	INIT_LIST_HEAD(&head->mypoint);
	return head;
}
struct kernellist *creat_new()
{
	struct kernellist *newnode=malloc(sizeof(struct kernellist));
	newnode->num=num;
}
int main()
{
	struct kernellist *myhead=init_list();
	struct kernellist *new1=creat_new(15);
	struct kernellist *new2=creat_new(14);
	//在尾部插入一个新的节点
	list_add_tail(&new1->mypoint,&myhead->mypoint);
	//遍历链表打印
	list_for_each_entry(pos,&myhead->mypoint,mypoint)
	{
		printf("目前遍历的节点存放的是:%d\n",pos->num);
	}
	//中间插入
	list_add_tail(struct list_head *new,struct list_head *head);
} */