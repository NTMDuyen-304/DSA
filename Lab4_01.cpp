
/*MSSV: 22520350
Full name: Nguyen Thi My Duyen
Session 04 - Classwork 01
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

int main() {
    const int SIZE = 1000;
    int arr[SIZE];
    srand(time(0));

    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 10000; // Random tu 0 den 9999
    }

    clock_t start = clock();
    bubbleSort(arr, SIZE);
    clock_t end = clock();
//em chay tren command line nen ko can utf-8
    cout << "Thời gian thực hiện Bubble Sort: " << (double)(end - start) / CLOCKS_PER_SEC << " giây." << endl;

    cout << "Mảng sau khi sắp xếp: ";
    for (int i = 0; i < 20; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
