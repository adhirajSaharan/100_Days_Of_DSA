#include <stdio.h>

#define MAX 100

int heap[MAX];
int size = 0;

/* swap two elements */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* move element up to maintain heap property */
void heapifyUp(int index)
{
    int parent = (index - 1) / 2;

    while(index > 0 && heap[parent] > heap[index])
    {
        swap(&heap[parent], &heap[index]);
        index = parent;
        parent = (index - 1) / 2;
    }
}

/* move element down to maintain heap property */
void heapifyDown(int index)
{
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if(left < size && heap[left] < heap[smallest])
        smallest = left;

    if(right < size && heap[right] < heap[smallest])
        smallest = right;

    if(smallest != index)
    {
        swap(&heap[index], &heap[smallest]);
        heapifyDown(smallest);
    }
}

/* insert element into heap */
void insert(int x)
{
    heap[size] = x;
    heapifyUp(size);
    size++;
}

/* return smallest element */
int peek()
{
    if(size == 0)
        return -1;

    return heap[0];
}

/* remove and return smallest element */
int extractMin()
{
    if(size == 0)
        return -1;

    int min = heap[0];

    heap[0] = heap[size - 1];
    size--;

    heapifyDown(0);

    return min;
}

/* main function */
int main()
{
    int n;
    scanf("%d", &n);

    while(n--)
    {
        char op[20];
        scanf("%s", op);

        if(op[0] == 'i')   // insert
        {
            int x;
            scanf("%d", &x);
            insert(x);
        }
        else if(op[0] == 'p')  // peek
        {
            printf("%d\n", peek());
        }
        else if(op[0] == 'e')  // extractMin
        {
            printf("%d\n", extractMin());
        }
    }

    return 0;
}
