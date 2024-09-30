/*
STT: 22520350
Full Name: Nguyen Thi My Duyen
In Class part 2 - Cau 7
*/
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int value;
    Node* link;
    Node(int x) : value(x), link(nullptr) {}
};

struct List {
    Node* head;
    List() : head(nullptr) {}
};

void insertAtEnd(List& A, int value) {
    Node* newNode = new Node(value);
    if (!A.head) {
        A.head = newNode;
    } else {
        Node* temp = A.head;
        while (temp->link) {
            temp = temp->link;
        }
        temp->link = newNode;
    }
}
void printList(Node* head) {
    while (head) {
        cout << head->value << " ";
        head = head->link;
    }
    cout << endl;
}

// Function to remove zero-sum consecutive nodes from the linked list
void removeZeroSumNodes(List& A) {
    Node* dummy = new Node(0); // Create a dummy node
    dummy->link = A.head; // Connect it to the head
    Node* prev = dummy; // Start with the dummy node
    Node* current = A.head;

    while (current != nullptr) {
        int sum = 0;
        Node* tmp = current;

        while (tmp != nullptr) {
            sum += tmp->value;

            if (sum == 0) {
                // If we find a zero-sum, remove the nodes between current and tmp
                prev->link = tmp->link;
                current = prev->link; // Move current to the next node
                break;
            }
            tmp = tmp->link;
        }

        if (tmp == nullptr) {
            // If no zero-sum was found, move prev and current
            prev = current;
            current = current->link;
        }
    }

    A.head = dummy->link; // Update the head to skip the dummy
    delete dummy; 
}

int main() {
    List A;
    int n, value;
    cout << "Nhap so luong phan tu trong danh sach: ";
    cin >> n;
    cout << "Nhap cac phan tu cua danh sach: ";
    for (int i = 0; i < n; ++i) {
        cin >> value;
        insertAtEnd(A, value);
    }
    cout << "Danh sach ban dau: ";
    printList(A.head);
    removeZeroSumNodes(A);

    cout << "Danh sach sau khi xoa cac node co tong bang 0: ";
    printList(A.head);

    return 0;
}
