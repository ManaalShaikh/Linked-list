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

struct node *delbeg(struct node *head)
{
	struct node *p;
	p=head;
	head=head->next;
	free(p);
	return head;
}
void main()
{
	struct node *head=NULL;
	int ch,val,pos;
	do
	{
		printf("\n 1.CREATE \n 2.DISPLAY \n 3.DELETE BEGIN");
		printf("\n ENTER CHOICE:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:head=create(head);
				break;
			case 2:disp(head);
				break;
			case 3:head=delbeg(head);
			break;
			default:printf("\n Invalid choice");
		}
		
	}while(ch<4);
	
}


