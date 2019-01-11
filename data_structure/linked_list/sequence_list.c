#include<stdio.h>
#define LIST_LENGTH 10
//定义一个结构体表示顺序表
struct list//顺序表{
{
	int a[10];//存放真实数据
	int last;//用来标记当前数组的最后一个有效成员的下标
};
//顺序表的初始化(创建顺序表)
int init_list(struct list *somelist)
{
	int i;
	somelist->a
	somelist->last = -1;
	return 0;
}
//往顺序表里面插入数据
int insert_list(int num,struct list *somelist)
{
	if(somelist->last+1<LIST_LENGTH)
	{
		somelist->a[somelist->last+1]=num;//不严谨,数组下标有限制
		somelist->last++;//更新下标
	}
	else
	{
		return -1;
	}
}
int find_list(struct list *somelist)
{
	int i;
	for(i = 0;i < somelist->last+1;i++)
	{
		printf("数据是:%d",somelist->a[i]);
		printf("\n");
	}
}
int delete_list(int num,struct list *somelist)
{
	if(somelist->last != -1)
	{
		int i;
		for(i = num-1;i < somelist->last;i++) 
		{
			somelist->a[i]=somelist->a[i+1];
		}
		somelist->a[i] = 0;
		--somelist->last;
	}
	else
	{
		return -1;
	}
}
int remove_list(int num,struct list *somelist)
{
	struct list *p = somelist->next;
	
}
int modify_list(int num,int to,struct list *somelist)
{
	somelist->a[num-1]=to;
}
void main()
{
	struct list mylist;
	init_list(&mylist);
	insert_list(15,&mylist);
	insert_list(13,&mylist);
	insert_list(14,&mylist);
	delete_list(3,&mylist);
	modify_list(2,20,&mylist);
	find_list(&mylist);
	//使用方式
}