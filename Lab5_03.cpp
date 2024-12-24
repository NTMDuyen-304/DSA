//STT: 225520350
//Full Name: Nguyen Thi My Duyen
//Session 05 - Exercise 03
//Notes or Remarks: ......

#include <iostream>
#include <algorithm>
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

class BinarySearchTree {
private:
    Node* root;

    // Helper function for insertion
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

    // Helper function for inorder traversal
    void inorderTraversalRecursive(Node* node) {
        if (node != nullptr) {
            inorderTraversalRecursive(node->left);
            cout << node->data << " ";
            inorderTraversalRecursive(node->right);
        }
    }

    // Helper function to calculate height
    int getHeightRecursive(Node* node) {
        if (node == nullptr) {
            return -1;  // Height of empty tree is -1
        }

        int leftHeight = getHeightRecursive(node->left);
        int rightHeight = getHeightRecursive(node->right);

        return max(leftHeight, rightHeight) + 1;
    }

    // Helper function to check if tree is balanced
    bool isBalancedRecursive(Node* node, int& height) {
        if (node == nullptr) {
            height = -1;
            return true;
        }

        int leftHeight = 0, rightHeight = 0;

        if (!isBalancedRecursive(node->left, leftHeight) ||
            !isBalancedRecursive(node->right, rightHeight) ||
            abs(leftHeight - rightHeight) > 1) {
            return false;
        }

        height = max(leftHeight, rightHeight) + 1;
        return true;
    }

public:
    BinarySearchTree() {
        root = nullptr;
    }

    // Basic operations
    void insert(int value) {
        root = insertRecursive(root, value);
    }

    void display() {
        if (root == nullptr) {
            cout << "Tree is empty" << endl;
            return;
        }
        cout << "Tree contents (inorder): ";
        inorderTraversalRecursive(root);
        cout << endl;
    }

    // New methods for finding min and max values
    int findMin() {
        if (root == nullptr) {
            throw runtime_error("Tree is empty");
        }

        Node* current = root;
        while (current->left != nullptr) {
            current = current->left;
        }
        return current->data;
    }

    int findMax() {
        if (root == nullptr) {
            throw runtime_error("Tree is empty");
        }

        Node* current = root;
        while (current->right != nullptr) {
            current = current->right;
        }
        return current->data;
    }

    // Method to get tree height
    int getHeight() {
        return getHeightRecursive(root);
    }

    // Method to check if tree is balanced
    bool isBalanced() {
        int height = 0;
        return isBalancedRecursive(root, height);
    }

    // Method to get balance factor of the tree
    int getBalanceFactor() {
        if (root == nullptr) {
            return 0;
        }

        int leftHeight = getHeightRecursive(root->left);
        int rightHeight = getHeightRecursive(root->right);

        return rightHeight - leftHeight;
    }
};

int main() {
    BinarySearchTree bst;
    int choice, value;

    while (true) {
        cout << "\nBinary Search Tree Operations:\n";
        cout << "1. Insert Value\n";
        cout << "2. Display Tree\n";
        cout << "3. Find Minimum\n";
        cout << "4. Find Maximum\n";
        cout << "5. Get Height\n";
        cout << "6. Check Balance\n";
        cout << "7. Get Balance Factor\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        try {
            switch (choice) {
                case 1:
                    cout << "Enter value to insert: ";
                    cin >> value;
                    bst.insert(value);
                    cout << "Value inserted successfully" << endl;
                    break;

                case 2:
                    bst.display();
                    break;

                case 3:
                    cout << "Minimum value: " << bst.findMin() << endl;
                    break;

                case 4:
                    cout << "Maximum value: " << bst.findMax() << endl;
                    break;

                case 5:
                    cout << "Tree height: " << bst.getHeight() << endl;
                    break;

                case 6:
                    if (bst.isBalanced()) {
                        cout << "Tree is balanced" << endl;
                    } else {
                        cout << "Tree is not balanced" << endl;
                    }
                    break;

                case 7:
                    cout << "Balance factor: " << bst.getBalanceFactor() << endl;
                    break;

                case 8:
                    cout << "Exiting program" << endl;
                    return 0;

                default:
                    cout << "Invalid choice. Please try again." << endl;
            }
        } catch (const runtime_error& e) {
            cout << "Error: " << e.what() << endl;
        }
    }

    return 0;
}
