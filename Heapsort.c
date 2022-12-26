// Heap Sort 
#include <stdio.h>
//Function to swap two elements
  void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
  }
  void heapify(int arr[], int n, int i) {
//Finding largest among root, left child and right child
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest])
      largest = l;
  
    if (r < n && arr[r] > arr[largest])
      largest = r;
//Swapping and continue heapifying if root is not largest
    if (largest != i) {
      swap(&arr[i], &arr[largest]);
      heapify(arr, n, largest);
    }
  }
//function to do heap sort
  void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
      heapify(arr, n, i);
    for (int i = n - 1; i >= 0; i--) {
      swap(&arr[0], &arr[i]);
// Heapify root element to get highest element at root again
      heapify(arr, i, 0);
    }
  }
//to print an array
  void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
      printf("%d ", arr[i]);
    printf("\n");
  }
  int main() {
    int arr[] = {2, 1, 3, 5, 6, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    heapSort(arr, n);
  
    printf("Our sorted array \n");
    printArray(arr, n);
  }