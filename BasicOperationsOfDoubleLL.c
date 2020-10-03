#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *left;
	struct node *right;
};

struct node *root = NULL;
int count = 0;

void create()
{
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	printf("\nEnter node data : ");
	scanf("%d",&temp->data);
	temp->left = NULL;
	temp->right = NULL;
	if(root == NULL)
	{
		root = temp;
	}
	else
	{
		struct node *ptr;
		ptr = root;
		while(ptr->right!=NULL)
		{
			ptr = ptr->right;
		}
		ptr->right = temp;
		temp->left = ptr;
	}
	count++;
	main();
}
void display()
{
	struct node *ptr;
	printf("\nThe entered linked list is : \n");
	ptr = root;
	while(ptr->right!=NULL)
	{
		printf("\n%d",ptr->data);
		ptr = ptr->right;
	}
	printf("\n%d",ptr->data);
	
	main();
}

void add_node()
{
	
	int pos;
	printf("\nEnter the position : ");
	scanf("%d",&pos);
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	printf("\nEnter node data : ");
	scanf("%d",&temp->data);
	temp->left = NULL;
	temp->right = NULL;
	if(pos>count+1)
	{
		printf("Invalid position");
	}
	else if(pos==1)
	{
			struct node *q;
			q = root;
			
			temp->right = root;
			q->left = temp;
			root = temp;
	}
	else if(pos==count+1)
	{
		struct node *p;
		p = root;
		while(p->right!=NULL)
		{
			p = p->right;
		}
		    p->right = temp;
			temp->left = p;
	}
	else
	{
		int i = 1;
		struct node *p,*q;
		p = root;
		while(i<pos-1)
		{
			p = p->right;
			i++;
		}
		q = p->right;
		p->right = temp;
		temp->left = p;
		temp->right = q;
		q->left = temp;
	}
	count++;
	main();
}
void delete_node()
{
	int pos;
	printf("\nEnter the position : ");
	scanf("%d",&pos);
	if(pos==1)
	{
		struct node *p;
		p = root;
		root = p->right;
		p->right = NULL;
		root->left = NULL;
		
	}
	else if(pos==count)
	{
		struct node *p,*q;
		p = root;
		while(p->right!=NULL)
		{
			p = p->right;
		}
		q = p->left;
		p->left = NULL;
		q->right = NULL;
	}
	else if(pos>count)
	{
		printf("\nInvalid Position");
	}
	else 
	{
		struct node *p,*q,*s;
		p = root;
		int i = 1;
		while(i<pos-1)
		{
			p = p->right;
			i++;
			
		}
		q = p->right;
		p->right = q->right;
		s = q->right;
		s->left = root;
		q->right = NULL;
		q->left = NULL;
	}
	count--;
	main();
	
}
int main()
{
	int choice;
	printf("1.Add Node At End : \n2.Add node at any positon : \n3.Display\n4.Delete Node from any position");
	scanf("\n%d",&choice);
	switch(choice)
	{
		case 1 : create();break;
		case 2 : add_node();break;
		case 3 : display();break;
		case 4 : delete_node();break;
		default : printf("Invalid Entry");
	}
	
	return 0;
}
