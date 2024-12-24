/*MSSV: 22520350
Full name: Nguyen Thi My Duyen
Session 04 - Classwork 05
Notes or Remarks:
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int binarySearch(int arr[], int item, int low, int high) {
    while (low <= high) {
        int mid = (low + high) / 2;
        if (item == arr[mid])
            return mid + 1;
        else if (item > arr[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}

void binaryInsertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int pos = binarySearch(arr, key, 0, i - 1);
        for (int j = i - 1; j >= pos; j--) {
            arr[j + 1] = arr[j];
        }
        arr[pos] = key;
    }
}

void normalInsertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    const int SIZE = 1000;
    int arr1[SIZE], arr2[SIZE];
    srand(time(0));

    for (int i = 0; i < SIZE; i++) {
        arr1[i] = arr2[i] = rand() % 10000;
    }

    clock_t start = clock();
    normalInsertionSort(arr1, SIZE);
    clock_t end = clock();
    cout << "Thời gian Insertion Sort thường: " << (double)(end - start) / CLOCKS_PER_SEC << " giây." << endl;

    start = clock();
    binaryInsertionSort(arr2, SIZE);
    end = clock();
    cout << "Thời gian Binary Insertion Sort: " << (double)(end - start) / CLOCKS_PER_SEC << " giây." << endl;

    return 0;
}
