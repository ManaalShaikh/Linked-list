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

struct node *delcom(struct node *head,int pos)
{
	struct node *temp,*p;
	int i;
	if(pos==1)
	{
		p=head;
		head=head->next;
		free(p);
	}
	else
	{
		for(i=1,temp=head;temp!=NULL && i<pos-1;i++,temp=temp->next);
		p=p->next;
		temp->next=p->next;
		free(p);
	}
	return head;

}

struct node *inscom(struct node *head,int val,int pos)
{
	struct node *newnode,*temp;
	int i;
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=val;
	if(pos==1)
	{
		newnode->next=head;
		head->prev=newnode;
		head=newnode;
	}
	else
	{
		for(i=1,temp=head;i<(pos-1) && temp->next!=NULL;i++,temp=temp->next);
		newnode->next=temp->next;
		temp->next->prev=newnode;
		temp->next=newnode;
		newnode->prev=temp;
	}
	return head;
}

int count_nodes(struct node *head)
{
	struct node *temp;
	int cnt=0;
	for(temp=head;temp!=NULL;temp=temp->next)
	{
		cnt++;
	}
	return cnt;
}

void main()
{
	struct node *head=NULL;
	int ch;
	int val,pos;
	do
	{
		printf("\n MENU \n 1.CREATE \n 2.DISPLAY \n 3.INSERT COMMON \n 4.DELETE COMMON \n 5.COUNT NODES \n");
		printf("\n Enter choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1 :head=create(head);
			break;
			case 2:disp(head);
			break;
			case 3 :printf("Enter value:");
				scanf("%d",&val);
				printf("Enter position:");
				scanf("%d",&pos);
				head=inscom(head,val,pos);
			break;
			case 4 :printf("Enter position:");
				scanf("%d",&pos);
				head=delcom(head,pos);
			break;
			case 5 :printf("Total NO. Of Nodes =%d",count_nodes(head));
			break;
			default:printf("\n INVALID CHOICE ");
			break;
		}
	}while(ch<5);
}

