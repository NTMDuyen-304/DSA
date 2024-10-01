/*
STT: 22520350
Full Name: Nguyen Thi My Duyen
Session 01 - Exercise 04
Notes or Remarks: ......
*/
#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* link;
    Node(int val) : value(val), link(nullptr) {}
};

class List {
public:
    Node* head;
    List() : head(nullptr) {}

    void AddTail(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->link != nullptr) {
                temp = temp->link;
            }
            temp->link = newNode;
        }
    }

    void printList() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->value << " -> ";
            temp = temp->link;
        }
        cout << "NULL";
    }
};

// Function to find the intersection point of two linked lists
Node* intersectionOf2List(List A, List B) {
    if (A.head == nullptr || B.head == nullptr) return nullptr;

    Node* tmpA = A.head;
    Node* tmpB = B.head;

    // Traverse both lists
    while (tmpA != nullptr) {
        // Check for intersection
        Node* checkB = B.head;
        while (checkB != nullptr) {
            if (tmpA == checkB) {  // Check memory address for intersection
                return tmpA;  // Intersection found
            }
            checkB = checkB->link;
        }
        tmpA = tmpA->link;
    }

    return nullptr;  // No intersection found
}

int main() {
    List A, B;
    int n;
    cout << "List 1: ";
    while (true) {
        cin >> n;
        if (n == 0) break;
        A.AddTail(n);
    }
    cout << endl << "List 2: ";
    while (true) {
        cin >> n;
        if (n == 0) break;
        B.AddTail(n);
    }
    Node* intersectionNode = A.head->link;  
    Node* tempB = B.head;
    while (tempB->link != nullptr) {  // Traverse B to the last node
        tempB = tempB->link;
    }
    tempB->link = intersectionNode;  // Create intersection

    // Find the intersection node
    Node* intersection = intersectionOf2List(A, B);
    if (intersection == nullptr) {
        cout << "No intersection" << endl;
    } else {
        cout << "The intersection is: "<< intersection->value;
    }

    return 0;
}
