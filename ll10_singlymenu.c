#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};

struct node *create(struct node *head)
{
	struct node *temp,*newnode;
	int i,n;
	printf("Enter Limit:");
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
			temp=newnode;
		}
	}
	return head;
}

void disp(struct node *head)
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
	head=newnode;
	return head;
}

struct node *insertmid(struct node *head,int val,int pos)
{
	struct node *newnode,*temp;
	int i;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=val;
	for(temp=head,i=1;temp->next!=NULL && i<pos-1;temp=temp->next,i++);
	newnode->next=temp->next;
	temp->next=newnode;
	return head;
}

struct node *insertend(struct node *head,int val)
{
	struct node *newnode,*temp;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=val;
	for(temp=head;temp->next!=NULL;temp=temp->next);
	temp->next=newnode;
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
	struct node *p,*temp;
	int i;
	for(temp=head,i=1;temp->next!=NULL && i<pos-1;temp=temp->next,i++);
	p=temp->next;
	temp->next=p->next;
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
	int ch,pos,val;
	do
	{
		printf("\n 1.CREATE \n 2.DISPLAY \n 3.INSERTBEG \n 4.INSERTMID \n 5.INSERTEND \n 6.DELETEBEG \n 7.DELETEMID \n 8.DELETEEND");
		printf(" \n Enter choice:");
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
				printf("Enter position:");
				scanf("%d",&pos);
				head=insertmid(head,val,pos);
				break;
			case 5 :printf("Enter value:");
				scanf("%d",&val);
				head=insertend(head,val);
				break;
			case 6 :head=delbeg(head);
				break;
			case 7 :printf("Enter pos:");
				scanf("%d",&pos);
				head=delmid(head,pos);
				break;
			case 8 :head=delend(head);
				break;
			default:printf("\n INVALID CHOICE");
				break;
		}
	}while(ch<9);

}
