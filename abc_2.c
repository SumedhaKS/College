#include <stdio.h>
#include<stdlib.h>
#define SIZE 5
int items[SIZE];
int front = -1, rear = -1;
// Function declarations
void create();
void display();
void delete();

// Check if the queue is full
int isFull()
{
    if ((front == rear + 1) || (front == 0 && rear == SIZE - 1))
        return 1;
    return 0;
}
// Check if the queue is empty
int isEmpty()
{
    if (front == -1)
        return 1;
    return 0;
}
// Adding an element
void enQueue(int element)
{
    if (isFull())
        printf("\n Queue is full!! \n");
    else
    {
        if (front == -1)
            front = 0;
        rear = (rear + 1) % SIZE;
        items[rear] = element;
        printf("\n Inserted -> %d", element);
    }
}

// Removing an element
int deQueue()
{
    int element;
    if (isEmpty())
    {
        printf("\n Queue is empty !! \n");
        return (-1);
    }
    else
    {
        element = items[front];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % SIZE;
        }
        printf("\n Deleted element -> %d \n", element);
        return (element);
    }
}

// Display the queue
void display()
{
    int i;
    if (isEmpty())
        printf(" \n Empty Queue\n");
    else
    {
        printf("\n Front -> %d ", front);
        printf("\n Items -> ");
        for (i = front; i != rear; i = (i + 1) % SIZE)
        {
            printf("%d ", items[i]);
        }
        printf("%d ", items[i]);
        printf("\n Rear -> %d \n", rear);
    }
}

int main()
{
    int choice;

    do
    {
        printf("\nMenu:\n");
        printf("1. Create\n");
        printf("2. Display\n");
        printf("3. Delete\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            create();
            break;
        case 2:
            display();
            break;
        case 3:
            delete ();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}
// Function to create a queue
void create()
{
    int element;
    printf("Enter the element to enqueue: ");
    scanf("%d", &element);
    enQueue(element);
}
// Function to delete an element from the queue
void delete()
{
    deQueue();
}