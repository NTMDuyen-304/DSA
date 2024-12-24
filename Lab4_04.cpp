/*MSSV: 22520350
Full name: Nguyen Thi My Duyen
Session 04 - Classwork 04
Notes or Remarks:Nguye
*/
#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>

using namespace std;

// Binary Search to find the insertion position
int binarySearch(const vector<int>& arr, int item, int low, int high) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == item)
            return mid + 1;
        else if (arr[mid] < item)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}

// Enhanced Insertion Sort using Binary Search
void binaryInsertionSort(vector<int>& arr) {
    for (int i = 1; i < arr.size(); ++i) {
        int key = arr[i];
        int pos = binarySearch(arr, key, 0, i - 1);

        // Shift elements to make space for the key
        for (int j = i - 1; j >= pos; --j) {
            arr[j + 1] = arr[j];
        }
        arr[pos] = key;
    }
}

// Standard Insertion Sort
void insertionSort(vector<int>& arr) {
    for (int i = 1; i < arr.size(); ++i) {
        int key = arr[i];
        int j = i - 1;

        // Shift elements of arr[0..i-1] that are greater than key
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Function to measure and compare performance
void compareSorts() {
    const int SIZE = 10000;
    vector<int> arr1(SIZE), arr2(SIZE);

    // Fill the arrays with random values
    srand(time(0));
    for (int i = 0; i < SIZE; ++i) {
        int num = rand() % 100000;
        arr1[i] = num;
        arr2[i] = num;
    }

    // Measure time for Binary Insertion Sort
    auto start = chrono::high_resolution_clock::now();
    binaryInsertionSort(arr1);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;
    cout << "Binary Insertion Sort Time: " << elapsed.count() << " seconds.\n";

    // Measure time for Standard Insertion Sort
    start = chrono::high_resolution_clock::now();
    insertionSort(arr2);
    end = chrono::high_resolution_clock::now();
    elapsed = end - start;
    cout << "Standard Insertion Sort Time: " << elapsed.count() << " seconds.\n";
}

int main() {
    compareSorts();
    return 0;
}