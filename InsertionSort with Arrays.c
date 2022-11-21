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
//Creating a void function insertionSort and 
//passing the address of the array and its length as its parameters
void insertionSort(int *A, int n){
    int key, j;
// Creating a for Loop for passes
    for (int i = 1; i <= n-1; i++)
    {
//collecting the element at the index i in an integer variable key
//This key is the element we would insert in the sorted subarray      
        key = A[i];
//j, which would be used to iterate through the sorted subarray and to find a perfect position for the key        
        j = i-1;
//a while loop run until either we finish through the sorted subarray or else we find an index fit for the key
        while(j>=0 && A[j] > key){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;
    }
}

int main(){
 
    int A[] = {21, 55, 65, 6, 22, 9,1};
    int n = 7;
    printArray(A, n);
    insertionSort(A, n);
    printArray(A, n);
    return 0;
}
