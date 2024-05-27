#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) 
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void display (int heap[], int currentSize) 
{
    printf("Heap => ");
    for (int i = 0; i < currentSize; i++) 
    {
        printf("%d ", heap[i]);
    }
    printf("\n");
}

void heapify (int arr[], int size, int i) 
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < size && arr[l] > arr[largest]) {
        largest = l;
    }
    if (r < size && arr[r] > arr[largest]) {
        largest = r;
    }
    if (largest != i) {
        swap(&arr[largest], &arr[i]);
        heapify(arr, size, largest);
    }
}

void heapSort (int arr[], int size) 
{
    int i;
    for (i = size / 2 - 1; i >= 0; i--) 
    {
        heapify(arr, size, i);    
    }
    for (i = size - 1; i > 0; i--) 
    {
        swap(&arr[0], &arr[i]); 
        heapify(arr, i, 0);  
    }
}

int main() 
{
    int heap[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int N = sizeof(heap) / sizeof(heap[0]);

    display(heap, N);

    heapSort(heap, N);
    display(heap, N);

    return 0;
}

/*
Heap => 9 8 7 6 5 4 3 2 1 0 
Heap => 0 1 2 3 4 5 6 7 8 9
*/