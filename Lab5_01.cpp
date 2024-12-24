//STT: 225520350
//Full Name: Nguyen Thi My Duyen
//Session 05 - Exercise 01
//Notes or Remarks: ......

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BinaryTree {
private:
    Node* root;

    // Helper function for inserting nodes recursively
    Node* insertRecursive(Node* current, int value) {
        if (current == nullptr) {
            return new Node(value);
        }

        if (value < current->data) {
            current->left = insertRecursive(current->left, value);
        } else if (value > current->data) {
            current->right = insertRecursive(current->right, value);
        }

        return current;
    }

    // Helper function for searching nodes recursively
    Node* searchRecursive(Node* current, int value) {
        if (current == nullptr || current->data == value) {
            return current;
        }

        if (value < current->data) {
            return searchRecursive(current->left, value);
        }
        return searchRecursive(current->right, value);
    }

    // Helper function to find minimum value node
    Node* findMin(Node* node) {
        Node* current = node;
        while (current && current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    // Helper function for deleting nodes recursively
    Node* deleteRecursive(Node* current, int value) {
        if (current == nullptr) {
            return nullptr;
        }

        if (value < current->data) {
            current->left = deleteRecursive(current->left, value);
        } else if (value > current->data) {
            current->right = deleteRecursive(current->right, value);
        } else {
            // Node with only one child or no child
            if (current->left == nullptr) {
                Node* temp = current->right;
                delete current;
                return temp;
            } else if (current->right == nullptr) {
                Node* temp = current->left;
                delete current;
                return temp;
            }

            // Node with two children
            Node* temp = findMin(current->right);
            current->data = temp->data;
            current->right = deleteRecursive(current->right, temp->data);
        }
        return current;
    }

    // Helper function for inorder traversal
    void inorderTraversalRecursive(Node* node) {
        if (node != nullptr) {
            inorderTraversalRecursive(node->left);
            cout << node->data << " ";
            inorderTraversalRecursive(node->right);
        }
    }

public:
    BinaryTree() {
        root = nullptr;
    }

    void insert(int value) {
        root = insertRecursive(root, value);
    }

    bool search(int value) {
        return searchRecursive(root, value) != nullptr;
    }

    void remove(int value) {
        root = deleteRecursive(root, value);
    }

    void display() {
        if (root == nullptr) {
            cout << "Tree is empty" << endl;
            return;
        }
        inorderTraversalRecursive(root);
        cout << endl;
    }
};

int main() {
    BinaryTree tree;
    int choice, value;

    while (true) {
        cout << "\nBinary Tree Operations:\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Search\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                tree.insert(value);
                break;

            case 2:
                cout << "Enter value to delete: ";
                cin >> value;
                tree.remove(value);
                break;

            case 3:
                cout << "Enter value to search: ";
                cin >> value;
                if (tree.search(value)) {
                    cout << "Value " << value << " found in the tree" << endl;
                } else {
                    cout << "Value " << value << " not found in the tree" << endl;
                }
                break;

            case 4:
                cout << "Tree contents (inorder traversal): ";
                tree.display();
                break;

            case 5:
                cout << "Exiting program" << endl;
                return 0;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
