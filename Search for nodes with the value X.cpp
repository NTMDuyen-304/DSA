/*
STT: 22520350
Full Name: Nguyen Thi My Duyen
Session 01 - Exercise 08
Notes or Remarks: ......
*/

#include <iostream>
using namespace std;

// Node structure
struct Node {
    int value;
    Node* next; // Pointer to the next node
    Node(int val) : value(val), next(nullptr) {}
};

// Function to insert a node at the end of the linked list
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

// Function to search for nodes with the value X in the list
void searchNodesWithValue(Node* head, int X) {
    Node* current = head;
    bool found = false;

    while (current != nullptr) {
        if (current->value == X) {
            found = true;
            // Print the address of the found node
            cout << "Tim thay gia tri " << current->value << " tai dia chi: " << current << endl;
        }
        current = current->next; // Move to the next node
    }

    if (!found) {
        cout << "NULL";
    }
}

// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout<< endl;
}

int main() {
    Node* l1 = nullptr; // Initialize the head of the list
    int n, value;

    cout << "Nhap so luong phan tu trong danh sach: ";
    cin >> n;
    cout << "Nhap cac phan tu trong danh sach: ";

    // Read elements into the linked list
    for (int i = 0; i < n; ++i) {
        cin >> value;
        insertAtEnd(l1, value);
    }

    cout << "Danh sach: ";
    printList(l1);
    
    int searchValue;
    cout << "Nhap gia tri can tim: ";
    cin >> searchValue;

    // Search for nodes with the specified value
    searchNodesWithValue(l1, searchValue);

    return 0;
}
