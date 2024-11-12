/*
STT: 22520350
Full Name: Nguyen Thi My Duyen
Session 01 - Exercise 06
Notes or Remarks: ......
*/
#include <bits/stdc++.h>
using namespace std;
int bidirectionalBinarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        if (arr[left] == target) {
            return left;
        }
        if (arr[right] == target) {
            return right;
        }
        left++;
        right--;
    }
    return -1; // Target not found
}

int main() {
    int a[100], n, target;
    cout<<"Nhập số phần tử mảng: ";
    cin>>n;
    cout<<"Nhập mảng: ";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<"Nhập phần tử muốn đếm: ";
    cin>>target;
    cout << "Target found at index: " << bidirectionalBinarySearch(a, n, target) << endl;
    return 0;
}
