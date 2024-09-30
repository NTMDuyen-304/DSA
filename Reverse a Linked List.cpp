/*
STT: 22520350
Full Name: Nguyen Thi My Duyen
In Class part 1 - Cau 5
*/
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

// Hàm thêm một giá trị vào cuối danh sách liên kết
void insertAtEnd(Node*& head, int value) {
    Node* newNode = new Node(value);
    if (!head) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Hàm đảo ngược danh sách liên kết
void reverse(Node*& head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;

    while (current) {
        next = current->next;   // Lưu trữ con trỏ tiếp theo
        current->next = prev;   // Đảo ngược con trỏ
        prev = current;         // Di chuyển prev lên
        current = next;         // Di chuyển current lên
    }
    head = prev; // Đặt head mới sau khi đảo ngược
}

// Hàm in danh sách liên kết
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    int n;

    // Nhập danh sách liên kết
    cout << "Nhap so luong phan tu trong danh sach: ";
    cin >> n;
    cout << "Nhap cac phan tu cua danh sach: ";
    for (int i = 0; i < n; ++i) {
        int data;
        cin >> data;
        insertAtEnd(head, data);
    }

    // In danh sách liên kết trước khi đảo ngược
    cout << "Danh sach truoc khi dao nguoc: ";
    printList(head);

    // Đảo ngược danh sách liên kết
    reverse(head);  // Gọi hàm reverse với head

    // In danh sách liên kết sau khi đảo ngược
    cout << "Danh sach sau khi dao nguoc: ";
    printList(head);

    return 0;
}
