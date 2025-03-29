#include <stdio.h>

long partition(long arr[], long low, long high) {
    long pivot = arr[high];
    long i = low - 1;

    for (long j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            long temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    long temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

void quickSort(long arr[], long low, long high) {
    if (low < high) {
        long pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    long arr[] = {45, 67, 77, 89, 32, 43};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    for (long i = 0; i < n; i++) {
        printf("%ld ", arr[i]);
    }
    printf("\n");

    quickSort(arr, 0, n - 1);

    printf("Sorted array:\n");
    for (long i = 0; i < n; i++) {
        printf("%ld ", arr[i]);
    }
    printf("\n");

    return 0;
}
