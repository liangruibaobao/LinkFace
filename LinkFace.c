#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
typedef struct  ComplexNode
{
	int data;
	struct ComplexNode *next;
	struct ComplexNode *random;
}CN;
CN *cn;
CN *CreateNode(int data)
{
	CN *node = (CN*)malloc(sizeof(CN));
	node->data = data;
	node->random = node->next = NULL;
	return node;
}
CN *InitCN()
{
	CN *n1 = CreateNode(1);
	CN *n2 = CreateNode(2);
	CN *n3 = CreateNode(3);
	CN *n4 = CreateNode(4);
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n1->random = n3;
	n2->random = n1;
	n3->random = n3;
	return n1;
}
void Copy(CN *list)
{
	CN *cur = list;
	CN *newnode;
	//�����������½������Ͻ�����
	while (cur != NULL)
	{
		newnode = CreateNode(cur->data);
		newnode->next = cur->next;
		cur->next = newnode;
		cur = newnode->next;
	}
	//����random�ֶ�
	cur = list;
	while (cur != NULL)
	{
		newnode = cur->next;
		if (cur->random != NULL)
		{
			newnode->random = cur->random->next;
		}
		cur = cur->next->next;
	}
	//�Ͽ��ɵĽ��
	cur = list;
	CN *next;
	CN *newnext;
	CN *result = list->next;
	while (cur != NULL)
	{
		newnode = cur->next;
		next = newnode->next;
		if (next == NULL)
		{
			newnext = NULL;
		}
		else
		{
			newnext = next->next;
		}
		cur->next = next;
		newnode->next = newnext;
		cur = next;
	}
	printf("���Ƴɹ�\n");
}
void test()
{
	InitCN();
}
int main()
{
	
	CN *cn= InitCN();
	Copy(cn);
	return 0;
}