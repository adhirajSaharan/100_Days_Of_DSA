#include <stdio.h>

/* swap two elements */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* heapify a subtree rooted at index i */
void heapify(int arr[], int n, int i)
{
    int largest = i;          // assume root is largest
    int left = 2*i + 1;       // left child
    int right = 2*i + 2;      // right child

    // if left child is larger
    if(left < n && arr[left] > arr[largest])
        largest = left;

    // if right child is larger
    if(right < n && arr[right] > arr[largest])
        largest = right;

    // if largest is not root
    if(largest != i)
    {
        swap(&arr[i], &arr[largest]);

        // heapify the affected subtree
        heapify(arr, n, largest);
    }
}

/* main heap sort function */
void heapSort(int arr[], int n)
{
    // build max heap
    for(int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // extract elements from heap
    for(int i = n-1; i > 0; i--)
    {
        // move current root to end
        swap(&arr[0], &arr[i]);

        // call heapify on reduced heap
        heapify(arr, i, 0);
    }
}

/* print array */
void printArray(int arr[], int n)
{
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}

/* main function */
int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);

    heapSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}
