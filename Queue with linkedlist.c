//Implementing a queue using a linked list
#include <stdio.h> 
#include <stdlib.h>

// Structure to create a node with data and the next pointer
struct node {
    int data;
    struct node * next;
};
//creating two struct Node pointers f and r which are used to mark the front and the rear ends
struct node * f = NULL;
struct node * r = NULL;

//creating a void function enqueue
void enqueue(int value) {
    struct node * pointer;
//creating a new struct Node and assigning its memory in heap dynamically using malloc    
    pointer = (struct node * ) malloc(sizeof(struct node));
    pointer -> data = value;
    pointer -> next = NULL;
//checking if it equals NULL    
    if ((f == NULL) && (r == NULL)) {
//making both f and r equal to pointer and for all the other cases just make the r point pointer        
        f = r = pointer;
    } else {
        r -> next = pointer;
        r = pointer;
    }
    printf("Node Inserted\n\n");
}

// Dequeue() operation on a queue
int dequeue() {
//checking if the queue is already not empty    
    if (f == NULL) {
        printf("\n Queue Underflow\n");
        return -1;
    } else {
        struct node * a = f;
//Storing the data of f in an integer variable b       
        int b = f-> data;
//making f equal to the next node to f   
        f = f -> next;
        free(a);
        return b;
    }
}
// Display all elements of the queue
void display() {
    struct node * a;
//Checking ig Queue is empty 
    if ((f== NULL) && (r == NULL)) {
        printf("\nQueue is Empty\n");
    } else {
        printf("The queue is \n");
        a = f;
        while (a) {
            printf("%d--->",a -> data);
            a = a -> next;
        }
        printf("NULL\n\n");
    }
}
//Example
int main() {
    int c, value;
    while (c != 4) {
        printf("1.a\n2.b\n3.c\n4.d\n");
        printf("\nEnter choice: ");
        scanf("%d", & c);
        switch (c) {
            case 1:
                printf("\nEnter the value to insert: ");
                scanf("%d", & value);
                enqueue(value);
                break;
            case 2:
                printf("Element popped :%d\n", dequeue());
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("\nIt is a wrong Choice\n");
        }
    }
    return 0;
}