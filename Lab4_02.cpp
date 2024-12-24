/*MSSV: 22520350
Full name: Nguyen Thi My Duyen
Session 04 - Classwork 02
Notes or Remarks:
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void benchmarkSort(int size) {
    int* arr = new int[size];
    srand(time(0));

    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 10000;
    }

    clock_t start = clock();
    bubbleSort(arr, size);
    clock_t end = clock();

    cout << "Thời gian cho mảng kích thước " << size << ": " << (double)(end - start) / CLOCKS_PER_SEC << " giây." << endl; 

    delete[] arr;
}

int main() {
    benchmarkSort(100);
    benchmarkSort(1000);
    benchmarkSort(10000);

    return 0;
}
