/*
STT: 22520350
Full Name: Nguyen Thi My Duyen
Session 02 - Exercise 02
Notes or Remarks: ......
*/
#include <iostream>
using namespace std;

struct Node {
    int Data;   
    Node* pNext;    

    Node(int data) : Data(data), pNext(nullptr) {}
};

class LinkList {
public:
    Node* pHead; 

    LinkList() : pHead(nullptr) {}

    void Insert(int data) {
        Node* newNode = new Node(data);
        if (!pHead) {
            pHead = newNode;
        } else {
            Node* temp = pHead;
            while (temp->pNext) {
                temp = temp->pNext;
            }
            temp->pNext = newNode;
        }
    }

    void PrintList() {
        Node* temp = pHead;
        while (temp) {
            cout << temp->Data << " -> ";
            temp = temp->pNext;
        }
        cout << "NULL" << endl;
    }

    LinkList* copyList() {
        if (pHead == NULL) {
            cout << "Empty list!" << endl;
            return NULL;
        }
        LinkList* temp = new LinkList; // Create a new linked list
        Node* curr = pHead; // Start from the head of the original list
        while (curr != NULL) {
            temp->Insert(curr->Data); // Copy data to the new list
            curr = curr->pNext; // Move to the next node
        }

        cout << "Your list has been copied!";
        return temp; 
    }
};

int main() {
    LinkList originalList;
    int n;

    cout << "Enter values for the list (enter 0 to finish):" << endl;
    while (true) {
        cin >> n;
        if (n == 0) break; 
        originalList.Insert(n); 
    }

    // Print the original list
    cout << "Original List: ";
    originalList.PrintList();

    // Copy the list
    LinkList* copiedList = originalList.copyList();

    // Print the copied list if it exists
    if (copiedList) {
        cout << "Copied List: ";
        copiedList->PrintList();
        
        // Cleanup memory for copied list
        Node* temp;
        while (copiedList->pHead) {
            temp = copiedList->pHead;
            copiedList->pHead = copiedList->pHead->pNext;
            delete temp; // Delete the node to free memory
        }
        delete copiedList; // Delete the copied list itself
    }

    // Cleanup memory for original list
    Node* temp;
    while (originalList.pHead) {
        temp = originalList.pHead;
        originalList.pHead = originalList.pHead->pNext;
        delete temp; // Delete the node to free memory
    }

    return 0;
}
