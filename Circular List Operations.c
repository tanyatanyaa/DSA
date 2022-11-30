#include <stdio.h>
#include <stdlib.h>

//structure of Circular List Node 
struct CListNode{
    int value; 
    struct CListNode* next;

    // Instead of maintaining a head, we will maintain a tail because of the circular 
    // nature of the linked list. 
};


// add first: Add a node at the starting. 
// returns the tail of the created list
struct CListNode* addFirst(struct CListNode* tail, int valueToBeAdded){
    
    struct CListNode* node = NULL;
    
    // new node to be added
    node = (struct CListNode*)malloc(sizeof(struct CListNode));
    node->value = valueToBeAdded;
    
    //check if the list is empty
    if(tail == NULL){
        tail = node;
        tail->next = node;
        
    }else{
        //non empty list, add our node at the starting of the list and adjust the tail 
        struct CListNode* temp = NULL;
        temp = tail->next;
        node->next = temp;
        tail->next = node;
    }
    
    return tail;
}


//add last: add a node in the end of the circular LL.
// returns the tail of the created list
struct CListNode* addLast(struct CListNode* tail, int valueToBeAdded){
    struct CListNode* node = NULL;
    // new node to be added
    node = (struct CListNode*)malloc(sizeof(struct CListNode));
    node->value = valueToBeAdded;
    
    //check if the list is empty
    if(tail == NULL){
        tail = node;
        tail->next = node;
        
    }else{
        //non empty List. 
        //add our node, and also adjust the tail. tail will contain our newly added node. 
        struct CListNode* temp;
        temp = tail->next;
        tail->next = node;
        node->next = temp;
        tail = node;
    }
    return tail;
}


//traverse and display the list
// we are using the same function to display the list and traversing. 
void traverse(struct CListNode* tail){
    
    struct CListNode* pointer = NULL;
    //pointer that will traverse the list one by one
    pointer = tail;
    do{
        
        pointer = pointer->next;
        printf("%d, ", pointer->value);
    }while(pointer != tail); 
    return;
}


// returns the node found after searching in  the created list
struct CListNode* search(struct CListNode* tail, int valToSearch){

    struct CListNode* pointer = NULL;
    //search by using pointer traversal. 
    pointer = tail;
    while(pointer->next != tail){

        //if found, return pointer. 
        if(pointer->value == valToSearch){
            return pointer;
        }
        pointer = pointer->next;
        
    }
    //return NULL if no node found. 
    return NULL;
}


//add after a particular CListNode
// returns the tail of the created list
struct CListNode* addAfter(struct CListNode* tail, int valueToBeAdded, int valueToBeAddedAfter){
    struct CListNode* nodeToAddAfter = NULL;
    nodeToAddAfter= search(tail, valueToBeAddedAfter);

    //if no node found with that value, do nothing. 
    if(nodeToAddAfter== NULL){
        return tail;
    }

    //if it is a tail node, simply call addLast
    if(nodeToAddAfter == tail){
        return addLast(tail, valueToBeAdded);
    }
    struct CListNode* temp = NULL;
    struct CListNode* newNode = NULL;
    newNode = (struct CListNode*)malloc(sizeof(struct CListNode));
    newNode->value = valueToBeAdded;
    
    temp = nodeToAddAfter->next;
    newNode->next = temp;
    nodeToAddAfter->next = newNode;
    
    //return tail after adding
    return tail;
    
}

//delete first
//return tail after modifying the list
struct CListNode* deleteFirst(struct CListNode* tail){
    if(tail->next == tail) return NULL;
    tail->next = tail->next->next;
    return tail;
}

//delete at end
//return tail after modifying the list
struct CListNode* deleteLast(struct CListNode* tail){
    if(tail->next == tail) return NULL;
    
    struct CListNode* pointer = NULL;
    pointer = tail->next;
    
    //
    while(pointer != tail){
        if(pointer->next == tail){
            break;
        }
        pointer = pointer->next;
    }
    pointer->next = pointer->next->next;
    tail = pointer;
    return tail;
}


//delete after
//return tail after modifying the list
struct CListNode* deleteAfter(struct CListNode* tail, int valToDeleteAfter){
    struct CListNode* nodeToDeleteAfter = NULL;
    nodeToDeleteAfter = search(tail,valToDeleteAfter);
    
    //if not found, do nothing. 
    if(nodeToDeleteAfter == NULL){
        return tail;
    }
    
    if(nodeToDeleteAfter == tail){
        return deleteFirst(tail);
    }
    
    if(nodeToDeleteAfter->next == tail){
        return deleteLast(tail);
    }
    
    nodeToDeleteAfter->next = nodeToDeleteAfter->next->next;
    return tail;
}


int main(void) {
	// experiments: verifying all the functions 
	
    struct CListNode* tail = NULL;
	
	tail = addLast(tail, 4);
	tail = addLast(tail, 2);
	tail = addLast(tail, 8);
	tail = addLast(tail, 12);
	tail = addLast(tail, 10);
	
	tail = addAfter(tail, 15, 10);
	
	traverse(tail);
	tail = deleteAfter(tail, 4);
	printf("\n");
	traverse(tail);
	
	return 0;
}

