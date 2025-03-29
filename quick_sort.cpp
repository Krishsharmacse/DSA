#include <iostream>
#include <algorithm>
using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Choosing the last element as pivot
    int i = low - 1; // Index of smaller element
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]); // Swap if element is smaller than pivot
        }
    }
    swap(arr[i + 1], arr[high]); // Place pivot in the correct position
    return i + 1; // Return the index of the pivot
}

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high); // Correct the parameters here
        quicksort(arr, low, pivot - 1); // Sort elements before pivot
        quicksort(arr, pivot + 1, high); // Sort elements after pivot
    }
}

int main() {
    int arr[] = {1, 2, 4, 6, 4, 7, 9, 32, 98};
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate number of elements

    quicksort(arr, 0, n - 1); // Correct the order of parameters

    // Print the sorted array
    for (int i = 0; i < n; i++) { // Initialize i to 0
        cout << arr[i] << " ";
    }
    cout << endl; // Print newline for better output formatting

    return 0;
}