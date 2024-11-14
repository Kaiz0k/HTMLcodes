#include<stdlib.h>
#include<stdio.h>
struct node
{
    int data;
    int priority;
    struct node * next;
    struct node * prev;
}Node;
struct node * insert(struct node *head,int n,int p)
{
    struct node *nnode=malloc(sizeof(struct node));
    struct node * temp=head;
    nnode->data=n;
    nnode->priority=p;
    nnode->next=NULL;
    if(head==NULL)
    {
        head=nnode;
        nnode->prev=NULL;
        return head;
    }
    else{
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=nnode;
        nnode->prev=temp;
        return head;
    }
}
void swap(struct node * a,struct node *b)
{
	int data,p;
    data=a->data;
    p=a->priority;
    a->data=b->data;
    a->priority=b->priority;
    b->data=data;
    b->priority=p;
}
struct node * sort(struct node *head){
	struct node *temp=head;
    struct node *last=NULL;
    int swapped;
    if(head==NULL)
    {
        return head;
    }
    do{
        swapped=0;
        temp=head;
	    while(temp->next!=last)
	    {
		    if(temp->priority > temp->next->priority)
		    {
			    swap(temp,temp->next);
		    }
            swapped=1;
            temp=temp->next;
	    }
        last=temp;
    }
    while(swapped);
    return head;
}
void display(struct node* head)
{
    struct node *temp=head;
    while(temp!=NULL)
    {
        printf("%d %d\n",temp->data,temp->priority);
        temp=temp->next;
    }
    printf("\n");
}
int main()
{
    struct node* head=NULL;
    int i,n,d,p;
    printf("enter the number of elements: ");
    scanf("%d",& n);
    printf("enter data and priority: \n");
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&d,&p);
        head=insert(head,d,p);
    }
    head=sort(head);
    printf("\nSorted as per priority: \n");
    display(head);
    return 0;
}

