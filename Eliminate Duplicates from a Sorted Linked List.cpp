/*
STT: 22520350
Full Name: Nguyen Thi My Duyen
Session 01 - Exercise 06
Notes or Remarks: ......
*/

#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* next; 
    Node(int val) : value(val), next(nullptr) {}
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

// Function to eliminate duplicates from a sorted linked list
void eliminateDuplicates(Node*& head) {
    if (head == nullptr) return; // Empty list, nothing to do

    Node* current = head;
    while (current != nullptr && current->next != nullptr) {
        if (current->value == current->next->value) {
            // Duplicate found, skip the next node
            Node* duplicate = current->next;
            current->next = current->next->next; // Bypass duplicate
            delete duplicate; // Free memory
        } else {
            current = current->next; // Move to the next node
        }
    }
}
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->value<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main() {
    Node* l1 = nullptr; 
    int n, value;

    cout << "Nhap so luong phan tu trong danh sach: ";
    cin >> n;
    cout << "Nhap cac phan tu cua danh sach (da sap xep): ";

    for (int i = 0; i < n; ++i) {
        cin >> value;
        insertAtEnd(l1, value);
    }

    cout << "Danh sach truoc khi loai bo trung lap: ";
    printList(l1);
    eliminateDuplicates(l1);
    cout << "Danh sach sau khi loai bo trung la: ";
    printList(l1);
    
    return 0;
}
