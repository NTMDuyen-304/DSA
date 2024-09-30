/*
STT: 22520350
Full Name: Nguyen Thi My Duyen
In Class part 1 - Cau 7
*/
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

// Hàm thêm một giá trị vào cuối danh sách liên kết
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

// Hàm in danh sách liên kết
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Hàm đảo ngược danh sách liên kết
Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;  // Lưu trữ con trỏ tiếp theo
        current->next = prev;        // Đảo ngược con trỏ
        prev = current;              // Di chuyển prev lên
        current = next;              // Di chuyển current lên
    }
    return prev;  // Trả về head mới sau khi đảo ngược
}

// Hàm kiểm tra danh sách liên kết có phải là palindrome hay không
bool isPalindrome(Node* head) {
    if (!head || !head->next) return true; // Nếu danh sách rỗng hoặc chỉ có một phần tử, nó là palindrome

    // Tìm điểm giữa của danh sách liên kết (dùng phương pháp fast & slow pointers)
    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Đảo ngược nửa sau của danh sách
    Node* secondHalf = reverseList(slow);
    Node* firstHalf = head;

    // So sánh hai nửa của danh sách
    Node* secondHalfCopy = secondHalf; // Giữ bản sao để khôi phục danh sách nếu cần
    while (secondHalf != nullptr) {
        if (firstHalf->data != secondHalf->data) {
            return false;  // Nếu có sự khác biệt thì không phải là palindrome
        }
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    // (Optional) Khôi phục danh sách nguyên bản
    reverseList(secondHalfCopy);

    return true;
}

int main() {
    Node* head = nullptr;
    int n;

    // Nhập danh sách liên kết
    cout << "Nhap so luong phan tu trong danh sach: ";
    cin >> n;
    cout << "Nhap cac phan tu cua danh sach: ";
    for (int i = 0; i < n; ++i) {
        int data;
        cin >> data;
        insertAtEnd(head, data);
    }

    // In danh sách liên kết
    cout << "Danh sach: ";
    printList(head);

    // Kiểm tra danh sách liên kết có phải là palindrome hay không
    if (isPalindrome(head)) {
        cout << "Danh sach la palindrome." << endl;
    } else {
        cout << "Danh sach khong phai la palindrome." << endl;
    }

    return 0;
}
