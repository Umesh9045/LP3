#include<bits/stdc++.h>
using namespace std;

int partition(int left, int right, int arr[]) {
    int pivot = arr[left];
    int i = left + 1;
    int j = right;

    while (i < j) {
        while (arr[i] < pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i < j) {
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[left], arr[j]);
    return j;
}

void quickSort(int arr[], int left, int right) {
    if (left < right) {
        int pivot = partition(left, right, arr);
        quickSort(arr, left, pivot - 1);
        quickSort(arr, pivot + 1, right);
    }
}

int main() {
    int arr[] = {5, 4, 2, 1, 7, 8, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
