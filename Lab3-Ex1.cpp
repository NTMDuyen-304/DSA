/*
STT: 22520350
Full Name: Nguyen Thi My Duyen
Session 01 - Exercise 01
Notes or Remarks: ......
*/
#include <bits/stdc++.h>
using namespace std;

// Hàm tìm kiếm nhị phân để tìm chỉ số bên trái của phần tử
int binarySearchLeft(int a[], int n, int target) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (a[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return left;
}

// Hàm tìm kiếm nhị phân để tìm chỉ số bên phải của phần tử
int binarySearchRight(int a[], int n, int target) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (a[mid] <= target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return right;
}

int countOccurrences(int a[], int n, int target) {
    int leftIndex = binarySearchLeft(a, n, target);
    int rightIndex = binarySearchRight(a, n, target);

    if (leftIndex <= rightIndex) {
        return rightIndex - leftIndex + 1;
    }
    return 0; // Không tìm thấy phần tử
}

int main() {
    int a[100], n, target;
    cout<<"Nhập số phần tử mảng: ";
    cin>>n;
    cout<<"Nhập mảng: ";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<"Nhập phần tử muốn đếm";
    cin>>target;
    cout << "Số lần xuất hiện của " << target << ": " << countOccurrences(a, n, target) << endl;
    return 0;
}
