/*
STT: 22520350
Full Name: Nguyen Thi My Duyen
In Class part 2 - Cau 4
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

// Function to remove the N-th node from the end of the linked list
void removeNthFromEnd(Node*& head, int n) {
    Node* first = head;
    Node* second = head;

    // Move first pointer n steps ahead
    for (int i = 0; i < n; i++) {
        if (first == nullptr) return; // n is greater than the number of nodes
        first = first->next;
    }

    // If first is nullptr, we need to remove the head node
    if (first == nullptr) {
        Node* temp = head;
        head = head->next; // Move head to the next node
        delete temp; // Delete old head
        return;
    }

    // Move both pointers until first reaches the end
    while (first->next) {
        first = first->next;
        second = second->next;
    }

    // Now second is at the node before the target node
    Node* temp = second->next;
    second->next = second->next->next; // Remove the N-th node
    delete temp; // Free the memory of the removed node
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

    int removePos;
    cout << "Nhap vi tri node muon xoa tu cuoi: ";
    cin >> removePos;

    removeNthFromEnd(head, removePos);

    cout << "Danh sach sau khi xoa node: ";
    printList(head);

    return 0;
}
