#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void buildMaxHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

void heapSort(int arr[], int n) {
    buildMaxHeap(arr, n);

    for (int i = n - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

struct PriorityQueue {
    int *arr;
    int size;
    int capacity;
};

void initPriorityQueue(struct PriorityQueue *pq, int capacity) {
    pq->arr = (int *)malloc(capacity * sizeof(int));
    pq->size = 0;
    pq->capacity = capacity;
}

void insert(struct PriorityQueue *pq, int key) {
    if (pq->size == pq->capacity) {
        printf("Priority Queue is full!\n");
        return;
    }

    pq->arr[pq->size] = key;
    pq->size++;

    int i = pq->size - 1;
    while (i != 0 && pq->arr[(i - 1) / 2] < pq->arr[i]) {
        swap(&pq->arr[i], &pq->arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int extractMax(struct PriorityQueue *pq) {
    if (pq->size <= 0) {
        printf("Priority Queue is empty!\n");
        return -1;
    }

    if (pq->size == 1) {
        pq->size--;
        return pq->arr[0];
    }

    int root = pq->arr[0];
    pq->arr[0] = pq->arr[pq->size - 1];
    pq->size--;

    heapify(pq->arr, pq->size, 0);

    return root;
}

int getMax(struct PriorityQueue *pq) {
    if (pq->size <= 0) {
        printf("Priority Queue is empty!\n");
        return -1;
    }
    return pq->arr[0];
}

void freePriorityQueue(struct PriorityQueue *pq) {
    free(pq->arr);
}

int main() {
    int arr[] = {17, 12, 155, 50, 45,450};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    heapSort(arr, n);

    printf("Sorted array using Heap Sort: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    struct PriorityQueue pq;
    initPriorityQueue(&pq, 10);

    insert(&pq, 17);
    insert(&pq, 12);
    insert(&pq, 155);
    insert(&pq, 50);
    insert(&pq, 45);
    insert(&pq, 450);

    printf("Max element in priority queue: %d\n", getMax(&pq));

    printf("Extracting max element: %d\n", extractMax(&pq));
    printf("Max element after extraction: %d\n", getMax(&pq));

    freePriorityQueue(&pq);

    return 0;
}
