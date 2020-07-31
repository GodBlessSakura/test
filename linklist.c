#include<stdio.h>
#include<stdlib.h>


typedef struct MyStruct
{
	int data;
	struct Mystruct* next;
}linknode;

//以下这些函数的 a 均为链表的起始位置

linknode * Init_linklist();
int insert_data_tail(linknode* a, int num);
int insert_data(linknode* a, int num);

int main()
{
	linknode* a;
	int locate;
	int length;
	linknode* head_of_all;
	a = Init_linklist();
	head_of_all = a;
	printf("the address of a is %p\n", a);
	for (int i = 0; i < 10; i++)
	{
		insert_data_tail(a, i);
	}

	a = head_of_all;
	length = length_list(a);
	printf("the length of this list is %d\n", length);

	a = head_of_all;
	while (a->next != NULL)
	{
	
		a = a->next;
		printf("the data is %d\n", a->data);
	}


	
	//printf("%s\n",Is_empty(a));
	
	a = head_of_all;
	//printf("%s\n",Is_empty(a));
	insert_numi_list(a, 5, 999);
	insert_numi_list(a, 6, 999);

	a = head_of_all;

	while (a->next != NULL)
	{
	
		a = a->next;
		printf("the data is %d\n", a->data);
	}
//	locate = locate_elem(a, 13);
	//locate = get_elem(a, 4);
	//printf("the located number is  %d", locate);
	destory_list(a);
	//free(a);
	//printf("a_data is %d\n", a->data);
}

linknode * Init_linklist()
{
	linknode* a;
	a = (linknode *)malloc(sizeof(linknode));
	a->data = 0;
	a->next = NULL;
	if (a == NULL) printf("init failed;");
	else return a;
}

//头插法实现链表插入
int insert_data(linknode* a, int num)
{
	if (a == NULL) return printf("linklist not exist\n");
	else {
		linknode* b;
		b = (linknode*)malloc(sizeof(linknode));
		if (b == NULL) return printf("kongjian buzu\n");
		else {
			b->data = num;
			b->next = a->next;
			a->next = b;
			return printf("OK\n");
		}
	}
}

//尾插法实现链表插入
int insert_data_tail(linknode* a, int num)
{
	if (a == NULL) return printf("linklist not exist\n");
	else {

		linknode* b,* head;
		head = a;
		b = (linknode*)malloc(sizeof(linknode));
		if (b == NULL) return printf("kongjian buzu\n");
		else {
			while (a->next != NULL)
				a = a->next;
			a->next = b;
			b->data = num;
			b->next = NULL;
		}
		//a = head;
		//printf("a->data = %d", a->data);
	}
}

//按值查找某元素是否存在，并返回其在链表中的顺序。
int locate_elem(linknode* a, int b)
{
	if (a == NULL || a->next == NULL) return -1;
	else {
		int locate = 0;
		while (a->next != NULL)
		{
			a = a->next;
			locate++;
			if (a->data == b) {
				return locate;
				break;
			}
		}
		return -2;		
	}
}
//按位查找某元素，并返回其值
int get_elem(linknode* a, int b)
{
	if (a == NULL || a->next == NULL || b <= 0) return -1;
	int j = 1;
	a = a->next;
	while (a && j<b)
	{
		a = a->next;
		j++;
	}
	if (!a || j > b) return -2;
	return a->data;
}

//判空链表
int Is_empty(linknode* a)
{
	if (a == NULL) return printf("this linklist dont exist\n");
	if (a->next == NULL) return ("this is a empty linklist\n");
	else
		return ("not empty\n");
}

//销毁链表
int destory_list(linknode* a)
{
	linknode* b = a;
	if (b== NULL) return printf("this is a illegal linklist\n");
	while (b != NULL)
	{
		b = b->next;
		free(a);
		a = b;
	}
}

//记录链表的长度，然后将指针拨回一开始的节点
int length_list(linknode* a)
{
	linknode* b = a;
	int length = 0;
	if (a == NULL) return -1;
	a = a->next;
	//if (a->next == NULL) return 0;
	for (length; a != NULL; length++)
		a = a->next;
	a = b;
	return length;
}


//在第i个位置插入num
int insert_numi_list(linknode* a, int i, int num)
{
	if (a == NULL) return printf("this is a ielegal linklist\n");
	int length = 0, j = 0;
	linknode* b;
	length = length_list(a);
	printf("before insert the length is %d\n", length);
	if (i<0 || i>length + 1) return ("ERROR1\n");
	a = a->next;
	while (a && j < i)
	{
		a = a->next;
		j++;
	}
	if (!a || j > i - 1) return printf("ERROR2\n");
	b = (linknode*)malloc(sizeof(linknode));
	if (!b) return printf("ERROR3\n");
	b->data = num;
	b->next = a->next;
	a->next = b;
	return	printf("OK\n");
	
}
//删除第i个位置元素的值
