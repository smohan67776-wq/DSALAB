#include<stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueue();
void dequeue();
void display();

void enqueue()
{
    int item;

    if (rear == MAX - 1)
    {
        printf("Queue Overflow!\n");
        return;
    }

    printf("Enter element to insert: ");
    scanf("%d", &item);

    if (front == -1)
        front = 0;

    rear++;
    queue[rear] = item;

    printf("Element inserted successfully.\n");
}

void dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("Queue Underflow!\n");
        return;
    }

    printf("Deleted element: %d\n", queue[front]);
    front++;
}

void display()
{
    int i;

    if (front == -1 || front > rear)
    {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    for (i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main()
{
    int choice;

    do
    {
        printf("\n--- Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch (choice)
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

    } while (choice != 4);

    return 0;
}
