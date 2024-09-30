/*
STT: 22520350
Full Name: Nguyen Thi My Duyen
In Class part 2 - Cau 3
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

// Function to swap two nodes in the linked list
void swapNodes(Node*& head, int x, int y) {
    if (x == y) return; // No need to swap the same node

    Node *prevX = nullptr, *currX = head;
    while (currX && currX->data != x) {
        prevX = currX;
        currX = currX->next;
    }

    Node *prevY = nullptr, *currY = head;
    while (currY && currY->data != y) {
        prevY = currY;
        currY = currY->next;
    }

    if (!currX || !currY) return; // One of the nodes not found

    // If x is not head, then link prevX to currY
    if (prevX) {
        prevX->next = currY;
    } 
    else {
        head = currY; // Change head if x was the head
    }

    // If y is not head, then link prevY to currX
    if (prevY) {
        prevY->next = currX;
    } else {
        head = currX; // Change head if y was the head
    }

    // Swap next pointers
    Node* temp = currY->next;
    currY->next = currX->next;
    currX->next = temp;
}

int main() {
    Node* head = nullptr;
    int n;
    cout << "Nhap so luong phan tu trong danh sach: ";
    cin >> n;
    cout << "Nhap cac phan tu cua danh sach: ";
    for (int i = 0; i < n; ++i) {
        int data;
        cin >> data;
        insertAtEnd(head, data);
    }

    cout << "Danh sach ban dau: ";
    printList(head);

    int x, y;
    cout << "Nhap gia tri cua hai node muon hoan doi: ";
    cin >> x >> y;

    swapNodes(head, x, y);

    cout << "Danh sach sau khi hoan doi: ";
    printList(head);

    return 0;
}
