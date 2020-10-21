#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vld.h>
#include <assert.h>
using namespace std;

#define DataType char

typedef struct StackNode{
	DataType data;
	struct StackNode* next;
}StackNode;

typedef StackNode* ListStack;

bool ListStackEmpty(ListStack *pst);
void ListStackInit(ListStack *pst);
DataType ListStackTop(ListStack *pst);
void ListStackPush(ListStack *pst, DataType x);
void ListStackPop(ListStack *pst);

bool ListStackEmpty(ListStack *pst)
{
	return *pst == NULL;
}

void ListStackInit(ListStack *pst)
{
	*pst = NULL;
}

DataType ListStackTop(ListStack *pst)
{
	assert(*pst != NULL);//
	return (*pst)->data;
}

void ListStackPush(ListStack *pst, DataType x)
{
	StackNode *node = (StackNode*)malloc(sizeof(StackNode));
	assert(node != NULL);
	node->data = x;

	node->next = *pst;
	*pst = node;
}

void ListStackPop(ListStack *pst)
{
	StackNode *p = *pst;
	*pst = p->next;
	free(p);
}

bool isValid(char * s){
	if (s == NULL)
		return false;
	if (*s == '\0')
		return true;

	ListStack st;
	ListStackInit(&st);

	while (*s != '\0')
	{
		if (*s == '(' || *s == '[' || *s == '{')
		{
			ListStackPush(&st, *s);
		}
		else
		{
			if (ListStackEmpty(&st))
				return false;
			int topval = ListStackTop(&st);
			if ((*s == ')' && topval != '(')
				|| (*s == ']' && topval != '[')
				|| (*s == '}' && topval != '{'))
				return false;
			ListStackPop(&st);
		}
		s++;
	}
	bool flag = ListStackEmpty(&st);
	free(st);
	st == NULL;
	return flag;
}

bool isValid(char *s)
{
	if (s == NULL)
		return false;
	if (*s == '\0')
		return true;

	int len = strlen(s);
	char *st = (char*)malloc(sizeof(char)*len);
	int top = 0;

	while (*s != '\0')
	{
		if (*s == '(' || *s == '[' || *s == '{')
			st[top++] = *s;
		else
		{
			if (top == 0)
				return false;
			if ((*s == ')'&& st[top - 1] != '(')
				|| (*s == ']'&& st[top - 1] != '[')
				|| (*s == '}' && st[top - 1] != '{'))
				return false;
			top--;
		}
		s++;
	}
	bool flag = (top == 0 ? 1 : 0);
	free(st);
	st = NULL;
	return flag;
}
