#include<stdio.h>
#include<stdlib.h>
//Creating the structure for nodes
struct Node{
//aninteger variable to store the data    
    int data;
//a struct Node pointer to store the address of next element    
    struct Node * next;
};

struct Node* topNode = NULL;
//traversal function to see if our operations are functioning 
void linkedListTraversal(struct Node *pointer)
{
    while (pointer != NULL)
    {
        printf("Element: %d\n", pointer->data);
        pointer = pointer->next; 
    }
}
//Creating an integer function isEmpty and passing the pointer to top node as parameter
int isEmpty(struct Node* topNode){
//if this top node is NULL, return 1   
    if (topNode==NULL){
        return 1;
    }
//else  returning 0     
    else{
        return 0;
    }
}
//Creating an integer function isFull and passing pointer to top node as parameter
int isFull(struct Node* topNode){
//Creating a new struct Node* and pointer a and assigning it a new memory location in heap    
    struct Node* a = (struct Node*)malloc(sizeof(struct Node));
//if a is NULL, return 1    
    if(a==NULL){
        return 1;
    }
//else returning 0    
    else{
        return 0;
    }
}
//Creating a struct Node* function PUSH which will return the pointer to the new top node
struct Node* push(struct Node* topNode, int x){
//if stack is full, return the condition overflow    
    if(isFull(topNode)){
        printf("Overflow\n");
    }
    else{
//Creating a new struct Node* pointer b and assigning it a new memory location in heap       
        struct Node* b = (struct Node*) malloc(sizeof(struct Node));
        b->data = x;
//Assigning topnode to the next member of b structure using b-> next = topNode
//and the given data to its data member    
        b->next = topNode;
        topNode = b;
//Returning this b as this is our new top node        
        return topNode;
    }
}
//Creating an integer function pop which will return the element we remove from the top
int pop(struct Node* tp){
//if stack is empty returning the condition underflow.    
    if(isEmpty(tp)){
        printf("Underflow\n");
    }
    else{
//Creating a new struct Node* pointer b and  make it point to the current top
//Storing the data of this node in an integer variable x  
        struct Node* b = tp;
//Assigning top to the next member of list by top = top->next as this is going to be our new top now      
        topNode = (tp)->next;
        int x = b->data;
        free(b); //freeing the pointer b
        return x; //returning x
    }
}
//pushing few elements and seeing if the changes reflect in the stack
int main(){
    topNode = push(topNode, 19);
    topNode = push(topNode, 1);
    topNode = push(topNode, 9);
    
//linkedListTraversal(top);
 
    int element = pop(topNode); 
    printf("Element popped: %d\n", element);
    linkedListTraversal(topNode);
    return 0;
}

