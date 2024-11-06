/*
STT: 22520350
Full Name: Nguyen Thi My Duyen
Session 01 - Exercise 02
Notes or Remarks: ......
*/
#include <bits/stdc++.h>
using namespace std;

// Hàm Jump Search
int jumpSearch(int arr[], int n, int target, int step_size) {
    // Bắt đầu từ chỉ số 0
    int prev = 0;
    int curr = 0;

    // Nhảy qua các khối với bước size = step_size
    while (curr < n && arr[curr] < target) {
        prev = curr;
        curr = min(curr + step_size, n - 1);  // Đảm bảo không vượt quá n-1
    }

    // Sau khi nhảy xong, tìm kiếm tuyến tính trong đoạn từ prev đến curr
    for (int i = prev; i <= curr; i++) {
        if (arr[i] == target) {
            return i;  // Nếu tìm thấy mục tiêu
        }
    }

    return -1;  // Nếu không tìm thấy
}

int main() {
    int arr[1000], n, target, step_size;
    cout<< "Nhap so luong phan tu: ";
    cin>>n;
    cout<<"Nhap mang: ";
    for(int i=0; i<n; i++)
        cin>>arr[i];
    cout << "Nhap muc tieu: ";
    cin >> target;

    cout << "Nhap kich thuoc buoc: ";
    cin >> step_size;

    int result = jumpSearch(arr, n, target, step_size);
    if (result != -1) {
        cout << "Phan tu tim thay tai chi so: " << result << endl;
    } else {
        cout << "Phan tu khong tim thay." << endl;
    }

    return 0;
}

