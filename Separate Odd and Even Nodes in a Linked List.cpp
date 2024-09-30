/*
STT: 22520350
Full Name: Nguyen Thi My Duyen
Session 02 - Exercise 05
Notes or Remarks: ......
*/
#include <iostream>
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
    } else {
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

// Function to separate odd and even nodes in the linked list
void separateOddEven(Node* head, Node*& oddHead, Node*& evenHead) {
    Node* oddTail = nullptr;
    Node* evenTail = nullptr;
    int index = 0;

    while (head) {
        if (index % 2 == 0) { // Even index
            if (!evenHead) {
                evenHead = head; // Initialize even list
                evenTail = evenHead;
            } else {
                evenTail->next = head; // Append to even list
                evenTail = evenTail->next;
            }
        } 
        else { // Odd index
            if (!oddHead) {
                oddHead = head; // Initialize odd list
                oddTail = oddHead;
            } else {
                oddTail->next = head; // Append to odd list
                oddTail = oddTail->next;
            }
        }
        head = head->next;
        index++;
    }

    // Null-terminate the lists
    if (evenTail) evenTail->next = nullptr;
    if (oddTail) oddTail->next = nullptr;
}

int main() {
    Node* head = nullptr;
    int n, value;
    cout << "Nhap so luong phan tu trong danh sach: ";
    cin >> n;
    cout << "Nhap cac phan tu cua danh sach: ";
    for (int i = 0; i < n; ++i) {
        cin >> value;
        insertAtEnd(head, value);
    }

    cout << "Danh sach ban dau: ";
    printList(head);

    Node* oddHead = nullptr;
    Node* evenHead = nullptr;

    separateOddEven(head, oddHead, evenHead);

    cout << "Danh sach cac node o vi tri le: ";
    printList(oddHead);

    cout << "Danh sach cac node o vi tri chan: ";
    printList(evenHead);

    return 0;
}
