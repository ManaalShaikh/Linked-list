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
	printf("Enter limit:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		newnode=(struct node *)malloc(sizeof(struct node));
		printf("Enter Value:");
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
		printf("%d \t",temp->data);
		temp=temp->next;
	}
}

void main()
{
	struct node *head=NULL;
	head=create(head);
	printf("\n Display Linked list:");
	disp(head);
}


