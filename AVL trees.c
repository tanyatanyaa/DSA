#include <stdio.h>
#include <stdlib.h>
//creating a struct node
struct Node
{
//integer variable data to store the data of the node    
    int key;
//struct Node pointer called left to store the address of the left child node    
    struct Node *left;
//struct Node pointer called right to store the address of the right child node    
    struct Node *right;
//height of that node for the ease of calculating the absolute balance factor    
    int height;
};
//Creating an integer getHeight,
//and passing the pointer to the struct node we want to get the height of as the only parameter
int getHeight(struct Node *n){
//if the struct node pointer is not NULL, return 0 if it is NULL
    if(n==NULL)
        return 0;
//otherwise return the height element of the struct node        
    return n->height;
}
//Creating a struct Node* function createNode and passing the key for the node as the only parameter
struct Node *createNode(int key){
//Reserving  memory in the heap for the node using malloc    
    struct Node* node = (struct Node *) malloc(sizeof(struct Node));
    node->key = key;
//Making left and right element of the struct node point to NULL and filling the data in the data element    
    node->left = NULL;
    node->right = NULL;
//setting the height element of this node as 1 because any new node would be a leaf node that has a height of 1    
    node->height = 1;
//returning the pointer node we created  
    return node;
}
 
int max (int a, int b){
    return (a>b)?a:b;
}
//contructing Node* function getBalanceFactor
//and passing the pointer to the struct node we want to get the balance factor of as the only parameter
int getBalanceFactor(struct Node * n){
//first checking whether the node is not NULL,if it is, simply returns 0
    if(n==NULL){
        return 0;
    }
//Otherwise returning the value after subtracting the height of right child with that of left    
    return getHeight(n->left) - getHeight(n->right);
}
//Create a struct Node* function rightRotate 
//and passing the pointer to the imbalanced struct node we want to right rotate as the only parameter
struct Node* rightRotate(struct Node* y){
//defining a struct node pointer variable x and initializing it with y->left    
    struct Node* x = y->left;
//making y the right child of x and T2 the left child of y. So, x->right in another struct node pointer variable T2   
    struct Node* T2 = x->right;
 
    x->right = y;
    y->left = T2;
//Height of x becomes one added to the maximum of the heights of both of its children
    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;
//Similarly, for y    
    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;
////returning x, since it's the new root for the subtree
    return x;
}
//Creating a struct Node* function leftRotate
//and passing the pointer to the imbalanced struct node we want to left rotate as the only parameter
struct Node* leftRotate(struct Node* x){
//defining a struct node pointer variable y and initializing it with x->right    
    struct Node* y = x->right;
//x the left child of x, and T2 the right child of x. Also storing y->left in another struct node pointer variable T2
    struct Node* T2 = y->left;

    y->left = x;
    x->right = T2;
//Height of x becomes one added to the maximum of the heights of both of its children
    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;
//similarly, for y    
    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;
//returning y, since it's the new root for the subtree
    return y;
}
//following the simple Binary Search Tree insertion operation 
struct Node *insert(struct Node* node, int key){
    if (node == NULL)
        return  createNode(key);
 
    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
 
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
//creating an integer bf and store in it the balance factor of the current node we are on while backtracking    
    int bf = getBalanceFactor(node);
//four cases possible, if this node gets imbalacned 
    // Left Left Case
//if bf has a value>1 and new node has data less than data of left child of the node itself, it's left rotation case 
        if(bf>1 && key < node->left->key){
//calling the rightRotate function to fix this disturbance          
            return rightRotate(node);
        }
    // Right Right Case
//if bf has a value<-1 and new node has data > data of right child of node itself, it's right rotation case
        if(bf<-1 && key > node->right->key){
//calling the leftRotate function to fix this disturbance            
            return leftRotate(node);
        }
    // Left Right Case
//if bf has a value>1 and the new node has data>data of left child of the node itself, it's a left right case    
    if(bf>1 && key > node->left->key){
//calling first leftRotate function passing left subtree       
            node->left = leftRotate(node->left);
//and then calling rightRotate function on updated node to fix this disturbance            
            return rightRotate(node);
        }
    // Right Left Case
//if bf has a value<-1 and the new node has data< data of right child of the node itself, it's a right left case    
    if(bf<-1 && key < node->right->key){
//calling first rightRotate function passing right subtree           
            node->right = rightRotate(node->right);
//then calling leftRotate             
            return leftRotate(node);
        }
    return node;
}

void preOrder(struct Node *root)
{
    if(root != NULL)
    {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}
//creating a struct node pointer root and initializing it with NULL
int main(){
    struct Node * root = NULL;
 
//we can add as many nodes as we want
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 3);
    preOrder(root);
    return 0;
}
