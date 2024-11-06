/*
STT: 22520350
Full Name: Nguyen Thi My Duyen
Session 01 - Exercise 07
Notes or Remarks: ......
*/
include <bits/stdc++.h>
using namespace std;

// Function to find the minimum element in the array
int findMin(int arr[], int n) {
    int min = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

// Function to find the maximum element in the array
int findMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Function to count elements <= mid
int countLessOrEqual(int arr[], int n, int mid) {
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] <= mid) {
            ++count;
        }
    }
    return count;
}

// Function to find the kth smallest element using a modified binary search
int kthSmallestUsingBinarySearch(int arr[], int n, int k) {
    int low = findMin(arr, n);
    int high = findMax(arr, n);

    while (low < high) {
        int mid = low + (high - low) / 2;
        int count = countLessOrEqual(arr, n, mid);

        if (count < k) {
            // Move to the right half
            low = mid + 1;
        } else {
            // Move to the left half
            high = mid;
        }
    }
    return low;  // 'low' now holds the kth smallest element
}

int main() {
    int arr[100], n, k;

    // Nhập số lượng phần tử trong mảng
    cout << "Nhap so luong phan tu: ";
    cin >> n;

    // Nhập mảng
    cout << "Nhap mang: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Nhập k
    cout << "Nhap k: ";
    cin >> k;

    // Kiểm tra xem k có hợp lệ không
    if (k <= 0 || k > n) {
        cout << "Gia tri k khong hop le!" << endl;
        return -1;
    }

    // Tìm phần tử nhỏ thứ k
    int result = kthSmallestUsingBinarySearch(arr, n, k);
    cout << "The " << k << "th smallest element is " << result << endl;

    return 0;
}
