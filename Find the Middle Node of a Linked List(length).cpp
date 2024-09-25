/* 
STT:
Full Name: Nguyen Thi My Duyen
In Class part 1 - Cau 1 
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
int getLength(Node* head) {
    int length = 0;
        while (head != nullptr) {
            length++;
            head = head->next;
        }
        return length;
}
Node* FindMiddleNode(Node*head){
    int l=getLength(head);
    int MidNode;
    if(l%2==0)
        MidNode=l/2 -1;
    else     
        MidNode=l/2;
    Node* temp=head;
    for(int i=0;i<MidNode;i++)
          temp = temp->next;
    return temp;
}

int main() {
    Node* head = nullptr;
    int n, x;
    cout << "Nhap so luong phan tu trong danh sach: ";
    cin >> n;
    cout << "Nhap cac phan tu cua danh sach: ";
    for (int i = 0; i < n; ++i) {
        int data;
        cin >> data;
        insertAtEnd(head, data);
    }
    printList(head);
    Node* Middle=FindMiddleNode(head);
    if (Middle) {
        cout << "The middle node value is: " << Middle->data << endl;
    } 
    else {
        cout << "The list is empty." << endl;
    }

    return 0;

}