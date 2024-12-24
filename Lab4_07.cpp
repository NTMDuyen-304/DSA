/*MSSV: 22520350
Full name: Nguyen Thi My Duyen
Session 04 - Classwork 07
Notes or Remarks:
*/
#include <iostream>
using namespace std;

void insertionSort(int arr[], int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[m + 1 + i];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}

void hybridMergeSort(int arr[], int l, int r) {
    if (r - l <= 10) {
        insertionSort(arr, l, r);
    } else {
        int m = l + (r - l) / 2;
        hybridMergeSort(arr, l, m);
        hybridMergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    int arr[20] = {12, 11, 13, 5, 6, 7, 1, 3, 9, 8, 20, 17, 14, 19, 18, 16, 15, 2, 4, 10};
    int n = 20;

    hybridMergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
