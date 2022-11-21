#include<stdio.h>
//Creating a void function printArray
//and passing the address of the array and its length as its parameters
void printArray(int* A, int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}
// Now creating a void function selectionSort 
//and passing the array's address and length as its parameters
void selectionSort(int *A, int n){
//Creating two integer variables: for  maintaining the min index which is called the indexOfMin 
//and nother for swapping purposes called temp
    int indexOfMin, temp;
    printf("After you run selection sort algorithm...\n");
//creating a for loop that tracks the number of passes  
//at each pass,first initializing the indexOfMin to be the first index of the unsorted part.
//So,inside this loop, initializing the indexOfMin to be i, which is always the first index 
//of the unsorted part of the array.    
    for (int i = 0; i < n-1; i++)
    {
        indexOfMin = i;
//Creating another loop to iterate over the rest of the elements in the unsorted part 
//to find if there is any lesser element than the one at indexOfMin. 
        for (int j = i+1; j < n; j++)
        {
// If we find an element at index j, which is less than the element at indexOfMin,
//then updating indexOfMin to j.            
            if(A[j] < A[indexOfMin]){
                indexOfMin = j;
            }
        }
//Swapping A[i] and A[indexOfMin]
        temp = A[i];
        A[i] = A[indexOfMin];
        A[indexOfMin] = temp;
    }
}
//when we finish iterating through both the i and the j loops, we will receive a sorted array.
int main(){
    
//Let us now check. Considering an array A of length 6.
    int A[] = {3, 5, 2, 13, 12,7};
    int n = 6;
    printArray(A, n);
    selectionSort(A, n);
    printArray(A, n);

    return 0;
}
