/*
STT: 22520350
Full Name: Nguyen Thi My Duyen
Session 02 - Exercise 06
Notes or Remarks: ......
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

// Function to divide the linked list into k parts
vector<Node*> splitListToParts(Node* head, int k) {
    vector<Node*> parts(k, nullptr); // Initialize parts with nullptr
    int length = 0;

    // Calculate the length of the linked list
    Node* current = head;
    while (current) {
        length++;
        current = current->next;
    }

    // Determine the size of each part
    int partSize = length / k; // Base size of each part
    int extraParts = length % k; // Extra nodes to distribute

    current = head;
    for (int i = 0; i < k; ++i) {
        parts[i] = current; // Start of the current part
        int currentPartSize = partSize + (i < extraParts ? 1 : 0); // Size of this part
        
        // Move to the end of the current part
        for (int j = 0; j < currentPartSize - 1 && current; ++j) {
            current = current->next;
        }
        
        // Disconnect the current part from the rest of the list
        if (current) {
            Node* nextPartHead = current->next;
            current->next = nullptr; // Terminate this part
            current = nextPartHead; // Move to the start of the next part
        }
    }

    return parts;
}

int main() {
    Node* head = nullptr;
    int n, value, k;
    cout << "Nhap so luong phan tu trong danh sach: ";
    cin >> n;
    cout << "Nhap cac phan tu cua danh sach: ";
    for (int i = 0; i < n; ++i) {
        cin >> value;
        insertAtEnd(head, value);
    }

    cout << "Danh sach ban dau: ";
    printList(head);

    cout << "Nhap so phan: ";
    cin >> k;

    // Divide the linked list into parts
    vector<Node*> parts = splitListToParts(head, k);

    // Print each part
    for (int i = 0; i < k; ++i) {
        cout << "Part " << i + 1 << ": ";
        printList(parts[i]);
    }

    return 0;
}
