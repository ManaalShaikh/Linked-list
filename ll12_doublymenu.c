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
struct node *insertbeg(struct node *head,int val)
{
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=val;
	newnode->next=head;
	head->prev=newnode;
	head=newnode;
	return head;
}

struct node *insertend(struct node *head,int val)
{
	struct node *newnode,*temp;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=val;
	newnode->next=NULL;
	for(temp=head;temp->next!=NULL;temp=temp->next);
	temp->next=newnode;
	newnode->prev=temp;
	return head;
}

struct node *insertmid(struct node *head,int val,int pos)
{
	struct node *temp,*newnode;
	int i;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=val;
	for(i=1,temp=head; i<(pos-1) && temp->next!=NULL;i++,temp=temp->next);
	newnode->next=temp->next;
	temp->next->prev=newnode;
	temp->next=newnode;
	newnode->prev=temp;
	return head;
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
	struct node *head=NULL;
	int i,ch,val,pos;
	do
	{
		printf("\n 1.CREATE \n 2.DISPLAY \n 3.INSERT BEGIN \n 4.INSERT END \n 5.INSERT MID \n 6.DELETE BEGIN \n 7.DELETE MIDDLE \n 8.DELETE END");
		printf("\n Enter choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1 :head=create(head);
			break;
			case 2 :disp(head);
			break;
			case 3 :printf("Enter value:");
				scanf("%d",&val);
				head=insertbeg(head,val);
			break;
			case 4 :printf("Enter value:");
				scanf("%d",&val);
				head=insertend(head,val);
			break;
			case 5 :printf("Enter value:");
				scanf("%d",&val);
				printf("Enter position:");
				scanf("%d",&pos);
				head=insertmid(head,val,pos);
			break;
			case 6 :head=delbeg(head);
			break;
			case 7 :printf("Enter position:");
				scanf("%d",&pos);
				head=delmid(head,pos);
			break;
			case 8 :head=delend(head);
			break;
			default :printf("\n INVALID CHOICE ");
			break;
		
		}
	}while(ch<9);
}
