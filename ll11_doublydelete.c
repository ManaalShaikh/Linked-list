#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int data;
	struct node *next,*prev;
};

struct node *create(struct node *head)
{
	struct node *newnode,*temp;
	int i,n;
	printf("Enter limit:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		newnode=(struct node*)malloc(sizeof(struct node));
		printf("Enter value:");
		scanf("%d",&newnode->data);
		newnode->next=NULL;
		if(head==NULL)
		{
			head=temp=newnode;
		}
		else
		{
			temp->next=newnode;
			newnode->prev=temp;
			temp=newnode;
		}
	}
	return head;
}

struct node *disp(struct node *head)
{
	struct node *temp=head;
	while(temp!=NULL)
	{
		printf("%d\t",temp->data);
		temp=temp->next;
	}
}

struct node *delbeg(struct node *head)
{
	struct node *p;
	p=head;
	head=head->next;
	free(p);
	return head;
}

struct node *delmid(struct node *head,int pos)
{
	struct node *temp,*p;
	int i;
	for(i=1,temp=head;i<(pos-1) && temp->next!=NULL ;i++,temp=temp->next);
	p=temp->next;
	temp->next=p->next;
	p->next->prev=temp;
	free(p);
	return head;
}

struct node *delend(struct node *head)
{
	struct node *p,*temp;
	for(temp=head;temp->next->next!=NULL;temp=temp->next);
	p=temp->next;
	temp->next=NULL;
	free(p);
	return head;
}

void main()
{
	int pos,ch;
	struct node *head=NULL;
	do{
	printf("\n 1.CREATE \n 2.DISPLAY \n 3.DELETE BEGIN \n 4.DELETE MIDDLE \n 5.DELETE END \n");
	printf("Enter the choice:");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1 : head=create(head);
			break;
		case 2 : disp(head);
			break;
		case 3 : head=delbeg(head);
			break;
		case 4 :printf("Enter position:");
			scanf("%d",&pos);
			head=delmid(head,pos);
			break;	
		case 5 :head=delend(head);
			break;
		default : printf("\n INVALID CHOICE");
			break;
	}
	}while(ch<6);
}
