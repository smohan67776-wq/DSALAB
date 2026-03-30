#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node*next;
};

struct node*front=NULL;
struct node*rear=NULL;

void enqueue()
{
	int item;
	struct node*newNode;
	
	newNode=(struct node *)malloc(sizeof(struct node));
	if(newNode==NULL)
	{
		printf("Heap Overflow!\n");
		return;
	}
	printf("Enter element to insert:");
	scanf("%d",&item);
	
	newNode->data=item;
	newNode->next=NULL;
	
	if(rear==NULL)
	{
		front=rear=newNode;
	}
	else
	{
		rear->next=newNode;
		rear=newNode;
	}
	printf("Enter insert successfully.\n");
}

void dequeue()
{
	struct node*temp;
	
	if(front==NULL)
	{
		printf("Queue Underflow!\n");
		return;
	}
	
	temp=front;
	printf("Deleted element:%d\n",temp->data);
	front=front->next;
	
	if(front==NULL)
	rear=NULL;
	
	free(temp);
}

void display()
{
	struct node*temp;
	
	if(front==NULL)
	{
		printf("Queue is empty.\n");
		return;
	}
	printf("Queue elements:\n ");
	temp=front;
	while(temp!=NULL)
	{
		printf("%d",temp->data);
		temp=temp->next;
	}
	printf("\n");
	
}

int main()
{
	int choice;
	
	do
	{
		printf("\n---Queue Menu---\n");
		printf("1.Enqueue\n2.Dequeue\n3.Dispaly\n4.Exit\n");
		printf("Enter your choice:");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				enqueue();
				break;
				case 2:
					dequeue();
					break;
					case 3:
						display();
						break;
						case 4:
							printf("Exiting program.\n");
							break;
							default:
								printf("Invalid choice!\n");
			}	
	} while (choice!=4);
	return 0;
}
