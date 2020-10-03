#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *link;
};

struct node *root = NULL;
int count = 0;
int num;
void end()
{
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	
	scanf("%d", &temp->data);
	temp->link=NULL;
	if(root==NULL)
	{
		root = temp;
	}
	else
	{
		struct node *ptr;
		ptr = root;
		while(ptr->link!=NULL)
		{
			ptr = ptr->link;
		}
		ptr->link = temp;
	}
	count++;
	if(count!=num)
	{
		end();
	}
	else
	{
		addNode();
	}
}
void display()
{
	struct node *ptr;
	ptr = root;
	while(ptr->link!=NULL)
	{
		printf("%d\t",ptr->data);
		ptr = ptr->link;
	}
	printf("%d\t",ptr->data);
	
}
void addNode()
{
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	
	scanf("%d",&temp->data);
	temp->link = NULL;
	
	int loc, i=1;
	scanf("%d",&loc);
	
	if(loc>count+1)
	{
		printf("Invalid");
	}
	else if(loc==1)
	{
		
		
		temp->link=root;
		root = temp;
		
	}
	else
	{
		struct node *ptr, *q;
		ptr = root;
		while(i<=loc-1)
		{
			ptr = ptr->link;
			i++;
		}
		q = ptr->link;
		ptr->link = temp;
		temp->link = q;
	}
	count++;
	display();
}
int main()
{
	scanf("%d",&num);
	end();
	
	return 0;
}
