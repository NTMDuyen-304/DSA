/* 
STT: 22520350
Full Name: Nguyen Thi My Duyen
In Class part 1 - Cau 3 
*/
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};
void insertAtEnd(Node*& head, int value) {
    Node* newNode = new Node(value);
    if (!head) {
        head = newNode;
    } 
    else {
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
Node* mergeTwoSortedLists(Node* l1, Node* l2) {
    Node* dummy = new Node(0);  // Chỗ chứa kết quả
    Node* tail = dummy;        
    while (l1 != nullptr && l2 != nullptr) {
        // Trường hợp l1<l2
        if (l1->data < l2->data) {
            tail->next = l1;   // Thêm l1 vào danh sách kết quả
            l1 = l1->next;     // Di chuyển l1 tới nút tiếp theo
        } 
        else {
            tail->next = l2;   // Thêm l2 vào danh sách kết quả
            l2 = l2->next;     // Di chuyển l2 tới nút tiếp theo
        }
        tail = tail->next;      // Di chuyển tail tới cuối danh sách kết quả
    }

    // Nếu l1 hoặc l2 còn phần tử, nối phần còn lại vào danh sách kết quả
    if (l1 != nullptr) {
        tail->next = l1;
    } 
    else {
        tail->next = l2;
    }

    return dummy->next;  // Trả về danh sách kết quả (bỏ qua nút giả)
}

int main() {
    Node* l1 = nullptr;
    Node* l2 = nullptr;
    int n1, n2;
    cout << "Nhap so luong phan tu trong danh sach thu nhat: ";
    cin >> n1;
    cout << "Nhap cac phan tu cua danh sach thu nhat (sap xep san): ";
    for (int i = 0; i < n1; ++i) {
        int data;
        cin >> data;
        insertAtEnd(l1, data);
    }
    cout << "Nhap so luong phan tu trong danh sach thu hai: ";
    cin >> n2;
    cout << "Nhap cac phan tu cua danh sach thu hai (sap xep san): ";
    for (int i = 0; i < n2; ++i) {
        int data;
        cin >> data;
        insertAtEnd(l2, data);
    }
    Node* mergedList = mergeTwoSortedLists(l1, l2);
    cout << "Danh sach sau khi hop nhat: ";
    printList(mergedList);
    return 0;
}
