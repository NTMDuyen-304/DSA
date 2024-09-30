/*
STT: 22520350
Full Name: Nguyen Thi My Duyen
Session 02 - Exercise 01
Notes or Remarks: ......
*/
#include <iostream>
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

// Hàm in danh sách liên kết
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Hàm tìm kiếm và in các node có giá trị X
Node* searchForValue(Node* head, int X) {
    Node* current = head;
    bool found = false;
    
    while (current != nullptr) {
        if (current->data == X) {
            cout << "Tim thay gia tri " << X << " tai dia chi: " <<current ;
            found = true;  
        }
        current = current->next;
    }

    if (!found) {
        cout << "NULL";
        return nullptr;
    }

    return head;
}

int main() {
    Node* head = nullptr;
    int n,a,b;
    // Nhập danh sách liên kết
    cout << "Nhap so luong phan tu trong danh sach: ";
    cin >> n;
    cout << "Nhap cac phan tu cua danh sach: ";
    for (int i = 0; i < n; ++i) {
        int data;
        cin >> data;
        insertAtEnd(head, data);
    }
    cout<<"Enter the two numbers: "; 
    cin>>a>>b;
     insertAtEnd(head, a);
     insertAtEnd(head, b);
    cout<<"List after added: ";
    printList(head); 
}
