/*MSSV: 22520350
Full name: Nguyen Thi My Duyen
Session 04 - Classwork 06
Notes or Remarks:Nguye
*/
#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

int findMax(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    return arr[0];
}

int main() {
    int arr[] = {3, 19, 1, 14, 8, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Giá trị lớn nhất: " << findMax(arr, n) << endl;

    return 0;
}
