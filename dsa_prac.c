#include<stdio.h>
struct node{
	int coef;
	int exp;
	struct node * next;
};
struct node * insert(int c,int e,struct node *head){
	struct node *nnode = malloc(sizeof(struct node));
	struct node *temp = malloc(sizeof(struct node));
	temp=head;
	nnode->coef=c;
	nnode->exp=e;
	nnode->next=NULL;
	if(head==NULL)
	{
		head=nnode;
		return head;
	}
	else{
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=nnode;
		return head;
	}
}
struct node * multiply(struct node *h1,struct node *h2)
{
	struct node *ptr1=h1;
	struct node *ptr2=h2;
	struct node *h3;
	int rc,re;
	while(ptr2!=NULL);
	{
		rc=ptr1->coef*ptr2->coef;
		re=ptr1->exp+ptr2->exp;
		h3=insert(rc,re,h3);
		ptr2=ptr2->next;
	}
}
void display(struct node * head)
{
	struct node *temp=head;
 	while(temp!=NULL)
 	{
 		printf("%dx^%d",temp->coef,temp->exp);
 		if(temp->next!=NULL)
 		{
 			printf("+");
		}
		temp=temp->next;
	}
}
void main()
{
	struct node *h1,*h2,*h3;
	int n1,n2,c,e;
	printf("enter number of elements you want to enter in polynomial 1: ");
	scanf("%d",&n1);
	printf("enter coefficient and exponent: ");
	while(n1--)
	{
		scanf("%d %d",&c,&e);
		h1=insert(c,e,h1);
	}
	printf("enter number of elements you want to enter in polynomial 2: ");
	scanf("%d",&n2);
	printf("enter coefficient and exponent: ");
	while(n2--)
	{
		scanf("%d %d",&c,&e);
		h2=insert(c,e,h2);
	}
}
