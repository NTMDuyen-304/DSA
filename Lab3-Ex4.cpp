/*
STT: 22520350
Full Name: Nguyen Thi My Duyen
Session 01 - Exercise 01
Notes or Remarks: ......
*/
#include <iostream>
using namespace std;


void Sort(int arr[], int n) {
    // Duyệt qua tất cả các phần tử trong mảng
    for (int i = 0; i < n - 1; i++) {
        // Duyệt qua phần tử chưa sắp xếp
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                // Hoán đổi nếu phần tử không đúng thứ tự
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Hàm tìm số bị thiếu sử dụng Binary Search
int findMissingNumber(int arr[], int n) {
    // Sắp xếp mảng trước khi tìm kiếm
    Sort(arr, n);
    int left = 0, right = n - 1;

    // Áp dụng tìm kiếm nhị phân để tìm số bị thiếu
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == mid) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return left; // Số bị thiếu sẽ là chỉ số "left" sau khi kết thúc vòng lặp
}

int main() {
    int arr[1000], n;
    cout << "Nhap so luong phan tu: ";
    cin >> n;

    cout << "Nhap mang: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "So bi thieu la: " << findMissingNumber(arr, n) << endl;
    return 0;
}
