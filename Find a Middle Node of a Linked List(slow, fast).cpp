/* 
STT: 22520350
Full Name: Nguyen Thi My Duyen
Session 01 - Exercise 01
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
        cout << head->data <<" ";
        head = head->next;
    }
    cout << endl;
}
Node* findMiddle(Node* head) {
    if (head == NULL) return NULL;
    Node* slow = head;
    Node* fast = head;
    // Move fast pointer two steps and slow pointer one step at a time
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    // Slow pointer will now be pointing to the middle node
    return slow;
}
int main() {
    Node* head = nullptr;
    int n, x;
    cout << "Nhap so luong phan tu: ";
    cin >> n;
    cout << "Nhap cac phan tu: ";
    for (int i = 0; i < n; ++i) {
        int data;
        cin >> data;
        insertAtEnd(head, data);
    }
    printList(head);
    Node* middle = findMiddle(head);
    if (middle != NULL) {
        cout << "The middle node value is: " << middle->data << endl;
    }
    return 0;
}
