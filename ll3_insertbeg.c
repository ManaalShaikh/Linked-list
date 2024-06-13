#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *create(struct node *head)
{
	struct node *newnode,*temp;
	int i,n;
	printf("Enter limit:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		newnode=(struct node *)malloc(sizeof(struct node));
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
		printf("%d \t",temp->data);
		temp=temp->next;
	}
}

struct node *insertbeg(struct node *head,int val)
{
	struct node *temp,*newnode;
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=val;
	newnode->next=head;
	head=newnode;
	return head;
}

void main()
{
	struct node *head=NULL;
	int ch,val,pos;
	do
	{
		printf("\n 1.CREATE \n 2.DISPLAY  \n 4.INSERT BEGIN");
		printf("\n ENTER CHOICE:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:head=create(head);
				break;
			case 2:disp(head);
				break;
			case 3:printf("Enter value:");
				scanf("%d",&val);
				head=insertbeg(head,val);
				break;

			default:printf("\n Invalid choice");
		}
		
	}while(ch<4);
	
}

