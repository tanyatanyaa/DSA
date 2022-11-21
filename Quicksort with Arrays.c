#include <stdio.h>
//Creating the printArray function
void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}
//Creating a void function partition, and passing
//the address of the array and the low and the high of the subarray as parameters. 
int partition(int A[], int low, int high)
{
    int pivot = A[low];
    int i = low + 1;
    int j = high;
    int temp;

    do
    {
//a while loop and run until the index i reaches an element greater than or equal to the pivot 
//or the array finishes.
    while (A[i] <= pivot)
        {
            i++;
        }
//while loop and run until our index j reaches an element smaller than the pivot or the array finishes
        while (A[j] > pivot)
        {
            j--;
        }

        if (i < j)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    } while (i < j);

    // Swap A[low] and A[j]
    temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    return j;
}
//Creating a void function quickSort and passing the address of the array and the lower index
void quickSort(int A[], int low, int high)
{
//Creating an integer variable partitionIndex for holding the index provided by the partition  
    int partitionIndex; 

    if (low < high)
    {
        partitionIndex = partition(A, low, high); 
        quickSort(A, low, partitionIndex - 1);  //for sorting left subarray 
        quickSort(A, partitionIndex + 1, high); //for sorting right subarray
    }
}

int main()
{
    
    int A[] = {8, 3, 3, 6, 5, 4, 7};
 
    int n = 9;
    n =7;
    printArray(A, n);
    quickSort(A, 0, n - 1);
    printArray(A, n);
    return 0;
}
